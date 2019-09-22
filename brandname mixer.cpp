#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <math.h>

#define TABSPACE 0 //keno anamesa sto | kai sta dexia brandnames
#define CUSTOMSPACE 20 //to keno anamesa sta brandnames kai ta | prosarmozetai dinamika ston kwdika, san max einai to CUSTOMSPACE
#define MAXLEXEWN 100000 //o counter sto telos tou programmatos

//change these to change print layout
#define LINEHR 3 //posa stoixeia ana grammi emfanizontai
#define LINEENTER 9 //allazei ka8e posa stoixeia 8a bazei keni grammi anamesa

using namespace std;

int main() 
{
	srand (time(NULL));
	vector<int> usednodes;
	// change these to change the brandnames
	string namestomix[] = {"Magic", "Can", "Happens"}
	// change this to change the name of the output file

	char filename[ ] = "BrandNames.txt";

	long int counter = 0, maxloops = 0;
	int brandscounter = 0, totalbrandnames = 0;
	int node1, node2, finalnumber;
	int i, printcounter=1;
	int numberofgivenwords = 0, lineenter=0;
	int node1len=0, node2len=0, sumstrlen=0, spacetoadd=0;

	string node1str;
	string node2str;
	string finalnumberstr;
	stringstream ss;
	
	bool flag = false;

	fstream mybrandsnamesfile;
	mybrandsnamesfile.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
	// If file does not exist, Create new file
	if (!mybrandsnamesfile ) 
	{
		cout << "> Cannot open file, file does not exist. Creating new file..";
		
		mybrandsnamesfile.open(filename,  fstream::in | fstream::out | fstream::trunc);
		mybrandsnamesfile <<"\n";
		mybrandsnamesfile.close();
	}	
	
	numberofgivenwords = (sizeof(namestomix)/sizeof(*namestomix));
	maxloops = numberofgivenwords*numberofgivenwords;
	cout<<"--------------------------------------"<<endl<<"[Dothikan "<< numberofgivenwords <<" lexeis]=>"<< "[" << maxloops-numberofgivenwords << " apotelesmata]" << endl;
	cout<<"--------------------------------------"<<endl<<"[Xekinaei h dimiourgia onomatwn]"<<endl<<"--------------------------------"<<endl<<endl;
	while(totalbrandnames<maxloops)
	{
		///////////dimiourgia ari8mou, starts here
		node1 = rand() % numberofgivenwords + 0;
		do
		{
			node2 = rand() % numberofgivenwords + 0;
		}while(node2==node1);
		ss << node1;
		ss << node2;
		finalnumberstr = ss.str();
		istringstream newss (finalnumberstr);
		newss >> finalnumber;
		///////////dimiourgia ari8mou, ends here
		///////////elegxos an iparxei idi, starts here
		if(totalbrandnames!=0)
		{
			for(i=0;i<counter;i++)
			{
				if(usednodes[i]==finalnumber)
				{
					flag = true;
					break;
				}
			}
		}
		////an o ari8mos den iparxei ton vazoume ston pinaka
		if(flag==false)
		{
			usednodes.push_back(finalnumber);
			brandscounter++;
			totalbrandnames++;
			lineenter++;
			cout << brandscounter <<". "<< "" << namestomix[node1] << namestomix[node2];
			////////grafoume sto arxeio starts
         		mybrandsnamesfile << brandscounter <<". "<< "" << namestomix[node1] << namestomix[node2]<<"\n";;
			////////grafoume sto arxeio ends	
			
			node1len = namestomix[node1].length();
			node2len = namestomix[node2].length();
			sumstrlen = node1len+node2len;
			if(sumstrlen<CUSTOMSPACE)
			{
				spacetoadd = CUSTOMSPACE - sumstrlen;
			}
			if(printcounter==LINEHR)
			{
				cout<<endl;
				printcounter=0;
			}
			else 
			{
				cout<<setw(spacetoadd)<< "|"<<setw(TABSPACE);
			}
			if(lineenter==LINEENTER)
			{
				cout<<endl;
				lineenter=0;
			}
			printcounter++;
		}
		else
		{
			flag = false;
			//continue;
		}
		///////////elegxos an iparxei idi, ends here
		ss.str("");
		counter++;
		if((totalbrandnames+numberofgivenwords)==maxloops)break;
		//cout << "	Iparxei idi: "<< namestomix[node1] <<  namestomix[node2] << endl;
	}
	cout<<endl<<endl<<"----------------------------"<<endl<<"["<<brandscounter<<" onomata dimiourgi8ikan]"<<endl<<"----------------------------";
	mybrandsnamesfile.close();	
	
	//perimenei ena pliktro gia na kleisei to programma
    	getch();
	return 0;
}