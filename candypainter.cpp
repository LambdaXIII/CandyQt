#include "candypainter.h"

namespace candy {

QList<QRect> borderSpliter(const QRect &sourceRect, int l, int t, int r, int b)
{
  int x = sourceRect.x();
  int y = sourceRect.y();
  int w = sourceRect.width();
  int h = sourceRect.height();

  QRect TL(x, y, l, t);
  QRect TC(x + l, y, w - l - r, t);
  QRect TR(x + w - r, y, r, t);

  QRect CL(x, y + t, l, h - t - b);
  QRect CC(x + l, y + t, w - l - r, h - t - b);
  QRect CR(x + w - r, y + t, r, h - t - b);

  QRect BL(x, y + h - b, l, b);
  QRect BC(x + l, y + h - b, w - l - r, b);
  QRect BR(x + w - r, y + h - b, r, b);

  QList<QRect> res {TL, TC, TR,
                    CL, CC, CR,
                    BL, BC, BR};
  return res;
}

void paintBorderImage(QPainter &painter, const QImage &image,
                      int border_left, int border_top, int border_right, int border_bottom,
                      const QRect &targetRect)
{
  /*
   int sW = image.width();
   int sH = image.width();
   int tX = targetRect.x();
   int tY = targetRect.y();
   int tW = targetRect.width();
   int tH = targetRect.height();

   QRect sTL(0, 0, border_left, border_top);
   QRect sTC(border_left, 0, sW - border_left - border_right, border_top);
   QRect sTR(sW - border_right, 0, border_right, border_top);
   QRect sCL(0, border_top, border_left, sH - border_top - border_bottom);
   QRect sCC(border_left, border_top, sW - border_left - border_right, sH - border_top - border_bottom);
   QRect sCR(sW - border_right, border_top, border_right, sH - border_top - border_bottom);
   QRect sBL(0, sH - border_bottom, border_left, border_bottom);
   QRect sBC(border_left, sH - border_bottom, sW - border_left - border_right, border_bottom);
   QRect sBR(sW - border_right, sH - border_bottom, border_right, border_bottom);

   QRect tTL(tX, tY, border_left, border_top);
   QRect tTC(tX + border_left, tY, tW - border_left - border_right, border_top);
   QRect tTR(tX + tW - border_right, tY, border_right, border_top);
   QRect tCL(tX, tY + border_top, border_left, tH - border_top - border_bottom);
   QRect tCC(tX + border_left, tY + border_top, tW - border_left - border_right, tH - border_top - border_bottom);
   QRect tCR(tX + tW - border_right, tY + border_top, border_right, tH - border_top - border_bottom);
   QRect tBL(tX, tY + tH - border_bottom, border_left, border_bottom);
   QRect tBC(tX + border_left, tY + tH - border_bottom, tW - border_left - border_right, border_bottom);
   QRect tBR(tX + tW - border_right, tY + tH - border_bottom, border_right, border_bottom);

   QList<QRect> sRects{sTL, sTC, sTR, sCL, sCC, sCR, sBL, sBC, sBR};
   QList<QRect> tRects{tTL, tTC, tTR, tCL, tCC, tCR, tBL, tBC, tBR};
   */

  QList<QRect> sRects = borderSpliter(image.rect(), border_left, border_top, border_right, border_bottom);
  QList<QRect> tRects = borderSpliter(targetRect, border_left, border_top, border_right, border_bottom);

  for (int i = 0; i < sRects.length(); i++) {
    painter.drawImage(tRects[i], image, sRects[i]);
  }
}

//void paintBorderImage(QPainter &painter, QImage &image, int border, QRect &targetRect)
//{
//  paintBorderImage(painter, image, border, border, border, border, targetRect) ;
//}

} //namespace candy
