#include <bits/stdc++.h>

using namespace std;

#define def 100

int main (void)
{
    // int x;
    // cin >> x;

    // for(int i = 1; i <= x; i++)
    // {
    //     for(int j = 1; j <= i; j++)
    //     {
    //         cout << '*' << endl;
    //     }
    // }

//     int n; 
//     cin >> n;

//     for(int i = 0; i <= n; i++)
//     {
//         for(int j = 0; j <= n; j++)
//         {
//             if (i + j >= n )
//             {
//                 cout << '*';
//             }
//             else{
//                 cout << "  ";
//             }

//             cout << endl;
//         }
//     }
// } 

    

	int n; 
    cin >> n;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n - i; j++)
		{
			cout << ' ';
		}
		
		for(int j = 1; j <= i; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
	

}
// ==================

