#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 

int main (void)
{

    string a, b = "hello";
    cin >> a;

    intl cnt = 0, index = 0;

    for(int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[index])
        {
            index++;
            cnt++;

            if(cnt == 5)
                break;
        }
            
        
    }

    if (cnt == 5)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

}