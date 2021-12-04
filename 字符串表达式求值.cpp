
stack<int> num;
stack<char> op;

// 使用末尾的运算符计算末尾的两个值
void eval()
{
	int b = num.top(); num.pop();
	int a = num.top(); num.pop();
	char c = op.top(); op.pop();
	int x;
	if (c == '+')      x = a + b;
	else if (c == '-') x = a - b;
	else if (c == '*') x = a * b;
	else              x = a / b;
	num.push(x);
}

int expToNum(string str)
{
	unordered_map<char, int> pr{ { '+', 1 }, { '-', 1 }, { '*', 2 }, { '/', 2 } };

	for (int i = 0; i < str.size(); i++)
	{
		auto c = str[i];
		if (isdigit(c))
		{   // 将整个数字取出来放入num栈中
			int x = 0, j = i;
			while (j < str.size() && isdigit(str[j]))
				x = x * 10 + str[j++] - '0';
			i = j - 1;
			num.push(x);
		}
		else if (c == '(')
			op.push(c);
		else if (c == ')')
		{   // 先计算()内部的表达式
			while (op.top() != '(')
				eval();
			op.pop();   // 弹出左括号
		}
		else
		{
			// 比较优先级：将前面优先级高的先计算
			while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c])
				eval();
			op.push(c);
		}
	}
	// 将剩余的运算符计算完毕
	while (op.size())
		eval();

	return num.top();
}
