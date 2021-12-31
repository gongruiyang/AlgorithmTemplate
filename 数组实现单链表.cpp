const int N = 1e5 + 10;
/*
head : ��ʾͷ�����±꣬����һ����Ч�ڵ�ĵ�ַ���±꣩
e[N] : ������ǽڵ��е�ֵ
ne[N] : ������ǽڵ�N��һ���ڵ�ĵ�ַ���±꣩
idx : ���浱ǰ�Ѿ��õ����ĸ��ڵ�
*/
int head, e[N], ne[N], idx;

void init()
{
	head = -1;
	idx = 0;
}

/*  
ͷ�巨��
head -> x -> O
[O, x]
*/
void add_to_head(int x)
{
	e[idx] = x;     // ��ʼ��idx�б����ֵ
	ne[idx] = head;     // ��idx�е�next�ڵ����Ϊhead�б����ԭ��ͷ�����±�
	head = idx;     // ����head�б����ͷ����±�
	idx++;  // ����idx
}

// ��x���뵽�±���k�Ľڵ���
void add(int k, int x)
{
	e[idx] = x;     // ��ʼ��idx�б����ֵ
	ne[idx] = ne[k];    // �� idx�ڵ��next�ڵ� ����Ϊ �±�Ϊk�Ľڵ��next�ڵ�
	ne[k] = idx;    // ���� �±�Ϊk�Ľڵ��next�ڵ�Ϊidx
	idx++;  // ����idx
}

// ���±�Ϊ k �Ľڵ����ĵ�ɾ��
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
			if (k == 0)  //  ɾ��ͷ����������ƶ�head����
				head = ne[head];
			else remove(k - 1);   // ���������б���ֵ���±�� 0 ��ʼ
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
