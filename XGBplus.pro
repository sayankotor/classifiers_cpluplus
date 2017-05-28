#-------------------------------------------------
#
# Project created by QtCreator 2017-05-25T15:13:44
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = XGBplus
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += /home/sayankotor/works/QtProjects/XGBplus/xgboost/include/xgboost/
INCLUDEPATH += /home/sayankotor/works/QtProjects/XGBplus/xgboost/dmlc-core/include/dmlc/
INCLUDEPATH += /home/sayankotor/works/QtProjects/XGBplus/xgboost/dmlc-core/include/
INCLUDEPATH += /home/sayankotor/works/QtProjects/XGBplus/xgboost/rabit/include/

SOURCES += main.cpp \
    XGBClassifierPID.cpp
# \
#    xgboost/src/c_api/c_api.cc

HEADERS += \
    XGBClassifierPID.h

unix:!macx: LIBS += -L$$PWD/xgboost/lib/ -lxgboost

INCLUDEPATH += $$PWD/xgboost/include
DEPENDPATH += $$PWD/xgboost/include
