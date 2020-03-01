#include "colorWidgetAndSliders.h"


ColorWidgetAndSliders::ColorWidgetAndSliders(int r, int g, int b, QWidget *parent)
    :cV{ new ColorWidget(r, g, b, 120, 160) },
     sliderRed{ new QSlider(Qt::Orientation::Horizontal) },
     sliderGreen{ new QSlider(Qt::Orientation::Horizontal) },
     sliderBlue{ new QSlider(Qt::Orientation::Horizontal) },
     layout( new QVBoxLayout )
    {
        sliderRed->setRange(1, 255);
        sliderGreen->setRange(1, 255);
        sliderBlue->setRange(1, 255);

        sliderRed->setValue(r);
        sliderGreen->setValue(g);
        sliderBlue->setValue(b);

        QObject::connect(sliderRed, &QSlider::valueChanged, cV, &ColorWidget::slotRed);
        QObject::connect(sliderGreen, &QSlider::valueChanged, cV, &ColorWidget::slotGreen);
        QObject::connect(sliderBlue, &QSlider::valueChanged, cV, &ColorWidget::slotBlue);

        QFormLayout *redButton = new QFormLayout;
        QFormLayout *greenButton = new QFormLayout;
        QFormLayout *blueButton = new QFormLayout;

        redButton->addRow("R:", sliderRed);
        greenButton->addRow("G:", sliderGreen);
        blueButton->addRow("B:", sliderBlue);

        layout->addWidget(cV, 1);
        layout->addLayout(redButton, 0);
        layout->addLayout(greenButton, 0);
        layout->addLayout(blueButton, 0);

        if(parent)
            parent->setLayout(layout);

        QObject::connect(sliderRed, &QSlider::valueChanged, this, &ColorWidgetAndSliders::redChange);
        QObject::connect(sliderGreen, &QSlider::valueChanged, this, &ColorWidgetAndSliders::greenChange);
        QObject::connect(sliderBlue, &QSlider::valueChanged, this, &ColorWidgetAndSliders::blueChange);
    }


void ColorWidgetAndSliders::redChange()
{
    colorUpdated(QColor(sliderRed->value(), sliderGreen->value(), sliderBlue->value()));
}

void ColorWidgetAndSliders::greenChange()
{
    colorUpdated(QColor(sliderRed->value(), sliderGreen->value(), sliderBlue->value()));
}

void ColorWidgetAndSliders::blueChange()
{
    colorUpdated(QColor(sliderRed->value(), sliderGreen->value(), sliderBlue->value()));
}
