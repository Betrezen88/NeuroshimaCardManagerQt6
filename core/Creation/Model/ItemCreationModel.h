#ifndef ITEMCREATIONMODEL_H
#define ITEMCREATIONMODEL_H

#include <QAbstractListModel>
#include <QObject>

#include "ItemCreation.h"

class ItemCreationModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ItemCreationModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<ItemCreation*> m_items;
};

#endif // ITEMCREATIONMODEL_H
