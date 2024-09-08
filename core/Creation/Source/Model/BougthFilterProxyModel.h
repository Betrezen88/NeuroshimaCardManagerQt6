#ifndef BOUGTHFILTERPROXYMODEL_H
#define BOUGTHFILTERPROXYMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

class BougthFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit BougthFilterProxyModel(QObject *parent = nullptr);
    BougthFilterProxyModel(QAbstractItemModel *sourceModel, QObject *parent = nullptr);

protected:
    bool filterAcceptsRow(int row, const QModelIndex& parent) const;
};

#endif // BOUGTHFILTERPROXYMODEL_H
