#include "AUList.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

AUList csvtoAUList(string csvfile) { //convert a csv file to a list structure
    AUList retCCList;
	ifstream ReadFile(csvfile); //open the csv file for reading
    string line, curvalue;
	getline(ReadFile, line); //throw away the first line (column names)
    while (getline(ReadFile,line)) {        
        stringstream ss(line); //turn the line into a string-stream
        int fielditer=0;
        BigMacPriceRecord newrec;
		while(getline(ss, curvalue, ',')){ //Separate each variable per sample from the comma separator
            switch (fielditer) { //We need to explicitly convert values to the appropriate type (stoi=integer, stod=double)
            	case 0: newrec.date=curvalue; break;
                case 1: newrec.curr_code=curvalue; break; 
                case 2: newrec.name=curvalue; break;
                case 3: newrec.local_price=stod(curvalue); break;
                case 4: newrec.dollar_ex=stod(curvalue); break;
                case 5: newrec.dollar_price=stod(curvalue); break;
			}
            fielditer++;
        }
        retCCList.PutItem(newrec);
    }
    return retCCList;
}

int main(int argc, char** argv) {
	AUList BigMacPriceData=csvtoAUList("BigmacPrice.csv");
	BigMacPriceData.PrintList(); //Print the data record-by-record
}
    
