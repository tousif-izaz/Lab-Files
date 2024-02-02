#include <iostream>

using namespace std;

int main()
{
    int var;
    bool flag = false;
    while (cin >> var)
    {
        if (var % 2 != 0)
        {
            flag = true;
        }
    }
    if (!flag)
    {
        cout << "all even" << endl;
        return 0;
    }
    else
    {
        cerr << "not all even" << endl;
        return 1;
    }
}