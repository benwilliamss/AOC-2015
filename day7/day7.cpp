#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <cinttypes>


using namespace std;


int main()
{
	//parsing
	ifstream myfile {"sample.txt"};

	if(!myfile) printf("txt file will not open");
	
	string temp;
	char lineOfTxt[25];
		
		
	unordered_map<string, int > mapOfSignals;//key - wire: value - signal 
	
	string wireKey;//to put use string as key

	
	uint16_t signal;
	while(myfile)//while queue not empty
	{
		char wire[3],srcWire1[3], srcWire2[3], gate[4];
		signal = 0;
		
		//Improvement: line of txt conversion to cstring 
		getline(myfile,temp);

		//cstring conversion
		
		if(temp.empty()) break;

		
		strcpy(lineOfTxt,temp.c_str());//conversion to c string  
		
		//printf("line: %s\n", lineOfTxt);


		//signal -> wire
		if(sscanf(lineOfTxt,"%" SCNu16" -> %s",&signal,&wire)==2){}

		//shift
		else if(sscanf(lineOfTxt,
					"%s %s %" SCNu16" ->%s"
					,&srcWire1,&gate,&signal,&wire)==4)

		{//printf("matched: %s %s %d -> %s \n\n", srcWire1,gate, signal,wire);
			if(mapOfSignals[srcWire1] !=0)
			{
				signal = strcmp(gate,"RSHIFT") ?
					mapOfSignals[srcWire1] << signal :
				       	mapOfSignals[srcWire1] >> signal; 	
						
					//remove from queue
			} 

		}

		//And/OR
		else if(sscanf(lineOfTxt,
					"%s %s %s ->%s"
					,&srcWire1,&gate,&srcWire2,&wire)==4)
		{ 		
			//find the srcwire1 & srcwire2 values 

			if(mapOfSignals[srcWire1] !=0 && mapOfSignals[srcWire2]!=0)
			{
				signal = strcmp(gate,"AND") ?
					mapOfSignals[srcWire1] | mapOfSignals[srcWire2] :
				       	mapOfSignals[srcWire1] & mapOfSignals[srcWire2]; 	
						
					//remove from queue
			} 
		}

		//NOT
		else
		{	
			sscanf(lineOfTxt,
					"NOT %s ->%s"
					,&srcWire1,&wire);
			
			 if(mapOfSignals[srcWire1] !=0) signal= ~mapOfSignals[srcWire1]; 	 
		}
		//cout << "wire: " << wire <<"\nsignal: "<< signal << endl;
		mapOfSignals[wire] = signal;//inserts 0 if signal unchanged

		


		
	}
	for(auto it : mapOfSignals)
	{
		cout << it.first <<": " << it.second << endl;
	}	

	return 0;
}
