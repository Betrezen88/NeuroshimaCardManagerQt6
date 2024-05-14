#include "TrickCreationModel.h"

TrickCreationModel::TrickCreationModel(QObject *parent)
    : QAbstractListModel{parent}
{

}

int TrickCreationModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_tricks.count();
}

QVariant TrickCreationModel::data(const QModelIndex &index, int role) const
{
    if ( index.row() < 0 || index.row() >= m_tricks.count() )
        return QVariant();

    TrickCreation* trick = m_tricks.at(index.row());
    if ( role == TrickRoles::NameRole )
        return trick->source()->name();
    if ( role == TrickRoles::DescriptionRole )
        return trick->source()->description();
    if ( role == TrickRoles::ActionRole )
        return trick->source()->action();
    if ( role == TrickRoles::RequirementsRole )
        return QVariant::fromValue(trick->requirements());

    return QVariant();
}

QHash<int, QByteArray> TrickCreationModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TrickRoles::NameRole] = "name";
    roles[TrickRoles::DescriptionRole] = "description";
    roles[TrickRoles::ActionRole] = "action";
    roles[TrickRoles::RequirementsRole] = "requirements";
    return roles;
}
