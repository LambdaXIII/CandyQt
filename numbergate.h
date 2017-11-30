#ifndef NUMBERGATE_H
#define NUMBERGATE_H

#include "candyqt_global.h"
#include <functional>

namespace candy {

template<class NUM>
std::function<NUM(NUM)> make_bottom_number_gate(const NUM bottom)
{
  auto gate = [ = ](NUM x)->NUM{
    if (x < bottom)
      return bottom;
    else
      return x;
  };
  return gate;
}


template<class NUM>
std::function<NUM(NUM)> make_top_number_gate(const NUM top)
{
  auto gate = [ = ](NUM x)->NUM{
    if (x > top)
      return top;
    else
      return x;
  };
  return gate;
}

template<class NUM>
std::function<NUM(NUM)> make_bottom_top_number_gate(const NUM bottom, const NUM top)
{
  auto gate = [ = ](NUM x)->NUM{
    if (x < bottom)
      return bottom;
    if (x > top)
      return top;
    return x;
  };
  return gate;
}


} //namespace candy

#endif // NUMBERGATE_H
