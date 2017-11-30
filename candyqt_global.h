#ifndef CANDYQT_GLOBAL_H
#define CANDYQT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CANDYQT_LIBRARY)
#  define CANDYQTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CANDYQTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CANDYQT_GLOBAL_H
