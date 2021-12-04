
const int N = 3e5 + 10;
int n, m;
int a[N], s[N];

typedef pair<int, int> PII;
vector<int> alls;
vector<PII> add, query;

int find(int x)
{
	int le = 0, ri = alls.size()-1;
	while(le < ri)
	{
		int mid = le + ri >> 1;
		if(alls[mid] >= x)  ri = mid;
		else le = mid + 1;
	}
	return le + 1;
}

int main()
{
	cin >> n >> m;

	// ���� n ��������ͬʱ���������±���뵽 ��ɢ����alls ��
	for (int i = 0; i < n; i++)
	{
		int x, c;
		cin >> x >> c;
		add.push_back({ x, c });

		alls.push_back(x);
	}

	// ���� m ��ѯ�ʣ�ͬʱ������ѯ���±���뵽 ��ɢ����alls ��
	for (int i = 0; i < m; i++)
	{
		int le, ri;
		cin >> le >> ri;
		query.push_back({ le, ri });

		alls.push_back(le);
		alls.push_back(ri);
	}

	// ����ɢ������������ȥ��
	sort(alls.begin(), alls.end()); // ����
	alls.erase(unique(alls.begin(), alls.end()), alls.end()); //ȥ��

	// �������ֵ����������a��
	for (auto e : add)
	{
		int _x = find(e.first);  //��ȡ x λ�� ��ɢ����alls �е��±� _x
		a[_x] += e.second;  // �����������
	}

	// ����ǰ׺������
	for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

	// ����ѯ��
	for (auto e : query)
	{
		int le = find(e.first), ri = find(e.second);
		cout << s[ri] - s[le - 1] << endl;
	}

	return 0;
}
