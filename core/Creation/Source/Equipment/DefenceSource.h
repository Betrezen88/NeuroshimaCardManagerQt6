#ifndef DEFENCESOURCE_H
#define DEFENCESOURCE_H

#include <QObject>
#include <QQmlEngine>

class DefenceSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString location READ location CONSTANT)
    Q_PROPERTY(quint8 value READ value CONSTANT)
    Q_PROPERTY(quint8 cutting READ cutting CONSTANT)
    QML_ELEMENT

public:
    explicit DefenceSource(QObject *parent = nullptr);
    DefenceSource(const QString& location, const quint8 value, const quint8 cutting, QObject* parent = nullptr);

    QString location() const;
    quint8 value() const;
    quint8 cutting() const;

signals:
private:
    QString m_location;
    quint8 m_value{0};
    quint8 m_cutting{0};
};

#endif // DEFENCESOURCE_H
