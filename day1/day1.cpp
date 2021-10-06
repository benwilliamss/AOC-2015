#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/*starts at floor 0
 * ( up one floor
 * ) down one floor*/

int main()
{
	ifstream myfile{"day1.txt"};

	if(!myfile)
	{
		cerr << "Could not open day1.txt\n";
	
		return 1;
	
	}
	
	string input;
	int floor = 0;
	int charCount =0;
	
	while(myfile)
	{


		getline(myfile,input);
		int n =0;
		while(input[n]!= '\0')
		{
			charCount+=1;

			if(input[n] =='(')
			{
		
				floor+=1;
			}
			else if(input[n] ==')')
			{
				floor-=1;
				if(floor == -1) 
				{
					cout << "\nEnterted the basement at " << charCount;	
										}
		
			}
						n+=1;
		}
		
			
	}
	cout << "\nSanta is on floor "<< floor;
		





	



	return 0;
}
