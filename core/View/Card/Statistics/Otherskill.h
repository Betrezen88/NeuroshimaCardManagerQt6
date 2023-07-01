#ifndef OTHERSKILL_H
#define OTHERSKILL_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

#include "../../../Data/Statistics/OtherSkillData.h"
#include "Skill.h"

class OtherSkill : public Skill
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString attribute READ attribute CONSTANT)

public:
    explicit OtherSkill(QObject *parent = nullptr);
    explicit OtherSkill(const OtherSkillData &data, QObject *parent = nullptr);

    QString attribute() const;

    Q_INVOKABLE QString attributeShort() const;

    OtherSkillData data() const;

private:
    QString m_attribute;
};

#endif // OTHERSKILL_H
