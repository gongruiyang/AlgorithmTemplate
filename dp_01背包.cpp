#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#if 0
const int N = 1010;
int n, m;
int v[N], w[N];
int f[N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i ++ )
    	for (int j = m; j >= v[i]; j -- )
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;

    return 0;
}

#endif

#if 1 // 二维 

const int N = 1e3 +10;
int n, m;
int v[N], w[N];
int f[N][N]; // f[0][0 ~ m] 应该是 0 

int main()
{
	cin >> n >> m; 
	for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	
	for(int i = 1; i <= n; i ++)
		for(int j = 0; j <= m; j ++)
		{
			f[i][j] = f[i - 1][j];
			if(j >= v[i])
				f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]); 
		} 

	cout << f[n][m] << endl;

	return 0;
}

#endif 
