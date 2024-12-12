#ifndef FT_UINTPTR_T

# define FT_UINTPTR_T
#  if __LP64__
#   define __WORDSIZE		64
#  else
#   define __WORDSIZE		32
#  endif

#  if __WORDSIZE == 64
#   define UINTPTR_MAX		18446744073709551615UL
#  else
#   define UINTPTR_MAX		4294967295UL
#  endif

#  ifndef _UINTPTR_T
#   define _UINTPTR_T
    typedef unsigned long	uintptr_t;
#  endif /* _UINTPTR_T */

#endif /* FT_UINTPTR_T */
