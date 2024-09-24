#ifndef DICE_H
#define DICE_H

#include <QObject>

class Dice : public QObject
{
    Q_OBJECT
public:
    explicit Dice(QObject *parent = nullptr);
    Dice(const qsizetype max, QObject *parent = nullptr);

    quint16 roll();
    QVector<quint16> roll(quint16 times);

private:
    qsizetype m_max;
};

#endif // DICE_H
