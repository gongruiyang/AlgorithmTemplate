
string mul(string a, int b)
{
	// ��������a�����vector A
	vector<int> A;
	for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');

	// A * b ��𰸴���C��
	vector<int> C;
	int t = 0;
	for(int i = 0; i < A.size() || t; i++)
	{
		if(i < A.size()) 
			t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}

	// �����λ0
	while(C.size() > 1 && C.back() == 0)
		C.pop_back();

	// ����ת���ַ���
	string ans;
	for(int i = C.size()-1; i >= 0; i--)
		ans.push_back(C[i] + '0');

	return ans;
}

