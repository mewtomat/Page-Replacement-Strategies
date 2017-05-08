#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


int main()
{
	ofstream out, out1;
	out.open("mydata.txt");
	out1.open("mydata2.txt");
	for(long int d = 130050001; d <= 130051000; d++)
	{
		out << d << endl;
		out1 << d << endl;
		srand(d);
		char a = (char)((int)'a'+ rand()%26); 
		char b = (char)((int)'a'+ rand()%26);
		char c = (char)((int)'a'+ rand()%26);
		cout << a << b << c << endl;
		string k = "";
		k = k + a + b + c;
		out << k<< endl;
		//cout << k << endl;
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

