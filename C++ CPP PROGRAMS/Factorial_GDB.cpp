/*
    GDB TUTORIAL
	https://www.cprogramming.com/gdb.html
	http://www.gdbtutorial.com/tutorial/commands
	http://www.onlinegdb.com/
	https://www.cprogramming.com/tutorial/debugging_concepts.html
	

    C Programming in Linux Tutorial #056 - GDB debugger (1/2)
    https://www.youtube.com/watch?v=rlN3XI8kuhI

    How to Debug a C or C++ Program on Linux Using gdb
    https://www.maketecheasier.com/debug-program-using-gdb-linux/
*/

#include<iostream>

using namespace std;

long factorial (int n);

int main()
{
    int n(0);

    cin >> n;

    long val = factorial(n);

    cout << "\n Factorial of " << n  << " is " << val;

    cin.get();

    return 0;
}

long factorial(int n)
{
    long result(1);

    //while(n>0) // CORRECT
    while(n--) // ERROR
    {   result*=n;
        // n--; // CORRECT
    }

    return result;
}