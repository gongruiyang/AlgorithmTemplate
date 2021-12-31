const int N = 1e5 + 10;
/*
head : 表示头结点的下标，即第一个有效节点的地址（下标）
e[N] : 保存的是节点中的值
ne[N] : 保存的是节点N下一个节点的地址（下标）
idx : 保存当前已经用到了哪个节点
*/
int head, e[N], ne[N], idx;

void init()
{
	head = -1;
	idx = 0;
}

/*  
头插法：
head -> x -> O
[O, x]
*/
void add_to_head(int x)
{
	e[idx] = x;     // 初始化idx中保存的值
	ne[idx] = head;     // 让idx中的next节点更新为head中保存的原先头结点的下标
	head = idx;     // 更新head中保存的头结点下标
	idx++;  // 更新idx
}

// 将x插入到下标是k的节点后边
void add(int k, int x)
{
	e[idx] = x;     // 初始化idx中保存的值
	ne[idx] = ne[k];    // 让 idx节点的next节点 更新为 下标为k的节点的next节点
	ne[k] = idx;    // 更新 下标为k的节点的next节点为idx
	idx++;  // 更新idx
}

// 见下标为 k 的节点后面的点删除
void remove(int k)
{
	ne[k] = ne[ne[k]];  // k->next = k->next->next
}

int main()
{
	int m;
	cin >> m;
	init();
	while (m--)
	{
		char op;
		cin >> op;
		if (op == 'H')
		{
			int x;
			cin >> x;
			add_to_head(x);
		}
		else if (op == 'D')
		{
			int k;
			cin >> k;
			if (k == 0)  //  删除头结点的情况，移动head即可
				head = ne[head];
			else remove(k - 1);   // 由于数组中保存值的下标从 0 开始
		}
		else
		{
			int k, x;
			cin >> k >> x;
			add(k - 1, x);
		}
	}

	for (int i = head; i != -1; i = ne[i])
		cout << e[i] << " ";
	cout << endl;

	return 0;
}
