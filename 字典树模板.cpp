const int N = 1e5 + 10;

int son[N][26]; // 每个结点最多有26个子节点（26个小写英文字母）
int cnt[N];     //以当前结点结尾的单词有多少个
int idx = 1;        // 当前用到的下标，idx为0时表示根结点，根结点是空节点
char str[N];    //用于存储字符串
void insert(char str[])
{
	int p = 0; // 从根结点开始
	for(int i = 0; str[i] != '\0'; i++) // 遍历字符串
	{
		int u = str[i] - 'a';   //将当前字母对应的编号: a ~ z -> 0 ~ 25
		if(!son[p][u])  // 如果当前 p 结点没有 u 这个子节点，便创建出来
			son[p][u] = idx++;
		p = son[p][u];  // 更新 p 结点
	}
	// 完整插入字符串后，p位于最后字符串最后一个字母
	cnt[p]++; //此时让以该字母为结尾的单词个数加一
}

int query(char str[])
{
	int p = 0;
	for(int i = 0; str[i] != '\0'; i++)
	{
		int u = str[i] - 'a';
		if(!son[p][u])  //  若某个字符不存在，说明该字符串str不存在于字典树中
			return 0;
		p = son[p][u];
	}
	return cnt[p];  // 返回该字符串出现的次数
}
