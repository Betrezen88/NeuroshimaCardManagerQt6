#ifndef TRICKCREATION_H
#define TRICKCREATION_H

#include <QObject>
#include <QQmlEngine>

#include <../Source/Statistics/TrickSource.h>
#include <../Source/Model/RequirementSourceModel.h>

class TrickCreation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(TrickSource* source READ source CONSTANT)
    Q_PROPERTY(RequirementSourceModel* requirements READ requirements CONSTANT)
    QML_ELEMENT
    QML_UNCREATABLE("TrickCreation is uncreatable.")

public:
    TrickCreation(QObject *parent = nullptr);
    TrickCreation(TrickSource* source, QObject* parent = nullptr);

    TrickSource *source() const;

    RequirementSourceModel *requirements() const;

private:
    TrickSource *m_source{nullptr};
    RequirementSourceModel *m_requirements{nullptr};
};

#endif // TRICKCREATION_H
