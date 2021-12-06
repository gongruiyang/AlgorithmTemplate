#include <iostream>
#include <algorithm>
#include <queue> 
#include <cstring>
using namespace std; 
typedef pair<int, int> PII;

const int N = 1e2 + 10;
int n, m;
int g[N][N];	// ���ڱ����ͼ 
int d[N][N];	// ÿһ�������е����ֱ�ʾ�ߵ���ǰ��������Ҫ�Ĳ��� 
queue<PII> q;	// ʹ�ö�������BFS 
// �������� 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
// ���ڱ���·�� 
PII path[N][N];
vector<PII> bestPath;	// ��������·�� 

int bfs()
{
	memset(d, -1, sizeof d);	// ��ʼ��·��ͼ 
	d[0][0] = 0;	// ���Ͻ�Ϊ��� 
	q.push(make_pair(0, 0));	// ���Ͻǵ�����п�ʼBFS 
	while(!q.empty())
	{
		PII head = q.front();
		q.pop();
		// �����ĸ����� 
		for(int i = 0; i < 4; i++)
		{
			// ��ȡ��ǰ�������� 
			int x = head.first + dx[i], y = head.second + dy[i];
			// �жϵ�ǰλ���Ƿ����� 
			if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
			{
				// �����߱�ʾ������У��������ߵ���ǰλ�����貽�� 
				d[x][y] = d[head.first][head.second] + 1;	// ��ǰ���� = ��һ�����Ӳ��� + 1 
				q.push(make_pair(x, y));
				path[x][y] = head; // ��ʾ�� t �ߵ���ǰ���ӵ� 
			}
		}
	}
	
	// Ѱ�ҵ�����·�� 
	int x = n - 1, y = m - 1;
	while(x || y)
	{
		bestPath.push_back(make_pair(x, y));
		PII lastStep = path[x][y];
		x = lastStep.first, y = lastStep.second;
	} 
	bestPath.push_back(make_pair(0, 0));
	reverse(bestPath.begin(), bestPath.end());
	
	// �����ߵ����½����貽�� 
	return d[n-1][m-1];
}

int main()
{
	cin >> n >> m;
	// ��ʼ����ͼ 
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> g[i][j];
		
	cout << "���ٲ�����" << bfs() << endl;
	cout << "����·����" << endl; 
	for(vector<PII>::iterator step = bestPath.begin(); step != bestPath.end(); step++)
	{
		cout << (*step).first << " " << (*step).second << endl; 
	}
	return 0;
}
