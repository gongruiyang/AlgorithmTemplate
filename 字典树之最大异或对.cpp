const int N = 1e5 + 10;
const int M = 31 * N;   // 31 * 1e5 -> һ������31λ һ����1e5����

int son[M][2];  //һ����M����� һ������� 0 �� 1 �������
int idx = 1;

// ���ڲ����x�����ֵ����й�����·��
void insert(int x)
{
	int p = 0;
	for(int i = 30; i >= 0; i--)
	{
		int u = (x >> i) & 1;
		if(!son[p][u]) son[p][u] = idx++;
		p = son[p][u];
	}
}

// ����x�������ֵ
int search(int x)
{
	int p = 0, res = 0;
	for(int i = 30; ~i; i--)
	{
		int u = (x >> i) & 1;
		if(son[p][!u])  // Ѱ�� x �ĵ� i λ���ڽڵ���ֵܽڵ��Ƿ����
		{
			res += 1 << i;  // ��iλ���Ų�ͬ�����ϸ�λ������ֵ
			p = son[p][!u];
		}
		else p = son[p][u]; // ����iλֻ����ͬ�Ľ�㣬�򲻻������ֵ
	}
	return res;
}

int main()
{
	int n, a[N];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		insert(a[i]);   // ����Tri��
	}

	int res = 0;
	for (int i = 0; i < n; i++)
		res = max(res, search(a[i]));

	cout << res << endl;

	return 0;
}
