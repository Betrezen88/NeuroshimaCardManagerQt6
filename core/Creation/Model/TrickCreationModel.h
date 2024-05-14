#ifndef TRICKCREATIONMODEL_H
#define TRICKCREATIONMODEL_H

#include <QAbstractListModel>
#include <QObject>

#include "../Statistics/TrickCreation.h"

class TrickCreationModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum TrickRoles {
        NameRole = Qt::UserRole+1,
        DescriptionRole,
        ActionRole,
        RequirementsRole
    };

    explicit TrickCreationModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<TrickCreation*> m_tricks;
};

#endif // TRICKCREATIONMODEL_H
