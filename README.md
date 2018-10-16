# Homework 1

Due until 23.10.2018, 16:00

## Problem 1

The series of Fibonacci numbers is defined as

![alt text](stuffy_stuff/formel.png "Logo Title Text 1")

where f(0) = 0, f(1) = 1. Write a program which reads an integer N from the console, calculates f(N) and prints the result to the console. For N=10 you should obtain the result 55.

* To compile your program use: **g++ fibonacci.cxx -o fibonacci**

## Problem 2
You are already familiar with the `cout` command to print
information to the console. Using a very similar command, you can
redirect output directly to a file. For this you have to include
the header file `fstream` and use an `ofstream` object,
as is demonstrated by the listing below.

```cpp
#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
 int a,b;

 // open file output.dat in order to write into it,
 // if the file already exists it will be overwritten
 ofstream out("output.dat");

 // Read input from console
 cout << "a = ";  cin >> a;      
 cout << "b = ";  cin >> b;

 cout << "a = " << a
      << "\t b = " << b << endl;   // Print to console
 out  << "a = " << a
      <<  "\t b = " << b << endl;  // Print to file

 out.close();

 return(0);
```
The formatting command ``\t`` prints
a tabulator in the respective position. After executing this program
a new file ``output.dat`` has been generated which contains all the things
you stuffed into ``out`` using the ``<<`` operator. The final command
``out.close()`` closes the file.

### Your assignment is:

Modify the program ***logmap.cxx*** (which is the solution to the problem to Lab 2 and will be provided _after_ the lab on Thursday this week) in the following way:
* Instead of iterating and printing the results (to the console) at the same time,
  modify your code such that first all calculations are done and only subsequently
  the results are written to the file.
* To keep things simple, you just have to store iteration results for one *r*
  value at a time. In the current program we carry out *Nskip* steps before we print
  values, i.e. you will need *Nend - Nskip* entries in your array.
* Insert an extra loop (inside the loop which modifies *r*) to print the values
  stored in the array to the file.
* Make sure your file is closed properly, i.e. if your file-handle is called ``out`` then
  do not forget the line ``out.close()``
