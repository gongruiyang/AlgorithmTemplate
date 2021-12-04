
int theLongestNonrepeatingSubstring(int a[], int n)
{
	unordered_map<int, int> hash;

	int ans = 0;
	for (int i = 0, j = 0; i < n; i++)
	{
		hash[a[i]]++;
		while (j < i && hash[a[i]] > 1)
		{
			hash[a[j]]--;
			j++;
		}
		ans = max(ans, i - j + 1);
	}
	return ans;
}
