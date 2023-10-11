#ifndef SKILLPACKCREATIONCHOOSABLE_H
#define SKILLPACKCREATIONCHOOSABLE_H

#include "SkillpackCreation.h"
#include <QQmlEngine>

class SkillCreationList;

class SkillpackCreationChoosable : public SkillpackCreation
{
    Q_OBJECT
    Q_PROPERTY(TypesCreation::Skillpack type READ type CONSTANT)
    QML_ELEMENT

public:
    explicit SkillpackCreationChoosable(QObject *parent = nullptr);
    explicit SkillpackCreationChoosable(SkillpackSource *source, QObject *parent = nullptr);

    TypesCreation::Skillpack type() const;

private slots:
    void onSkillChanged(const SkillCreationList* skill);

private:
    TypesCreation::Skillpack m_type;
};

#endif // SKILLPACKCREATIONCHOOSABLE_H
