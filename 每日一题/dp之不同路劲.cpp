#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int uniquePaths(int m, int n) 
{
	const int N = 110;
	int a[N][N];
	
	// 第一行和第一列的格子达到方式只有一种 
	for(int i = 0; i < m; i ++) a[i][0] = 1;
	for(int j = 0; j < n; j ++) a[0][j] = 1;
	// 其他格子的到达方式分别是上方和左方到达方式之和 
	for(int i = 1; i < m; i ++)
		for(int j = 1; j < n; j ++)
			a[i][j] = a[i-1][j] + a[i][j-1];

	return a[m-1][n-1];
}
int main()
{
	cout << uniquePaths(3, 7) <<endl;

	return 0;
}

