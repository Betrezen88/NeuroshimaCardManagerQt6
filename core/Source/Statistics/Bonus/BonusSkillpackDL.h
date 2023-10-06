#ifndef BONUSSKILLPACKDL_H
#define BONUSSKILLPACKDL_H

#include "BonusSource.h"
#include <QQmlEngine>

class BonusSkillpackDL : public BonusSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Bonus type READ type CONSTANT)
    Q_PROPERTY(QStringList list READ list CONSTANT)
    Q_PROPERTY(QString selected READ selected WRITE setSelected NOTIFY selectedChanged FINAL)
    QML_ELEMENT

public:
    explicit BonusSkillpackDL(QObject *parent = nullptr);
    explicit BonusSkillpackDL(const QStringList& list, QObject* parent = nullptr);

    Types::Bonus type() const;
    QStringList list() const;

    QString selected() const;
    void setSelected(const QString &newSelected);

signals:
    void selectedChanged();

private:
    Types::Bonus m_type;
    QStringList m_list;
    QString m_selected;
};

#endif // BONUSSKILLPACKDL_H
