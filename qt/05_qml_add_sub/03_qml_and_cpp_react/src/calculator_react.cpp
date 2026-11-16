#include "calculator_react.h"

CalculatorReact::CalculatorReact(QObject* parent) : QObject(parent) {
}

void CalculatorReact::add(const QString& val1, const QString& val2) {
    QPair<double, double> pair;
    if (parse(val1, val2, pair)) {
        m_result = QString::number(pair.first + pair.second);
        emit resultChanged();
    }
}

void CalculatorReact::sub(const QString& val1, const QString& val2) {
    QPair<double, double> pair;
    if (parse(val1, val2, pair)) {
        m_result = QString::number(pair.first - pair.second);
        emit resultChanged();
    }
}

void CalculatorReact::clearResult() {
    m_result = "";
    emit resultChanged();
}

QString CalculatorReact::result() const {
    return m_result;
}

bool CalculatorReact::parse(const QString& val1, const QString& val2,
        QPair<double, double>& pair) {
    bool status1 {false};
    bool status2 {false};
    double d1 = QString(val1).replace(',', '.').toDouble(&status1);
    double d2 = QString(val2).replace(',', '.').toDouble(&status2);
    if (!status1 || !status2) {
        m_result = "Error: NaN!";
        emit resultChanged();
        return false;
    }
    pair.first = d1;
    pair.second = d2;
    return true;
}