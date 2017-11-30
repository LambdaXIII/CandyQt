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

} //namespace candy

#endif // NUMBERGATE_H
