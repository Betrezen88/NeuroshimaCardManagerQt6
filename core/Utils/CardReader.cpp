#include "CardReader.h"

#include <QFile>

CardReader::CardReader(QObject *parent)
    : QObject{parent}
{

}

QJsonDocument CardReader::load(const QString &filepath)
{
    QByteArray data = readFile(filepath);

    if (data.isEmpty()) {
        emit error(QString("Plik %1 jest pusty.").arg(filepath));
        return QJsonDocument();
    }

    QJsonParseError parseError;
    QJsonDocument json = QJsonDocument::fromJson(data);

    if (QJsonParseError::NoError != parseError.error) {
        emit error(QString("Błąd parsowania pliku: %1\nError: %2\nOffset: %3")
                       .arg(filepath, parseError.errorString()).arg(parseError.offset));
        return QJsonDocument();
    }

    return json;
}

QByteArray CardReader::readFile(const QString &filepath)
{
    if (filepath.isEmpty()) {
        emit error("Pusta nazwa pliku do odczytania.");
        return QByteArray();
    }

    QFile file(filepath);

    if (!file.exists()) {
        emit error(QString("Plik %1 nie istnieje.").arg(filepath));
        return QByteArray();
    }

    if (!file.open(QIODevice::ReadOnly)) {
        emit error(QString("Nie można otworzyć pliku %1").arg(filepath));
        return QByteArray();
    }

    return file.readAll();
}
