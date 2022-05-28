#include <bits/stdc++.h>
using namespace std;
vector<string> v(10), ans(10);
vector<bool> done(10, false);
int n;

void helper(int ind)
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
					helper(j);
					ans[ind] += ans[j];
					break;
				}
		}
		else
			ans[ind].push_back(str[i]);
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
			helper(i);
		printf("First(%c) : [ ", v[i][0]);
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << ", ";
		cout << "]\n";
	}
}
