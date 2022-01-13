#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

    string add(string x, string y)
    {
        vector<int> A,B,C;
        for(int i = x.size() - 1; i >= 0; i --) A.push_back(x[i] - '0');
        for(int i = y.size() - 1; i >= 0; i --) B.push_back(y[i] - '0');
        for(int i = 0, t = 0; i < A.size() || i < B.size() || t; i ++)
        {
            if(i < A.size()) t += A[i];
            if(i < B.size()) t += B[i];
            C.push_back(t % 10);
            t /= 10;
        }
        string res;
        for(int i = C.size() - 1; i >= 0; i --)  res += to_string(C[i]);
        return res;
    }
    vector<int> splitIntoFibonacci(string num) 
    {
        vector<string> tmp;
        for(int i = 0; i < num.size(); i ++)
            for(int j = i + 1; j + 1 < num.size(); j ++)
            {
                int a = -1, b = i, c = j;
                if(b - a >= 10 || c - b >= 10)
                {
                	cout << b - a << ' ' << c - b << endl;
                	return {};
				}
                tmp.clear();
                tmp.push_back(num.substr(a + 1, b - a));
                tmp.push_back(num.substr(b + 1, c - b));
                while(true)
                {
                    if(b-a > 1 && num[a+1] == '0' || c-b > 1 && num[b+1] == '0') break;
                    auto x = num.substr(a + 1, b - a), y = num.substr(b + 1, c - b);
                    auto z = add(x, y);
                    if(num.substr(c + 1, z.size()) != z) break;
                    tmp.push_back(z);
                    a = b, b = c, c += z.size();
                    if(c + 1 == num.size())
                    {
                        int n = tmp.size();
                        vector<int> ans(n);
                        for(int k = 0; k < n; k ++)
                        {
                            ans[k] = stol(tmp[k]);
                            cout << "-" << endl;
                            if(ans[k] > INT_MAX || ans[k] < 0) return {};
                        }
                        return ans;
                    }
                }
            }
        return {};
    }

int main()
{
	splitIntoFibonacci("31326395158253411");

	return 0;
}

