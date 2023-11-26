#include "TrickSourceModel.h"

TrickSourceModel::TrickSourceModel(QObject *parent)
    : QAbstractListModel{parent}
{

}

int TrickSourceModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_tricks.count();
}

QVariant TrickSourceModel::data(const QModelIndex &index, int role) const
{
    if ( index.row() < 0 || index.row() >= m_tricks.count() )
        return QVariant();

    TrickSourceItem* trick = m_tricks.at(index.row());
    if ( role == TrickRoles::RequirementsRole )
        return QVariant::fromValue(trick->requirements());
    if ( role == TrickRoles::AvailableRole )
        return trick->available();
    if ( role == TrickRoles::SourceRole )
        return QVariant::fromValue(trick->source());

    return QVariant();
}

void TrickSourceModel::addTricks(const QString &name, const QVector<TrickSource *> &tricks)
{
    for ( const auto trick : tricks ) {
        m_tricks.append( new TrickSourceItem(name, trick, this) );
    }
}

QHash<int, QByteArray> TrickSourceModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TrickRoles::SourceRole] = "source";
    roles[TrickRoles::RequirementsRole] = "requirements";
    return roles;
}
