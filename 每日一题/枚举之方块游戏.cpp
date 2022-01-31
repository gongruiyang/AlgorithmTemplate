#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int s1[26], s2[26], ans[26];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		memset(s1, 0, sizeof s1);
		memset(s2, 0, sizeof s2);
		
		string a, b;
		cin >> a >> b;
		
		for(int i = 0; i < a.size() || i < b.size(); i ++) 
		{
			if(i < a.size()) s1[a[i] - 'a'] ++;
			if(i < b.size()) s2[b[i] - 'a'] ++;
		}
		
		for(int i = 0; i < 26; i ++) 
			ans[i] += max(s1[i], s2[i]);
	}
	for(int i = 0; i < 26; i ++) cout << ans[i] << endl;

	return 0;
}

