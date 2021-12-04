
int prefix(vector<int>& v, int le, int ri)
{
	vector<int> s(v.size() + 1);
	s[0] = 0;	// 前缀和数组首位置0
	// s[i] = s[i-1] + v[i-1]
	for(int i = 1; i < v.size() + 1; i++)
		s[i] = s[i-1] + v[i-1];
	return s[ri] - s[le-1];
}
