#include<bits/stdc++.h>
#include <conio.h>

using namespace std;

int main (void)
{

    int n, a[100], j ,i, temp, max_count = 1, count = 1;
    count = 0;

    cin >> n;

    
    // input-array
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    
    // Sort-the-array
    for(i = 0; i < n; i++) 
	{		
		for(j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

    // finding-the-most-duplicate-element   
    for (int i = 1; i < n; i++) { 
        if (a[i] == a[i - 1]) 
            count++; 
        else { 
            if (count > max_count) { 
                max_count = count;
            } 
            
        } 
    }

    if (n == 1)
        count++;
    

    cout << count << endl;
}

// for (i = 0; i < n; i++)
//     {
//         if (a[i] == a[i + 1])
//             count++;

//         if (n == 1)
//             count++;
//     }