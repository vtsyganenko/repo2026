Implementation where C++ types are registrated in the QML.

In this example, we don't put C++ objects to the QML context, but register classes in the QML, so we able to create such objects in the QML code.
Here the register CalculatorReact type:
```
    // Register our C++ class as QML type:
    // Params: module name, module version (1.0), qml tag
    qmlRegisterType<CalculatorReact>("Backend.Calculation", 1, 0, "Calculator");
```
In the QML code, we can create calculator object:
```
    import Backend.Calculation 1.0

    Calculator {
        id: calc
    }
```
Logger class HistoryLogger is registered as singleton, so we don't need to create it in the QML code, it created in the lambda
```
    // Register singleton
    qmlRegisterSingletonType<HistoryLogger>("Backend.Logger", 1, 0, "Logger",
        [](QQmlEngine* engine, QJSEngine* scriptEngine) -> QObject* {
            Q_UNUSED(engine);
            Q_UNUSED(scriptEngine);
            // QML engine will delete it
            return new HistoryLogger("calculation_log.txt");
        });
```
In the QML code, we just use the singleton
```
    import Backend.Logger 1.0

    // caught signal from calc here
    Connections {
        target: calc
        function onExpressionEvaluated(expression) {
            Logger.log(expression)
        }
    }
```
