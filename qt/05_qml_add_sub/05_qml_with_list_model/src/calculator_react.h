#ifndef CALCULATOR_REACT_H
#define CALCULATOR_REACT_H

#include <QObject>
#include <QPair>

class CalculatorReact : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString result READ result NOTIFY resultChanged)

public:
    explicit CalculatorReact(QObject* parent = nullptr);

    Q_INVOKABLE void add(const QString& val1, const QString& val2);
    Q_INVOKABLE void sub(const QString& val1, const QString& val2);
    Q_INVOKABLE void clearResult();

    QString result() const;

signals:
    // needed for result property
    void resultChanged();
    // sends a line with calculation
    void expressionEvaluated(const QString& expression);

private:
    QString m_result;

    bool parse(const QString& val1, const QString& val2, 
        QPair<double, double>& pair);
};

#endif // CALCULATOR_REACT_H
