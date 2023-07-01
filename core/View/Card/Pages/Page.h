#ifndef PAGE_H
#define PAGE_H

#include <QObject>

#include "../../../Data/Common/Types.h"

class Page: public QObject
{
    Q_OBJECT
    Q_PROPERTY(Types::Page type READ type CONSTANT)

public:
    Page(QObject *parent = nullptr) : QObject(parent) {}
    virtual ~Page() {}

    virtual Types::Page type() const = 0;

signals:
    void wasModified();
};

#endif // PAGE_H
