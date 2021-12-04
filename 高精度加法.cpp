
string add(string& a, string& b)
{
	// 1. 将字符串处理至数组中：将 数据低位 放在数组的 索引低位 中
	vector<int> A, B;
	for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');
	for(int i = b.size()-1; i >= 0; i--) B.push_back(b[i] - '0');

	// 2. 对数组进行按位求和，放置在C数组中
	vector<int> C;
	int t = 0;
	for(int i = 0; i < A.size() || i < B.size(); i++)
	{
		if(i < A.size()) t += A[i];
		if(i < B.size()) t += B[i];
		C.push_back(t % 10);
		t /= 10;
	}
	if(t) C.push_back(t);

	// 3. 将C数组处理成字符串：将数据 从高位至低位 向字符串中插入
	string ans;
	for (int i = C.size() - 1; i >= 0; i--)
		ans.push_back(C[i] + '0');

	return ans;
}

