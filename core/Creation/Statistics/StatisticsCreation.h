#ifndef STATISTICSCREATION_H
#define STATISTICSCREATION_H

#include <QObject>
#include <QQmlListProperty>
#include "qqmlintegration.h"

#include "AttributeCreation.h"

#include <DiseaseSource.h>
#include <OriginSource.h>
#include <ProfessionSource.h>
#include <SkillpointsCreationManager.h>
#include <SpecializationSource.h>

class StatisticsCreation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<AttributeCreation> attributes READ attributes CONSTANT)
    Q_PROPERTY(DiseaseSource* disease READ disease WRITE setDisease NOTIFY diseaseChanged FINAL)
    Q_PROPERTY(OriginSource* origin READ origin WRITE setOrigin NOTIFY originChanged FINAL)
    Q_PROPERTY(FeatureSource* originFeature READ originFeature WRITE setOriginFeature NOTIFY originFeatureChanged FINAL)
    Q_PROPERTY(AttributeBonusSource* attributeBonus READ attributeBonus WRITE setAttributeBonus NOTIFY attributeBonusChanged FINAL)
    Q_PROPERTY(ProfessionSource* profession READ profession WRITE setProfession NOTIFY professionChanged FINAL)
    Q_PROPERTY(FeatureSource* professionFeature READ professionFeature WRITE setProfessionFeature NOTIFY professionFeatureChanged FINAL)
    Q_PROPERTY(SpecializationSource* specialization READ specialization WRITE setSpecialization NOTIFY specializationChanged FINAL)
    Q_PROPERTY(SkillpointsCreationManager* skillpointsManager READ skillpointsManager CONSTANT)
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

    AttributeBonusSource *attributeBonus() const;
    void setAttributeBonus(AttributeBonusSource *newAttributeBonus);

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
    Q_INVOKABLE QStringList attributesNames() const;

    SkillpointsCreationManager* skillpointsManager() const;

signals:
    void diseaseChanged();
    void originChanged();
    void originFeatureChanged();
    void attributeBonusChanged();
    void professionChanged();
    void professionFeatureChanged();
    void specializationChanged();
    void specializationChangedTo(const QString& specialization);
    void applyAttributeBonus(const AttributeBonusSource* bonus);
    void removeAttributeBonus(const AttributeBonusSource* bonus);
    void applyFeatureBonus(const BonusSource* bonus);
    void removeFeatureBonus(const BonusSource* bonus);

private slots:
    void onRemoveAttributeBonus(const AttributeBonusSource *bonus);
    void onApplyAttributeBonus(const AttributeBonusSource* bonus);
    void onApplyFeatureBonus(const BonusSource* bonus);
    void onRemoveFeatureBonus(const BonusSource* bonus);
    void onAttributeBonusListChanged(const QString& from, const QString& to);
    void onSkillpackChanged(const QString& from, const QString& to, const int value);

private:
    void init();
    SkillpackCreation* findSkillpack(const QString& name);

    static qsizetype attributesCount(QQmlListProperty<AttributeCreation>* list);
    static AttributeCreation* attribute(QQmlListProperty<AttributeCreation>* list, qsizetype index);

private:
    DiseaseSource *m_disease{nullptr};
    OriginSource *m_origin{nullptr};
    FeatureSource *m_originFeature{nullptr};
    AttributeBonusSource *m_attributeBonus{nullptr};
    ProfessionSource *m_profession{nullptr};
    FeatureSource *m_professionFeature{nullptr};
    SpecializationSource *m_specialization{nullptr};
    QVector<AttributeCreation*> m_attributes;
    SkillpointsCreationManager* m_skillpointsManager{nullptr};
};

#endif // STATISTICSCREATION_H
