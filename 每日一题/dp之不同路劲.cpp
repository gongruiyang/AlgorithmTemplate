#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int uniquePaths(int m, int n) 
{
	const int N = 110;
	int a[N][N];
	
	// ��һ�к͵�һ�еĸ��Ӵﵽ��ʽֻ��һ�� 
	for(int i = 0; i < m; i ++) a[i][0] = 1;
	for(int j = 0; j < n; j ++) a[0][j] = 1;
	// �������ӵĵ��﷽ʽ�ֱ����Ϸ����󷽵��﷽ʽ֮�� 
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

