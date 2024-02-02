#include <iostream>
#include <assert.h>
using namespace std;

bool is_array_sorted(int values[], int size)
{
	// IMPLEMENT A RECURSIVE VERSION OF THIS METHOD...

	assert(size > 0);
	if(size == 1) {
		return true;
	}
	if(size == 2) {
		return (values[1] > values[0]);
	}
	return (values[size-1] > values[size-2]) && is_array_sorted(values, --size); 
	return false;
}

int main()
{
	int values[1000];
	int size;
	cout << "Enter integers.  Type control-D when done\n";
	for (size = 0; cin >> values[size]; size++);
	if (is_array_sorted(values, size))
		cout << "The values you entered ARE sorted\n";
	else 
		cout << "The values you entered ARE NOT sorted\n";
}
