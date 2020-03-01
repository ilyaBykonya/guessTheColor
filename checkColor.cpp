#include "checkColor.h"

CheckColor::CheckColor(QColor c, QObject *parent)
    :color{ c }, QObject(parent)
    {
    }

void CheckColor::slotCheckColor(QColor c)
{
    if(abs(c.red() - this->color.red()) > 10){
        return;
    } else if(abs(c.green() - this->color.green()) > 10){
        return;
    } else if(abs(c.blue() - this->color.blue()) > 10){
        return;
    } else {
        checkColorResultIsTrue(true);
    }
}
