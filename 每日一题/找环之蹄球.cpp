#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; 
	cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    sort(a.begin(), a.end());
	
	// 判断每个点传球方向：向右传：0，向左传：1
	vector<int> edge(n, 0);  
    edge[n - 1] = 1; //最后一个一定向左传球
    for(int i = 1; i < n - 1; i++)
        if(a[i] - a[i - 1] <= a[i + 1] - a[i]) 
			edge[i] = 1; //i向左传球

	int ans = 0; 
    for(int i = 0; i < n; i++)
        if(edge[i] == 1 && edge[i - 1] == 0) 	//遇到环 i-1 <-> i
		{
            ans++; //一个球
            // 环位于中间 i-2 -> i-1 <-> i <- i+1 
            if(i >= 2 && i < n - 1 && edge[i - 2] == 0 && edge[i + 1] == 1) 
				ans++; //两个球
        }
    cout << ans << endl;
    return 0;
}

