#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, x, v;
	cin >> n;
	
	vector<int> stk;
	while(n --)
	{
		cin >> x >> v;
		while(stk.size() && v < stk.back()) stk.pop_back();
		stk.push_back(v);	
	} 
	cout << stk.size() << endl;

	return 0;
}

