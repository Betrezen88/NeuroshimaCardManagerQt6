#ifndef ANSWERCREATION_H
#define ANSWERCREATION_H

#include <QObject>
#include <QQmlEngine>

#include <QuestionSource.h>

class AnswerCreation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QuestionSource* source READ source CONSTANT)
    Q_PROPERTY(QString answer READ answer WRITE setAnswer NOTIFY answerChanged FINAL)
    QML_ELEMENT
    QML_UNCREATABLE("AnswerCreation is uncreatable.")

public:
    explicit AnswerCreation(QObject *parent = nullptr);
    AnswerCreation(QuestionSource *source, QObject *parent = nullptr);

    QuestionSource* source() const;

    QString answer() const;
    void setAnswer(const QString &newAnswer);

signals:
    void answerChanged();

private:
    QuestionSource* m_source{nullptr};
    QString m_answer;
};

#endif // ANSWERCREATION_H
