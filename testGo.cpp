extern "C" int get4Roots(struct Z [][4], const double *, int);

#include "roots.h"

#include <random>
#include <complex>

#include <gtest/gtest.h>

#define EPS 1E-8

//TEST(GTest, DISABLED_4thRootTiny)
TEST(GTest, 4thRootTiny)
{
   const int N = 100;
   double a[N];

   const double UP = 1e-2;
   double lower_bound = -(UP/2);
   double upper_bound = -lower_bound;

   std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
   std::default_random_engine re;
   for (int i=0; i<N; i++)
   {
      a[i] = unif(re);
   }

   struct Z root[N][4];

   get4Roots(root, a, N);

   for(int i = 0; i < N; i++)
   {
      for(int j = 0; j < 4; j++)
      {
	 std::complex<double> z(root[i][j].Re, root[i][j].Im);
	 
	 double delta = std::abs((std::pow(z, 4) - a[i])) / a[i];

	 EXPECT_NEAR(delta, 0, EPS);
      }
   }
}

TEST(GTest, 4thRootSmall)
{
   const int N = 100;
   double a[N];

   const int UP = 1e5;
   int lower_bound = -(UP>>1);
   int upper_bound = -lower_bound;
   
   std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
   std::default_random_engine re;
   for (int i=0; i<N; i++)
   {
      a[i] = unif(re);
   }

   struct Z root[N][4];

   get4Roots(root, a, N);

   for(int i = 0; i < N; i++)
   {
      for(int j = 0; j < 4; j++)
      {
	 std::complex<double> z(root[i][j].Re, root[i][j].Im);
	 
	 double delta = std::abs((std::pow(z, 4) - a[i])) / a[i];

	 EXPECT_NEAR(delta, 0, EPS);
      }
   }
}

TEST(GTest, 4thRootHuge)
{
   const int N = 100;
   double a[N];

   int64_t lower_bound = -(UINT64_MAX>>1);
   int64_t upper_bound = -lower_bound;
   
   std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
   std::default_random_engine re;
   for (int i=0; i<N; i++)
   {
      a[i] = unif(re);
   }

   struct Z root[N][4];

   get4Roots(root, a, N);

   for(int i = 0; i < N; i++)
   {
      for(int j = 0; j < 4; j++)
      {
	 std::complex<double> z(root[i][j].Re, root[i][j].Im);
	 
	 double delta = std::abs((std::pow(z, 4) - a[i])) / a[i];

	 EXPECT_NEAR(delta, 0, EPS);
      }
   }
}
