#ifndef STATISTICSSOURCE_H
#define STATISTICSSOURCE_H

#include <QObject>
#include "qqmlintegration.h"

#include "AttributeSource.h"
#include "OriginSource.h"
#include "ProfessionSource.h"
#include "SpecializationSource.h"

class StatisticsSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<AttributeSource> attributes READ attributes NOTIFY attributesChanged FINAL)
    Q_PROPERTY(QQmlListProperty<OriginSource> origins READ origins NOTIFY originsChanged FINAL)
    Q_PROPERTY(QQmlListProperty<ProfessionSource> professions READ professions NOTIFY professionsChanged FINAL)
    Q_PROPERTY(QQmlListProperty<SpecializationSource> specializations READ specializations NOTIFY specializationsChanged FINAL)
    QML_ELEMENT

public:
    explicit StatisticsSource(QObject *parent = nullptr);

    QQmlListProperty<AttributeSource> attributes();
    qsizetype attributesCount() const;
    AttributeSource* attribute(qsizetype index);

    QQmlListProperty<OriginSource> origins();
    qsizetype originsCount() const;
    OriginSource* origin(qsizetype index);

    QQmlListProperty<ProfessionSource> professions();
    qsizetype professionsCount() const;
    ProfessionSource* profession(qsizetype index);

    QQmlListProperty<SpecializationSource> specializations();
    qsizetype specializationsCount() const;
    SpecializationSource* specialization(qsizetype index);

signals:
    void attributesChanged();
    void originsChanged();
    void professionsChanged();
    void specializationsChanged();

public slots:
    void addAttributes(const QVector<AttributeSource*>& attributes);
    void addOrigins(const QString& name, const QVector<OriginSource*>& origins);
    void addProfessions(const QString& name, const QVector<ProfessionSource*>& professions);
    void addSpecializations(const QVector<SpecializationSource*>& specializations);

private:
    static qsizetype attribtuesCount(QQmlListProperty<AttributeSource> *list);
    static AttributeSource* attribute(QQmlListProperty<AttributeSource> *list, qsizetype index);

    static qsizetype originsCount(QQmlListProperty<OriginSource> *list);
    static OriginSource* origin(QQmlListProperty<OriginSource> *list, qsizetype index);

    static qsizetype professionsCount(QQmlListProperty<ProfessionSource> *list);
    static ProfessionSource* profession(QQmlListProperty<ProfessionSource> *list, qsizetype index);

    static qsizetype specializationsCount(QQmlListProperty<SpecializationSource> *list);
    static SpecializationSource* specialization(QQmlListProperty<SpecializationSource> *list, qsizetype index);

private:
    QVector<AttributeSource*> m_attributes;
    QVector<OriginSource*> m_origins;
    QVector<ProfessionSource*> m_professions;
    QVector<SpecializationSource*> m_specializations;

    QMap<QString, QVector<OriginSource*>> m_originSources;
    QMap<QString, QVector<ProfessionSource*>> m_professionSource;
};

#endif // STATISTICSSOURCE_H
