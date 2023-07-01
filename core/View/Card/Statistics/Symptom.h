#ifndef SYMPTOM_H
#define SYMPTOM_H

#include <QObject>
#include <QQmlListProperty>
#include <QtQml/qqmlregistration.h>

#include "../../../Data/Statistics/SymptomData.h"

class Modifier;

class Symptom : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QQmlListProperty<Modifier> penalties READ penalties CONSTANT)

public:
    explicit Symptom(QObject *parent = nullptr);
    explicit Symptom(const SymptomData &data, QObject *parent = nullptr);

    QString name() const;
    QString description() const;

    QQmlListProperty<Modifier> penalties();
    qsizetype penaltiesCount() const;
    Modifier* penalty(qsizetype index);

    SymptomData data() const;

private:
    static qsizetype penaltiesCount(QQmlListProperty<Modifier> *list);
    static Modifier* penalty(QQmlListProperty<Modifier> *list, qsizetype index);

private:
    QString m_name;
    QString m_description;
    QVector<Modifier*> m_penalties;
};

#endif // SYMPTOM_H
