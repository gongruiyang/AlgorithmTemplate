#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 10;
int n, ans;
bool vis[N][N]; // �����жϸ����Ƿ��߹�
char g[N][N];   // �洢��ͼ
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

// le : ����������  ri : ����������
void dfs(int x, int y, int le, int ri)
{
	if(le != 0 && le == ri)
	{
		ans = max(ans, le);
		return ;
	}
	for(int i = 0; i < 4; i++)	// �����ĸ����� 
	{
		// ��ȡ���������ĵ����� 
		int a = x + dx[i], b = y + dy[i]; 
		/* �жϺϷ��ԣ�
			1. �㲻�ܳ���ͼ 
			2. �㲻�ܱ������� 
			3. ri>0˵���Ѿ���ʼ�����������ˣ����������������Ӧ�ú��Ե�ǰ���� 
		*/ 
		if(a < 1 || b < 1 || a > n || b > n || vis[a][b] || (ri > 0 && g[a][b] == '(')) continue;	
		
		// DFS + ����
		vis[a][b] = 1;
		if(g[a][b] == '(') 	dfs(a, b, le + 1, ri);
		else 				dfs(a, b, le, ri + 1);
		vis[a][b] = 0;
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> g[i] + 1;
		
	// ��ʼλ�ñ���Ϊ������
	if(g[1][1] == ')')
	{
		cout << ans << endl;
		return 0;
	}
	
	vis[1][1] = 1;
	dfs(1, 1, 1, 0);
	
	cout << ans * 2 <<endl; 
	return 0;
}

