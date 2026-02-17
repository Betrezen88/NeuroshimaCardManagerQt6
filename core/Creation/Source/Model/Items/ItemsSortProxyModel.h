#ifndef ITEMSSORTPROXYMODEL_H
#define ITEMSSORTPROXYMODEL_H

#include <QObject>
#include <QQmlEngine>
#include <QSortFilterProxyModel>

class ItemsSortProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit ItemsSortProxyModel(QObject *parent = nullptr);
    ItemsSortProxyModel(QAbstractItemModel *sourceModel, QObject *parent = nullptr);

protected:
    bool lessThan(const QModelIndex& left, const QModelIndex& right) const override;
};

#endif // ITEMSSORTPROXYMODEL_H
