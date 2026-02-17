#ifndef ITEMNAMEPROXYMODEL_H
#define ITEMNAMEPROXYMODEL_H

#include <QSortFilterProxyModel>

class ItemNameProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit ItemNameProxyModel(QObject *parent = nullptr);

    bool filterByName() const;
    void setFilterByName(const bool &newFilterByName);

protected:
    bool filterAcceptsRow(int row, const QModelIndex& parent) const;

private:
    bool m_filterByName{true};
};

#endif // ITEMNAMEPROXYMODEL_H
