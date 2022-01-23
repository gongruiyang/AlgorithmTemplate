#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector> 
#include <unordered_map> 
using namespace std;


// �������� 
vector<int> topKFrequent(vector<int>& nums, int k) 
{
	// ���� <nums : cnts> ӳ�� 
	unordered_map<int, int> cnt;
	for(auto x : nums) cnt[x] ++;
	
	// s[c] = i : ���� c �ε��� i ���� 
	int n = nums.size();
	vector<int> s(n + 1);
	for(auto [x, c] : cnt) s[c] ++;
	
	//	�ҵ����ִ�������ǰ k ������Ƶ�ʷֽ��� i 
	int i = n, t = 0;
	while(t < k)
	{
		t += s[i];
		i --;	
	} 
	
	// ������Ƶ�ʴ��� i ��ȫ�����뵽����
	vector<int> res;
	for(auto [x, c] : cnt)
		if(c > i) res.push_back(x);
	return res; 
}

int main()
{


	return 0;
}

