#ifndef LOGRADOURO_H
#define LOGRADOURO_H

#include <QObject>

class Logradouro : public QObject
{
    Q_OBJECT
    int logr_id;
    QString logr_pais;
    QString logr_estado;
    QString logr_cidade;
    QString logr_bairro;
    QString logr_logradouro;
    QString logr_cep;
public:
    explicit Logradouro(QObject *parent = nullptr) : QObject(parent) {}
public slots:
    int getLogr_id() const { return logr_id; }
    void setLogr_id(int value) { logr_id = value; }

    QString getLogr_pais() const { return logr_pais; }
    void setLogr_pais(const QString &value) { logr_pais = value; }

    QString getLogr_estado() const { return logr_estado; }
    void setLogr_estados(const QString &value) { logr_estado = value; }

    QString getLogr_cidade() const { return logr_cidade; }
    void setLogr_cidade(const QString &value) { logr_cidade = value; }

    QString getLogr_bairro() const { return logr_bairro; }
    void setLogr_bairro(const QString &value) { logr_bairro = value; }

    QString getLogr_logradouro() const { return logr_logradouro; }
    void setLogr_logradouro(const QString &value) { logr_logradouro = value; }

    QString getLogr_cep() const { return logr_cep; }
    void setLogr_cep(const QString &value) { logr_cep = value; }
};

#endif // LOGRADOURO_H
