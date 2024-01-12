// ! I AM NOT INSANE 
#include <bits/stdc++.h> 
using namespace std; 

const int MaxN = 1e6; 
int a[MaxN]; 

int main()
{

    int n; std::cin >> n;
    for(int i = 1; i < n; i++) std::cin >> a[i];
    sort(a, a + n);
    for(int i = 1; i <= n; i++)
        if(a[i] != i){
            std::cout << i << endl;
            break;
        }
}