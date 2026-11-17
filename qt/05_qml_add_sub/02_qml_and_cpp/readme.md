Implementation where qml uses c++ methods.
Class Calculator is registered in the QML context:
```
    QQmlApplicationEngine engine;
    <...>
    Calculator calc;
    engine.rootContext()->setContextProperty("calc", &calc);
```
Class Calculator has methods marked as Q_INVOKABLE:
```
Q_INVOKABLE double add(double val1, double val2);
```
These methods could be called from the qml side:
```
    function add() {
        let values = parse()
        if(values) {
            let res = calc.add(values[0], values[1])
            resultField.text = res.toString()
        }
    }
``
