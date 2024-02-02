#include <iostream>
#include <assert.h>
using namespace std;

// int helperFuncMax(int values[], int size, int maxNow) {
// 	if(size == 0) {
// 		return maxNow;
// 	} if(values[size] > helperFuncMax(values, size-1, maxNow)) {
// 		maxNow = values[size];
// 	}
// 	return maxNow;


//  }
int largest_in_array(int values[], int size)
{
	// IMPLEMENT A RECURSIVE VERSION OF THIS FUNCTION...
	//return helperFuncMax(values, size-1, values[size-1]);
	if(size == 1) {
		return values[0];
	}
	int now = values[size-1];
	int max = largest_in_array(values, size-1);
	return max > now ? max:now;
}



int main()
{
	int values[1000];
	int size;
	cout << "Enter integers.  Type control-D when done\n";
	for (size = 0; cin >> values[size]; size++);
	cout << "The largest value is " << largest_in_array(values, size) << endl;

}
