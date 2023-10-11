#ifndef SKILLPACKCREATIONGENERAL_H
#define SKILLPACKCREATIONGENERAL_H

#include "SkillpackCreation.h"
#include <QQmlEngine>

class SkillpackCreationGeneral : public SkillpackCreation
{
    Q_OBJECT
    Q_PROPERTY(TypesCreation::Skillpack type READ type CONSTANT)
    QML_ELEMENT

public:
    explicit SkillpackCreationGeneral(QObject *parent = nullptr);
    explicit SkillpackCreationGeneral(SkillpackSource *source, QObject *parent = nullptr);

    TypesCreation::Skillpack type() const;

private:
    TypesCreation::Skillpack m_type;
};

#endif // SKILLPACKCREATIONGENERAL_H
