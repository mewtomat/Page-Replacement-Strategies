#include <iostream>
#include <fstream>
#include <String>
#include <time.h>
using namespace std;


int main()
{
	ifstream out, out1;
	out.open("mydata.txt",'w');
	out1.open("mydata12.txt",'w');
	for(double d = 130050001; d <= 130050100; d++)
	{
		out << d << endl;
		out1 << d << endl;
		
		char a = (char)((int)'a'+ srand(time(NULL))%26); 
		char b = (char)((int)'a'+ srand(time(NULL))%26);
		char c = (char)((int)'a'+ srand(time(NULL))%26);
		String k = ""+a+b+c;
		out << k<< endl;
		if(d%4 == 0)out1 << "Maths"<< endl;
		if(d%4 == 1)out1 << "Physics"<< endl;
		if(d%4 == 2)out1 << "Statistics"<< endl;
		if(d%4 == 3)out1 << "Biology"<< endl;
		
		
		out << d % 7 << endl;
		out1 << d % 29 << endl;
		out << d % 11 << endl;
		out1 << d % 37 << endl;
		out << d % 19 << endl;
		out1 << d %  59<< endl;
	}
	
	out.close();
	out1.close();
}

