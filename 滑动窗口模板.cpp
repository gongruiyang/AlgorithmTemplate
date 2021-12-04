const int N = 1e6 + 10;

// a:存储原数组
// q:单调队列，存储窗口中值的下标
int a[N], q[N];

int main()
{
	int n, k;
	cin >> n >> k;

	for(int i = 0; i < n; i++)  
		cin >> a[i];

	// 单调队列：升序
	int head = 0, tail = -1;
	for(int i = 0; i < n; i++)
	{
		// 判断队头是否已经不在窗口中
		if(head <= tail && i - k + 1 > q[head])
			head++;

		// 判断队尾元素若比当前值大则删掉
		while(head <= tail && a[q[tail]] >= a[i])
			tail--;
		// 将当前值下标放入单调队列中
		q[++tail] = i;

		// 当窗口形成时开始输出
		if(i >= k - 1)
			cout << a[q[head]] << " ";
	}

	cout << endl;

	// 单调队列：降序
	head = 0, tail = -1;
	for(int i = 0; i < n; i++)
	{
		// 判断队头是否已经不在窗口中
		if(head <= tail && i - k + 1 > q[head])
			head++;

		// 判断队尾元素若比当前值小则删掉
		while(head <= tail && a[q[tail]] <= a[i])
			tail--;
		// 将当前值下标放入单调队列中
		q[++tail] = i;

		// 当窗口形成时开始输出
		if (i >= k - 1)
			cout << a[q[head]] << " ";
	}
	cout << endl;
	return 0;
}
