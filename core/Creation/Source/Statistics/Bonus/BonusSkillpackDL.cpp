#include "BonusSkillpackDL.h"

BonusSkillpackDL::BonusSkillpackDL(QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::SkillpackDL}
{

}

BonusSkillpackDL::BonusSkillpackDL(const QStringList &list, QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::SkillpackDL}
    , m_list{list}
{

}

Types::Bonus BonusSkillpackDL::type() const
{
    return m_type;
}

QStringList BonusSkillpackDL::list() const
{
    return m_list;
}

QString BonusSkillpackDL::selected() const
{
    return m_selected;
}

void BonusSkillpackDL::setSelected(const QString &newSelected)
{
    if (m_selected == newSelected)
        return;
    m_selected = newSelected;
    emit selectedChanged();
}
