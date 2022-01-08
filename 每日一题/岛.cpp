#include <iostream>
#include <algorithm>
using namespace std;

#define height first
#define pos second
const int N = 1e5 + 10;

int n;
typedef pair<int, int> PII;
PII a[N];	// ��� n ����ص� λ�� �� �߶� 
bool vis[N];	// �洢 n ������Ƿ���û��״̬��0��ʾû����û  1��ʾ����û 

int main()
{
	// 1. �� n ����ص� ˳�� �� �߶� ���� a ������ȥ 
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int h;
		cin >> h;
		a[i].pos    = i;
		a[i].height = h;
	}
	// 2. ���ո߶����򣺵��ݵ���ǰ�� 
	sort(a, a + n);
	
	int ans = 1, cnt = 1;
	for(int i = 0; i < n; i++)
	{
		// ����ǰλ�� cur ���������û
		int cur = a[i].pos;
		vis[cur] = 1;
		// �ж� cur ���ߵ���û״̬��δ����û��״̬ -> true 
		bool le = ((cur - 1 >= 0) && !vis[cur - 1]);
		bool ri = ((cur + 1 <  n) && !vis[cur + 1]);
		if(le && ri) cnt ++;	// ��û����û 
		else if(!le && !ri) cnt --;	// ������û
		// �ж��Ƿ���Ҫ���� ans : ֮������Ҫ�ж�����Ϊ��ֹ��������������ͬ�߶ȵ���� 
		if(i == n - 1 || a[i].height != a[i+1].height)
			ans = max(ans, cnt); 
	}
	
	cout << ans << endl;
	
	return 0;
}
