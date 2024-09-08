#ifndef SOURCELOADER_H
#define SOURCELOADER_H

#include <QObject>
#include <QJsonDocument>

#include "SourceDocument.h"

class SourceLoader : public QObject
{
    Q_OBJECT
public:
    explicit SourceLoader(QObject *parent = nullptr);

    void load();

signals:
    void sendSourceDocument(const SourceDocument& document);

private slots:
    void onError(const QString& message);
};

#endif // SOURCELOADER_H
