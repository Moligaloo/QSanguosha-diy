#include "auxiliary.h"

#include <QMap>

const Card::Suit Card::AllSuits[4] = {
    Card::Spade,
    Card::Club,
    Card::Heart,
    Card::Diamond
};

QString Card::Suit2String(Suit suit){
    switch(suit){
    case Spade: return "spade";
    case Heart: return "heart";
    case Club: return "club";
    case Diamond: return "diamond";
    default: return "no_suit";
    }
}

Engine *Sanguosha;

Engine::Engine(){
    Sanguosha = this;
}

QStringList Engine::getKingdoms() const{
    QStringList kingdoms;
    kingdoms << "wei" << "shu" << "wu" << "qun" << "god";
    return kingdoms;
}

QColor Engine::getKingdomColor(const QString &kingdom) const{
    static QMap<QString, QColor> color_map;
    if(color_map.isEmpty()){
        color_map["wei"] = QColor(0x54, 0x79, 0x98);
        color_map["shu"] = QColor(0xD0, 0x79, 0x6C);
        color_map["wu"] = QColor(0x4D, 0xB8, 0x73);
        color_map["qun"] = QColor(0x8A, 0x80, 0x7A);
        color_map["god"] = QColor(0x96, 0x94, 0x3D);
    }

    return color_map.value(kingdom);
}

QString Engine::translate(const QString &key) const{
    static QMap<QString, QString> t;
    if(t.isEmpty()){
        t["wei"] = tr("wei");
        t["shu"] = tr("shu");
        t["wu"] = tr("wu");
        t["qun"] = tr("qun");
        t["god"] = tr("god");

        t["spade"] = tr("spade");
        t["heart"] = tr("heart");
        t["club"] = tr("club");
        t["diamond"] = tr("diamond");
    }

    return t.value(key);
}
