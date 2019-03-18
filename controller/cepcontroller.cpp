#include <controller/cepcontroller.h>

extern CWF::SqlDatabaseStorage conexao;

void CepController::doGet(CWF::Request &request, CWF::Response &response) const
{
    CWF::SqlQuery qry(conexao.getDatabase());
    qry.exec("select * from logradouro");
    response.write(qry.toJson());
}

void CepController::doDelete(CWF::Request &request, CWF::Response &response) const
{
    response.write(CWF::SqlQuery(conexao.getDatabase()).deleteRecord("logradouro", "logr_cep = " + request.getParameter("logr_cep")));
}

void CepController::doPut(CWF::Request &request, CWF::Response &response) const
{
    response.write(CWF::SqlQuery(conexao.getDatabase()).updateFromJson(request.bodyToJsonObject(), "logradouro", "logr_cep = " + request.getParameter("logr_cep")));
}

void CepController::doPost(CWF::Request &request, CWF::Response &response) const
{
    response.write(CWF::SqlQuery(conexao.getDatabase()).insertFromJson(request.bodyToJsonObject(), "logradouro"));
}
