const int N = 1e7 + 10;
int head, tail;
int que[N];

void init(){ head = 0, tail = -1; }
void push(int x){ que[++tail] = x; }
void pop(){ head++; }
bool empty(){ return head > tail; }
int query(){ return que[head]; }

int main()
{
	int m;
	cin >> m;
	init();
	while(m--)
	{
		string op;
		cin >> op;
		int x;
		if(op == "push")
		{
			cin >> x;
			push(x);
		}
		else if(op == "pop")
		{
			pop();
		}
		else if(op == "empty")
		{
			if(empty()) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else cout << query() << endl;
	}

	return 0;
}
