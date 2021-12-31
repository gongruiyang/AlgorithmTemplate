#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-6;
const int N = 110;

double a[N][N];
int n;

int gauss()
{
	int col, row;
	for(col = 0, row = 0; col < n; col ++)
	{
		// 寻找最大行 t 
		int t = row;
		for(int i = row; i < n; i++)
			if(fabs(a[i][col]) > fabs(a[t][col]))
				t = i;

		if(fabs(a[t][col]) < eps) continue;
		
		// 将第 t 行与第 row 行交换  
		for(int i = col; i <= n; i ++) swap(a[t][i], a[row][i]);
		// 将第 row 行第一个数消成 1 
		for(int i = n; i >= col; i --) a[row][i] /= a[row][col];
		// 将第 row 行下面的数消成 0
		for(int i = row + 1; i < n; i++)
			if(fabs(a[i][col]) > eps)
			{
				for(int j = n; j >= col; j--)
					a[i][j] -= a[row][j] * a[i][col];	
			} 
		row ++;
	}
	if(row < n)
	{
		for(int i = row; i < n; i ++)
			if(fabs(a[i][n]) > eps)
				return 0;
		return 2;
	}
	// 从下往上求解 
	for(int i = n - 1; i >= 0; i --)
		for(int j = i + 1; j < n; j ++)
			a[i][n] -= a[j][n] * a[i][j];
	
	return 1;	// 有唯一解 
}

int gaussXOR()
{
	int col, row;
	for(col = 0, row = 0; col < n; col ++)
	{
		// 寻找最大行 t 
		int t = row;
		for(int i = row; i < n; i++)
			if(a[i][col])
			{
				t = i;
				break;
			}

		if(!a[t][col]) continue;
		
		// 将第 t 行与第 row 行交换  
		for(int i = col; i <= n; i ++) swap(a[t][i], a[row][i]);
		// 将第 row 行下面的数消成 0
		for(int i = row + 1; i < n; i++)
			if(a[i][col])
			{
				for(int j = n; j >= col; j--)
					a[i][j] ^= a[row][j];	
			} 
		row ++;
	}
	if(row < n)
	{
		for(int i = row; i < n; i ++)
			if(a[i][n])
				return 0;
		return 2;
	}
	// 从下往上求解 
	for(int i = n - 1; i >= 0; i --)
		for(int j = i + 1; j < n; j ++)
			a[i][n] ^= a[j][n] & a[i][j];
	
	return 1;	// 有唯一解 
}


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n + 1; j++)
			cin >> a[i][j];
			
	int t = guass();
	
	if(t == 0)
		cout << "No solution" << endl;
	else if(t == 1)
		for(int i = 0; i < n; i++) printf("%.2lf\n", a[i][n]);
	else if(t == 2)
		cout << "Infinite group solutions" << endl;
	
	return 0;
}
