#include "main_window.hpp"

#include <QBrush>
#include <QColor>
#include <QPainter>
#include <QPoint>
#include <QRect>


void MainWindow::_prepareFractal(QPainter& paint, const QRect& rect)
{
    paint.setBrush(QBrush(QColor(0, 0, 0)));
    paint.drawPolygon(
        QPolygon(
            QVector<QPoint>{
                rect.bottomLeft(),
                rect.bottomRight(),
                rect.topLeft() + QPoint(rect.width() / 2, 0)
            }
        )
    );
    paint.setBrush(QBrush(QColor(255, 255, 255)));
}


void MainWindow::_drawFractal(QPainter& paint, const QRect& rect, size_t numIterations)
{
    if (numIterations == 0)
    {
        return;
    }

    auto quarterWidth = rect.width() / 4;
    auto halfWidth = rect.width() / 2;
    auto halfHeight = rect.height() / 2;
    auto x = rect.left();
    auto y = rect.top();

    QRect rect1(x + quarterWidth, y + 0,          halfWidth, halfHeight);
    QRect rect2(x + 0,            y + halfHeight, halfWidth, halfHeight);
    QRect rect3(x + halfWidth,    y + halfHeight, halfWidth, halfHeight);

    paint.drawPolygon(
        QPolygon(
            QVector<QPoint>{
                QPoint(x + quarterWidth,             y + halfHeight),
                QPoint(x + halfWidth + quarterWidth, y + halfHeight),
                QPoint(x + halfWidth,                y + rect.height()),
            }
        )
    );

    _drawFractal(paint, rect1, numIterations - 1);
    _drawFractal(paint, rect2, numIterations - 1);
    _drawFractal(paint, rect3, numIterations - 1);
}


void MainWindow::paintEvent([[maybe_unused]] QPaintEvent* event)
{
    QPainter paint(this);
    QRect rect(0, 0, width(), height());
    _prepareFractal(paint, rect);
    _drawFractal(paint, rect, 6);
}
