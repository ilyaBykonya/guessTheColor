#ifndef COLORWIDGET_H
#define COLORWIDGET_H

#include <QWidget>
#include <QVBoxLayout>

class ColorWidget : public QWidget
{
    Q_OBJECT
private:
    int red;
    int green;
    int blue;
public:
    explicit ColorWidget(int r, int g, int b, int w = 120, int h = 245, QWidget *parent = nullptr);
    QColor getColor() const { return QColor(red, green, blue); }
public slots:
    void slotRed(int r);
    void slotGreen(int g);
    void slotBlue(int b);
};

#endif // COLORWIDGET_H
