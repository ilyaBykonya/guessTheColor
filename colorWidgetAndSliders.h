#ifndef COLORWIDGETANDSLIDERS_H
#define COLORWIDGETANDSLIDERS_H
#include "colorWidget.h"
#include <QSlider>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QObject>

class ColorWidget;

class ColorWidgetAndSliders : public QObject
{
    Q_OBJECT
private:
    QVBoxLayout *layout;

    ColorWidget *cV;
    QSlider *sliderRed;
    QSlider *sliderGreen;
    QSlider *sliderBlue;
public:
    ColorWidgetAndSliders(int r, int g, int b, QWidget *parent = nullptr);
    QVBoxLayout* getLayout() { return layout; }
public slots:
    void redChange();
    void greenChange();
    void blueChange();
signals:
    void colorUpdated(QColor);

};

#endif // COLORWIDGETANDSLIDERS_H
