#ifndef OTHERSKILLCREATION_H
#define OTHERSKILLCREATION_H

#include <QObject>
#include <QQmlEngine>

#include <../Source/Statistics/OtherSkillSource.h>

class OtherSkillCreation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(OtherSkillSource* source READ source CONSTANT)
    Q_PROPERTY(int value READ value NOTIFY valueChanged FINAL)
    Q_PROPERTY(int min READ min CONSTANT)
    Q_PROPERTY(int max READ max CONSTANT)
    Q_PROPERTY(QString attributeShort READ attributeShort CONSTANT)
    QML_ELEMENT

public:
    explicit OtherSkillCreation(QObject *parent = nullptr);
    explicit OtherSkillCreation(OtherSkillSource* source, QObject *parent = nullptr);

    OtherSkillSource* source() const;
    int value() const;
    int min() const;
    int max() const;

    QString attributeShort() const;

signals:
    void valueChanged();
    void increased(int value);
    void decreased(int value);

public slots:
    void increase();
    void decrease();

private:
    OtherSkillSource* m_source;
    int m_value{0};
    int m_min{0};
    int m_max{5};
    QString m_attributeShort;
};

#endif // OTHERSKILLCREATION_H
