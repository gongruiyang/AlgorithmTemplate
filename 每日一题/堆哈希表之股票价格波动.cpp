#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

class StockPrice {
public:
    int cur;            // ��¼����ʱ����е����ֵ
    map<int, int> hash; // ���� <ʱ�� : �۸�> ӳ��
    multiset<int> ms;   // �ײ����������ղ���ֵ��������
    
    StockPrice() 
    {
        cur = 0;
    }
    
    void update(int t, int p) 
    {
        // ά�� cur һֱ����ʱ������ֵ
        cur = max(cur, t);
        if(hash.count(t))
        {
            // �� ms �ж�Ӧ t ֮ǰ�ļ۸�ɾ���� 
            int oldprice = hash[t];
            auto pos = ms.find(oldprice);
            ms.erase(pos);
        }
        // ��<t:p>���뵽��ϣ���У� ���µļ۸�����ms��
        ms.insert(p);
        hash[t] = p;
    }
    
    int current() 
    {
        return hash[cur];
    }
    
    int maximum() 
    {
        return *ms.rbegin();
    }
    
    int minimum() 
    {
        return *ms.begin();
    }
};

int main()
{


	return 0;
}

