#include<iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

/*
 * algorithm: l*w*2 + l*h*2+ w*h*2+ w*h
 * assign the first int to width
 * assign the second int to height
 * last int to length
 *
 * Parsing the input: stop at each x, put the int into a dimension
*/

int main()
{
			
		
	ifstream myfile{"day2.txt"};
	if(!myfile)
	{
		cerr <<  "Could not open day2.txt\n";		
		return 1;
	}
	
			
				
	string input;
	int charIndex;
	char currentChar;
	int midBoundChange;

	int WrappingPaper =0;
	int Ribbon =0;

	string 	str_length;
	string  str_width;
	string  str_height;

	int length;
	int width;
	int height;



		while(myfile)
		{	
			getline(myfile, input);

			int inputSize = input.length();


			if(inputSize==0) break; //breaks if given a blank line
			//if size of the input is different, change the mid bound to account for htis
			else if(inputSize==5) midBoundChange = 2;
			else if(inputSize==6) midBoundChange =1;
			else midBoundChange =0;	
			
			//resets the string to append characters to			
				str_length="";
				str_width ="";
				str_height="";

				charIndex =0;
				while(input[charIndex]!= '\0')
				{	
					currentChar = input[charIndex];
				
				

					if(charIndex <= 1 && currentChar != 'x')
					{
					//width
						str_width += currentChar;
					}
					else if (charIndex <= 4 - midBoundChange && currentChar != 'x')
					{
						str_height += currentChar;

					}
					else if(currentChar != 'x')
					{

					//length 
						str_length += currentChar;
					}
					charIndex +=1;


				}
			
			
			//string to int
			length= stoi(str_length);
			height= stoi(str_height);
			width = stoi(str_width);
			
			//works out the smallestSideArea 
			int smallestSideArea;
			int smallestDistanceOfRibbon;
			
			if(length >= width && length>= height)
			{
				smallestSideArea = width*height;
				smallestDistanceOfRibbon = width *2 + height*2;
			}
			else if(height >= width && height >= length)
			{	
				smallestSideArea=length*width;
				smallestDistanceOfRibbon = length*2 + width*2;
			}
			else
			{
				smallestSideArea = length * height;
				smallestDistanceOfRibbon = length *2 + height*2;
			}
			cout <<"\n"<< width <<"x"<<height<<"x"<<length<<"\n";
			cout << "length: " <<input.size() << "\n";
			cout << "SmallestSideArea: " << smallestSideArea <<"\n";
			cout << "Surface Area: " << 2*(length*width+height*width+height*length) <<"\n";
		       	cout << "Smallest ribbon length: " << smallestDistanceOfRibbon << "\n";	
		WrappingPaper += 2*(length*width+height*width+height*length) + smallestSideArea;
			
		Ribbon += (length*height*width + smallestDistanceOfRibbon);
		

		}

		
		cout<< "\n\nWrapping paper total to order: " <<WrappingPaper<< endl;		
		cout << "Ribbon total to order: " << Ribbon << endl; 
		return 0;
}
