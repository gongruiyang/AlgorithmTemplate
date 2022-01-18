#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n;
vector<int> a,b;
int main()
{
	cin >> n;
	char opt;
	int x;
	while(n --)
	{
		cin >> opt >> x;
		if(opt == 'T') a.push_back(x);
		else b.push_back(x);
	}
	b.push_back(1000);	// 最终目的地 
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	
	double t = 0, s = 0, v = 1;	// t 是当前时间 s 是当前路程 v 是速度倒数
	// 2路归并 
	int i = 0, j = 0;
	while(i < a.size() || j < b.size())
	{
		if(j == b.size() || i < a.size() && a[i] - t < (b[j] - s) * v)
		{
			//按时间减速先发生 
			s += (a[i] - t) / v;
			t = a[i];
			v ++;
			i ++;
		}
		else
		{
			// 按照路程减速先发生 
			t += (b[j] - s) * v;
			s = b[j];
			v ++;
			j ++;
		}	
	} 
	
	printf("%.0lf\n", t);
	return 0;
}

