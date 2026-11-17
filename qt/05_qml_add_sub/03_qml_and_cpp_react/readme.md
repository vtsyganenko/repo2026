Implementation where qml uses c++ methods and receives c++ signals.

Class CalculatorReact is registered in the QML context. It has Q_INVOKABLE methods available from the QML side. See example 02.

Also, class CalculatorReact has property:
```
Q_PROPERTY(QString result READ result NOTIFY resultChanged)
```
with getter and notification signal:
```
public:
    <...>
    QString result() const;

signals:
    void resultChanged();
```
So UI element field could be connected with the notification signal:
```
    TextField {
        id: resultField
        Layout.fillWidth: true
        readOnly: true
        selectByMouse: true
        text: calc.result
    }
```
