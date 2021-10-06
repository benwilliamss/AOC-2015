#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std; 

int main()
{

	ifstream myfile{"day5.txt"}; 
		
	if(!myfile) cout << "Could not open file"<< endl;
	
	
	string inputLine;


	//variables used
	int vowelCount;
	int niceStringCount=0;
	bool twiceInARow;
	bool noBadStrings;

	char prevChar;
	char currentChar;
	
	while(myfile)
	{
		getline(myfile, inputLine);
		

		//transform(inputLine.begin(),inputLine.end(),inputLine.begin(),::tolower);		
		//resets values
		twiceInARow = false;
		noBadStrings = true;
		vowelCount =0;
		int charIndex =0;
		prevChar =' ';

		
		cout << "String: "<< inputLine << "\n";
		while(inputLine[charIndex] != '\0')
		{
			
			currentChar = inputLine[charIndex];
			
			//check for bad string combo
			if(
					currentChar == 'b'&& prevChar =='a'|| 
					currentChar == 'd'&& prevChar =='c'|| 
					currentChar == 'q'&& prevChar =='p'|| 
					currentChar == 'y'&& prevChar =='x'  				     		   ){ cout<< "contains: " << prevChar << currentChar<<"\n"; noBadStrings = false; break; }


			//letter consecutive repeats
			if(currentChar == prevChar)
			{
				twiceInARow = true;
			       	cout << "Twice in a row: " << currentChar << " & " << prevChar<< "\n";
		       	}
			//current letter a vowel 
			if(currentChar == 'a'|| currentChar == 'i'|| currentChar == 'e'|| currentChar == 'o'|| currentChar == 'u') vowelCount+=1;
			
						
			prevChar = currentChar;
			charIndex+=1;	
		}
			cout << "Number of vowels: " << vowelCount <<"\n";

		if(vowelCount >= 3 && twiceInARow && noBadStrings){ niceStringCount+=1;
					cout <<"Nice String: True";
		}
	cout<< "\n\n";
	}

	cout << "Number of nice strings: " << niceStringCount << endl;
	return 0;
}


