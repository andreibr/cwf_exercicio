QT -= gui
QT += network xml sql

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        logradouro_dao.cpp \
        main.cpp

INCLUDEPATH += /usr/lib
debug {
    LIBS += -L/usr/lib -lCPPWebFrameworkd
}
release {
    LIBS += -L/usr/lib -lCPPWebFramework
}

DISTFILES += \
    server/config/ssl/cert.pem \
    server/config/ssl/key.pem \
    server/config/cppwebserverpages/resources/images/logo.png \
    server/config/cppwebserverpages/resources/images/favicon.ico \
    server/config/cppwebserverpages/resources/css/cppweb.css \
    server/config/cppwebserverpages/403.view \
    server/config/cppwebserverpages/404.view \
    server/config/cppwebserverpages/index.view \
    server/config/CPPWeb.ini \
    server/config/log/CPPWebServer.log \
    server/pages/cep.html \
    server/pages/fatorialresult.view

HEADERS += \
    logradouro.h \
    logradouro_dao.h

