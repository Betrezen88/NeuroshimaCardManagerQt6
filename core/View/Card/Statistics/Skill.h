#ifndef SKILL_H
#define SKILL_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

#include "../../../Data/Statistics/SkillData.h"

class Skill : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(bool used READ used WRITE setUsed NOTIFY usedChanged)

public:
    explicit Skill(QObject *parent = nullptr);
    explicit Skill(const SkillData &data, QObject *parent = nullptr);

    QString name() const;
    int value() const;
    bool used() const;

    void setUsed(bool newUsed);

    SkillData data() const;

signals:
    void usedChanged();

protected:
    QString m_name;
    int m_value{0};
    bool m_used{false};
};

#endif // SKILL_H
