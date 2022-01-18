#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

const int N = 1e3 + 10;
int a[N];
int n; 

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    sort(a + 1, a + 1 + n);

    // ���� <λ�ã�˳��> ӳ��
    map<int, int> m;
    for(int i = 1; i <= n; i ++) m[a[i]] = i;


    int res = 0;
    for(int i = 1; i <= n - 1; i ++)
        for(int j = i + 1; j <= n; j ++)
        {
            // ��λ [j + len, j + 2 * len] �����߶��Ǳ�����
            int len = a[j] - a[i];
            if(m.lower_bound(a[j] + len) == m.end()) continue;  // ���䲻����
            auto le = m.lower_bound(a[j] + len);    // Ѱ�ұ� v[j] + len      С��� ��ֵ
            auto ri = m.upper_bound(a[j] + len * 2);// Ѱ�ұ� v[j] + 2 * len  ��     ��ֵ
            ri --;                                  // Ѱ�ұ� v[j] + 2 * len  С��� ��ֵ
            res += ri->second - le->second + 1;     // ����ǰ���������������
        }
    cout << res << endl;

    return 0;
}
