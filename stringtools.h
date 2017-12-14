#ifndef STRINGTOOLS_H
#define STRINGTOOLS_H

#include "candyqt_global.h"

namespace candy {

CANDYQTSHARED_EXPORT int how_many_chinese_chars(QString s);
CANDYQTSHARED_EXPORT int how_many_english_words(QString s);

CANDYQTSHARED_EXPORT QString fix_digit_count_2(int x);

} //namespace candy

#endif // STRINGTOOLS_H
