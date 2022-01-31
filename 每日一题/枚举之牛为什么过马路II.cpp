#include <iostream>
#include <bitset> 
using namespace std;

int main()
{
	string s;
	cin >> s;
	
	int ans = 0;
	// ö�� 26 ����ĸ 
	for(int i = 0;i < 26; i ++)
	{
		bitset<32> bits;	// ��¼ A-Z �Ƿ����
		for(char c : s)
		{
			bits[c - 'A'] = bits[c - 'A'] ^ 1;
			if(c - 'A' == i && bits[i] == 1)
				bits = 0, bits[i] = 1;
			if(c - 'A' == i && bits[i] == 0)
				ans += bits.count();	
		}
	}
	cout << ans / 2 << endl;

	return 0;
}

