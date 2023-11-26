#ifndef TRICKSOURCEMODEL_H
#define TRICKSOURCEMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QQmlEngine>

#include "TrickSourceItem.h"

class TrickSourceModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT

public:
    enum TrickRoles {
        SourceRole = Qt::UserRole+1,
        RequirementsRole,
        AvailableRole
    };

    explicit TrickSourceModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

    void addTricks(const QString& name, const QVector<TrickSource*>& tricks);

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QVector<TrickSourceItem*> m_tricks;
};

#endif // TRICKSOURCEMODEL_H
