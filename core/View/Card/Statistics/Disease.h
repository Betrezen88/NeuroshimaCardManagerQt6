#ifndef DISEASE_H
#define DISEASE_H

#include <QObject>
#include <QQmlListProperty>
#include <QtQml/qqmlregistration.h>

#include "../../../Data/Statistics/DiseaseData.h"

class Symptom;

class Disease : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QString cure READ cure CONSTANT)
    Q_PROPERTY(QQmlListProperty<Symptom> symptoms READ symptoms CONSTANT)

public:
    explicit Disease(QObject *parent = nullptr);
    explicit Disease(const DiseaseData &data, QObject *parent = nullptr);

    QString name() const;
    QString description() const;
    QString cure() const;

    QQmlListProperty<Symptom> symptoms();
    qsizetype symptomsCount() const;
    Symptom* symptom(qsizetype index);

    DiseaseData data() const;

private:
    static qsizetype symptomsCount(QQmlListProperty<Symptom> *list);
    static Symptom* symptom(QQmlListProperty<Symptom> *list, qsizetype index);

private:
    QString m_name;
    QString m_description;
    QString m_cure;
    QVector<Symptom*> m_symptoms;
};

#endif // DISEASE_H
