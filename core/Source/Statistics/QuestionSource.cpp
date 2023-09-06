#include "QuestionSource.h"

QuestionSource::QuestionSource(QObject *parent)
    : QObject{parent}
{

}

QuestionSource::QuestionSource(const QString &question, const QString &description, QObject *parent)
    : QObject{parent}
    , m_question{question}
    , m_description{description}
{

}

QString QuestionSource::question() const
{
    return m_question;
}

QString QuestionSource::description() const
{
    return m_description;
}
