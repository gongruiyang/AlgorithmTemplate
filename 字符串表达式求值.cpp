
stack<int> num;
stack<char> op;

// ʹ��ĩβ�����������ĩβ������ֵ
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
		{   // ����������ȡ��������numջ��
			int x = 0, j = i;
			while (j < str.size() && isdigit(str[j]))
				x = x * 10 + str[j++] - '0';
			i = j - 1;
			num.push(x);
		}
		else if (c == '(')
			op.push(c);
		else if (c == ')')
		{   // �ȼ���()�ڲ��ı��ʽ
			while (op.top() != '(')
				eval();
			op.pop();   // ����������
		}
		else
		{
			// �Ƚ����ȼ�����ǰ�����ȼ��ߵ��ȼ���
			while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c])
				eval();
			op.push(c);
		}
	}
	// ��ʣ���������������
	while (op.size())
		eval();

	return num.top();
}
