#include <iostream>
#include <algorithm>
#include <cstring>
#include <map> 
using namespace std;

const int N = 1e5 + 10;
int f[N], g[N];
int n, m;
int maxLCS;

int minOperations(vector<int>& target, vector<int>& arr) 
{
	// ��ʼ��ȫ�ֱ��� 
	n = target.size(), m = arr.size();
	memset(g, 0x3f3f3f3f, sizeof g);
	
	// �� target ���� value -> idx ��ӳ���ϵ 
	map<int, int> hash;
	for(int i = 0; i < n; i++) hash[target[i]] = i;
	
	// �� target �� arr �еĹ���Ԫ�� x λ�� target �����е��±� dix �������� nums �� 
	vector<int> nums;
	for(int i = 0; i < m; i++)
	{
		int x = arr[i];
		if(hash.count(x))
		{
			int idx = hash[x];
			nums.push_back(idx); 
		} 
	}
	
	// ���� g �� f ���飬����� �LIS �ĳ��� maxLCS 
	int size = nums.size();
	for(int i = 0; i < size; i++)
	{
		// �� g ������Ѱ�� g[idx] < nums[i] �ķָ�� idx
		int le = 0, ri = size; 
		while(le < ri)
		{
			int mid = le + ri + 1 >> 1;
			if(g[mid] < nums[i]) le = mid;
			else ri = mid - 1;
		}
		int idx = ri + 1; 
		f[i] = f[idx] + 1;
		g[idx] = min(g[idx], nums[i]);
		maxLCS = max(maxLCS, idx);
	}
	return n - maxLCS;
}

int main()
{
	vector<int> target = {5,10,8,11,3,15,9,20,18,13};
	vector<int> arr	   = {15,8,2,9,11,20,8,11,7,2};
	cout << minOperations(target, arr); 

	return 0;
}

