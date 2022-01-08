#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;


// names �洢ԭ����˳�� 		     ���� ��������ĸ������������
// up    �洢������������ĸ�������У����� ��������ĸ������������ 
// down  �洢������������ĸ�������У����� ��������ĸ���ս������� 
vector<string> names, up, down;
int n;
int main()
{
	cin >> n;
	while(n--)
	{
		string s;
		cin >> s;
		
		// �� s ����ÿ����ĸ ��������
		sort(s.begin(), s.end());
		names.push_back(s);
		up.push_back(s);
		
		// �� s ����ÿ����ĸ ��������
		reverse(s.begin(), s.end());
		down.push_back(s);

	}
    
    // ���� ÿ���ַ�������ʼ�ַ� ��������
    sort(up.begin(), up.end());
    sort(down.begin(), down.end());
    
    for(auto& s : names)
    {
    	// ��ʱ s ����ĸ�����������У����ڴ��ֵ���������߽磬+1��Ϊ���˳���1��ʼ 
    	int le = lower_bound(down.begin(), down.end(), s) - down.begin() + 1;
    	reverse(s.begin(), s.end());
    	// ��ʱ s ����ĸ���ս������У���С�ֵ��������ұ߽磬-1��ʾҪ��>=��λ�� +1��Ϊ���˳���1��ʼ 
    	int ri = upper_bound(up.begin(), up.end(), s) - up.begin() - 1 + 1;
		cout << le << ' ' << ri << endl;
	}
    
    return 0;
}
