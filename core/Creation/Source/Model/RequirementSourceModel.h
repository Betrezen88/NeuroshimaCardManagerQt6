#ifndef REQUIREMENTSOURCEMODEL_H
#define REQUIREMENTSOURCEMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QQmlEngine>

#include "../Common/RequirementSource.h"

class RequirementSourceModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT

public:
    enum RequirementRoles {
        NameRole = Qt::UserRole+1,
        TypeRole,
        ValueRole,
        OptionalRole
    };

    explicit RequirementSourceModel(QObject *parent = nullptr);
    explicit RequirementSourceModel(const QVector<RequirementSource*>& requirements, QObject *parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QVector<RequirementSource*> m_requirments;
};

#endif // REQUIREMENTSOURCEMODEL_H
