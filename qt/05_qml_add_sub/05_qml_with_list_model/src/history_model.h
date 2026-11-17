#ifndef HISTORY_MODEL_H
#define HISTORY_MODEL_H

#include <QAbstractListModel>

struct HistoryItem {
    QString timestamp;
    QString expression;
};

class HistoryModel : public QAbstractListModel {
    Q_OBJECT

public:
    HistoryModel(QObject* parent = nullptr);

    enum HistoryRoles {
        TimestampRole = Qt::UserRole + 1,
        ExpressionRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addItem(const QString& expression);

private:
    QVector<HistoryItem> m_items;
};

#endif // HISTORY_MODEL_H
