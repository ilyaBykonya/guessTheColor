#include "colorWidget.h"

ColorWidget::ColorWidget(int r, int g, int b, int w, int h, QWidget *parent)
    :red{ r }, green{ g }, blue{ b }, QWidget(parent)
    {
        QPalette pall;
        pall.setColor(this->backgroundRole(), QColor(red, green, blue));
        this->setPalette(pall);
        this->setAutoFillBackground(true);
        this->setFixedSize(w, h);
    }

void ColorWidget::slotRed(int r)
{
    this->red = r;
    QPalette pall;
    pall.setColor(this->backgroundRole(), QColor(red, green, blue));
    this->setPalette(pall);
}

void ColorWidget::slotGreen(int g)
{
    this->green = g;
    QPalette pall;
    pall.setColor(this->backgroundRole(), QColor(red, green, blue));
    this->setPalette(pall);
}

void ColorWidget::slotBlue(int b)
{
    this->blue = b;
    QPalette pall;
    pall.setColor(this->backgroundRole(), QColor(red, green, blue));
    this->setPalette(pall);
}
