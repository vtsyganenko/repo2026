#include "history_model.h"

#include <QDateTime>

HistoryModel::HistoryModel(QObject* parent): QAbstractListModel(parent) {

}

int HistoryModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_items.count();
}

QVariant HistoryModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() < 0 || index.row() >= m_items.count())
        return QVariant();

    const HistoryItem& item = m_items.at(index.row());
    if (role == HistoryRoles::TimestampRole) {
        return item.timestamp;
    } else if (role == HistoryRoles::ExpressionRole) {
        return item.expression;
    }

    return QVariant();
}

QHash<int, QByteArray> HistoryModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[HistoryRoles::TimestampRole] = "timestamp";
    roles[HistoryRoles::ExpressionRole] = "expression";
    return roles;
}

void HistoryModel::addItem(const QString& expression) {
    beginInsertRows(QModelIndex(), m_items.count(), m_items.count());
    QString timestamp = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss.zzz");
    m_items.append({timestamp, expression});
    endInsertRows();
}