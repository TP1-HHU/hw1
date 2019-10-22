# Homework 1

Due until 29.10.2019, 16:00

## Problem 1
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

Modify the program ***logmap.cxx*** (which is the solution to the problem to Lab 1) in the following way:
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


## Problem 2
In this problem you will do some statistics of pseudo-random numbers.
C++ provides random numbers via the command ``int rand()`` which is an extension from ``cstdlib`` (i.e. you will need ``#include <cstdlib>``). Every call of the function ``rand()`` will output an integer value between 0 and ``RAND_MAX``.
``RAND_MAX`` is an integer constant coming from ``cstdlib`` and ist the maximum possible random number.

Your assignment is:
* Write a program which creates an array of ``N=100`` random double values between **0** and **1**.
  * The array is to be created in ``main``, but filling it with random numbers should be done in an extra function. You will need pointers for this.
* Calculate the expected value *m* and the variance *v* of your *N* random numbers *x_i*, where
 <p align="center">
 <img src="stuffy_stuff/formel.png" width="150">

* Write one function that calculates both values *m* and *v*. This function should  return both values to the main program at the same time. Use pointers for this. The resulting values should be printed to the screen in the main program.

A note on ``rand()`` and random number generators in general:

Every call to ``rand()`` gives a new pseudo-random number. However, if you run your code several times, you will notice that you will get always the *same* sequence of random numbers. This is because the generator is always *seeded* by the same value (see e.g. [this](https://en.wikipedia.org/wiki/Pseudorandom_number_generator) Wikipedia article). In order to always get a different sequence of pseudo-random numbers, take a look at the command ``srand()``, which e.g. could be used in conjunction with the time that the program is started.
