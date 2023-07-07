#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

#include "../../../Data/Statistics/ExperienceData.h"

class Experience : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(int gathered READ gathered NOTIFY gatheredChanged)
    Q_PROPERTY(int spended READ spended NOTIFY spendedChanged)

public:
    explicit Experience(QObject *parent = nullptr);
    explicit Experience(const ExperienceData &data, QObject *parent = nullptr);

    int gathered() const;
    int spended() const;

    Q_INVOKABLE int left() const;
    Q_INVOKABLE void add(const int value);
    Q_INVOKABLE void spend(const int value);

    ExperienceData data() const;

signals:
    void gatheredChanged();
    void spendedChanged();

private:
    int m_gathered{0};
    int m_spended{0};
};

#endif // EXPERIENCE_H
