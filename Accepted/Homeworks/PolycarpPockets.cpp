#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
#define def 100


int main (void)
{
    
    intl n, ans = 0, tmp;

    cin >> n;

    intl a[def], copy[def];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        copy[i] = a[i];
    }
    
    intl count = 0;

    // ---------------------------------------------------

    for(int i = 0; i < n; i++)
    {

        for(int j = 0; j < n; j++)
        {
            if(a[i] == copy[j])
                count++;
        }


        if(ans < count)
        {
            ans = count;
        }

        count = 0;
        

    }

        cout << ans;


    

}

//3

// 3 = b[2]


// b[0] = 1
// b[1] = 3
// b[2] = 1
// b[0] = 1
