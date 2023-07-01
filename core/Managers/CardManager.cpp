#include "CardManager.h"

#include "../Utils/CardReader.h"
#include "../Utils/CardConverter.h"

#include <QUrl>
#include <QDebug>

CardManager::CardManager(QObject *parent)
    : QObject{parent}
{

}

void CardManager::saveAll()
{

}

void CardManager::save(const Card *card)
{

}

void CardManager::load(const QString &filepath)
{
    if (filepath.isEmpty()) {
        emit error("Podana ścieżka do pliku jest pusta.");
        return;
    }
    QUrl fileUrl{filepath};

    CardReader reader;
    reader.connect(&reader, &CardReader::error, this, &CardManager::error);

    QJsonDocument json = reader.load(fileUrl.toLocalFile());

    if (json.isEmpty()) {
        return;
    }

    CardConverter converter;
    CardData cardData = converter.toData(json);
    cardData.filename = fileUrl.toLocalFile();

    appendCard( new Card(cardData, this) );

    if ( !m_cards.isEmpty() && m_currentCard == nullptr ) {
        setCurrentCard( m_cards.front() );
    }
}

void CardManager::close(const Card *card)
{

}

QQmlListProperty<Card> CardManager::cards()
{
    return QQmlListProperty<Card>(this, this,
                                  &CardManager::appendCard,
                                  &CardManager::cardsCount,
                                  &CardManager::card,
                                  &CardManager::clearCards);
}

void CardManager::appendCard(Card *card)
{
    m_cards.append(card);
    emit cardsChanged();
}

qsizetype CardManager::cardsCount() const
{
    return m_cards.count();
}

Card *CardManager::card(qsizetype index)
{
    return m_cards.at(index);
}

void CardManager::clearCards()
{
    m_cards.clear();
}

void CardManager::appendCard(QQmlListProperty<Card> *list, Card *card)
{
    reinterpret_cast<CardManager*>(list->data)->appendCard(card);
}

qsizetype CardManager::cardsCount(QQmlListProperty<Card> *list)
{
    return reinterpret_cast<CardManager*>(list->data)->cardsCount();
}

Card *CardManager::card(QQmlListProperty<Card> *list, qsizetype index)
{
    return reinterpret_cast<CardManager*>(list->data)->card(index);
}

void CardManager::clearCards(QQmlListProperty<Card> *list)
{
    reinterpret_cast<CardManager*>(list->data)->clearCards();
}

Card *CardManager::currentCard() const
{
    return m_currentCard;
}

void CardManager::setCurrentCard(Card *newCurrentCard)
{
    if (m_currentCard == newCurrentCard)
        return;
    m_currentCard = newCurrentCard;
    emit currentCardChanged();
}
