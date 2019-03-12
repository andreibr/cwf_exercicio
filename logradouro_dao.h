#ifndef LOGRADOURO_DAO_H
#define LOGRADOURO_DAO_H

#include <cwf/qlistobject.h>
#include "logradouro.h"

class LogradouroDAO
{
public:
    QJsonArray inserir(const Logradouro &logradouro);
    bool atualizar(const Logradouro &logradouro);
    bool deletar(int logr_id);
    bool salvar(const Logradouro &logradouro);
    QJsonArray buscar();
    Logradouro* buscarPorId(int logr_id);
};

#endif // LOGRADOURO_DAO_H
