#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>
using namespace std;
bool wordBreak(string s, vector<string>& wordDict) 
{
	// Ê¹ÓÃ×Ö·û´®¹þÏ££¬½«µ¥´Ê×ÖµäÓ³Éä³ÉÊý×Ö
	// wordDict -> ULL 
	typedef unsigned long long ULL;
	const int P = 131;
	unordered_set<ULL> hash;
	for(auto& e : wordDict)
	{
		ULL h = 0;
		for(auto& c : e) h = h * P + c;
		hash.insert(h);
	}
	
	// DP 
	int n = s.size();
	vector<bool> f(n + 1, false);
	f[n] = true;
	for(int i = n - 1; i >= 0; i --)
	{
		UUL h = 0;
		for(int j = i; j < n; j ++)
		{
			h = h * P + s[j];
			if(hash.count(h) && f[j + 1])
			{
				f[i] = true;
				break;
			}
		}
	}	
	
	return f[0];
}
int main()
{


	return 0;
}

