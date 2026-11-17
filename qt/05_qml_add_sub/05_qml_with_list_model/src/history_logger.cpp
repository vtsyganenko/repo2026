#include "history_logger.h"

#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>

HistoryLogger::HistoryLogger(const QString& fileName, QObject* parent)
: QObject(parent) {
    QString binaryDir = QCoreApplication::applicationDirPath();
    QString path = binaryDir + "/" + fileName;
    m_file.setFileName(path);

    if (m_file.open(QIODevice::Append | QIODevice::Text)) {
        m_out.setDevice(&m_file);
        m_out.setCodec("UTF-8");
    } else {
        qWarning() << "file " << path << " error: " << m_file.errorString();
    }
}

HistoryLogger::~HistoryLogger() {
    if (m_file.isOpen()) {
        m_out.flush();
        m_file.close();
    }
}

void HistoryLogger::log(const QString& expression) {
    if (m_file.isOpen()) {
        QString timestamp = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss.zzz");
        m_out << "[" << timestamp << "] " << expression << "\n";
        m_out.flush();
    }
}
