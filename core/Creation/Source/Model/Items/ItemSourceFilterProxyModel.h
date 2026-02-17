#ifndef ITEMSOURCEFILTERPROXYMODEL_H
#define ITEMSOURCEFILTERPROXYMODEL_H

#include <QQmlEngine>
#include <QSortFilterProxyModel>

#include "ItemNameProxyModel.h"
#include "ItemsSortProxyModel.h"

class ItemSourceFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(bool ascendingOrder READ ascendingOrder WRITE setAscendingOrder NOTIFY ascendingOrderChanged FINAL)
    Q_PROPERTY(QString pattern READ pattern WRITE setPattern NOTIFY patternChanged FINAL)
    Q_PROPERTY(ItemsSortProxyModel* model READ model CONSTANT)
    QML_ELEMENT

public:
    explicit ItemSourceFilterProxyModel(QObject *parent = nullptr);

    bool ascendingOrder() const;
    void setAscendingOrder(bool newAscendingOrder);

    QString pattern() const;
    void setPattern(const QString &newPattern);

    ItemsSortProxyModel *model() const;

signals:
    void ascendingOrderChanged();
    void patternChanged();

private:
    bool m_ascendingOrder;
    QString m_pattern;

    ItemNameProxyModel *m_nameFilter{nullptr};
    ItemsSortProxyModel *m_sortModel{nullptr};
};

#endif // ITEMSOURCEFILTERPROXYMODEL_H
