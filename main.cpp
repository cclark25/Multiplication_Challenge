#include <iostream>

using namespace std;

long int Multiply(int, int);

int main(){
	cout << "4 * 3 = " << Multiply(4,3) << endl;
	cout << "5 * -12 = " << Multiply(5,-12) << endl;
	cout << "-6 * -9 = " << Multiply(-6,-9) << endl;
	cout << "-7 * 2 = " << Multiply(-7,2) << endl;
	cout << "7 * 0 = " << Multiply(7,0) << endl;
	cout << "-7 * 0 = " << Multiply(-7,0) << endl;
	cout << "0 * 0 = " << Multiply(0,0) << endl;
	return 0;
}

// My Elegant solution to multiplication without using the * or / operators.
long int Multiply(int a, int b){
	// I made the return value a long int in the event that the result is too large to store in an int
	long int result = 0;

	// These variables are used to determine whether or not the function should return a positive or negative number
	// result_neg is determined using a bitwise XOR of the a_neg and b_neg values. 
	bool a_neg = a < 0;
	bool b_neg = b < 0;
	bool result_neg = a_neg ^ b_neg;

	// The value of a is set to be negative if result_neg is true or positive otherwise.
	// The value of b is always set to be positive.
	// This will gaurantee that the for loop will always run properly and that the result will have the appropriate sign.
	if(result_neg){
		a = a_neg ? a : -a;
	}
	else{
		a = a_neg ? -a : a;
	}
	b = b_neg ? -b : b;

	// I use a for loop to add a, b times.
	// Some may opt to use recursion for this, but I avoid using recursion because it puts the program at risk of a stack buffer overflow.
	// Since b is always positive at this point, an infinite loop will never occur.
	for(int i = b; i > 0; i-- ){
		// If a is positive, this will always increase the value of a, otherwise it will always decrement it.
		result += a;
	}
	
	return result;

}
