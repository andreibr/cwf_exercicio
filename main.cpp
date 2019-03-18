
#include <cwf/cppwebapplication.h>
#include <cwf/sqldatabasestorage.h>
#include "controller/cepcontroller.h"

// ajustar conectividade para sua base de dados
CWF::SqlDatabaseStorage conexao("QPSQL", "mydbinstance.cnkc8za0e9tr.us-east-1.rds.amazonaws.com", "cepdb", "root", "12qwaszx", 5432);

int main(int argc, char* argv[])
{
    CWF::CppWebApplication server(argc, argv, "/home/andreibr/Workspaces/QTworkspace/cwf_exercicio/server");
    server.addController<CepController>("/cep");
    server.start();
}
