#include <controller/cepcontroller.h>

void CepController::doGet(CWF::Request &request, CWF::Response &response) const
{
    QJsonObject json;
    Logradouro logradouro;

    std::unique_ptr<CWF::QListObject> logradouros(CepDAO().buscar());
    if(logradouros.get())
    {
        request.fillQObject(&logradouro);

        json["logr_bairro"]     =  logradouro.getLogr_bairro();
        json["logr_cep"]        =  logradouro.getLogr_cep();
        json["logr_cidade"]     =  logradouro.getLogr_cidade();
        json["logr_estado"]     =  logradouro.getLogr_estado();
        json["logr_id"]         =  logradouro.getLogr_id();
        json["logr_logradouro"] =  logradouro.getLogr_logradouro();
        json["logr_pais"]       =  logradouro.getLogr_pais();

    }
    response.write(json);
}

void CepController::doDelete(CWF::Request &request, CWF::Response &response) const
{
    QJsonObject json;
    // CWF::Variant resultado(factorial( request.getParameter("numero").toInt()));
    if( CepDAO().deletar(request.getParameter("id").toInt()) )
    {
        json["messages"] = "success";
        json["value"] = true;
    }
    else
    {
        json["messages"] = "unsuccess";
        json["value"] = false;
    }

    response.write(json);
}

void CepController::doPut(CWF::Request &request, CWF::Response &response) const
{
    QJsonObject json;

     Logradouro logradouro;
     request.fillQObject(&logradouro);
     request.addAttribute("logradouro", &logradouro);

    if( CepDAO().atualizar(logradouro))
    {
        json["messages"] = "success";
        json["value"] = true;
    }
    else
    {
        json["messages"] = "unsuccess";
        json["value"] = false;
    }

    response.write(json);
}

void CepController::doPost(CWF::Request &request, CWF::Response &response) const
{
    QJsonObject json;

    Logradouro logradouro;
    request.fillQObject(&logradouro);

    if( CepDAO().inserir(logradouro))
    {
        json["messages"] = "success";
        json["value"] = true;
    }
    else
    {
        json["messages"] = "unsuccess";
        json["value"] = false;
    }

    response.write(json);
}
