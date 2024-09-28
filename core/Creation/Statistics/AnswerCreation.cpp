#include "AnswerCreation.h"

AnswerCreation::AnswerCreation(QObject *parent)
    : QObject{parent}
{}

AnswerCreation::AnswerCreation(QuestionSource* source, QObject *parent)
    : QObject{parent}
    , m_source{source}
{

}

QString AnswerCreation::answer() const
{
    return m_answer;
}

void AnswerCreation::setAnswer(const QString &newAnswer)
{
    if (m_answer == newAnswer)
        return;
    m_answer = newAnswer;
    emit answerChanged();
}

QuestionSource *AnswerCreation::source() const
{
    return m_source;
}
