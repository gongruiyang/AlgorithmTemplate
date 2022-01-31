#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// ���� 
void solution1()
{
	int n, ans = 0;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	
	sort(a.begin(), a.end());
	
	for(auto i = a.begin(); i != a.end(); i ++)
	{
		auto le = i, ri = i;	// ����ÿһ��������������쵽�����ұ߽� 
		int tle = 1, tri = 1;	// ��ը�뾶
		// Ѱ�� ���ڵ���  *le - tle �ı߽� le 
		while(lower_bound(a.begin(), le, *le - tle) != le)
		{
			// ÿ�ζ���������߽�Ĳݶ� 
			le = lower_bound(a.begin(), le, *le - tle);
			tle ++;	 
		}
		// Ѱ�� С�ڵ���  *ri + tri �ı߽� ri 
		while(--upper_bound(ri, a.end(), *ri + tri) != ri)
		{
			// ÿ�ζ��������ұ߽�Ĳݶ� 
			ri = --upper_bound(ri, a.end(), *ri + tri);
			tri ++;
		}
		// ��ȡ������ǰ������Χ 
		ans = max(ans, (int)(ri - le + 1));
	}
	cout << ans << endl;	
}

// BFS
void solution2()
{	
	int n, ans = 0;
	cin >> n;
	vector<int> a(n);
	unordered_map<int, int> hash; // <��xi : ״̬> 
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
		hash[a[i]] = -1;	// ��ʼ״̬����Ϊ -1 
	}
	
	// ö��ÿһ���� 
	for(int i = 0; i < n; i ++)
	{
		auto copy = hash;	// ���� hash �� 
		copy[a[i]] = 1; 	// ����ǰ�� i ��������Ϊ��ʼ������ 
		
		queue<int> q;
		q.push(a[i]);
		int num = 0; //������¼��ǰ��������������ٸ���
		while(q.size())
		{
			int t = q.front();	// ��ǰ������ 
			q.pop();
			num ++;
			
			// ���� [t - copy[t], t + copy[t]] ��Χ�ڵĵ� 
			for(int k = -copy[t]; k <= copy[t]; k ++)
			{
				if(copy[t + k] == -1)	// �� t + k �㻹δ�������������� 
				{
					q.push(t + k);
					// ��ǰ��������뾶Ϊ��һ����İ뾶 + 1 
					copy[t + k] = copy[t] + 1;
				} 
			}
		} 
		ans = max(ans, num); 
	} 
	cout << ans << endl;
} 

int main()
{
	solution2();

	return 0;
}

