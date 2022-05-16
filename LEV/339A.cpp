#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 

int main (void)
{

    string a, b;
    cin >> a;

    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == '+')
            continue;
        else
            b = a[i];
    }

    for(int i = 0; i < b.size(); i++)
    {
        for (int j = i + 1; j < b.size(); j++)
        {
           if (b[i] <= b[j])
            {
                int tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }

    for(int i = 0; i < b.size(); i++)
    {
        cout << b[i] << '+';
    }

}
