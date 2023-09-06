#ifndef SKILLCREATION_H
#define SKILLCREATION_H

#include <QObject>
#include "qqmlintegration.h"

#include <SkillSource.h>

class SkillCreation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(SkillSource* source READ source CONSTANT)
    Q_PROPERTY(int value READ value NOTIFY valueChanged FINAL)
    Q_PROPERTY(int min READ min NOTIFY minChanged FINAL)
    Q_PROPERTY(int max READ max NOTIFY maxChanged FINAL)
    QML_ELEMENT

public:
    explicit SkillCreation(QObject *parent = nullptr);
    explicit SkillCreation(SkillSource* source, QObject* parent = nullptr);

    SkillSource *source() const;
    int value() const;
    int min() const;
    int max() const;

signals:
    void valueChanged();
    void increased(int value);
    void decreased(int value);
    void minChanged();
    void maxChanged();

public slots:
    void increase();
    void decrease();
    void increasedBy(const int value);
    void decreaseBy(const int value);

private:
    SkillSource *m_source{nullptr};
    int m_value{0};
    int m_min{0};
    int m_max{5};
};

#endif // SKILLCREATION_H
