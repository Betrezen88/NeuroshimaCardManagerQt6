#ifndef STATISTICSCREATION_H
#define STATISTICSCREATION_H

#include <QObject>
#include <QQmlListProperty>
#include "qqmlintegration.h"

#include "AttributeCreation.h"

#include <DiseaseSource.h>
#include <OriginSource.h>
#include <ProfessionSource.h>
#include <SpecializationSource.h>

class StatisticsCreation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<AttributeCreation> attributes READ attributes CONSTANT)
    Q_PROPERTY(DiseaseSource* disease READ disease WRITE setDisease NOTIFY diseaseChanged FINAL)
    Q_PROPERTY(OriginSource* origin READ origin WRITE setOrigin NOTIFY originChanged FINAL)
    Q_PROPERTY(FeatureSource* originFeature READ originFeature WRITE setOriginFeature NOTIFY originFeatureChanged FINAL)
    Q_PROPERTY(ProfessionSource* profession READ profession WRITE setProfession NOTIFY professionChanged FINAL)
    Q_PROPERTY(FeatureSource* professionFeature READ professionFeature WRITE setProfessionFeature NOTIFY professionFeatureChanged FINAL)
    Q_PROPERTY(SpecializationSource* specialization READ specialization WRITE setSpecialization NOTIFY specializationChanged FINAL)
    QML_ELEMENT

public:
    explicit StatisticsCreation(QObject *parent = nullptr);
    explicit StatisticsCreation(const QVector<AttributeCreation*>& attributes, QObject* parent = nullptr);

    DiseaseSource *disease() const;
    void setDisease(DiseaseSource *newDisease);

    OriginSource *origin() const;
    void setOrigin(OriginSource *newOrigin);

    FeatureSource *originFeature() const;
    void setOriginFeature(FeatureSource *newOriginFeature);

    ProfessionSource *profession() const;
    void setProfession(ProfessionSource *newProfession);

    FeatureSource *professionFeature() const;
    void setProfessionFeature(FeatureSource *newProfessionFeature);

    SpecializationSource *specialization() const;
    void setSpecialization(SpecializationSource *newSpecialization);

    QQmlListProperty<AttributeCreation> attributes();
    qsizetype attribitesCount() const;
    AttributeCreation* attribute(qsizetype index);

    Q_INVOKABLE AttributeCreation* attribute(const QString& name);

signals:
    void diseaseChanged();
    void originChanged();
    void originFeatureChanged();
    void professionChanged();
    void professionFeatureChanged();
    void specializationChanged();

private:
    static qsizetype attributesCount(QQmlListProperty<AttributeCreation>* list);
    static AttributeCreation* attribute(QQmlListProperty<AttributeCreation>* list, qsizetype index);

private:
    DiseaseSource *m_disease{nullptr};
    OriginSource *m_origin{nullptr};
    FeatureSource *m_originFeature{nullptr};
    ProfessionSource *m_profession{nullptr};
    FeatureSource *m_professionFeature{nullptr};
    SpecializationSource *m_specialization{nullptr};
    QVector<AttributeCreation*> m_attributes;
};

#endif // STATISTICSCREATION_H
