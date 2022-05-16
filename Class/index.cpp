#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef pair<int, int> pii;
typedef pair<pii, int> pos;

int main() 
{
    int a = 5;
    int b[10];

    pii c = (4, 10); 
    c.first = 20;
    c.second = 50;

    pair<pii, int> d = make_pair(pii(3, 5), 10);

    pos s = pos(pii(1,6), 11);

    cout << s.S;

    c = make_pair(3, 5);

    pair<int, int> m[10];

    m[1].first = 3;
    m[1].second = 10;

    sort(m + 1, m + n + 1);

    map<string, string> mp;

    mp["pouria"] = "0936....";
    mp["ali"] = ",,,,,";

    cout << mp["artin"];

    mp["artin"] = "123124";



    mp.clear();

    
    int a1 = 10;
    int a2 = 20;
    int c = a(a1, a2);
    cout << c;

    mySwap(a1 , a2);
}

void mySwap(int x, int y) 
{
    int tmp = x;
    x = y;
    y = x;
    return;
}

int a(int x,int y)
{
    int ans = x * y;
    return ans;
}