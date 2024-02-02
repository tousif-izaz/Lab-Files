//

#include <cmath>
#include <ctype.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "dstack.h"

// bool isOperator(char c)
// {
//     return (c == '+' || c == '-' || c == '^' || c == '/' || c == '*');
// }
// int precedence(char op)
// {
//     if (op == '^')
//         return 3;
//     if (op == '*' || op == '/')
//         return 2;
//     else
//         return 1;
// }

int main()
{
    Dstack stack;
    while (cin.peek() != EOF)
    {
        if (isspace(cin.peek()))
        {
            cin.ignore();
        }
        else if (isdigit(cin.peek()) || cin.peek() == '.')
        {
            double operand;
            if (cin >> operand)
            {
                stack.push(operand);
            }
            else
            {
                cerr << "Error: Invalid expression." << endl;
                exit(1);
            }
            if (cin.peek() == '.')
            {
                cerr << "Error: Invalid expression." << endl;
                exit(1);
            }
        }
        else
        {
            char op;
            cin >> op;
            if (stack.size() < 2)
            {
                cerr << "Error: Invalid expression." << endl;
                exit(1);
            }
            double rightOp, leftOp;
            if (!stack.pop(rightOp) || !stack.pop(leftOp))
            {
                cerr << "Error: Invalid expression." << endl;
                exit(1);
            }
            double result;
            switch (op)
            {
            case '+':
                result = leftOp + rightOp;
                break;
            case '-':
                result = leftOp - rightOp;
                break;
            case '*':
                result = leftOp * rightOp;
                break;
            case '/':
                if (rightOp == 0)
                {
                    cerr << "Error: Invalid expression." << endl;
                    exit(1);
                }
                result = leftOp / rightOp;
                break;
            case '^':
                result = pow(leftOp, rightOp);
                break;

            default:
                cerr << "Error: Invalid expression." << endl;
                exit(1);
                break;
            }
            stack.push(result);
        }
    }
    if (stack.size() == 1)
    {
        double finalResult;
        if (stack.pop(finalResult))
        {
            cout << finalResult << endl;
        }
        else
        {
            cerr << "Error: Invalid expression." << endl;
            exit(1);
        }
    }
    else
    {
        cerr << "Error: Invalid expression." << endl;
        exit(1);
    }
    return 0;
}