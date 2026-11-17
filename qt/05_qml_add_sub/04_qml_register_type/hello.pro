QT += quick

CONFIG += c++17 console

HEADERS += ./src/calculator_react.h \
        ./src/history_logger.h

SOURCES += ./src/main.cpp \
        ./src/calculator_react.cpp \
        ./src/history_logger.cpp

RESOURCES += ./ui/qml.qrc
