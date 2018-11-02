QT += core gui widgets

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    base/AgeGroup.cpp \
    base/Country.cpp \
    base/Gender.cpp \
    base/HasId.cpp \
    base/HasName.cpp \
    base/GroupWithJobPreferences.cpp \
    base/Job.cpp \
    base/Race.cpp \
    base/Region.cpp \
    base/Religion.cpp \
    store/AgeGroupStore.cpp \
    gui/MainWindow.cpp \
    store/JobStore.cpp \
    store/GenderStore.cpp \
    store/RaceStore.cpp \
    store/ReligionStore.cpp

HEADERS += \
    QPtr.hpp \
    base/AgeGroup.hpp \
    base/Country.hpp \
    base/Gender.hpp \
    base/HasId.hpp \
    base/HasName.hpp \
    base/GroupWithJobPreferences.hpp \
    base/JobPrefTable.hpp \
    base/Job.hpp \
    base/Race.hpp \
    base/Region.hpp \
    base/Religion.hpp \
    store/AgeGroupStore.hpp \
    gui/MainWindow.hpp \
    store/JobStore.hpp \
    store/GenderStore.hpp \
    store/RaceStore.hpp \
    store/ReligionStore.hpp

DISTFILES += \
    LICENSE.md

FORMS += \
    gui/MainWindow.ui
