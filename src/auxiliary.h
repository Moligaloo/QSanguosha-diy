#ifndef AUXILIARY_H
#define AUXILIARY_H

#include <QObject>
#include <QColor>

class Card: public QObject{
    Q_OBJECT

public:
    enum Suit {Spade, Club, Heart, Diamond, NoSuit};

    static const Suit AllSuits[4];
    static QString Suit2String(Suit suit);
};

class Engine: public QObject{
    Q_OBJECT

public:
    Engine();
    QStringList getKingdoms() const;
    QColor getKingdomColor(const QString &kingdom) const;
    QString translate(const QString &key) const;
};

extern Engine *Sanguosha;

#endif // AUXILIARY_H
