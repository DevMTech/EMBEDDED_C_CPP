#include <iostream>

#define CANDIDATENUM 10

using namespace std;

typedef struct // Election // Candidates
{
	string name;
	int voteCount;
}Election;

int main ()
{
 	//const char** candidateList = {"Joe", "Bob", "Mary", "Suzy", "Margaret", "Eleanor", "Alex", "Thomas", "Andrew", "Ilene"};
	//string candidateList = new string [10];
	
	string candidateList[] = {"Joe", "Bob", "Mary", "Suzy", "Margaret", "Eleanor", "Alex", "Thomas", "Andrew", "Ilene"}; // CANDIDATENUM
	
	//Election Candidates[] = new Election[10*sizeof(Election)]; 
	Election Candidates[CANDIDATENUM];
	
	// initialize
	for ( int i = 0; i < CANDIDATENUM; ++i )
	{
		Candidates[i].name = candidateList[i];
		Candidates[i].voteCount = NULL;
	}

 	

	int candidate;
	int maxCount = 0;
	
	cout << "\n Vote for the candidate of your choice, using numbers ";
	cout << "\n 0) Joe 1) Bob 2) Mary 3) Suzy 4) Margaret 5) Eleanor 6) Alex 7) Thomas 8) Andrew 9) Ilene";
	cout << "\n Exit by entering a non-candidate number (>9) : ";
	cin >> candidate;	
	
	// enter votes until the user exits by entering a non-candidate number
	while ( 0 <= candidate && candidate <= CANDIDATENUM-1 )
	{
 		//Candidates[candidate].voteCount++;
 		
 		if(maxCount < ++Candidates[candidate].voteCount)
		{
			maxCount = Candidates[candidate].voteCount;
			//winner = i;
		}
		
		cout << "\n Vote for the candidate of your choice, using numbers ";
		cout << "\n 0) Joe 1) Bob 2) Mary 3) Suzy 4) Margaret 5) Eleanor 6) Alex 7) Thomas 8) Andrew 9) Ilene";
		cout << "\n Exit by entering a non-candidate number (>9) : ";
		cin >> candidate;

	}
	
	cout << "\n --------------ELECTION RESULT ---------------- \n";
	
	 
	for ( int i = 0; i < CANDIDATENUM; ++i )
	{	
		cout << "\n "<< Candidates[i].name << " : " << Candidates[i].voteCount << '\n';
	}
	
	cout << "\n Winner(s) : \n";
	for(int i = 0; i < CANDIDATENUM; i++)
	{
		if(maxCount == Candidates[i].voteCount)
		{
			cout << " " << Candidates[i].name << '\n';
		}
	}
	
}
