#ifndef CARDREADER_H
#define CARDREADER_H

#include <QObject>
#include <QJsonDocument>

class CardReader : public QObject
{
    Q_OBJECT
public:
    explicit CardReader(QObject *parent = nullptr);

    QJsonDocument load(const QString &filepath);

signals:
    void error(QString message);

private:
    QByteArray readFile(const QString &filepath);
};

#endif // CARDREADER_H
