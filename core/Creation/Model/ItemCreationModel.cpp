#include "ItemCreationModel.h"

ItemCreationModel::ItemCreationModel(QObject *parent) {}

int ItemCreationModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_items.count();
}

QVariant ItemCreationModel::data(const QModelIndex &index, int role) const
{
    return QVariant();
}

QHash<int, QByteArray> ItemCreationModel::roleNames() const
{
    QHash<int, QByteArray> roles;;

    return roles;
}
