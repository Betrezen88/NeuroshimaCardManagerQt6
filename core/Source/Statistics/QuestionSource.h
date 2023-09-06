#ifndef QUESTIONSOURCE_H
#define QUESTIONSOURCE_H

#include <QObject>
#include <QQmlEngine>

class QuestionSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString question READ question CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    QML_ELEMENT

public:
    explicit QuestionSource(QObject *parent = nullptr);
    explicit QuestionSource(const QString& question, const QString& description, QObject* parent = nullptr);

    QString question() const;
    QString description() const;

private:
    QString m_question;
    QString m_description;
};

#endif // QUESTIONSOURCE_H
