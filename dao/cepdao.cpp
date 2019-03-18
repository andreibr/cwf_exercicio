#include "cepdao.h"
#include <cwf/sqlquery.h>

extern CWF::SqlDatabaseStorage conexao;

CepDAO::CepDAO(){}

bool CepDAO::inserir(const Logradouro &logradouro)
{
    CWF::SqlQuery qry(conexao);
    qry.prepare("insert into logradouro(logr_estado, logr_cidade, logr_bairro, logr_logradouro, logr_cep) "
                "values(:logr_estado, :logr_cidade, :logr_bairro, :logr_logradouro, :logr_cep);");
    qry.bindValue(":logr_estado", logradouro.getLogr_estado() );
    qry.bindValue(":logr_cidade", logradouro.getLogr_cidade() );
    qry.bindValue(":logr_bairro", logradouro.getLogr_bairro() );
    qry.bindValue(":logr_logradouro", logradouro.getLogr_logradouro() );
    qry.bindValue(":logr_cep", logradouro.getLogr_cep() );

    return qry.exec()["success"].toBool();
}

bool CepDAO::atualizar(const Logradouro &logradouro)
{
    CWF::SqlQuery qry(conexao);
    qry.prepare("update logradouro set "
                "logr_estado = :logr_estado, "
                "logr_cidade = :logr_cidade,"
                "logr_bairro = :logr_bairro,"
                "logr_logradouro = :logr_logradouro,"
                "logr_cep = :logr_cep"
                "where logr_id = :id;");
    qry.bindValue(":id", logradouro.getLogr_id() );
    qry.bindValue(":logr_estado", logradouro.getLogr_estado() );
    qry.bindValue(":logr_cidade", logradouro.getLogr_cidade() );
    qry.bindValue(":logr_bairro", logradouro.getLogr_bairro() );
    qry.bindValue(":logr_logradouro", logradouro.getLogr_logradouro() );
    qry.bindValue(":logr_cep", logradouro.getLogr_cep() );

    return qry.exec()["success"].toBool();
}

bool CepDAO::deletar(int id)
{
    CWF::SqlQuery qry(conexao);
    qry.prepare("delete from logradouro where logr_id = :id;");
    qry.bindValue(":id", id);
    return qry.exec()["success"].toBool();
}

bool CepDAO::salvar(const Logradouro &logradouro)
{
    return logradouro.getLogr_id() == 0 ? inserir(logradouro) : atualizar(logradouro);
}

CWF::QListObject* CepDAO::buscar()
{
    CWF::SqlQuery qry(conexao);
    if(qry.exec("select * from logradouro")["success"].toBool())
    {
        CWF::QListObject *logradouros = new CWF::QListObject;
        qry.first();
        while(qry.isValid())
        {
            Logradouro *logradouro = new Logradouro;
            logradouro->setLogr_id(qry.record().value("logr_id").toInt());
            logradouro->setLogr_estado(qry.record().value("logr_estado").toString());
            logradouro->setLogr_cidade(qry.record().value("logr_cidade").toString());
            logradouro->setLogr_bairro(qry.record().value("logr_bairro").toString());
            logradouro->setLogr_logradouro(qry.record().value("logr_logradouro").toString());
            logradouro->setLogr_cep(qry.record().value("logr_cep").toString());
            logradouro->setLogr_pais(qry.record().value("logr_pais").toString());
            logradouros->add(logradouro);
            qry.next();
        }
        return logradouros;
    }
    return nullptr;
}

Logradouro* CepDAO::buscarPorId(int id)
{
    Logradouro *logradouro = new Logradouro;
    if(id > 0)
    {
        CWF::SqlQuery qry(conexao);
        qry.prepare("select * from logradouro where logr_id = :id");
        qry.bindValue(":id", id);
        if(qry.exec()["success"].toBool())
        {
            qry.first();
            logradouro->setLogr_id(id);
            logradouro->setLogr_estado(qry.record().value("logr_estado").toString());
            logradouro->setLogr_cidade(qry.record().value("logr_cidade").toString());
            logradouro->setLogr_bairro(qry.record().value("logr_bairro").toString());
            logradouro->setLogr_logradouro(qry.record().value("logr_logradouro").toString());
            logradouro->setLogr_cep(qry.record().value("logr_cep").toString());
        }
    }
    return logradouro;
}
