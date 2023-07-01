#include "CardWriter.h"

#include <QFile>

CardWriter::CardWriter(QObject *parent)
    : QObject{parent}
{

}

void CardWriter::save(const QString &filepath, const QJsonDocument &json)
{
    if (filepath.isEmpty()) {
        emit error("Podana nazwa pliku jest pusta.");
        return;
    }

    QFile file(filepath);

    if (!file.open(QIODevice::WriteOnly)) {
        emit error(QString("Plku %1 nie mógł zostać otworzeony do zapisu.").arg(filepath));
        return;
    }

    if (-1 == file.write(json.toJson())) {
        emit error(QString("Zapis pliku %1 nie powiódł się.").arg(filepath));
        return;
    }

    emit message(QString("Plik %1 został zapisany pomyślnie"));
}
