#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int main()
{
    int i, j, m, n;
    long min_area=0;
    int xmax=0, xmin=0, ymax=0, ymin=0;
    
    int x[]={-4, 3, 1, -5, 4, -2, 7};
    int y[]={3, -1, -2, -3, -6, 9, -8};
    // int k = 2;
	
	int s = sizeof(x)/sizeof(x[0]);
	
	int k = s-1;
	
	float arr[s], swap=0;
	int index[s], index1[s];
	
	for(i=0; i<s; i++)
	{
		index[i]=i;
		index1[i]=0;
			
		arr[i] = sqrt((x[i]*x[i])+(y[i]*y[i]));
		
		cout << "arr[" << i << "] = " << arr[i] << endl; 
		
		// cout << "arr[" << i << "] = " << sqrt((x[i]*x[i])+(y[i]*y[i])) << endl;
	}
	
//	for(i=0; i<s; i++)
//	{		cout << "arr[" << i << "] = " << arr[i] << endl; 
//	}
	
	cout << endl; 
	
	for(i=0; i<s; i++)
	{
		cout << "index[" << i << "] = " << index[i] << endl; 
	}
	
	cout << endl;
	
	for(i=0; i<s-1; i++)
	{
		for(j=i+1; j<s; j++)
		{
			if(arr[j]<arr[i])
			{	
				swap = arr[i];
				arr[i]=arr[j];
				arr[j]=swap;
								
				//index[i] = j;					
				swap = index[i];
				index[i]=index[j];
				index[j]=index[i];
			}
		}
	}


//	
//	for(i=0; i<s-1; i++)
//	{
//		for(j=i+1; j<s; j++)
//		{
//			m = arr[i];
//			if(arr[j]<m)
//			{	
//				m = arr[j];
//				n = j;
//				
//			}
//		}
//		
//		swap = arr[i];
//		arr[i]=arr[n];
//		arr[n]=swap;
//		
//		swap = index[i];
//		index[i]=index[n];
//		index[n]=index[i];
//	}
	
	for(i=0; i<s; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl; 
	}
	
	cout << endl; 

	for(i=0; i<s; i++)
	{
		cout << "index[" << i << "] = " << index[i] << endl; 
	}

    for(i=0; i<k; i++)
    {	m = index[i];
        if(x[m]>xmax) xmax = x[m];
        if(x[m]<xmin) xmin = x[m];

        if(y[m]>ymax) ymax = y[m];
        if(y[m]<ymin) ymin = y[m];
    }

    j = abs(xmax-xmin);
    m = abs(ymax-ymin);

    n = (j>m)? (long)j : (long)m;

    min_area = (long) (n+2)*(n+2);
    
    
	
	cout << endl << "min_area = " << min_area << endl; 
	
    return 0;

}
