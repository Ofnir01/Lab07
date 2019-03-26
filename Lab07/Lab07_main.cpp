#include <iostream>
#include <cstdlib>
#include <string>
#include "exceptions.h"
#include "Stress.h"
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using Stress::ipow_s;
using Stress::lots_of_ints;
using Stress::slice_sum_s;

int main() {
	int option;

	const int SIZE = 10;
	int arr[SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	bool repeat;
	char ans;

	do {
		//Display greeting and menu for the user.
		cout << "This program will demostrate exeption exemples for integer overflow, subscripts" << endl;
		cout << "out of range in an array, and shortage in memory to allocate.";
		cout << "Please enter:\n";
		cout << "\t1. Exception for integer overflow.\n";
		cout << "\t2. Exception for array subscripts.\n";
		cout << "\t3. Exception for shortage in memory allocation.\n";
		cout << "Which demostration you want to observe? ";
		cin >> option;

		//Input validation for the user input.
		while (option < 1 || option > 3) {
			cout << "Invalid input. Please try again.";
			cin >> option;
		}

		try {
			switch (option) {

				//Case 1 that will execute the integer overflow.
			case 1:
				ipow_s(2, 100);
				break;

				//Case 2 that will execute the subscript out of range.
			case 2:
				slice_sum_s(arr, 5, 9, SIZE);
				break;

				//Case 3 that will execute the memory allocation shortage.
			case 3:
				lots_of_ints(-1);
				break;
			}
		}

		//This catch statement will detect is integer overflow happened while executing.
		catch (OverflowException &error) {
			cerr << error.what();
		}

		//This catch statement will detect if a subscript is not within the limits of an array.
		catch (SubscriptException &error) {
			cerr << error.what();
		}

		//This catch statement will detect if a there is not enough space for the amount of memory
		//trying to be allocated.
		catch (MemoryException &error) {
			cerr << "Not enough space to allocate memory. Size tried to be allocated: " << error.getSize() << " bytes\n\n";
		}

		//Display the user if he wants to repeat the process again.
		cout << "Do you want to try again? Y/N\n";
		cin >> ans;

		if (ans == 'Y' || ans == 'y') {
			repeat = true;
		}

		else if (ans == 'N' || ans == 'n') {
			repeat = false;
		}

		cout << endl; //print white line for next iteration.
	}

	while (repeat);

	return 0;
}