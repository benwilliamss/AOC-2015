#include <fstream>
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

//specilisation of the hash class
typedef pair<int,int> coordinate;
namespace std
{

	template<>

	struct hash<coordinate>
	{
		public :
			//function object to take a pair as input
    		size_t operator()( const coordinate &coordinate) const
		{
       			return std::hash<int>()(coordinate.first) ^ std::hash<int>() (coordinate.second);
    		}
	};

};

int main()
{


	ifstream myfile{"day3.txt"};
	if(!myfile)
	{
		cerr <<  "Could not open day3.txt\n";		
		return 1;
	}
	string line;
	int presents =1; 	
	int santaX=0;
	int santaY=0;
	char movementPiece;

	coordinate Node; 
	unordered_set<coordinate> santasCoordinates;

	santasCoordinates.insert(coordinate(0,0));//start point
	if(myfile)
	{	
	
		getline(myfile,line);
		int charIndex =0;
		while(line[charIndex] != '\0')
		{	movementPiece = line[charIndex];

										
			if(movementPiece == '>') santaX+=1;
			else if(movementPiece == '<') santaX-=1;
			else if(movementPiece == 'v') santaY-=1;
			else if(movementPiece == '^') santaY+=1;
			Node = coordinate(santaX,santaY);
			if(santasCoordinates.find(Node)==santasCoordinates.end())
			{	//element not found in either 
					santasCoordinates.insert(Node);
					presents+=1;
			}
			charIndex++;	
			
		}
			
		

	

	}
	cout << "Number of houses that recieved atleast one present: " << presents << endl;

	return 0;	
}
