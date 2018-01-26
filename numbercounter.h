#ifndef NUMBERCOUNTER_H
#define NUMBERCOUNTER_H

#include "candy_macros.h"
#include "candyqt_global.h"

namespace candy {

template<class NUM_TYPE>
class CANDYQTSHARED_EXPORT NumberCounter
{
  CANDY_PROPERTY_RO(NUM_TYPE, defaultValue)
  CANDY_PROPERTY(NUM_TYPE, value, Value)
  CANDY_PROPERTY_RO(NUM_TYPE, stepValue)
public:
  explicit NumberCounter(NUM_TYPE default_value, NUM_TYPE step_value)
    : m_defaultValue(default_value), m_value(default_value), m_stepValue(step_value)
  {
  }

  void stepForward(int step = 1)
  {
    setValue(value() + stepValue()*step);
  }

  void stepBackward(int step = 1)
  {
    setValue(value() - stepValue()*step);
  }

  NumberCounter& operator ++()
  {
    stepForward(1);
    return this;
  }

  NumberCounter& operator --()
  {
    stepBackward(1);
    return this;
  }

};

} //namespace candy


#endif // NUMBERCOUNTER_H
