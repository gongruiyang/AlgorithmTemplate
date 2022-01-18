#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;


typedef vector<int> VI;
vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) 
{
	int n = a.size(), m = b.size();
	if(n == 0 || m == 0) return {};
	priority_queue<VI, vector<VI>, greater<VI>> heap;
	for(int i = 0; i < m; i ++) heap.push({a[0] + b[i], 0, i});
	vector<VI> res;
	while(k --)
	{
		auto t = heap.top();
		heap.pop();
		res.push_back({a[t[1]], b[t[2]]});
		if(t[1] + 1 < n)
			heap.push({a[t[1] + 1] + b[t[2]], t[1] + 1, t[2]});
	}
	return res;
}
int main()
{
	auto res = kSmallestPairs({1,7,11}, {2,4,6}, 3);

	return 0;
}

