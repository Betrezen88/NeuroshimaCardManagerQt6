#ifndef ATTRIBUTECREATION_H
#define ATTRIBUTECREATION_H

#include <QObject>
#include <QQmlListProperty>
#include "qqmlintegration.h"

#include <AttributeSource.h>

#include "SkillpackCreation.h"

class AttributeCreation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(AttributeSource* source READ source CONSTANT)
    Q_PROPERTY(QQmlListProperty<SkillpackCreation> skillpacks READ skillpacks CONSTANT)
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged FINAL)
    Q_PROPERTY(int bonus READ bonus WRITE setBonus NOTIFY bonusChanged FINAL)
    QML_ELEMENT

public:
    explicit AttributeCreation(QObject *parent = nullptr);
    explicit AttributeCreation(AttributeSource* source, QObject* parent = nullptr);

    AttributeSource *source() const;

    QQmlListProperty<SkillpackCreation> skillpacks();
    qsizetype skillpacksCount() const;
    SkillpackCreation* skillpack(qsizetype index);

    int value() const;
    void setValue(int newValue);

    int bonus() const;
    void setBonus(int newBonus);

signals:
    void valueChanged();
    void bonusChanged();

private:
    static qsizetype skillpacksCount(QQmlListProperty<SkillpackCreation>* list);
    static SkillpackCreation* skillpack(QQmlListProperty<SkillpackCreation>* list, qsizetype index);

private:
    AttributeSource *m_source = nullptr;
    QVector<SkillpackCreation*> m_skillpacks;
    int m_value{0};
    int m_bonus{0};
};

#endif // ATTRIBUTECREATION_H
