#ifndef TRICKSOURCEITEM_H
#define TRICKSOURCEITEM_H

#include <QObject>
#include <QQmlEngine>

#include "../Statistics/TrickSource.h"
#include "RequirementSourceModel.h"

class TrickSourceItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sourceName READ sourceName CONSTANT)
    Q_PROPERTY(TrickSource* source READ source CONSTANT)
    Q_PROPERTY(RequirementSourceModel* requirements READ requirements CONSTANT)
    Q_PROPERTY(bool available READ available WRITE setAvailable NOTIFY availableChanged FINAL)
    Q_PROPERTY(bool bought READ bought WRITE setBought NOTIFY boughtChanged FINAL)
    QML_ELEMENT

public:
    explicit TrickSourceItem(QObject *parent = nullptr);
    explicit TrickSourceItem(const QString& sourceName, TrickSource* source, QObject *parent = nullptr);

    QString sourceName() const;

    TrickSource *source() const;
    RequirementSourceModel *requirements() const;

    bool available() const;
    void setAvailable(bool newAvailable);

    bool bought() const;
    void setBought(bool newBought);

signals:
    void availableChanged();
    void boughtChanged();

private:
    QString m_sourceName;
    TrickSource* m_source{nullptr};
    bool m_available{false};
    RequirementSourceModel *m_requirements{nullptr};
    bool m_bought{false};
};

#endif // TRICKSOURCEITEM_H
