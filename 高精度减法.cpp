
// 比较 A 和 B 的大小
bool cmp(vector<int>& A, vector<int>& B)
{
	// 位数不一致
	if(A.size() != B.size())    
		return A.size() > B.size();

	// 位数一致
	for(int i = A.size()-1; i >= 0; i--)
	if(A[i] != B[i])
		return A[i] > B[i];

	// 完全相同
	return true;
}

// A - B
string sub(vector<int>& A, vector<int>& B)
{
	vector<int> C;

	// A - B
	int t = 0;
	for(int i = 0; i < A.size(); i++)
	{
		t = A[i] - t;
		if(i < B.size()) t -= B[i];
		C.push_back((t + 10) % 10);
		if(t < 0) t = 1;
		else t = 0;
	}

	// 处理高位无效0
	while(C.size() > 1 && C.back() == 0)
		C.pop_back();

	// 将vector变为字符串
	string ans;
	for(int i = C.size()-1; i >= 0; i--)
		ans.push_back(C[i] + '0');

	return ans;
}

// 输入输出处理
string output(string& a, string& b)
{
	// 将字符串变成数组：数据低位在数组低位
	vector<int> A,B;
	for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');
	for(int i = b.size()-1; i >= 0; i--) B.push_back(b[i] - '0');

	// 判断A和B哪一个大，保证总是大的减小的
	string ans;
	if(cmp(A,B))
		ans += sub(A, B);
	else
	{
		ans += '-';
		ans += sub(B, A);
	}

	return ans;
}

