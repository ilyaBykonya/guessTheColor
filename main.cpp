//Made with Qt5
#include <QApplication>
#include <QtWidgets>
#include <ctime>
#include "colorWidget.h"
#include "colorWidgetAndSliders.h"
#include "checkColor.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget mainWidget;
    QHBoxLayout *mainLay = new QHBoxLayout;

    QPushButton quit("quit");
    QObject::connect(&quit, &QPushButton::clicked, qApp, &QApplication::quit);

    ColorWidgetAndSliders *user = new ColorWidgetAndSliders(155, 34, 32);
    ColorWidget *test = new ColorWidget(0,0,0);
    QVBoxLayout *testLay = new QVBoxLayout;
    testLay->addWidget(test);

    CheckColor checker(test->getColor());

    QObject::connect(user, &ColorWidgetAndSliders::colorUpdated, &checker, &CheckColor::slotCheckColor);
    QObject::connect(&checker, &CheckColor::checkColorResultIsTrue, &quit, &QPushButton::show);
    QObject::connect(&checker, &CheckColor::checkColorResultIsTrue, [&](){ mainWidget.setEnabled(false); });

    mainLay->addLayout(user->getLayout());
    mainLay->addLayout(testLay);
    mainWidget.setLayout(mainLay);
    mainWidget.show();
    return app.exec();
}
