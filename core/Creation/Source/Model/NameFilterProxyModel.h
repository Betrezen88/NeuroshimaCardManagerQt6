#ifndef NAMEFILTERPROXYMODEL_H
#define NAMEFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class NameFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit NameFilterProxyModel(QObject *parent = nullptr);

    bool filterByName() const;
    void setFilterByName(const bool &newFilterByName);

protected:
    bool filterAcceptsRow(int row, const QModelIndex& parent) const;

private:
    bool m_filterByName{true};
};

#endif // NAMEFILTERPROXYMODEL_H
