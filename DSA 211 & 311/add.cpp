#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

bool legal_int(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    int sum = 0;
    for (int i = 1; i < argc; i++)
    {
        if (legal_int(argv[i]))
        {
            sum = sum + atoi(argv[i]);
        }
        else
        {
            cerr << "Error: illegal integer." << endl;
            return 1;
        }
    }
    cout << sum << endl;
    return 0;
}