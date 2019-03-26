#include "Stress.h"
#include "exceptions.h"
#include <new>
#include <string>
using std::string;

//*******************************************************************************************************
//This function receives two ints, and returns base^power. It will return 1 if power == 0,				*
//where base and power are both non-negative numbers.													*
//*******************************************************************************************************
unsigned int Stress::ipow_s(unsigned int base, unsigned int power) {
	unsigned int tempNum = 1;
	for (unsigned int index = 0; index < power; index++) {
		if (base == 0) {
			return 0;
		}
		else if (tempNum * base < tempNum) {
			throw OverflowException("Integer overflow happened.\n\n");
		}
		else
			tempNum *= base;
	}

	return tempNum;
}

//*******************************************************************************************************
//This function takes one pointer to an int (more specifically to an array of pointers, a				*
//a starting subscript for the pointer, and an end subscript for the array. Therefore, the function		*
//will return the sum of the first 'k' values in 'vals' starting at index 'start'.						*
//*******************************************************************************************************
int Stress::slice_sum_s(const int* vals, const int start, const int k, const int size) {
	int sum = 0;
	for (int index = start; index < start + k; index++) {
		if (index == size) {
			throw SubscriptException("Subscript is out of limits.\n\n");
		}
		
		else
			sum += vals[index];
	}

	return sum;
}


//*******************************************************************************************************
//This function receives as a parameter an integer value that represents the quantity of times that		*
//the ++++++++++++++++++. It will allocate memory using the new operator. If memory failed to be		*
//allocated, then an expetion will be thrown. The function will return the exact amount of memory		*
//succesfully allocated.																				*
//*******************************************************************************************************
int Stress::lots_of_ints(const unsigned long long k) {
	int size = 2; //, index = 0;
	//while (k < 0 || index < k) 
	for (int index = 0; k < 0 || index < k; index++) {

		int *ptr = nullptr;
		try {
			ptr = new int[size];
		}

		catch (std::bad_alloc) {
			throw MemoryException(size);
		}

		size *= 2;
		delete[] ptr;
		ptr = nullptr;
		//index++;
	}
	return size;
}