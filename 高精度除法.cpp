
// A / b ������������ r
string div(string& a, int b, int& r)
{
	// �����봦������飺���ݸ�λ���������λ
	vector<int> A;
	for(int i = 0; i < a.size(); i++) A.push_back(a[i] - '0');

	// A / b
	vector<int> C;
	int t = 0;
	for(int i = 0; i < a.size(); i++)
	{
		t = t * 10 + A[i];
		C.push_back(t / b);
		t = t % b;
	}

	// ������
	r = t;

	// ����ǰ��0
	reverse(C.begin(), C.end());
	while(C.size() > 1 && C.back() == 0)
		C.pop_back();
	reverse(C.begin(), C.end());

	// �������
	string ans;
	for(int i = 0; i < C.size(); i++)
		ans += C[i] + '0';

	return ans;
}

