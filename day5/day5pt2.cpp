#include <iostream>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std; 

int main()
{

	ifstream myfile{"day5.txt"}; 

	if(!myfile) cout << "Could not open file"<< endl;


	

	//variables used
	int niceStringCount=0;
	unordered_set <string> stringPairs; //Uses pair class pair<iterator, bool> as keys
	string inputLine;

	bool repeatBetween;
	bool noBadStrings;
	string pairString;


	char prevChar;
	char prevTwoChar;
	char currentChar;
	
	while(myfile)
	{
		getline(myfile, inputLine);

		if(inputLine.empty()) break;
		
		//resets values
		noBadStrings = false;
		repeatBetween = false;

		prevChar= inputLine[0]; 
		int charIndex =1;
		
		stringPairs.clear();//clears set		

		while(inputLine[charIndex] != '\0')
		{
			
			currentChar = inputLine[charIndex];
			
			//insert pair 
			pairString = std::string() + prevChar + currentChar;	
			auto value = stringPairs.insert(pairString);

			if( charIndex >= 2)//condition to prevent indexing out of bounds
			{
				prevTwoChar = inputLine[charIndex-2];
			
				if(currentChar == prevTwoChar)//check for character repeat
				{ 
					repeatBetween = true;
				}
				if(!value.second)//check for repeat value
				{ 						
					
					if(prevChar != prevTwoChar)//check for overlap
					{	
						noBadStrings = true;		
					}
				}

			}
			//changes for next pair insertion	
			prevChar =currentChar;		
			charIndex+=1;	
		}
			
		if(repeatBetween && noBadStrings)
		{
		       	niceStringCount+=1;
		}
	}

	cout << "Number of nice strings: " << niceStringCount << endl;
	return 0;
}


