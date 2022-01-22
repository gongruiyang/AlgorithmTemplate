#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

class Trie 
{
public:
	struct Node
	{
		Node* son[26];
		bool is_end;	
		Node()
		{
			// 将26个子节点初始化
			for(int i = 0; i < 26; i ++) son[i] = NULL;
			is_end = false; 
		}
	}*root; 
	
    Trie() 
	{
		root = new Node();
    }
    
    void insert(string word) 
	{
		auto p = root;
		for(auto c : word)
		{
			int u = c - 'a';
			if(!p->son[u])
				p->son[u] = new Node();
			p = p->son[u];
		}
		p->is_end = true;
    }
    
    bool search(string word) 
	{
		auto p = root;
		for(auto c : word)
		{
			int u = c - 'a';
			if(!p->son[u]) return false;
			p = p->son[u];
		}
		return p->is_end;
    }
    
    bool startsWith(string prefix) 
	{
		auto p = root;
		for(auto c : prefix)
		{
			int u = c - 'a';
			if(!p->son[u]) return false;
			p = p->son[u];
		}
		return true;
    }
};
int main()
{


	return 0;
}

