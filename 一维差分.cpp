
const int N = 100010;
int m, n;
int a[N],b[N];

int main()
{
	cin >> n >> m;

	// ��ȡ����
	for(int i = 1; i <= n; i++)	scanf("%d", &a[i]);

	// ����������
	for(int i = 1; i <= n; i++) b[i] = a[i] - a[i-1];

	// �Բ��������в������
	while(m--)
	{
		int le, ri, c;
		cin >> le >> ri >> c;
		b[le] += c;
		b[ri+1] -= c;
	}

	// ���� �޸Ĺ���Ĳ������b ���� �µ�ǰ׺������a
	for(int i = 1; i <= n; i++) a[i] = a[i-1] + b[i];

	for(int i = 1; i <= n; i++) printf("%d ", a[i]);

	return 0;
}
