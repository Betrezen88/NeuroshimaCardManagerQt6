#ifndef SKILLCREATIONSINGLE_H
#define SKILLCREATIONSINGLE_H

#include "SkillCreation.h"
#include <QQmlEngine>

class SkillCreationSingle : public SkillCreation
{
    Q_OBJECT
    Q_PROPERTY(TypesCreation::Skill type READ type CONSTANT)
    QML_ELEMENT

public:
    explicit SkillCreationSingle(QObject *parent = nullptr);
    explicit SkillCreationSingle(SkillSource *source, QObject *parent = nullptr);

    TypesCreation::Skill type() const;

private:
    TypesCreation::Skill m_type;
};

#endif // SKILLCREATIONSINGLE_H
