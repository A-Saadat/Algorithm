#include <bits/stdc++.h>

using namespace std;

int my_min(int x, int y)
{
	if(x < y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

void my_swap(int x, int y) // a = 3 , x = 3, b = 10, y = 10
{
	int tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	int a = 3;
	int b = 10;
	
	my_swap(a, b);
	
	cout << a;
}

