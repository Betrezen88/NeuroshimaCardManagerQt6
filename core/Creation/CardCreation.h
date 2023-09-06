#ifndef CARDCREATION_H
#define CARDCREATION_H

#include <QObject>
#include "qqmlintegration.h"

#include <StatisticsSource.h>

#include "StatisticsCreation.h"

class CardCreation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(StatisticsSource* statisticsSource READ statisticsSource CONSTANT)
    Q_PROPERTY(StatisticsCreation* statisticsCreation READ statisticsCreation NOTIFY statisticsCreationChanged FINAL)
    QML_ELEMENT

public:
    explicit CardCreation(QObject *parent = nullptr);

    StatisticsSource *statisticsSource() const;
    StatisticsCreation *statisticsCreation() const;

signals:
    void statisticsCreationChanged();

private:
    void init();

private:
    StatisticsSource* m_statisticsSource{nullptr};
    StatisticsCreation* m_statisticsCreation{nullptr};
};

#endif // CARDCREATION_H
