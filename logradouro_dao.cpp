#include "logradouro_dao.h"
#include <cwf/sqlquery.h>
#include <cwf/sqldatabasestorage.h>

extern CWF::SqlDatabaseStorage storage;

QJsonArray LogradouroDAO::inserir(const Logradouro &logradouro)
{
    CWF::SqlQuery qry(storage);
    qry.prepare("insert into logradouro(logr_pais, logr_estado, logr_cidade, logr_bairro, logr_logradouro, logr_cep)"
                "values(:pais, :estado, :cidade, :bairro, :logradouro, :cep);");
    qry.bindValue(":pais", logradouro.getLogr_pais());
    qry.bindValue(":estado", logradouro.getLogr_estado());
    qry.bindValue(":cidade", logradouro.getLogr_cidade());
    qry.bindValue(":bairro", logradouro.getLogr_bairro());
    qry.bindValue(":logradouro", logradouro.getLogr_logradouro());
    qry.bindValue(":cep", logradouro.getLogr_cep());
    qry.exec();
    return qry.toJson();
}

bool LogradouroDAO::atualizar(const Logradouro &logradouro)
{

}

bool LogradouroDAO::deletar(int logr_id)
{

}

bool LogradouroDAO::salvar(const Logradouro &logradouro)
{

}

QJsonArray LogradouroDAO::buscar()
{
    CWF::SqlQuery qry(storage);
    qry.exec("select * from logradouro");
    return qry.toJson();
}

Logradouro* LogradouroDAO::buscarPorId(int logr_id)
{

}
