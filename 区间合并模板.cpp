
typedef pair<int, int> PII;
/*
 *	MethDes: 区间合并
 *	Para1: segs 待合并区间的左右端点，单个元素是一个 pair<int, int>
*/
void intervalMerge(vector<PII>& segs)
{
	vector<PII> ans;

	sort(segs.begin(), segs.end());

	int st = -2e9, ed = -2e9;
	for(auto seg : segs)
	{
		if(seg.first > ed)  // 当前的seg区间与正在维护的区间没有交集
		{
			if(st != -2e9)  // 将产生的答案区间放入ans中
				ans.push_back({st, ed});
			st = seg.first, ed = seg.second;    //更新正在维护的区间左右端点
		}
		else ed = max(ed, seg.second);
	}
	if(st != -2e9)  ans.push_back({st, ed});    // 将最后产生的区间放入答案中

	segs = ans; //将答案保存在原数组中
}
