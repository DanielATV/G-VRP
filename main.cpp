#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
#include <regex> 
using namespace std;

class Geeks 
{ 
    // Access specifier 
    public: 
  
    // Data Members 
    string geekname; 
  
    // Member Functions() 
    void printname() 
    { 
       cout << "Geekname is: " << geekname; 
    } 
};

int main(){
    
    // Vector of string to save tokens 
    vector <string> tokens; 
      

    fstream newfile;

    regex spaces ("\\s+");

    newfile.open("AB101.dat",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string tp;
        string dummy;
        string replace = " ";

        

        getline(newfile, tp);
        dummy = regex_replace(tp,spaces,replace);
        //tokens.push_back(tp);
        cout << dummy << '\n'; 

        while(getline(newfile, tp)){ //read data from file object and put it into string.
 
            //cout << tp << "\n"; //print the data of the string
        }
        newfile.close(); //close the file object.
    }
}