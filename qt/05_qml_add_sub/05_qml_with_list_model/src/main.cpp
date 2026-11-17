#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "calculator_react.h"
#include "history_logger.h"
#include "history_model.h"

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

    // Register our C++ class as QML type:
    // Params: module name, module version (1.0), qml tag
    qmlRegisterType<CalculatorReact>("Backend.Calculation", 1, 0, "Calculator");

    // Register singleton
    qmlRegisterSingletonType<HistoryLogger>("Backend.Logger", 1, 0, "Logger",
        [](QQmlEngine* engine, QJSEngine* scriptEngine) -> QObject* {
            Q_UNUSED(engine);
            Q_UNUSED(scriptEngine);
            // QML engine will delete it
            return new HistoryLogger("calculation_log.txt");
        });

    qmlRegisterType<HistoryModel>("Backend.History", 1, 0, "History");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl) {
                QCoreApplication::exit(-1);
            }
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
