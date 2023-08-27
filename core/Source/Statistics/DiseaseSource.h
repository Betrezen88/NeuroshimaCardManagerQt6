#ifndef DISEASESOURCE_H
#define DISEASESOURCE_H

#include <QObject>
#include <QQmlListProperty>
#include "qqmlintegration.h"

#include "SymptomSource.h"

class DiseaseSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QString cure READ cure CONSTANT)
    Q_PROPERTY(QQmlListProperty<SymptomSource> symptoms READ symptoms CONSTANT)
    QML_ELEMENT

public:
    explicit DiseaseSource(QObject *parent = nullptr);
    explicit DiseaseSource(const QString& name,
                           const QString& description,
                           const QString& cure,
                           const QVector<SymptomSource*>& symptoms,
                           QObject* parent = nullptr);

    QString name() const;
    QString description() const;
    QString cure() const;

    QQmlListProperty<SymptomSource> symptoms();
    qsizetype symptomsCount() const;
    SymptomSource* symptom(qsizetype index);

private:
    static qsizetype symptomsCount(QQmlListProperty<SymptomSource> *list);
    static SymptomSource* symptom(QQmlListProperty<SymptomSource> *list, qsizetype index);

private:
    QString m_name;
    QString m_description;
    QString m_cure;
    QVector<SymptomSource*> m_symptoms;
};

#endif // DISEASESOURCE_H
