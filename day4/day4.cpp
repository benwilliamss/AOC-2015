#include<iostream>
#include<fstream>
#include <regex>
//#include <openssl/md5.h>
#include "openssl/md5.h"

using namespace std;
int main()
{
	/*
	 * Need to generate a hash with 5x 0's
	 * Find the lowest positive number to combine
	 with my string to get 5 0's hash function

	 
	 */
	int count =1;
		string input = "yzbqklnj"; 
		input += to_string(count);

		string str;
		//	str.append(input,0,5); -> get first 5 characters of a string
		cout << "characters " << str << " of " << input << endl;
		//MD5()
		
		
		//if(regex_search(hexvalue,))
		{
		}
		count++;
	
		

		
	return 0;
}

