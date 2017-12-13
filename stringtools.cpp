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

} //namespace candy
