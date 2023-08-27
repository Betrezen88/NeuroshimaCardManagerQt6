#ifndef SOURCEDOCUMENT_H
#define SOURCEDOCUMENT_H

#include <QObject>
#include <QJsonDocument>

class SourceDocument : public QObject
{
    Q_OBJECT
public:
    enum Type { Attributes, Origins, Professions, Diseases, Tricks, Features, Specializations, Unknown };
    explicit SourceDocument(QObject *parent = nullptr);
    explicit SourceDocument(const QString& type, const QString& name, const QJsonDocument& document, QObject* parent = nullptr);

    Type type() const;
    QString name() const;
    QJsonDocument document() const;

private:
    Type stringToType(const QString& string);

private:
    Type m_type;
    QString m_name;
    QJsonDocument m_document;
};

#endif // SOURCEDOCUMENT_H
