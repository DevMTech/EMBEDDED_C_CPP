#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
 
class RandomInteger
{
	private:
		int low;
		int high;
		int value;
		static int count;
		
	public:
		RandomInteger(int low, int high):low(low), high(high){};
		~RandomInteger();
		RandomInteger(const RandomInteger &rInt)=delete;
		void print()const;
		
};



int main()
{
	
	return 0;
}
