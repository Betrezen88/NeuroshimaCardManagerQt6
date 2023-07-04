#ifndef STATISTICS_H
#define STATISTICS_H

#include <QQmlListProperty>
#include <QtQml/qqmlregistration.h>

#include "Page.h"

#include "../Statistics/Attribute.h"
#include "../Statistics/Disease.h"
#include "../Statistics/Experience.h"
#include "../Statistics/Origin.h"
#include "../Statistics/Otherskill.h"
#include "../Statistics/Profession.h"
#include "../Statistics/Reputation.h"
#include "../Statistics/Specialization.h"
#include "../Statistics/Trick.h"
#include "../Statistics/Wound.h"

#include "../../../Data/Pages/StatisticsData.h"

class Statistics : public Page
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString fullname READ fullname CONSTANT)
    Q_PROPERTY(QQmlListProperty<Attribute> attributes READ attributes CONSTANT)
    Q_PROPERTY(Disease* disease READ disease CONSTANT)
    Q_PROPERTY(Experience* experience READ experience CONSTANT)
    Q_PROPERTY(Origin* origin READ origin CONSTANT)
    Q_PROPERTY(QQmlListProperty<OtherSkill> otherSkills READ otherSkills CONSTANT)
    Q_PROPERTY(Profession* profession READ profession CONSTANT)
    Q_PROPERTY(Specialization* specialization READ specialization CONSTANT)
    Q_PROPERTY(QQmlListProperty<Trick> tricks READ tricks CONSTANT)
    Q_PROPERTY(Reputation* reputation READ reputation CONSTANT)
    Q_PROPERTY(QQmlListProperty<Wound> wounds READ wounds NOTIFY woundsChanged)
    Q_PROPERTY(QStringList locations READ locations CONSTANT)

public:
    explicit Statistics(QObject *parent = nullptr);
    explicit Statistics(const StatisticsData &data, QObject *parent = nullptr);

    QString fullname() const;

    Types::Page type() const;
    Disease *disease() const;
    Experience *experience() const;
    Origin *origin() const;
    Profession *profession() const;
    Specialization *specialization() const;

    QQmlListProperty<Attribute> attributes();
    qsizetype attributesCount() const;
    Attribute* attribute(qsizetype index);
    Q_INVOKABLE Attribute* attribute(const QString& name);

    QQmlListProperty<OtherSkill> otherSkills();
    qsizetype otherSkillsCount() const;
    OtherSkill* otherSkill(qsizetype index);

    Reputation *reputation() const;

    QQmlListProperty<Trick> tricks();
    qsizetype tricksCount() const;
    Trick* trick(qsizetype index);

    QQmlListProperty<Wound> wounds();
    void addWound(Wound* wound);
    qsizetype woundsCount() const;
    Wound* wound(qsizetype index);
    void clearWounds();

    Q_INVOKABLE QString woundsForLocation(const QString& location);

    QStringList locations() const;

    StatisticsData data();

signals:
    void woundsChanged();

private:
    static qsizetype attributesCount(QQmlListProperty<Attribute> *list);
    static Attribute* attribute(QQmlListProperty<Attribute> *list, qsizetype index);
    static qsizetype otherSkillsCount(QQmlListProperty<OtherSkill> *list);
    static OtherSkill* otherSkill(QQmlListProperty<OtherSkill> *list, qsizetype index);
    static qsizetype tricksCount(QQmlListProperty<Trick> *list);
    static Trick* trick(QQmlListProperty<Trick> *list, qsizetype index);
    static void addWound(QQmlListProperty<Wound> *list, Wound* wound);
    static qsizetype woundsCount(QQmlListProperty<Wound> *list);
    static Wound* wound(QQmlListProperty<Wound> *list, qsizetype index);
    static void clearWounds(QQmlListProperty<Wound> *list);

private:
    Types::Page m_type;
    QString m_name;
    QString m_surname;
    QString m_nickanem;
    Disease* m_disease{nullptr};
    Experience* m_experience{nullptr};
    Origin* m_origin{nullptr};
    Profession* m_profession{nullptr};
    Specialization* m_specialization{nullptr};
    QVector<Attribute*> m_attributes;
    QVector<OtherSkill*> m_otherSkills;
    QVector<Trick*> m_tricks;
    Reputation* m_reputation{nullptr};
    QVector<Wound*> m_wounds;

    const QStringList m_locations{ "Głowa", "Lewa ręka", "Prawa ręka", "Tors", "Lewa noga", "Prawa noga" };
};

#endif // STATISTICS_H
