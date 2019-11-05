//--------------------------------------------------
// Basic statistics on pseudo-random numbers,
// GL, 11.11.2017
//--------------------------------------------------
#include <cmath>
#include <iostream>
#include <cstdlib>
//--------------------------------------------------
using namespace std;
//--------------------------------------------------
void random_numbers(double* const p, const int N);
void statistics(double& mean, double& var,
                const double* const p, const int N);
//--------------------------------------------------
int main(){
   srand(time(NULL));
   const int N = 100000;
   double p[N];
   double mean, var;

   random_numbers(p,N);
   statistics(mean, var, p, N);

   cout << "Mean = " << mean << endl;
   cout << "Variance = " << var << endl;

   return 0;
}
//--------------------------------------------------
void random_numbers(double* const p, const int N){
  for(int i=0; i<N; i++)
  {
     p[i] = rand()/double(RAND_MAX);
     cout << p[i] << endl;
   }
}
//--------------------------------------------------
void statistics(double& mean, double& var,
                const double* const p, const int N){
   mean = 0;
   for(int i=0; i<N; i++)
     mean += p[i];
   mean /= N;

   var = 0;
   for(int i=0; i<N; i++)
     var += pow( p[i]-mean, 2);
   var /= N;
}
//--------------------------------------------------
//--------------------------------------------------
