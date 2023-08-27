#ifndef SOURCECONVERTER_H
#define SOURCECONVERTER_H

#include <QObject>

#include "SourceDocument.h"

class SourceConverter : public QObject
{
    Q_OBJECT
public:
    explicit SourceConverter();

signals:

public slots:
    void convertSourceDocument(const SourceDocument& document);

private:
};

#endif // SOURCECONVERTER_H
