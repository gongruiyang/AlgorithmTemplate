
string mul(string a, int b)
{
	// 将大数据a处理成vector A
	vector<int> A;
	for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');

	// A * b 后答案存在C中
	vector<int> C;
	int t = 0;
	for(int i = 0; i < A.size() || t; i++)
	{
		if(i < A.size()) 
			t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}

	// 处理高位0
	while(C.size() > 1 && C.back() == 0)
		C.pop_back();

	// 将答案转成字符串
	string ans;
	for(int i = C.size()-1; i >= 0; i--)
		ans.push_back(C[i] + '0');

	return ans;
}

