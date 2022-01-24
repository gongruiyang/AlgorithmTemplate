#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int coinChange(vector<int>& coins, int amount) 
{
	vector<int> f(amount + 1, 1e8);
	f[0] = 0;
 	for(auto v : coins)
		for(int j = v; j <= amount; j ++)
			f[j] = min(f[j], f[j-v] + 1);
	if(f[amount] == 1e8) return -1;
	return f[m];
}
int main()
{


	return 0;
}

