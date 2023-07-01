#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

#include "Pages/Page.h"
#include "Pages/Statistics.h"

struct CardData;

class Card : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString filePath READ filePath CONSTANT)
    Q_PROPERTY(QString filename READ filename CONSTANT)
    Q_PROPERTY(Page* currentPage READ currentPage WRITE setCurrentPage NOTIFY currentPageChanged)
    Q_PROPERTY(Statistics* statistics READ statistics CONSTANT)

public:
    explicit Card(QObject *parent = nullptr);
    explicit Card(const CardData &data, QObject *parent = nullptr);

    QString filePath() const;

    void addPage(Page *page);
    void removePage(Page *page);
    Q_INVOKABLE bool hasPage(Types::Page type) const;

    Page *currentPage() const;
    void setCurrentPage(Page *newCurrentPage);

    Statistics *statistics();

    CardData data();

    QString filename() const;

signals:
    void currentPageChanged();

private:
    Page* getPage(Types::Page type);

private:
    QString m_filePath;
    QVector<Page*> m_pages;
    Page *m_currentPage{nullptr};
};

#endif // CARD_H
