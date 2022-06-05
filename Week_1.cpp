#include <bits/stdc++.h>
using namespace std;

bool isKeyword(string &str)
{
    string arr[33] = {"int", "char", "float", "double", "signed", "unsigned", "short", "long",
                      "if", "else", "for", "while", "do", "auto", "break", "continue", "main"};
    for (int i = 0; i < 10; i++)
        if (arr[i] == str)
            return 1;
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    string str;
    unordered_set<string> operators({"+", "*", "-", "%", "/", "="});
    while (cin >> str)
    {
        if (count(str.begin(), str.end(), '#'))
        {
            cout << str << " is a Preprocessor directive\n";
        }

        else if (str[0] >= '0' && str[1] <= 9)
        {
            cout << str << " is a Number\n";
        }
        else if (isKeyword(str))
        {
            cout << str << " is a keyword\n";
        }
        else if (operators.count(str))
        {
            cout << str << " is an Operator";
        }
        else
        {
            cout << str << " is an identifier\n";
        }
    }
    return 0;
}