#ifndef TRICKSOURCESORTFILTERPROXYMODEL_H
#define TRICKSOURCESORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QObject>
#include <QQmlEngine>

#include "NameFilterProxyModel.h"
#include "RequirementFilterProxyModel.h"
#include "AvailableFilterProxyModel.h"
#include "TrickSortProxyModel.h"

class TrickSourceSortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(bool ascendingOrder READ ascendingOrder WRITE setAscendingOrder NOTIFY ascendingOrderChanged FINAL)
    Q_PROPERTY(QString pattern READ pattern WRITE setPattern NOTIFY patternChanged FINAL)
    Q_PROPERTY(QString sortBy READ sortBy WRITE setSortBy NOTIFY sortByChanged FINAL)
    Q_PROPERTY(bool availableOnly READ availableOnly WRITE setAvailableOnly NOTIFY availableOnlyChanged FINAL)
    Q_PROPERTY(QStringList sortByModel READ sortByModel CONSTANT)
    Q_PROPERTY(TrickSortProxyModel* model READ model CONSTANT)
    QML_ELEMENT

public:
    TrickSourceSortFilterProxyModel(QObject *parent = nullptr);

    bool ascendingOrder() const;
    void setAscendingOrder(bool newAscendingOrder);
    QString pattern() const;
    void setPattern(const QString &newPattern);

    QString sortBy() const;
    void setSortBy(const QString &newSortBy);

    QStringList sortByModel() const;

    TrickSortProxyModel *model() const;

    bool availableOnly() const;
    void setAvailableOnly(bool newAvailableOnly);

signals:
    void ascendingOrderChanged();
    void patternChanged();
    void sortByChanged();
    void availableOnlyChanged();

private:
    const QStringList m_sortByModel{"Nazwa", "Wymagania"};

    NameFilterProxyModel *m_nameFilter{nullptr};
    RequirementFilterProxyModel *m_requirementFilter{nullptr};
    AvailableFilterProxyModel *m_availableFilter{nullptr};
    TrickSortProxyModel *m_sortModel{nullptr};
    bool m_ascendingOrder{true};
    QString m_pattern;
    QString m_sortBy;
    bool m_availableOnly{false};
};

#endif // TRICKSOURCESORTFILTERPROXYMODEL_H
