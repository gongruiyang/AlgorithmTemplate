const int N = 1e5 + 10;
const int M = 1e6+10;
int m,n;
char s[M];  // ԭ�ַ���
char p[N];	// ģʽ��
int ne[N];	

int main()
{
	cin >> n >> p + 1 >> m >> s + 1;

	// ����next�������
	for(int i = 2, j = 0; i <= n; i++)
	{
		while(j && p[i] != p[j+1])  
			j = ne[j];
		if(p[i] == p[j+1]) j++;
		ne[i] = j;
	}
	/*
	for(int i = 2; i <= n; i++)
	{
		int now = ne[i-1];
		while(now && p[now+1] != p[i])
			now = ne[now];
		if(p[now+1] == p[i])
			ne[i] = now+1;
	}
	*/
	// kmpƥ�����
	for(int i = 1, j = 0; i <= m; i++)
	{
		// �жϵ�ǰ�ַ�s[i]�Ƿ���p[j+1]ƥ��
		while(j && s[i] != p[j+1]) 
			j = ne[j];  // ����ƥ����������
		if(s[i] == p[j+1])  // ƥ��ɹ���ǰ�ַ� 
			j++;
		if(j == n)
		{   // ����ģʽ����ƥ��ɹ�
			cout << i - n << " ";
			j = ne[j];
		}
	}

	return 0;
}
