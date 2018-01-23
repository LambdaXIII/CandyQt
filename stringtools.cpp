#include "stringtools.h"
#include <QRegExp>

namespace candy {


int how_many_chinese_chars(QString s)
{
  QRegExp chn("[\u4e00-\u9fa5]");
  chn.indexIn(s);
  return chn.captureCount();
}

int how_many_english_words(QString s)
{
  QRegExp eng("[a-zA-z]+");
  eng.indexIn(s);
  return eng.captureCount();
}

QString fix_digit_count_2(int x)
{
  if (x < 0)
    x = -x;
  if (x >= 100)
    x = x % 100;
  if (x < 10)
    return QString("0%1").arg(x);
  return QString("%1").arg(x);
}

QString fix_digit_count_3(int x)
{
  if (x < 0)
    x = -x;
  if (x >= 1000)
    x = x % 1000;

  if (x < 100)
    return QString("0%1").arg(fix_digit_count_2(x));

  return QString::number(x);
}

} //namespace candy
