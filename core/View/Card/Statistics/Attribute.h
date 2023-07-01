#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <QObject>
#include <QQmlListProperty>
#include <QtQml/qqmlregistration.h>

#include "../../../Data/Statistics/AttributeData.h"
#include "Skillpack.h"

class Attribute : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(QQmlListProperty<Skillpack> skillpacks READ skillpacks CONSTANT)

public:
    explicit Attribute(QObject *parent = nullptr);
    explicit Attribute(const AttributeData &data, QObject *parent = nullptr);

    QString name() const;
    int value() const;

    QQmlListProperty<Skillpack> skillpacks();
    qsizetype skillpacksCount() const;
    Skillpack* skillpack(qsizetype index);

    AttributeData data() const;

private:
    static qsizetype skillpacksCount(QQmlListProperty<Skillpack> *list);
    static Skillpack* skillpack(QQmlListProperty<Skillpack> *list, qsizetype index);

private:
    QString m_name;
    int m_value;
    QVector<Skillpack*> m_skillpacks;
};

#endif // ATTRIBUTE_H
