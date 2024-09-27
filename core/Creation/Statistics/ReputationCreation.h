#ifndef REPUTATIONCREATION_H
#define REPUTATIONCREATION_H

#include <QObject>
#include <QQmlEngine>
#include "qqmlintegration.h"

class ReputationCreation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString place READ place CONSTANT)
    Q_PROPERTY(quint8 value READ value WRITE setValue NOTIFY valueChanged FINAL)
    Q_PROPERTY(quint8 min READ min CONSTANT)
    Q_PROPERTY(quint8 max READ max CONSTANT)
    QML_ELEMENT
    QML_UNCREATABLE("StatisticsCreation is uncreatable.")

public:
    explicit ReputationCreation(QObject *parent = nullptr);
    ReputationCreation(const QString &place, const quint8 min, const quint8 max, QObject *parent = nullptr);

    QString place() const;

    quint8 value() const;
    void setValue(quint8 newValue);

    quint8 min() const;
    quint8 max() const;

signals:
    void valueChanged();
    void increased();
    void decreased();

public slots:
    void increase();
    void decrease();

private:
    QString m_place;
    quint8 m_value{0};
    quint8 m_min{0};
    quint8 m_max{0};
};

#endif // REPUTATIONCREATION_H
