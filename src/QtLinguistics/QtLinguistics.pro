NAME         = QtLinguistics
TARGET       = $${NAME}

QT           = core
QT          -= gui
QT          += network
QT          += sql
QT          += script
QT          += Essentials
QT          += Mathematics
QT          += QtFFmpeg
QT          += QtAudio
QT          += AudioIO
QT          += QtNLP
QT          += QtMatcher

load(qt_build_config)
load(qt_module)

INCLUDEPATH += $${PWD}/../../include/$${NAME}

HEADERS     += $${PWD}/../../include/$${NAME}/qtlinguistics.h

include ($${PWD}/Corpus/Corpus.pri)
include ($${PWD}/Pronunciation/Pronunciation.pri)

OTHER_FILES += $${PWD}/../../include/$${NAME}/headers.pri

include ($${PWD}/../../doc/Qt/Qt.pri)

TRNAME       = $${NAME}
include ($${PWD}/../../Translations.pri)

win32 {
LIBS        += -lws2_32
}
