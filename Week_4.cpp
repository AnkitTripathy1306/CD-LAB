#include <bits/stdc++.h>
using namespace std;
vector<string> v(10), first(10);
vector<unordered_set<char>> follow(10);
vector<bool> done(10, false);
int n;

void followHelper(int ind)
{
    char ch = v[ind][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j < v[i].size(); j++)
        {
            if (v[i][j] == ch)
            {
                if (j + 1 == v[i].size() || v[i][j + 1] == '/')
                {
                    follow[ind].insert(follow)
                }
            }
        }
    }
}

void firstHelper(int ind)
{
    string str = v[ind];
    for (int i = 2; i < str.size(); i++)
    {
        if (str[i - 1] != '/')
            continue;
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            for (int j = ind + 1; j < n; j++)
                if (v[j][0] == str[i])
                {
                    firstHelper(j);
                    for (auto it : first[j])
                        if (it != '@')
                            first[ind] += it;
                    if (!count(first[j].begin(), first[j].end(), '@'))
                        break;
                }
        }
        else
            first[ind].push_back(str[i]);
    }
    done[ind] = 1;
}

int main()
{
    cout << "Enter No of productions: ";
    cin >> n;
    printf("Enter %d productions:\n", n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
    {
        if (!done[i])
            firstHelper(i);
        printf("First(%c) : [ ", v[i][0]);
        for (int j = 0; j < first[i].size(); j++)
            cout << first[i][j] << ", ";
        cout << "]\n";
    }
    done = vector<bool>(10, false);
    for (int i = 0; i < n; i++)
    {
        if (!done[i])
            followHelper(i);
        printf("follow(%c) : [ ", v[i][0]);
        for (auto it : follow[i])
            cout << it << ", ";
        cout << "]\n";
    }
}
