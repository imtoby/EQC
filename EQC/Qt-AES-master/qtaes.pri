QT += core
CONFIG += c++11

HEADERS += \
    $$PWD/aesni/aesni-enc-cbc.h \
    $$PWD/aesni/aesni-enc-ecb.h \
    $$PWD/aesni/aesni-key-exp.h \
    $$PWD/qaesencryption.h
SOURCES += \
    $$PWD/qaesencryption.cpp

INCLUDEPATH += $$PWD

DISTFILES += \
    $$PWD/README.md