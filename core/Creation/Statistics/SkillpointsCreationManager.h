#ifndef SKILLPOINTSCREATIONMANAGER_H
#define SKILLPOINTSCREATIONMANAGER_H

#include <QObject>
#include <QQmlEngine>

#include <../../Source/Statistics/SpecializationSource.h>

struct Skillpoints {
    int current;
    int max;
};

class SkillpointsCreationManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString specialization READ specialization WRITE setSpecialization NOTIFY specializationChanged FINAL)
    Q_PROPERTY(int generalSkillpoints READ generalSkillpoints NOTIFY generalSkillpointsChanged FINAL)
    Q_PROPERTY(int specializationSkillpoints READ specializationSkillpoints NOTIFY specializationSkillpointsChanged FINAL)
    Q_PROPERTY(int specializationSkillpointsMax READ specializationSkillpointsMax WRITE setSpecializationSkillpointsMax NOTIFY specializationSkillpointsMaxChanged FINAL)
    QML_ELEMENT

public:
    explicit SkillpointsCreationManager(QObject *parent = nullptr);

    QString specialization() const;
    void setSpecialization(const QString &newSpecialization);

    int generalSkillpoints() const;
    int specializationSkillpoints() const;

    int specializationSkillpointsMax() const;
    void setSpecializationSkillpointsMax(int newSpecializationSkillpointsMax);

    Q_INVOKABLE bool canSkillpackBeBought(const QString& specialization);
    Q_INVOKABLE bool canSkillBeIncreased(const QString& specialization, const int value);

signals:
    void specializationChanged();
    void generalSkillpointsChanged();
    void specializationSkillpointsChanged();
    void specializationSkillpointsMaxChanged();

public slots:
    void onSkillpackBought(const QStringList& specializations);
    void onSkillpackSold(const QStringList& specializations);
    void onSkillBought(const QStringList &specializations, const int value);
    void onSkillSold(const QStringList &specializations, const int value);

private:
    int availablePoints(const QString& specialization);
    int buySkillCost(const int level);
    int sellSkillCost(const int level);

    void setGeneralSkillpoints(const int newGeneralSkillpoints);
    void setSpecializationSkillpoints(const int newSpecializationSkillpoints);

private:
    QString m_specialization;
    Skillpoints m_general{35, 35};
    Skillpoints m_specializations{30, 30};
    const int m_skillpackCost{5};
};

#endif // SKILLPOINTSCREATIONMANAGER_H
