#include <cwf/sqlquery.h>
#include <cwf/cppwebapplication.h>
#include <cwf/sqldatabasestorage.h>

#include "model/logradouro.h"
#include "logradouro_dao.h"

// ajustar base de dados
CWF::SqlDatabaseStorage conexao("QPSQL", "cepdb.cvjysrwbh0op.us-east-1.rds.amazonaws.com", "cepdb", "root", "12qwaszx", 5432);

class CEPController : public CWF::Controller
{

public:
    void doGet(CWF::Request &request, CWF::Response &response) const override
    {
        CWF::SqlQuery qry(conexao.getDatabase());
        qry.exec("select * from logradouro");
        response.write(qry.toJson());
    }

    void doPost(CWF::Request &request, CWF::Response &response) const override
    {
        CWF::SqlQuery qry(conexao.getDatabase());
        response.write(qry.insertFromJson(request.bodyToJsonObject(), "logradouro"));
    }

    void doDelete(CWF::Request &request, CWF::Response &response) const override
    {
        CWF::SqlQuery qry(conexao.getDatabase());
        response.write(qry.deleteRecord("logradouro", "cli_id = " + request.getParameter("logr_id")));
    }

    void doPut(CWF::Request &request, CWF::Response &response) const override
    {
        CWF::SqlQuery qry(conexao.getDatabase());
        response.write(qry.updateFromJson(request.bodyToJsonObject(), "logradouro", "logr_id = " + request.getParameter("logr_id")));
    }
};

int main(int argc, char* argv[])
{
    CWF::CppWebApplication server(argc, argv, "/home/andreibr/Workspaces/QTworkspace/cwf_exercicio/server");
    server.addController<CEPController>("/cep");
    server.start();
}
