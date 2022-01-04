#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

/*
	Flood Fill \ DFS \ BFS \ ö�� 
*/ 
#define x first
#define y second
typedef pair<int, int> PII;
const int N = 55;
int n, m;
char g[N][N];	// ���ͼ 
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};	// ������������ 

void bfs(int sx, int sy, vector<PII>& v)
{
	queue<PII> q;
	/* 
	��ʼ��״̬��
		1. ���õ�[sx, sy]��������� 
		2. ���õ�[sx, sy]����Ϊ�Ѿ������� X-> . 
		3. ���õ�[sx, sy]����v�� 
	*/ 
	g[sx][sy] = '.';
	q.push({sx, sy});
	v.push_back({sx, sy});
	// ʹ�ö��н��� BFS 
	while(!q.empty())
	{
		PII t = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++)	// ö�� 4 �������������� 
		{
			int x = t.x + dx[i], y = t.y + dy[i];
			// �жϵ�ǰ�� [x, y] �Ƿ�Ϊ X 
			if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '.') continue;	// ���� X ����Ըõ� [x, y] 
			/*
			��[x, y]�� X ��������õ㣺 
				1. ���õ�[sx, sy]��������� 
				2. ���õ�[sx, sy]����Ϊ�Ѿ������� X-> . 
				3. ���õ�[sx, sy]����v�� 
			*/ 
			g[x][y] = '.';
			q.push({x, y});
			v.push_back({x, y});
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> g[i];
	// 1. ��������ͨ���е����е�ֱ�������������� 
	vector<PII> v1, v2;	// �洢ÿ����ͨ���е����е�
	bool flag = true;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			if(g[i][j] == 'X' && flag) // ��¼��һ����ͨ�� 
			{	
				bfs(i, j, v1);
				flag = false;
			}
			else if(g[i][j] == 'X' && !flag) // ��¼�ڶ�����ͨ�� 
				bfs(i, j, v2);
		} 
	
	// 2. ����2����ͨ�����ö�٣�Ѱ��������ͨ���е���̾���
	int res = 1e9;
	for(int i = 0; i < v1.size(); i ++)
		for(int j = 0; j < v2.size(); j ++) 
		{
			int x1 = v1[i].x, y1 = v1[i].y;
			int x2 = v2[j].x, y2 = v2[j].y;
			res = min(res, abs(x1 - x2) + abs(y1 - y2));
		}
		
	cout << res - 1 << endl;	// ��ĸ��� = �ߵĸ��� - 1 

	return 0;
}

