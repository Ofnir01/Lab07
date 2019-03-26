#ifndef STRESS_H_
#define STRESS_H_
namespace Stress
{
	//*******************************************************************************************************
	//This function receives two ints, and returns base^power. It will return 1 if power == 0,				*
	//where base and power are both non-negative numbers.													*
	//Example: ipow_s(2, 2) will return the result of 2^2 = 4												*
	//*******************************************************************************************************
	unsigned int ipow_s(const unsigned int, const unsigned int);

	//*******************************************************************************************************
	//This function takes one pointer to an int (more specifically to an array of pointers, a				*
	//a starting subscript for the pointer, and an end subscript for the array. Therefore, the function		*
	//will return the sum of the first 'k' values in 'vals' starting at index 'start'.						*
	//Example: arr[] = {1, 2, 3, 4} is sent to slice_sum_s(arr, 0, 3) will return the sum of of the			*
	//elements 0 - 3 from the array. It will return  1 + 2 + 3 + 4											*
	//*******************************************************************************************************
	int slice_sum_s(const int*, const int, const int, const int);

	//*******************************************************************************************************
	//This function receives as a parameter an integer value that represents the quantity of times that		*
	//the ++++++++++++++++++. It will allocate memory using the new operator. If memory failed to be		*
	//allocated, then an expetion will be thrown. The function will return the exact amount of memory		*
	//succesfully allocated.																				*
	//*******************************************************************************************************
	int lots_of_ints(const unsigned long long);
};

#endif