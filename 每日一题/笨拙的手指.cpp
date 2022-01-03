#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;
LL res;	// 存答案 

// 将 2进制字符串a 转化为 3进制字符串c 
string two2Three(string a)
{
	//	2进制a 转换到 10进制tmp
	LL tmp = 0;
	for(int i = a.size() - 1; i >= 0; i--)
	{
		tmp += (a[i] - '0') * pow(2, a.size() - i - 1);
	}
	// 10进制tmp 转换到 3进制c
	string c;
	while(tmp)
	{
		LL bit = tmp % 3;
		if(bit)
		{
			c += bit + '0';
			tmp -= bit;
			tmp /= 3;
		}
		else
		{
			c += '0';
			tmp /= 3;
		}
	}
	reverse(c.begin(), c.end());
	return c;
}
// 判断两个 3进制字符串 中是否只有 1 位不一样 
bool judge(string b, string c)
{
	int n = b.size(), m = c.size();
	if(m != n) return false;
	
	int nums = 0;
	for(int i = 0; i < n; i++)
	{
		if(b[i] != c[i]) nums++;
		if(nums > 1) return false;
	}
	return nums == 1;
}
// 将 3进制字符串c 转换为 10进制ans 
LL toAns(string c)
{
	LL ans = 0;
	for(int i = c.size() - 1; i >= 0; i--)
	{
		ans += (c[i] - '0') * pow(3, c.size() - i - 1);
	}
	return ans;
}

int main()
{
	string a, b;
	cin >> a >> b;
	
	for(int i = 0; i < a.size(); i ++)
	{
		string c;
		if(a[i] == '0')
		{
			a[i] = '1';
			c = two2Three(a);
			a[i] = '0';
		}
		else
		{
			a[i] = '0';
			c = two2Three(a);
			a[i] = '1';
		}
		if(judge(b, c))	// true 表示 c 和 b 只有 1 位不一样 
		{
			res = toAns(c);
			break;
		}
	}

	cout << res << endl;
	return 0;	
} 

