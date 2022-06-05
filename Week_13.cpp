#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cout << "Enter Expression: ";
    cin >> str;
    cout << "\n3Address Code\n";
    char j = 'A';
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '*' || str[i] == '/')
        {
            printf("%c = %c % c %c\n", j, str[i - 1], str[i], str[i + 1]);
            str[i - 1] = j++;
            for (int k = i; k < n - 1; k++)
                str[k] = str[k + 2];
            i--;
            n -= 2;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '+' || str[i] == '-')
        {
            printf("%c = %c % c %c\n", j, str[i - 1], str[i], str[i + 1]);
            str[i - 1] = j++;
            for (int k = i; k < n - 1; k++)
                str[k] = str[k + 2];
            i--;
            n -= 2;
        }
    }
    printf("%c = %c\n", str[0], str[2]);
}