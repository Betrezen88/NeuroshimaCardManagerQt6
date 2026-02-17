#ifndef ITEMSOURCEMODEL_H
#define ITEMSOURCEMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QQmlEngine>

#include "ShopItemSource.h"

class ItemSourceModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT

public:
    enum ShopItemRoles {
        SourceRole = Qt::UserRole+1,
        QuantityRole
    };

    explicit ItemSourceModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    void addItem(const QString& name, const QVector<ItemSource*>& items);

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QVector<ShopItemSource*> m_items;
};

#endif // ITEMSOURCEMODEL_H
