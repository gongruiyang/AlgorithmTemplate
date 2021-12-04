
string add(string& a, string& b)
{
	// 1. ���ַ��������������У��� ���ݵ�λ ��������� ������λ ��
	vector<int> A, B;
	for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');
	for(int i = b.size()-1; i >= 0; i--) B.push_back(b[i] - '0');

	// 2. ��������а�λ��ͣ�������C������
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

	// 3. ��C���鴦����ַ����������� �Ӹ�λ����λ ���ַ����в���
	string ans;
	for (int i = C.size() - 1; i >= 0; i--)
		ans.push_back(C[i] + '0');

	return ans;
}

