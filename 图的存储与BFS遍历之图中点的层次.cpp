#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 1e5+ 10, M = N * 2;
int h[N], e[M], ne[M], idx;
int n, m;
queue<int> q;
int d[N];

void add(int a, int b)  // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int bfs()
{
    d[1] = 0;
    q.push(1);
    while(q.size())
    {
        int t = q.front();
        q.pop();
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(d[j] == -1)
            {
            	// 存储路程 
                d[j] = d[t] + 1;
                q.push(j);
            }
        }
    }
    return d[n];
}

int main()
{
    memset(h, -1, sizeof h);
    memset(d, -1, sizeof d);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs() << endl;
    return 0;
}
