#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

class StockPrice {
public:
    int cur;            // 记录所有时间戳中的最大值
    map<int, int> hash; // 保存 <时间 : 价格> 映射
    multiset<int> ms;   // 底层红黑树，按照插入值升序排列
    
    StockPrice() 
    {
        cur = 0;
    }
    
    void update(int t, int p) 
    {
        // 维护 cur 一直保存时间戳最大值
        cur = max(cur, t);
        if(hash.count(t))
        {
            // 将 ms 中对应 t 之前的价格删除掉 
            int oldprice = hash[t];
            auto pos = ms.find(oldprice);
            ms.erase(pos);
        }
        // 将<t:p>插入到哈希表中， 将新的价格插入的ms中
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

