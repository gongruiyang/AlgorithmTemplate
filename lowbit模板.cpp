
int lowbit(int x)
{
	return x & (-x);
}
int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int x;
		cin >> x;
		int ans = 0;
		while(x)
		{
			x -= lowbit(x);
			ans++;
		}
		cout << ans << ' ';
	}

	return 0;
}
