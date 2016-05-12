#include "common.h"

#pragma warning(push, 0)
#include <math.h>
#include <cstdlib>
#pragma warning(pop)

EXPORT double better_rand()
{
  double f = ( double )rand() / RAND_MAX;
  return f;
}
