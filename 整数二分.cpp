int BSearch(vector<int>& v, int target)		// я╟ур >= x ╣дср╠ъ╫Г
{
	int le = 0, ri = v.size() - 1;
	while (le < ri)
	{
		int mid = le + ri >> 1;
		if (v[mid] >= target)
			ri = mid;
		else
			le = mid + 1;
	}
	return le;
}

int BSearch(vector<int>& v, int target)		// я╟ур <= x ╣двС╠ъ╫Г
{
	int le = 0, ri = v.size() - 1;
	while (le < ri)
	{
		int mid = le + ri + 1 >> 1;
		if (v[mid] <= target)
			le = mid;
		else
			ri = mid - 1;
	}
	return le;
}
