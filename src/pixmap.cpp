#include "pixmap.h"

#include <QPainter>
#include <QGraphicsColorizeEffect>
#include <QMessageBox>
#include <QImageReader>

Pixmap::Pixmap(const QString &filename, bool center_as_origin)
    :pixmap(filename)
{

#ifndef QT_NO_DEBUG
//only complains about pixmap loading errors under debug mode
    if(pixmap.isNull()){
        QImageReader reader(filename);
        QString error_string = reader.errorString();

        QString warning = tr("Can not load image %1[%2], error string is %3")
                          .arg(filename).arg(metaObject()->className()).arg(error_string);
        QMessageBox::warning(NULL, tr("Warning"), warning);
    }
#endif
    if(center_as_origin)
        setTransformOriginPoint(pixmap.width()/2, pixmap.height()/2);
}

Pixmap::Pixmap()
{
}

QRectF Pixmap::boundingRect() const{
    return QRectF(0, 0, pixmap.width(), pixmap.height());
}

bool Pixmap::changePixmap(const QString &filename){
    bool success = pixmap.load(filename);
    if(success)
        prepareGeometryChange();

    return success;
}

void Pixmap::setPixmap(const QPixmap &pixmap){
    this->pixmap = pixmap;
    prepareGeometryChange();
}

void Pixmap::shift(){
    moveBy(-pixmap.width()/2, -pixmap.height()/2);
}

void Pixmap::scaleSmoothly(qreal ratio){
    qreal width = pixmap.width() * ratio;
    qreal height = pixmap.height() * ratio;
    pixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    prepareGeometryChange();
}

void Pixmap::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->drawPixmap(0, 0, pixmap);
}

QVariant Pixmap::itemChange(GraphicsItemChange change, const QVariant &value){
    if(change == ItemSelectedHasChanged){
        if(value.toBool()){
            QGraphicsColorizeEffect *effect = new QGraphicsColorizeEffect(this);
            effect->setColor(QColor(0xCC, 0x00, 0x00));
            setGraphicsEffect(effect);
        }else
            setGraphicsEffect(NULL);

        emit selected_changed();
    }else if(change == ItemEnabledHasChanged){
        if(this->inherits("CardItem"))
        {
            if(value.toBool()){
                setOpacity(1.0);
            }else{
                setOpacity(0.7);
            }
        }
        else emit enable_changed();
    }

    return QGraphicsObject::itemChange(change, value);
}
