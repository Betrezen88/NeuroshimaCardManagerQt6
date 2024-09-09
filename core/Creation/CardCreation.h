#ifndef CARDCREATION_H
#define CARDCREATION_H

#include <QObject>
#include "qqmlintegration.h"

#include <StatisticsSource.h>

#include "StatisticsCreation.h"
#include "SkillpointsCreationManager.h"

class CardCreation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(StatisticsSource* statisticsSource READ statisticsSource CONSTANT)
    Q_PROPERTY(StatisticsCreation* statisticsCreation READ statisticsCreation NOTIFY statisticsCreationChanged FINAL)
    Q_PROPERTY(SkillpointsCreationManager* skillpointsManager READ skillpointsManager CONSTANT)
    QML_ELEMENT
    QML_UNCREATABLE("CardCreation is uncreatable.")

public:
    explicit CardCreation(QObject *parent = nullptr);

    StatisticsSource *statisticsSource() const;
    StatisticsCreation *statisticsCreation() const;
    SkillpointsCreationManager* skillpointsManager() const;

signals:
    void statisticsCreationChanged();

private:
    void init();

private:
    StatisticsSource* m_statisticsSource{nullptr};
    StatisticsCreation* m_statisticsCreation{nullptr};
    SkillpointsCreationManager* m_skillpointsManager{nullptr};
};

#endif // CARDCREATION_H
