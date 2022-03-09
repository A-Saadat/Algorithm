#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000;
int a[maxN + 10];

int main()
{
	int n;
	cin >> n;
		

	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
		
	int ans = 0;
	int cnt = 0;
		
	for(int i = 1; i <= n; i++)
	{
		// fix a[i]
		
		for(int j = 1; j <= n; j++)
		{
			// red -> a[j]
			if(a[j] == a[i])
				cnt++;				
		}
		
		if(cnt > ans)
			ans = cnt; // ans = ans + cnt;	
	}
	cout << ans;
}