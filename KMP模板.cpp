const int N = 1e5 + 10;
const int M = 1e6+10;
int m,n;
char s[M];  // 原字符串
char p[N];	// 模式串
int ne[N];	

int main()
{
	cin >> n >> p + 1 >> m >> s + 1;

	// 构造next数组过程
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
	// kmp匹配过程
	for(int i = 1, j = 0; i <= m; i++)
	{
		// 判断当前字符s[i]是否与p[j+1]匹配
		while(j && s[i] != p[j+1]) 
			j = ne[j];  // 若不匹配则往后退
		if(s[i] == p[j+1])  // 匹配成功当前字符 
			j++;
		if(j == n)
		{   // 整个模式串都匹配成功
			cout << i - n << " ";
			j = ne[j];
		}
	}

	return 0;
}
