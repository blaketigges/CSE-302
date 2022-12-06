#include "BST.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

BST csvtoBST(string csvfile) {
    BST retBST;
    ifstream ReadFile(csvfile); //open the csv file for reading
    string line, curvalue;
    getline(ReadFile, line); //throw away the first line (column names)
    while (getline(ReadFile,line)) {        
        stringstream ss(line); //turn the line into a string-stream
        int fielditer=0;
        Laptop_Data newrec;
        while(getline(ss, curvalue, ',')){ //Separate each variable per sample from the comma separator
            switch (fielditer) { //We need to explicitly convert values to the appropriate type (stoi=integer, stod=double)
            	case 0: newrec.Laptop_ID=stoi(curvalue); break;
                case 1: newrec.Company=curvalue; break; 
                case 2: newrec.Product=curvalue; break;
                case 3: newrec.TypeName=curvalue; break;
                case 4: newrec.Inches=stod(curvalue); break;
                case 5: newrec.ScreenResolution=curvalue; break;
                case 6: newrec.Cpu=curvalue; break;
                case 7: newrec.Ram=curvalue; break;
                case 8: newrec.Memory=curvalue; break;
                case 9: newrec.Gpu=curvalue; break;
                case 10: newrec.OpSys=curvalue; break;
                case 11: newrec.Weight=curvalue; break;
                case 12: newrec.Price_euros=stod(curvalue); break;
            }
            fielditer++;
        }
        retBST.PutItem(newrec);
    }
    return retBST;
}
int main(int argc, char** argv) {
    BST Laptop_Data=csvtoBST("laptop_price.csv");
    Laptop_Data.PrintTree(); //Print the data record-by-record
}
    
