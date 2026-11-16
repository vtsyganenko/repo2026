#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "calculator.h"

// turn off scaling for high dpi monitors
void scale_fix() {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    #if QT_VERSION >= QT_VERSION_CHECK(5, 14, 0)
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(
        Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    #endif
}

int main(int argc, char* argv[]) {
    scale_fix();
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl) {
                QCoreApplication::exit(-1);
            }
        }, Qt::QueuedConnection);

    Calculator calc;
    engine.rootContext()->setContextProperty("calc", &calc);

    engine.load(url);

    return app.exec();
}
