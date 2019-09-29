QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Cocinero.cpp \
    CocineroThread.cpp \
    Comensal.cpp \
    MainWindow.cpp \
    caja.cpp \
    cajathread.cpp \
    cocina.cpp \
    cocinathread.cpp \
    cola.cpp \
    #componente.cpp \
    colacomensales.cpp \
    dialog.cpp \
    entradadatosiniciales.cpp \
    generadorpersonasthread.cpp \
    lavaplatos.cpp \
    lavaplatosthread.cpp \
    listacomensales.cpp \
    listaingredientes.cpp \
    listamesas.cpp \
    listameseros.cpp \
    listaplatos.cpp \
    listasolicitudes.cpp \
    main.cpp \
   # mediador.cpp \
    manejadorcomensales.cpp \
    mesa.cpp \
    mesero.cpp \
    meserothread.cpp \
    pila.cpp \
    restaurante.cpp \
    solicitud.cpp\


HEADERS += \
    Cocinero.h \
    CocineroThread.h \
    Comensal.h \
    #Componente.h \
    Ingrediente.h \
    MainWindow.h \
    #Mediador.h \
    Mesero.h \
    Solicitud.h \
    caja.h \
    cajathread.h \
    cocina.h \
    cocinathread.h \
    cola.h \
    colacomensales.h \
    dialog.h \
    generadorpersonasthread.h \
    lavaplatos.h \
    lavaplatosthread.h \
    listacomensales.h \
    listaingredientes.h \
    listamesas.h \
    listameseros.h \
    listaplatos.h \
    listasolicitudes.h \
    manejadorcomensales.h \
    mesa.h\ \
    meserothread.h \
    pila.h \
    plato.h \
    restaurante.h

FORMS += \
    dialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    MyResources.qrc
