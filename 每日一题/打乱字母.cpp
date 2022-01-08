#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;


// names 存储原名字顺序 		     但是 名字中字母按照升序排列
// up    存储按照名字首字母升序排列，但是 名字中字母按照升序排列 
// down  存储按照名字首字母升序排列，但是 名字中字母按照降序排列 
vector<string> names, up, down;
int n;
int main()
{
	cin >> n;
	while(n--)
	{
		string s;
		cin >> s;
		
		// 将 s 按照每个字母 升序排列
		sort(s.begin(), s.end());
		names.push_back(s);
		up.push_back(s);
		
		// 将 s 按照每个字母 降序排列
		reverse(s.begin(), s.end());
		down.push_back(s);

	}
    
    // 按照 每个字符串的起始字符 升序排列
    sort(up.begin(), up.end());
    sort(down.begin(), down.end());
    
    for(auto& s : names)
    {
    	// 此时 s 中字母按照升序排列，在在大字典序中找左边界，+1因为输出顺序从1开始 
    	int le = lower_bound(down.begin(), down.end(), s) - down.begin() + 1;
    	reverse(s.begin(), s.end());
    	// 此时 s 中字母按照降序排列，在小字典序中找右边界，-1表示要找>=的位置 +1因为输出顺序从1开始 
    	int ri = upper_bound(up.begin(), up.end(), s) - up.begin() - 1 + 1;
		cout << le << ' ' << ri << endl;
	}
    
    return 0;
}
