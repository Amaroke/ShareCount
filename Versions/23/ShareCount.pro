QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accueil.cpp \
    cagnotte.cpp \
    compte.cpp \
    comptecommun.cpp \
    connexion.cpp \
    creercompte.cpp \
    depensespartagees.cpp \
    fenetreutilisateur.cpp \
    gestionnairebdd.cpp \
    gestionnairedialogue.cpp \
    inscription.cpp \
    invitation.cpp \
    main.cpp \
    utilisateur.cpp

HEADERS += \
    accueil.hpp \
    cagnotte.hpp \
    compte.hpp \
    comptecommun.hpp \
    connexion.hpp \
    creercompte.hpp \
    depensespartagees.hpp \
    fenetreutilisateur.hpp \
    gestionnairebdd.hpp \
    gestionnairedialogue.hpp \
    inscription.hpp \
    invitation.hpp \
    utilisateur.hpp

FORMS += \
    accueil.ui \
    cagnotte.ui \
    comptecommun.ui \
    connexion.ui \
    creercompte.ui \
    depensespartagees.ui \
    fenetreutilisateur.ui \
    inscription.ui \
    invitation.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
