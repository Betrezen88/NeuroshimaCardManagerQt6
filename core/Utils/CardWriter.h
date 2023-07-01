#ifndef CARDWRITER_H
#define CARDWRITER_H

#include <QObject>
#include <QJsonDocument>

class CardWriter : public QObject
{
    Q_OBJECT
public:
    explicit CardWriter(QObject *parent = nullptr);

    void save(const QString &filepath, const QJsonDocument &json);

signals:
    void error(QString text);
    void message(QString text);
};

#endif // CARDWRITER_H
