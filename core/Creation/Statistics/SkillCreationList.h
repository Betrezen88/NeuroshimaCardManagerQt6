#ifndef SKILLCREATIONLIST_H
#define SKILLCREATIONLIST_H

#include <SkillCreation.h>
#include <QQmlEngine>

class SkillCreationList : public SkillCreation
{
    Q_OBJECT
    Q_PROPERTY(TypesCreation::Skill type READ type CONSTANT)
    Q_PROPERTY(QString selected READ selected WRITE setSelected NOTIFY selectedChanged FINAL)
    Q_PROPERTY(QStringList list READ list CONSTANT)
    QML_ELEMENT

public:
    explicit SkillCreationList(QObject *parent = nullptr);
    explicit SkillCreationList(const QVector<SkillSource*>& sources, QObject *parent = nullptr);

    TypesCreation::Skill type() const;

    QStringList list() const;

    QString selected() const;
    void setSelected(const QString &newSelected);

signals:
    void selectedChanged(const QString& selected);
    void skillChanged(const SkillCreationList* skill);

private slots:
    void onSelectedChanged(const QString& selected);

private:
    TypesCreation::Skill m_type;
    QStringList m_list;
    QString m_selected;
    QVector<SkillSource*> m_sources;
};

#endif // SKILLCREATIONLIST_H
