#ifndef MAIN_WINDOW_HPP_INCLUDED
#define MAIN_WINDOW_HPP_INCLUDED


#include <QMainWindow>
#include <QPainter>
#include <QRect>


class MainWindow : public QMainWindow
{
public:
    void paintEvent(QPaintEvent* event);

private:
    void _prepareFractal(QPainter& paint, const QRect& rect);
    void _drawFractal(QPainter& paint, const QRect& rect, size_t numIterations = 3);
};


#endif  // MAIN_WINDOW_HPP_INCLUDED
