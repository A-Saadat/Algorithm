#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
#define def 100000

int main ()
{   

    intl n;
	intl count = 1, ans = 1;
	cin >> n;

	intl h1, m1, h, m;
	cin >> h1 >> m1;

	while(--n){
	    cin >> h >> m;
	    if (h1 == h && m1 == m){
	        count++;

	        if (count > ans)
	            ans = count;
	    }
        else
	        count = 1;
        
	    h1 = h;
	    m1 = m;
	}
    
	cout<<ans;

}
