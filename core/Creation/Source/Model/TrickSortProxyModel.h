#ifndef TRICKSORTPROXYMODEL_H
#define TRICKSORTPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QQmlEngine>

class TrickSortProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit TrickSortProxyModel(QObject *parent = nullptr);
    explicit TrickSortProxyModel(QAbstractItemModel *sourceModel, QObject *parent = nullptr);

protected:
    bool lessThan(const QModelIndex& left, const QModelIndex& right) const override;
};

#endif // TRICKSORTPROXYMODEL_H
