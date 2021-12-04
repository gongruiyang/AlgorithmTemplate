
// �Ƚ� A �� B �Ĵ�С
bool cmp(vector<int>& A, vector<int>& B)
{
	// λ����һ��
	if(A.size() != B.size())    
		return A.size() > B.size();

	// λ��һ��
	for(int i = A.size()-1; i >= 0; i--)
	if(A[i] != B[i])
		return A[i] > B[i];

	// ��ȫ��ͬ
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

	// �����λ��Ч0
	while(C.size() > 1 && C.back() == 0)
		C.pop_back();

	// ��vector��Ϊ�ַ���
	string ans;
	for(int i = C.size()-1; i >= 0; i--)
		ans.push_back(C[i] + '0');

	return ans;
}

// �����������
string output(string& a, string& b)
{
	// ���ַ���������飺���ݵ�λ�������λ
	vector<int> A,B;
	for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');
	for(int i = b.size()-1; i >= 0; i--) B.push_back(b[i] - '0');

	// �ж�A��B��һ���󣬱�֤���Ǵ�ļ�С��
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

