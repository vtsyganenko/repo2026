#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QObject::connect(&w, &Widget::quit, &a, QApplication::quit);
    w.show();
    return QApplication::exec();
}
