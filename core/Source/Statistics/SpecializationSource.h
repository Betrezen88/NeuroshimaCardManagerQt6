#ifndef SPECIALIZATIONSOURCE_H
#define SPECIALIZATIONSOURCE_H

#include "qqmlintegration.h"
#include <QObject>

class SpecializationSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    QML_ELEMENT

public:
    explicit SpecializationSource(QObject *parent = nullptr);
    explicit SpecializationSource(const QString& name, const QString& description, QObject* parent = nullptr);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // SPECIALIZATIONSOURCE_H
