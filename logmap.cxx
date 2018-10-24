#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ofstream out("output.dat");
	double x0 = 0.5;
	const int Nskip = 100; //Number of iterations to skip
	const int Nend  = 200; //Number of total iterations
  double x[Nend-Nskip];

	for(double r=0; r <= 4; r += 0.001){
	   x[0]=x0;
	   for(int i=1; i <= Nskip; i++)
		   x[0] = r*x[0]*(1-x[0]);
	   for(int i=0; i < Nend-Nskip-1; i++){
	   		   x[i+1] = r*x[i]*(1-x[i]);
   	   }
		 for(int i=0; i < Nend-Nskip; i++)
			  out << r << "\t" << x[i] << endl;
	}

  out.close();
	return 0;
}
