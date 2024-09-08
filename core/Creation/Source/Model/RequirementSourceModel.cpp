#include "RequirementSourceModel.h"

RequirementSourceModel::RequirementSourceModel(QObject *parent)
    : QAbstractListModel{parent}
{

}

RequirementSourceModel::RequirementSourceModel(const QVector<RequirementSource *> &requirements, QObject *parent)
    : QAbstractListModel{parent}
    , m_requirments{requirements}
{

}

int RequirementSourceModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_requirments.count();
}

QVariant RequirementSourceModel::data(const QModelIndex &index, int role) const
{
    if ( index.row() < 0 || index.row() >= m_requirments.count() )
        return QVariant();

    if ( role == RequirementRoles::NameRole )
        return m_requirments.at(index.row())->name();
    if ( role == RequirementRoles::TypeRole )
        return static_cast<int>(m_requirments.at(index.row())->type());
    if ( role == RequirementRoles::ValueRole )
        return m_requirments.at(index.row())->value();
    if ( role == RequirementRoles::OptionalRole )
        return m_requirments.at(index.row())->optional();

    return QVariant();
}

QHash<int, QByteArray> RequirementSourceModel::roleNames() const
{
    return QHash<int, QByteArray>{
        {RequirementRoles::NameRole, "name"},
        {RequirementRoles::TypeRole, "type"},
        {RequirementRoles::ValueRole, "value"},
        {RequirementRoles::OptionalRole, "optional"}
    };
}
