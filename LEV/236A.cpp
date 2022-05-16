#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 

int main (void)
{

    string a, b;
    cin >> a;

    for(int i = 0; i < a.size(); i++)
    {
        for (int j = 1; j < a.size(); j++)
        {
            if(a[i] != a[j])
                a[i] = b[i];
            else
                continue;
        }
        
    }

    if(b.size() % 2 == 2)
        cout << "CHAT WITH HER!";
    else
        cout << "IGNORE HIM!";

}