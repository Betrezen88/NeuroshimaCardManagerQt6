#ifndef STATISTICSSOURCE_H
#define STATISTICSSOURCE_H

#include <QObject>
#include "qqmlintegration.h"

#include "AttributeSource.h"
#include "DiseaseSource.h"
#include "OriginSource.h"
#include "ProfessionSource.h"
#include "QuestionSource.h"
#include "SpecializationSource.h"
#include "TrickSource.h"

#include "../Model/TrickSourceModel.h"

class StatisticsSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<AttributeSource> attributes READ attributes NOTIFY attributesChanged FINAL)
    Q_PROPERTY(QQmlListProperty<DiseaseSource> diseases READ diseases NOTIFY diseasesChanged FINAL)
    Q_PROPERTY(QQmlListProperty<OriginSource> origins READ origins NOTIFY originsChanged FINAL)
    Q_PROPERTY(QQmlListProperty<ProfessionSource> professions READ professions NOTIFY professionsChanged FINAL)
    Q_PROPERTY(QQmlListProperty<QuestionSource> questions READ questions NOTIFY questionsChanged FINAL)
    Q_PROPERTY(QQmlListProperty<SpecializationSource> specializations READ specializations NOTIFY specializationsChanged FINAL)
    Q_PROPERTY(TrickSourceModel* model READ model CONSTANT)
    Q_PROPERTY(QStringList places READ places NOTIFY placesChanged FINAL)
    QML_ELEMENT

public:
    explicit StatisticsSource(QObject *parent = nullptr);

    QQmlListProperty<AttributeSource> attributes();
    qsizetype attributesCount() const;
    AttributeSource* attribute(qsizetype index);

    const QVector<AttributeSource*>& attributes() const;

    QQmlListProperty<DiseaseSource> diseases();
    qsizetype diseasesCount() const;
    DiseaseSource* disease(qsizetype index);

    QQmlListProperty<OriginSource> origins();
    qsizetype originsCount() const;
    OriginSource* origin(qsizetype index);

    QQmlListProperty<ProfessionSource> professions();
    qsizetype professionsCount() const;
    ProfessionSource* profession(qsizetype index);

    QQmlListProperty<QuestionSource> questions();
    qsizetype questionsCount() const;
    QuestionSource* question(qsizetype index);

    QQmlListProperty<SpecializationSource> specializations();
    qsizetype specializationsCount() const;
    SpecializationSource* specialization(qsizetype index);

    QStringList places() const;

    TrickSourceModel *model() const;

signals:
    void attributesChanged();
    void diseasesChanged();
    void originsChanged();
    void professionsChanged();
    void specializationsChanged();
    void tricksChanged();
    void placesChanged();
    void questionsChanged();

public slots:
    void addAttributes(const QVector<AttributeSource*>& attributes);
    void addDiseases(const QString& name, const QVector<DiseaseSource*>& diseases);
    void addOrigins(const QString& name, const QVector<OriginSource*>& origins);
    void addProfessions(const QString& name, const QVector<ProfessionSource*>& professions);
    void addQuestions(const QString& name, const QVector<QuestionSource*>& questions);
    void addSpecializations(const QVector<SpecializationSource*>& specializations);
    void addTricks(const QString& name, const QVector<TrickSource *> &tricks);
    void addPlaces(const QStringList& places);

private:
    static qsizetype attribtuesCount(QQmlListProperty<AttributeSource> *list);
    static AttributeSource* attribute(QQmlListProperty<AttributeSource> *list, qsizetype index);

    static qsizetype diseasesCount(QQmlListProperty<DiseaseSource> *list);
    static DiseaseSource* disease(QQmlListProperty<DiseaseSource> *list, qsizetype index);

    static qsizetype originsCount(QQmlListProperty<OriginSource> *list);
    static OriginSource* origin(QQmlListProperty<OriginSource> *list, qsizetype index);

    static qsizetype professionsCount(QQmlListProperty<ProfessionSource> *list);
    static ProfessionSource* profession(QQmlListProperty<ProfessionSource> *list, qsizetype index);

    static qsizetype questionsCount(QQmlListProperty<QuestionSource> *list);
    static QuestionSource* question(QQmlListProperty<QuestionSource> *list, qsizetype index);

    static qsizetype specializationsCount(QQmlListProperty<SpecializationSource> *list);
    static SpecializationSource* specialization(QQmlListProperty<SpecializationSource> *list, qsizetype index);

private:
    QVector<AttributeSource*> m_attributes;
    QVector<DiseaseSource*> m_diseases;
    QVector<OriginSource*> m_origins;
    QVector<ProfessionSource*> m_professions;
    QVector<QuestionSource*> m_questions;
    QVector<SpecializationSource*> m_specializations;
    TrickSourceModel *m_model{nullptr};
    QStringList m_places;

    QMap<QString, QVector<DiseaseSource*>> m_diseaseSources;
    QMap<QString, QVector<OriginSource*>> m_originSources;
    QMap<QString, QVector<ProfessionSource*>> m_professionSource;
    QMap<QString, QVector<QuestionSource*>> m_questionSources;
    QMap<QString, QVector<TrickSource*>> m_trickSources;
};

#endif // STATISTICSSOURCE_H
