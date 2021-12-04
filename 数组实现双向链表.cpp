
const int N = 1e5 + 10;
/*
le[N] : ���� �±�ΪN�Ľڵ� �� ��ڵ���±�
ri[N] : ���� �±�ΪN�Ľڵ� �� �ҽڵ���±�
e[N]  : ���� �±�ΪN�Ľڵ� �� ֵ
idx   : ��ǰ�����Ľڵ�
*/
int l[N], r[N], e[N], idx;

void init()
{
	r[0] = 1;
	l[1] = 0;
	idx = 2;
}

// �ڽڵ�a���ұ߲���һ���ڵ�
// a <-> x <-> O
void insert(int a, int x)
{
	// �����½ڵ�
	e[idx] = x;

	// ������ָ��
	l[idx] = a;
	r[idx] = r[a];

	// �޸ľ�ָ��
	l[r[a]] = idx;
	r[a] = idx;

	// ����idx
	idx++;
}

// O <-> a <-> O
void remove(int a)
{
	r[l[a]] = r[a]; // a->le->ri = a->ri
	l[r[a]] = l[a]; // a->ri->le = a->le
}
