vector<string> split(string& s, char ch)
{
	vector<string> ans;
	int n = s.size();
	string tmp;
	for (int i = 0; i < n; i++)
	{
		// ˫ָ��ģ��
		int j = i;
		while (j < n && s[j] != ch) j++;

		// ��Ŀ�����߼�
		//for (int k = i; k < j; k++)
		//	tmp.push_back(s[k]);
		tmp = s.substr(i, j - i + 1);
		ans.push_back(tmp);
		tmp.clear();
		i = j;
	}
	return ans;
}
