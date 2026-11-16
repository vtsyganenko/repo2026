#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

class Calculator : public QObject {
    Q_OBJECT
public:
    explicit Calculator(QObject* parent = nullptr);

    Q_INVOKABLE double add(double val1, double val2);
    Q_INVOKABLE double sub(double val1, double val2);
};

#endif // CALCULATOR_H
