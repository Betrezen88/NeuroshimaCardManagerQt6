#include "Card.h"

#include "../../Data/CardData.h"

#include <QUrl>

Card::Card(QObject *parent)
    : QObject{parent}
{

}

Card::Card(const CardData &data, QObject *parent)
    : QObject{parent}
{
    m_filePath = data.filename;

    if ( data.statistics ) {
        addPage(new Statistics(*data.statistics, this));
    }
}

QString Card::filePath() const
{
    return m_filePath;
}

void Card::addPage(Page *page)
{
    m_pages.append( page );
    if ( m_currentPage == nullptr ) {
        setCurrentPage( m_pages.front() );
    }
}

void Card::removePage(Page *page)
{
    m_pages.removeOne(page);
}

bool Card::hasPage(Types::Page type) const
{
    auto found = std::find_if(m_pages.begin(), m_pages.end(),[&type](const Page *page){
        return page->type() == type;
    });
    return found != m_pages.end();
}

Page *Card::currentPage() const
{
    return m_currentPage;
}

void Card::setCurrentPage(Page *newCurrentPage)
{
    if (m_currentPage == newCurrentPage)
        return;
    m_currentPage = newCurrentPage;
    emit currentPageChanged();
}

Statistics *Card::statistics()
{
    return hasPage(Types::Page::Statistics)
               ? qobject_cast<Statistics*>(getPage(Types::Page::Statistics))
               : nullptr;
}

CardData Card::data()
{
    return CardData {
        .filename = m_filePath,
        .statistics = hasPage(Types::Page::Statistics)
                          ? new StatisticsData(statistics()->data())
                          : nullptr
    };
}

Page* Card::getPage(Types::Page type)
{
    auto found = std::find_if(m_pages.begin(), m_pages.end(),[&type](const Page *page){
        return page->type() == type;
    });
    return *found;
}

QString Card::filename() const
{
    return QUrl(m_filePath).fileName();
}
