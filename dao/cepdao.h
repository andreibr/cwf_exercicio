#ifndef CEPDAO_H
#define CEPDAO_H

#include "model/logradouro.h"
#include <cwf/qlistobject.h>


class CepDAO
{
public:
    CepDAO();
    bool inserir(const Logradouro &logradouro);
    bool atualizar(const Logradouro &logradouro);
    bool deletar(int id);
    bool salvar(const Logradouro &logradouro);
    CWF::QListObject* buscar();
    Logradouro* buscarPorId(int id);
};

#endif // CEPDAO_H
