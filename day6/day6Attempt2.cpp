#include <iostream>
#include <fstream>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;







void lightsGrid(
			int startX, 
			int startY,
	       		int endX,
			int endY,
			int lightsCoordinates[1000][1000],
			int lightOn
			)
{


	for(int x = startX; x <= endX; x++ )
	{
	
		for(int y = startX; y <=endY ; y++ )
		{
		 //find/insert
		 //depending if lights on is on(1), off(2) or toggle(3)	
		 
		
					
			if(lightOn == 3)
			{//toggle 
				
				
				/*auto elementFound = lightsCoordinates.find(coordinates);
				if(elementFound == lightsCoordinates.end()){}

				else
				{
					cout <<"("<< x << ","<< y  << ")"<< "value: " 
					<< lightsCoordinates[coordinates] <<" \n ";
				}*/
				
				
				int toggleValue =lightsCoordinates[x][y]; 
								
				

				if( toggleValue==1)
				{
					lightsCoordinates[x][y] = 2;
	
				}
				else
				{
					lightsCoordinates[x][y] = 1;
				}
				//cout <<"("<< x << ","<< y  << ")"<< "value before: " 
				//	<<toggleValue << "Value after"
				//	<< lightsCoordinates[coordinates] <<" \n ";
		
			
			}

			else lightsCoordinates[x][y] = lightOn;
			
		}
	}

	
	//return lightsCoordinates;
}


void coordinateCount(int lightsCoordinates[1000][1000])
{
	
	int numberOfLightsOn=0;


	//needs to iterate through a 2D array 
		
	cout << "Number of lights on: " << numberOfLightsOn << endl;


	
}



void partOne()
{
	ifstream myfile{"day6.txt"};

	if(!myfile)
	{
		cout << "could not open txt file"<< endl; 
	}
	
	
	//variables used
	string lineOfTxt; //line of text in input file

	int lightOn;//int to denote light on, off or toggle 
	
	
	int startX, startY, endX, endY;


	int lightsCoordinates[1000][1000];



	while(myfile)
	{ 
		getline(myfile,lineOfTxt);
		
		
		if(lineOfTxt.empty()) break;	
		
				
		//cout << "String: " << lineOfTxt << "\n";
		scanf lineOfTxt(lineOfTxt, "turn on %d,%d through %d,%d", startX, startY, EndX,EndY);	
		
		/*cout <<"start coord: " 
		<< startCoordinates.first << "," 
		<< startCoordinates.second << "\n";

		cout << "end coordinates: " << endCoordinates.first 
		<< "," << endCoordinates.second<< "\n";
		cout <<"LightOn value: " << lightOn <<"\n";*/

				/*lightsCoordinates =lightsGrid
						( 	
						startX,
						startY,
						endX,
						endY,
						lightsCoordinates,
						lightOn
			  			);*/
		
					
	}

	//coordinateCount(lightsCoordinates);	 
	
}



int main()
{
	
	partOne();
 	return 0;
}
