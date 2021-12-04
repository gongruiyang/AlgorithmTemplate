
const int N = 1e5 + 10;
/*
le[N] : 保存 下标为N的节点 的 左节点的下标
ri[N] : 保存 下标为N的节点 的 右节点的下标
e[N]  : 保存 下标为N的节点 的 值
idx   : 当前操作的节点
*/
int l[N], r[N], e[N], idx;

void init()
{
	r[0] = 1;
	l[1] = 0;
	idx = 2;
}

// 在节点a的右边插入一个节点
// a <-> x <-> O
void insert(int a, int x)
{
	// 创建新节点
	e[idx] = x;

	// 建立新指针
	l[idx] = a;
	r[idx] = r[a];

	// 修改旧指针
	l[r[a]] = idx;
	r[a] = idx;

	// 更新idx
	idx++;
}

// O <-> a <-> O
void remove(int a)
{
	r[l[a]] = r[a]; // a->le->ri = a->ri
	l[r[a]] = l[a]; // a->ri->le = a->le
}
