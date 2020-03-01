#ifndef CHECKCOLOR_H
#define CHECKCOLOR_H

#include <QColor>
#include <QObject>
#include <cmath>


class CheckColor : public QObject
{
    Q_OBJECT
private:
    QColor color;
public:
    explicit CheckColor(QColor c, QObject *parent = nullptr);
public slots:
    void slotCheckColor(QColor c);
signals:
    void checkColorResultIsTrue(bool);
};

#endif // CHECKCOLOR_H
