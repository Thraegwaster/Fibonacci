// Fibonacci.cpp : Defines the entry point for the console application.
// One might expect that in C++ you could use an array to store the
// numbers of the Fibonacci sequence. This would work if we only wanted
// 40 terms, but we want a number of terms that are to be determined at runtime.
// Unfortunately, arrays cannot be dynamically resized in C++, so instead
// we will use a more advanced data type: the vector.
// N.B. in C++ a vector is actually a rectangular array or matrix.

#include "stdafx.h" // required only in Microsoft Visual Studio
#include <iostream>
#include <vector> // Enable support for vectors.

using namespace std;

int n, k, term1, term2;

int getUserInput();



int main()
{
	// First get user inputs for number of terms required and the starting
	// numbers of the sequence.
	cout << "\nEnter the number of terms of the sequence you want to find: ";
	n = getUserInput(); // Calls the function getUserInput() -- see below -- and stores the returned value in n.
	cout << "\nEnter the first term of the sequence: ";
	term1 = getUserInput();
	cout << "\nEnter the second term of the sequence: ";
	term2 = getUserInput();
	
	// Define the vector that will hold the terms of our sequence.
	vector <int> fibterms(n);

	// Insert the first two terms of the sequence...
	fibterms[0] = term1;
	fibterms[1] = term2;

	cout << fibterms[0] << ", " << fibterms[1] << ", ";

	// Loop to populate the rest of the vector.
	// N.B. vector elements are numbered from zero, not 1. Hence the third vector element is actually element 2.
	for (k = 2; k <= n - 1; k++)
	{
		fibterms[k] = fibterms[k - 1] + fibterms[k - 2];
		// The if-else block below is there to make sure that the last element
		// printed out does not have a comma after it!
		if (k != n - 1)
		{
			cout << fibterms[k] << ", ";
		}
		else cout << fibterms[k] << "\n";
	}
		

	return 0;
}

// The purpose of this function is simply to get input from the user.
// The input is stored in whatever variable was used to call the function.
int getUserInput()
{
	int number;
	cin >> number;
	return number;
}

