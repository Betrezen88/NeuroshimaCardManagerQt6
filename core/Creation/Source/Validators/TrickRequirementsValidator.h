#ifndef TRICKREQUIREMENTSVALIDATOR_H
#define TRICKREQUIREMENTSVALIDATOR_H

#include <QObject>

#include "../../Statistics/AttributeCreation.h"
#include <TrickSourceItem.h>

class TrickRequirementsValidator : public QObject
{
    Q_OBJECT
public:
    explicit TrickRequirementsValidator(QObject *parent = nullptr);

    void validate(const QVector<AttributeCreation*>& attributes, const QVector<TrickSourceItem*>& tricks);

signals:

private:
    bool meetsRequirement(const QVector<AttributeCreation*>& attributes, const RequirementSource* requirement);
};

#endif // TRICKREQUIREMENTSVALIDATOR_H
