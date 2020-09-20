#ifndef _ROOTS_H
#define _ROOTS_H 1

#define SIN_PI_4  0.707106781
#define EPS_EQ  1E-9 /* equality of the two */
#define EPS_STOP  1E-15 /* to stop iteration */

#define NEIGHBOR(val1, val2, bound) (((val1 > val2) ? (val1 - val2) : (val2 - val1)) < bound)

struct Z
{
   double Re;
   double Im;
};

int get4Roots(struct Z [][4], const double *, int);

#endif  /* roots.h */
