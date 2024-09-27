#ifndef SKILLPOINTSCREATIONMANAGER_H
#define SKILLPOINTSCREATIONMANAGER_H

#include <QObject>
#include <QQmlEngine>

#include <../../Source/Statistics/SpecializationSource.h>

struct Skillpoints {
    quint8 current;
    quint8 max;
};

class SkillpointsCreationManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString specialization READ specialization WRITE setSpecialization NOTIFY specializationChanged FINAL)
    Q_PROPERTY(quint8 generalSkillpoints READ generalSkillpoints NOTIFY generalSkillpointsChanged FINAL)
    Q_PROPERTY(quint8 specializationSkillpoints READ specializationSkillpoints NOTIFY specializationSkillpointsChanged FINAL)
    Q_PROPERTY(quint8 specializationSkillpointsMax READ specializationSkillpointsMax WRITE setSpecializationSkillpointsMax NOTIFY specializationSkillpointsMaxChanged FINAL)
    Q_PROPERTY(quint8 tricksCount READ tricksCount NOTIFY tricksCountChanged FINAL)
    Q_PROPERTY(quint8 availableReputationPoints READ availableReputationPoints NOTIFY availableReputationPointsChanged FINAL)
    Q_PROPERTY(bool isReputationGeneralPoint READ isReputationGeneralPoint WRITE setIsReputationGeneralPoint NOTIFY isReputationGeneralPointChanged FINAL)
    QML_ELEMENT
    QML_UNCREATABLE("SkillpointsCreationManager is uncreatable.")

public:
    explicit SkillpointsCreationManager(QObject *parent = nullptr);

    QString specialization() const;
    void setSpecialization(const QString &newSpecialization);

    quint8 generalSkillpoints() const;
    quint8 specializationSkillpoints() const;

    quint8 specializationSkillpointsMax() const;
    void setSpecializationSkillpointsMax(quint8 newSpecializationSkillpointsMax);

    quint8 tricksCount() const;

    Q_INVOKABLE bool canSkillpackBeBought(const QString& specialization);
    Q_INVOKABLE bool canSkillBeIncreased(const QString& specialization, const quint8 value);
    Q_INVOKABLE bool canTrickBeBought();
    Q_INVOKABLE bool canReputationBeBougth();

    quint8 availableReputationPoints() const;

    bool isReputationGeneralPoint() const;
    void setIsReputationGeneralPoint(bool newIsReputationGeneralPoint);

signals:
    void specializationChanged();
    void generalSkillpointsChanged();
    void specializationSkillpointsChanged();
    void specializationSkillpointsMaxChanged();
    void tricksCountChanged();
    void availableReputationPointsChanged();
    void isReputationGeneralPointChanged();

public slots:
    void onSkillpackBought(const QStringList& specializations);
    void onSkillpackSold(const QStringList& specializations);
    void onSkillBought(const QStringList &specializations, const quint8 value);
    void onSkillSold(const QStringList &specializations, const quint8 value);
    void onTrickBought();
    void onTrickSold();
    void onReputationBougth();
    void onReputationSold();

private:
    quint8 availablePoints(const QString& specialization);
    quint8 buySkillCost(const quint8 level);
    quint8 sellSkillCost(const quint8 level);

    void setGeneralSkillpoints(const quint8 newGeneralSkillpoints);
    void setSpecializationSkillpoints(const quint8 newSpecializationSkillpoints);

private:
    QString m_specialization;
    Skillpoints m_general{35, 35};
    Skillpoints m_specializations{30, 30};
    const quint8 m_skillpackCost{5};
    quint8 m_trickCount{0};
    quint8 m_availableReputationPoints{1};
    bool m_isReputationGeneralPoint{false};
};

#endif // SKILLPOINTSCREATIONMANAGER_H
