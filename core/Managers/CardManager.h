#ifndef CARDMANAGER_H
#define CARDMANAGER_H

#include "qqmlintegration.h"
#include <QObject>
#include <QQmlListProperty>

#include "../View/Card/Card.h"

class CardManager : public QObject
{
    Q_OBJECT
    QML_NAMED_ELEMENT(CardManager)
    Q_PROPERTY(QQmlListProperty<Card> cards READ cards NOTIFY cardsChanged)
    Q_PROPERTY(Card* currentCard READ currentCard WRITE setCurrentCard NOTIFY currentCardChanged)

public:
    explicit CardManager(QObject *parent = nullptr);

    QQmlListProperty<Card> cards();
    void appendCard(Card* card);
    qsizetype cardsCount() const;
    Card* card(qsizetype index);
    void clearCards();

    Card* currentCard() const;
    void setCurrentCard(Card* newCurrentCard);

signals:
    void error(const QString &text);
    void cardsChanged();

    void currentCardChanged();

public slots:
    void saveAll();
    void save(const Card* card);
    void load(const QString &filepath);
    void close(const Card* card);

private:
    static void appendCard(QQmlListProperty<Card> *list, Card* card);
    static qsizetype cardsCount(QQmlListProperty<Card> *list);
    static Card* card(QQmlListProperty<Card> *list, qsizetype index);
    static void clearCards(QQmlListProperty<Card> *list);

private:
    QVector<Card*> m_cards;
    Card* m_currentCard{nullptr};
};

#endif // CARDMANAGER_H
