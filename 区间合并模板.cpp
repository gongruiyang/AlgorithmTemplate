
typedef pair<int, int> PII;
/*
 *	MethDes: ����ϲ�
 *	Para1: segs ���ϲ���������Ҷ˵㣬����Ԫ����һ�� pair<int, int>
*/
void intervalMerge(vector<PII>& segs)
{
	vector<PII> ans;

	sort(segs.begin(), segs.end());

	int st = -2e9, ed = -2e9;
	for(auto seg : segs)
	{
		if(seg.first > ed)  // ��ǰ��seg����������ά��������û�н���
		{
			if(st != -2e9)  // �������Ĵ��������ans��
				ans.push_back({st, ed});
			st = seg.first, ed = seg.second;    //��������ά�����������Ҷ˵�
		}
		else ed = max(ed, seg.second);
	}
	if(st != -2e9)  ans.push_back({st, ed});    // ��������������������

	segs = ans; //���𰸱�����ԭ������
}
