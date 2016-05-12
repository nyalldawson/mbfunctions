#ifndef MBFUNCTIONS_H
#define MBFUNCTIONS_H

#define UNUSED(x) (void)x;

template< typename Iter >
inline void deleteAll( Iter begin, Iter end )
{
  for ( ; begin != end; ++begin )
  {
    delete (*begin);
  }
}

#endif // MBFUNCTIONS_H

