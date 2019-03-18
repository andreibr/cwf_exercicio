#ifndef CEPCONTROLLER_H
#define CEPCONTROLLER_H

#include <cwf/controller.h>
#include <cwf/sqlquery.h>
#include <cwf/response.h>
#include <cwf/response.h>

class CepController : public CWF::Controller
{
public:

    void doDelete(CWF::Request &request, CWF::Response &response) const override;
    void doGet(CWF::Request &request, CWF::Response &response) const override;
    void doPut(CWF::Request &request, CWF::Response &response) const override;
    void doPost(CWF::Request &request, CWF::Response &response) const override;

};

#endif // CEPCONTROLLER_H
