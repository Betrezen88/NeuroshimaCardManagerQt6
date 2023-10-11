#ifndef SKILLPACKCREATION_H
#define SKILLPACKCREATION_H

#include <QObject>
#include <QQmlListProperty>
#include "qqmlintegration.h"

#include <SkillpackSource.h>

#include "SkillCreation.h"
#include "Common/Types.h"

class SkillpackCreation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(SkillpackSource* source READ source CONSTANT)
    Q_PROPERTY(QQmlListProperty<SkillCreation> skills READ skills CONSTANT)
    Q_PROPERTY(bool bought READ bought WRITE setBought NOTIFY boughtChanged FINAL)
    QML_ELEMENT

public:
    explicit SkillpackCreation(QObject *parent = nullptr);
    explicit SkillpackCreation(SkillpackSource *source, QObject* parent = nullptr);

    virtual TypesCreation::Skillpack type() const = 0;

    SkillpackSource *source() const;

    QQmlListProperty<SkillCreation> skills();
    qsizetype skillsCount() const;
    SkillCreation* skill(qsizetype index);

    bool bought() const;
    void setBought(const bool newBougth);

    void increaseSkillsBy(const int value);
    void decreaseSkillsBy(const int value);

signals:
    void boughtChanged(const bool bought);
    void skillIncreased(const QStringList& specializations, const int level);
    void skillDecreased(const QStringList& specializations, const int level);

public slots:
    void onBoughtChanged(const bool bougth);

private:
    static qsizetype skillsCount(QQmlListProperty<SkillCreation>* list);
    static SkillCreation* skill(QQmlListProperty<SkillCreation>* list, qsizetype index);

protected:
    SkillpackSource *m_source{nullptr};
    QVector<SkillCreation*> m_skills;

private:
    bool m_bought{false};
};

#endif // SKILLPACKCREATION_H
