#include "Dice.h"
#include <QRandomGenerator64>

Dice::Dice(QObject *parent)
    : QObject{parent}
{}

Dice::Dice(const qsizetype max, QObject *parent)
    : QObject(parent)
    , m_max(max)
{

}

quint16 Dice::roll()
{
    return QRandomGenerator::global()->bounded(1, m_max);
}

QVector<quint16> Dice::roll(quint16 times)
{
    QVector<quint16> results;
    for (quint16 i{0}; i < times; ++i) {
        results.append( QRandomGenerator::global()->bounded(1, m_max+1) );
    }
    return results;
}
