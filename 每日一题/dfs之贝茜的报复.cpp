#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

unordered_map<char, int> odd;		// <��ĸ : ż������> 
unordered_map<char, int> uneven;	// <��ĸ : ��������>
unordered_map<char, int> a;			// <��ĸ : ��ֵ> 
const string S = "BESIGOM";
int ans, n;
// ���ʽ����(B + I)*(G + O + E + S)*(M) 
// key : ��֤����һ�����ʽΪż������ 
void dfs(int u, int x)
{
	if(u == 7)
	{
		// ���б��ʽ������������� 
		if((a['B'] + a['I']) % 2 && (a['G'] + a['O'] + a['E'] + a['S']) % 2 && a['M'] % 2)
			return ;
		// ���ڱ��ʽΪż�������
		ans += x;
		return ; 
	}
	char ch = S[u];
	a[ch] = 1;	// ö��������� 
	dfs(u + 1, x * uneven[ch]);	 
	a[ch] = 2;	// ö��ż����� 
	dfs(u + 1, x * odd[ch]);
}

int main()
{
	cin >> n;
	while(n --)
	{
		char c;
		int x;
		cin >> c >> x;
		if(x % 2) uneven[c] ++;
		else odd[c] ++;
	}
	dfs(0, 1);
	cout << ans << endl;
	
	return 0;
}

