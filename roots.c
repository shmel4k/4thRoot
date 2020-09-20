#include "roots.h"

/*
 * This function calculates 4 complex roots for the passed value.
 *
 * dst - storage for the found roots,
 * the roots are located for the passed i-th value each as follows:
 *    dst[i][0] - 1st
 *    dst[i][1] - 2nd
 *    dst[i][2] - 3d
 *    dst[i][3] - 4th
 *
 * src - array of the double values to calculate the roots for
 * 
 * len - the 'src' length
 *
 * */

int get4Roots(struct Z dst[][4], const double *src, int len)
{
   if (len <= 0)
      return -1;

   struct Z *r = *dst; /* roots */

   for(; len--; src++)
   {
      double val = *src;
      if NEIGHBOR(val, 0, EPS_EQ)
      {
	 for(int i = 0; i < 4; i++, r++)
	 {
	    r->Re = r->Im = 0;
	 }
      }
      else
      {
         double x = 10.0;
	 if (val < 0) val = -val;
         double nx;
/*
 * 4th root
         for (;;)
         {
            nx = (3*x + val / (x*x*x)) / 4;
            if NEIGHBOR(x, nx, EPS_STOP)
	       break;
            x = nx;
         }
*/	 
         
/*
 * 2nd root 2 times
 */
	 for (;;)
         {
            nx = (x + val / x) / 2;
            if NEIGHBOR(x, nx, EPS_STOP)
	       break;
            x = nx;
         }
	 for (val = x;;)
         {
            nx = (x + val / x) / 2;
            if NEIGHBOR(x, nx, EPS_STOP)
	       break;
            x = nx;
         }


         if (*src > 0)
         {
            r->Re = x; r->Im = 0;
	    r++;
	    r->Re = 0; r->Im = x;
	    r++;
	    r->Re = -x; r->Im = 0;
	    r++;
	    r->Re = 0; r->Im = -x;
	    r++;
         }
	 else
	 {
	    r->Re = x * SIN_PI_4;
	    r->Im = x * SIN_PI_4;
	    r++;
	    r->Re = -x * SIN_PI_4;
	    r->Im = x * SIN_PI_4;
	    r++;
	    r->Re = -x * SIN_PI_4;
	    r->Im = -x * SIN_PI_4;
	    r++;
	    r->Re = x * SIN_PI_4;
	    r->Im = -x * SIN_PI_4;
	    r++;
	 }
      }
   }

   return 0;
}
