#include <iostream>
using namespace std;

bool equal_string(const char str1[], const char str2[])
{
	// IMPLEMENT A RECURSIVE VERSION OF THIS METHOD...
	if(*str1 == '\0' && *str2 == '\0') {
		return true;
	}
	return (*str1 == *str2) && equal_string(++str1, ++str2);                                                                    
}
                              
int main()
{
	char str1[1000], str2[1000];

	// initialize str1 and str2 to empty
	str1[0] = '\0';
	str2[0] = '\0';

	cout << "enter first string: ";
	cin >> str1;
	cout << "enter second string: ";
	cin >> str2;

	if (equal_string(str1, str2))
		cout << "<" << str1 << "> is equal to <" << str2 << ">\n";
	else 
		cout << "<" << str1 << "> is NOT equal to <" << str2 << ">\n";
}
