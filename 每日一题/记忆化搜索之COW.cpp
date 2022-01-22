#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	long long c = 0, co = 0, cow = 0;
	for(auto e : s)
	{
		if(e == 'C') c ++;
		else if(e == 'O') co += c;
		else cow += co; 
	}
	
	cout << cow << endl;
	
	return 0;
}

