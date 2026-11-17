#ifndef HISTORY_LOGGER_H
#define HISTORY_LOGGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>

class HistoryLogger : public QObject {
    Q_OBJECT

public:
    HistoryLogger(const QString& fileName, QObject* parent = nullptr);
    ~HistoryLogger() override;

    Q_INVOKABLE void log(const QString& expression);

private:
    QFile m_file;
    QTextStream m_out;
};

#endif // HISTORY_LOGGER_H
