#include <iostream>
#include <fstream>
#include <unordered_map>
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

typedef unordered_map<int, int> MapOfCoords;

void partOne( int startX,
			int startY,
			int endX,
			int endY,
			MapOfCoords &lightsCoordinates,
			int lightOn
			)
{


	for(int x = startX; x <= endX; x++ )
	{
	
		for(int y = startY; y <=endY; y++ )
		{
		 //find/insert
		 //depending if lights on is on(1), off(-1) or toggle(2)	
		 
		
			//pair<int,int> coordinates = make_pair(x,y);
			
			int coordinates = x << 10 | y; 
			//bitwise shift right, 
			//utilise 20bits for encoding of both x and y together
			if(lightOn == 2)
			{//toggle 
				
			
				int toggleValue =lightsCoordinates[coordinates]; 
								
				

				if( toggleValue==1)
				{
					lightsCoordinates[coordinates] = -1;
	
				}
				else
				{
					lightsCoordinates[coordinates] = 1;
				}
				/*cout <<"("<< x << ","<< y  << ")"<< "value before: " 
					<<toggleValue << " & Value after: "
					<< lightsCoordinates[coordinates] <<" \n ";*/
		
			
			}

			else lightsCoordinates[coordinates] = lightOn;
			
		}
	}
}

void partTwo( int startX,
			int startY,
			int endX,
			int endY,
			MapOfCoords &lightsBrightness,
			int lightOn
			)
{


	for(int x = startX; x <= endX; x++ )
	{
	
		for(int y = startY; y <=endY; y++ )
		{
		 
		 //depending if lights on is on(1), off(-1) or toggle(2)	
		 
		
			
			
			int coordinates = x << 10 | y; 
			//bitwise shift right, 
			//utilise 20bits for encoding of both x and y together
		
			if(lightsBrightness[coordinates]+lightOn <= 0)lightsBrightness[coordinates]=0;
			else lightsBrightness[coordinates]+=lightOn;


			
		}
	}
}

void lightsOnCount(MapOfCoords lightsCoordinates)
{
	
	int numberOfLightsOn=0;


	for(auto it : lightsCoordinates)
	{
		
		
		if(it.second==1) numberOfLightsOn+=1;
	
	}
	
	cout << numberOfLightsOn << endl;


	
}

void brightnessCount(MapOfCoords lightsBrightness)
{


	int brightness =0;
	for(auto it : lightsBrightness)
	{

		brightness += it.second;
	}
	cout<< brightness << endl;

}






int main()
{
	
	//variables 
	string  lineOfTxt; //line of text in input file

	int lightOn;//int to denote light on, off or toggle 
	
	int startX, startY, endX, endY;	

	MapOfCoords lightsCoordinates;
	MapOfCoords lightsBrightness;
	
	char onOff[4];


	//parsing 
	
	ifstream myfile{"day6.txt"};

	if(!myfile)
	{
		cout << "could not open txt file"<< endl; 
	}
	
	while(myfile)
	{ 
		getline(myfile,lineOfTxt);
		
		if(lineOfTxt.empty()) break;	
		
		
	
		if (sscanf(lineOfTxt.c_str(),
				 "turn %s %d,%d through %d,%d"
				 , onOff, &startX, &startY, &endX, &endY
			  )==5
		   )
		{	
			lightOn = strcmp(onOff, "on") ? -1: 1;
		}
		else
		{
    		    	sscanf(
					lineOfTxt.c_str(), 
					"toggle %d,%d through %d,%d",
				       	&startX, &startY, &endX, &endY
					
			      );
			lightOn=2;
		}	
	
	
			partOne
			  (
				startX,
				startY,
				endX,
				endY,
				lightsCoordinates,
				lightOn
			  );
			//partTwo
			partTwo
			  (
				startX,
				startY,
				endX,
				endY,
				lightsBrightness,
				lightOn
			  );




	 }

	cout << "Number of lights: ";
       	lightsOnCount(lightsCoordinates);
       

	cout << "Overall brightness: ";
	brightnessCount(lightsBrightness);


 	return 0;
}
