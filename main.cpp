#include <cwf/sqlquery.h>
#include <cwf/cppwebapplication.h>
#include <cwf/sqldatabasestorage.h>

#include "logradouro.h"
#include "logradouro_dao.h"

// ajustar base de dados
CWF::SqlDatabaseStorage storage("QPSQL", "cepdb.cvjysrwbh0op.us-east-1.rds.amazonaws.com", "cepdb", "root", "12qwaszx", 5432);

class CEPController : public CWF::Controller
{

public:
    void doGet(CWF::Request &request, CWF::Response &response) const override
    {
       response.write( LogradouroDAO().buscar() );
    }

    void doPost(CWF::Request &request, CWF::Response &response) const override
    {
        Logradouro logradouro;
        request.fillQObject(&logradouro);
        response.write( LogradouroDAO().inserir(logradouro) );
    }
};

int main(int argc, char* argv[])
{
    CWF::CppWebApplication server(argc, argv, "/home/andreibr/Workspaces/QTworkspace/cwf_exercicio/server");
    server.addController<CEPController>("/cep");
    server.start();
}
