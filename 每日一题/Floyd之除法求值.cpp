#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set> 
#include <unordered_map>
#include <vector>
using namespace std;

vector<double> calcEquation(vector<vector<string>>& equations, 
                            vector<double>& values, 
                            vector<vector<string>>& queries) 
{
    unordered_set<string> vers; // 存节点 
    unordered_map<string, unordered_map<string, double>> d;	// 存每两个点之间的距离 
	// 枚举所有的方程
	for(int i = 0; i < equations.size(); i ++)
	{
		// 从 a 指向 b 的距离是 c 
		auto a = equations[i][0], b = equations[i][1];
		auto c = values[i];
		d[a][b] = c, d[b][a] = 1 / c;
		vers.insert(a), vers.insert(b); 
	} 
	
	// Floyd
	for(auto k : vers)
		for(auto i : vers)
			for(auto j : vers)
				if(d[i][k] && d[k][j])
					d[i][j] = d[i][k] * d[k][j];
	
	// 枚举每个询问 检查是否存在路径 
	vector<double> res;
	for(auto q : queries)
	{
		auto a = q[0], b = q[1];
		if(d[a][b]) res.push_back(d[a][b]);
		else res.push_back(-1); 
	}			
	 
	return res;
}

int main()
{
	vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
	vector<double> values = {2.0, 3.0};
	vector<vector<string>> queries = {{"a","c"}, {"b","a"}, {"a","e"},
	{"a","a"}, {"x","x"}};
	
	auto res = calcEquation(equations, values, queries);
	for(auto e : res) cout << e << ' ';

	return 0;
}

