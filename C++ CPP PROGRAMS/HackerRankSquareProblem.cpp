#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'minArea' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY x
 *  2. INTEGER_ARRAY y
 *  3. INTEGER k
 */

long minArea(vector<int> x, vector<int> y, int k) 
{
    int i, j, m, n, swap=0;
    long min_area=0;
    int xmax=0, xmin=0, ymax=0, ymin=0;
	
	int s = x.size();
	
	long arr[s];
	int index[s];
	
	for(i=0; i<s; i++)
	{
		index[i]=i;
		
		arr[i] = sqrt((x[i]*x[i])+(y[i]+y[i]));
	}
	
	for(i=0; i<s-1; i++)
	{
		for(j=i+1; j<s; j++)
		{
			if(arr[j]>arr[i])
			{
				swap = arr[i];
				arr[i]=arr[j];
				arr[j]=swap;
				
				swap = index[i];
				index[i]=index[j];
				index[j]=index[i];
			}
		}
	}
	
	for(i=0; i<s; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl; 
	}

	for(i=0; i<s; i++)
	{
		cout << "index[" << i << "] = " << index[i] << endl; 
	}

    for(i=0; i<s; i++)
    {	m = index[i];
        if(x[m]>xmax) xmax = x[m];
        else if(x[m]<xmin) xmin = x[m];

        if(y[m]>ymax) ymax = y[m];
        else if(y[m]<ymin) ymin = y[m];
    }

    j = abs(xmax-xmin);
    m = abs(ymax-ymin);

    n = (j>m)? (long)j : (long)m;

    min_area = (long) (n+2)*(n+2);

    return min_area;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string x_count_temp;
    getline(cin, x_count_temp);

    int x_count = stoi(ltrim(rtrim(x_count_temp)));

    vector<int> x(x_count);

    for (int i = 0; i < x_count; i++) {
        string x_item_temp;
        getline(cin, x_item_temp);

        int x_item = stoi(ltrim(rtrim(x_item_temp)));

        x[i] = x_item;
    }

    string y_count_temp;
    getline(cin, y_count_temp);

    int y_count = stoi(ltrim(rtrim(y_count_temp)));

    vector<int> y(y_count);

    for (int i = 0; i < y_count; i++) {
        string y_item_temp;
        getline(cin, y_item_temp);

        int y_item = stoi(ltrim(rtrim(y_item_temp)));

        y[i] = y_item;
    }

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    long result = minArea(x, y, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

