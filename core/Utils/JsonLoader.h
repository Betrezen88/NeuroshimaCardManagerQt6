#ifndef JSONLOADER_H
#define JSONLOADER_H

#include <QObject>
#include <QJsonDocument>

class JsonLoader : public QObject
{
    Q_OBJECT
public:
    explicit JsonLoader(QObject *parent = nullptr);

    QJsonDocument load(const QString& filepath);

signals:
    void error(const QString& message);

private:
    QByteArray readFile(const QString& filepath);
};

#endif // JSONLOADER_H
