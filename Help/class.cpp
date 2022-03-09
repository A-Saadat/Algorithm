#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int a[n + 10];
	
	for(int i = 1; i <= n; i++)
	{	
		cin >> a[i];
	}
	
	cout << a[2] - a[1] << " " << a[n] - a[1] << endl;
	
	for(int i = 2; i <= n - 1; i ++)
	{
		/*
		// min i  -- a[i-1] , a[i+1]
		
		int min1 = a[i + 1] - a[i];
		int min2 = a[i] - a[i - 1];
		
		//cout << min(min1, min2) << " ";
		
		if(min1 < min2)
		{
			cout << min1 << " ";
		}
		else
		{
			cout << min2 << " ";
		}
		
		int max1 = a[n] - a[i];
		int max2 = a[i] - a[1];
		
		cout << max(max1, max2) << endl;
		
		if(max1 > max2)
		{
			cout << max1 << endl;
		}
		else
		{
			cout << max2 << endl;
		}		
		*/
		cout << min(a[i + 1] - a[i], a[i] - a[i - 1]) << " " << max(a[n] - a[i], a[i] - a[1]) << endl;
		
	}
	
	
	cout << a[n] - a[n - 1] << " " << a[n] - a[1];
	
	
	
}