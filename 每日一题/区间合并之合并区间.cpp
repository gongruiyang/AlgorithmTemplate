#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

// ����ϲ�ģ���� 
vector<vector<int>> merge(vector<vector<int>>& a)
{
	if(a.empty()) return {};
	
 	vector<vector<int>> res;
	sort(a.begin(), a.end());
	// ά������ [le, ri] 
	int le = a[0][0], ri = a[0][1];
	for(int i = 1; i < a.size(); i ++)
	{
		if(a[i][0] > ri)	
		{
			// ��ǰ����[a[i][0], a[i][1]]������ά��������[le,ri]û�н��� 
			res.push_back({le, ri});
			le = a[i][0], ri = a[i][1];
		}
		else	// �н��� 
			ri = max(ri, a[i][1]);
	} 
	res.push_back({le, ri});
	return res;
}

int main()
{


	return 0;
}

