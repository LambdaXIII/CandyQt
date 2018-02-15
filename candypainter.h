#ifndef CANDYPAINTER_H
#define CANDYPAINTER_H

#include <QPainter>
#include "candyqt_global.h"

namespace candy {
CANDYQTSHARED_EXPORT QList<QRect> borderSpliter(const QRect &sourceRect, int l, int t, int r, int b);

CANDYQTSHARED_EXPORT void paintBorderImage(QPainter &painter, const QImage &image, int border_left, int border_top, int border_right, int border_bottom, const QRect &targetRect);
//CANDYQTSHARED_EXPORT void paintBorderImage(QPainter &painter, QImage &image, int border, QRect &targetRect);



} //namespace candy

#endif // CANDYPAINTER_H
