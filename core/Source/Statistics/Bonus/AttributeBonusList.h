#ifndef ATTRIBUTEBONUSLIST_H
#define ATTRIBUTEBONUSLIST_H

#include "AttributeBonusSource.h"
#include <QQmlEngine>

class AttributeBonusList : public AttributeBonusSource
{
    Q_OBJECT
    Q_PROPERTY(Types::AttributeBonus type READ type CONSTANT)
    Q_PROPERTY(QStringList list READ list CONSTANT)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    QML_ELEMENT

public:
    explicit AttributeBonusList(QObject *parent = nullptr);
    explicit AttributeBonusList(const QStringList& list, const int value, QObject* parent = nullptr);

    Types::AttributeBonus type() const;
    QStringList list() const;

    QString name() const;
    void setName(const QString &newName);

signals:
    void nameChanged();
    void nameWasChanged(const QString& from, const QString& to);

private:
    Types::AttributeBonus m_type;
    QStringList m_list;
    QString m_name;
};

#endif // ATTRIBUTEBONUSLIST_H
