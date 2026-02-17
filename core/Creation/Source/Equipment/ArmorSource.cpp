#include "ArmorSource.h"

ArmorSource::ArmorSource(QObject *parent)
    : ItemSource{parent}
{}

ArmorSource::ArmorSource(const QString &name,
                         const QString &description,
                         const quint32 price,
                         const quint8 availability,
                         const QString &category,
                         const quint8 durability,
                         const QVector<DefenceSource *> &defence,
                         QObject *parent)
    : ItemSource{name, description, price, availability, category, parent}
    , m_durability{durability}
    , m_defence{defence}
{

}

Types::Item ArmorSource::type() const
{
    return m_type;
}

quint8 ArmorSource::durability() const
{
    return m_durability;
}

QQmlListProperty<DefenceSource> ArmorSource::defence()
{
    return QQmlListProperty<DefenceSource>(this, this,
                                           &ArmorSource::defenceCount,
                                           &ArmorSource::defence);
}

qsizetype ArmorSource::defenceCount() const
{
    return m_defence.count();
}

DefenceSource *ArmorSource::defence(qsizetype index)
{
    return m_defence.at(index);
}

qsizetype ArmorSource::defenceCount(QQmlListProperty<DefenceSource> *list)
{
    return reinterpret_cast<ArmorSource*>(list->data)->defenceCount();
}

DefenceSource *ArmorSource::defence(QQmlListProperty<DefenceSource> *list, qsizetype index)
{
    return reinterpret_cast<ArmorSource*>(list->data)->defence(index);
}
