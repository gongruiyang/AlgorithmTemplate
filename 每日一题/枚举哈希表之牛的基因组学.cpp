#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 110;
const string gins = "AGCT";
int n, m;
char a[N][N], b[N][N];

int main()
{
	cin >> n >> m; 
	for(int i = 0; i < n; i ++) cin >> a[i];
	for(int i = 0; i < n; i ++) cin >> b[i];
	
	int res = 0;
	// ö��ÿһλ���� 
	for(int i = 0; i < m; i ++)
	{
		// ���ߵ�ţ�ĵ� i �л�������ϣ���� 
		bool hash[4] = {};
		for(int j = 0; j < n; j ++)
			hash[gins.find(a[j][i])] = true;
		
		// �ж���ͨţ�Ļ����Ƿ��ڹ�ϣ���г���
		bool flag = true;
		for(int j = 0; j < n; j ++)
			if(hash[gins.find(b[j][i])]) 
				flag = false;
		// ���������û�н��������ʾ�ҵ�һ�з������� 
		if(flag) res ++;
	}
	
	cout << res << endl;

	return 0;
}

