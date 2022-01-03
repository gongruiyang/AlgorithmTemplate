#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;
int arr[N];

int main()
{
	int n, k;
	cin >> n >> k;
	while(k--)
	{
		int a, b;
		cin >> a >> b;
		arr[a]   += 1;
		arr[b+1] -= 1;
	}
	for(int i = 0; i < n; i++) 
		arr[i] = arr[i-1] + arr[i];
	sort(arr, arr + n);
	cout << arr[n/2] << endl;
	
	return 0;
} 
