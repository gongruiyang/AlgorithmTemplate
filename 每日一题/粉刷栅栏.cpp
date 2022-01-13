#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	// 1. ������ map 
	map<int, int> hash;
	int cur = 0;	// ���ڼ�¼��ǰ�ߵ����� 
	for(int i = 0; i < n; i ++)
	{
		int steps;
		char dir;
		cin >> steps >> dir;
		if(dir == 'R')	// ����������[cur, cur + steps]
			hash[cur] += 1, hash[cur + steps + 1] -= 1, cur += steps;
		else 			// ����������[cur - steps, cur]
			hash[cur - steps] += 1, hash[cur + 1] -= 1, cur -= steps;
	}
	
	// 2. ����ǰ׺������
	int nums = 0;	// ���ڼ�¼��ǰλ��������� 
	int ans = 0;	// ���ڼ�¼���з�����������ĳ���֮�� 
	int le;	//���ڼ�¼ÿһ�����������������߽� 
	for(auto e : hash)
	{
		int k = e.first;
		int change = e.second;
		
		if(nums <= 1 && nums + change >= 2) 	// nums�� <2 ��� >=2 ˵���������µ��������߽磬�����������߽�Ϊ k 
			le = k;
		else if(nums >= 2 && nums + change <= 1) // nums�� >=2 ��� <2 ˵���������µ�������ұ߽磬����������ұ߽�Ϊ k - 1 
			ans += k - 1 - le;	// ����������[le, k-1]������εĳ��� 
	
		nums += change;	// ���� nums 
	}
	cout << ans << endl;

	return 0;	
}
