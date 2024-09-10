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
        AvailableRole,
        Bougth
    };

    explicit TrickSourceModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    void addTricks(const QString& name, const QVector<TrickSource*>& tricks);

    QVector<TrickSourceItem*> tricks() const;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QVector<TrickSourceItem*> m_tricks;
};

#endif // TRICKSOURCEMODEL_H
