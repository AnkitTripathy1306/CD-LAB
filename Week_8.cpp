#include <bits/stdc++.h>
using namespace std;

int main()
{
    string op = "", exp;
    cout << "Enter Expression: ";
    cin >> exp;
    stack<char> stk;
    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] >= 'A' && exp[i] <= 'Z')
            op += exp[i];
        else if (exp[i] == '(')
            stk.push('(');
        else if (exp[i] == '+' || exp[i] == '-')
        {
            while (stk.top() == '+' || stk.top() == '-' || stk.top() == '*' || stk.top() == '/')
            {
                op += stk.top();
                stk.pop();
            }
            stk.push(exp[i]);
        }
        else if (exp[i] == '*' || exp[i] == '/')
        {
            while (stk.top() == '*' || stk.top() == '/')
            {
                op += stk.top();
                stk.pop();
            }
            stk.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (stk.top() != '(')
            {
                op += stk.top();
                stk.pop();
            }
            stk.pop();
        }
    }
    cout << op;
}