#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath> 

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

static double haversine(double lat1, double lon1, 
                        double lat2, double lon2) 
    { 
        // distance between latitudes 
        // and longitudes 
        double dLat = (lat2 - lat1) * 
                      M_PI / 180.0; 
        double dLon = (lon2 - lon1) *  
                      M_PI / 180.0; 
  
        // convert to radians 
        lat1 = (lat1) * M_PI / 180.0; 
        lat2 = (lat2) * M_PI / 180.0; 
  
        // apply formulae 
        double a = pow(sin(dLat / 2), 2) +  
                   pow(sin(dLon / 2), 2) *  
                   cos(lat1) * cos(lat2); 
        double rad = 4182.44949; 
        double c = 2 * asin(sqrt(a)); 
        return rad * c; 
    }
int main(){

    //Variables del archivo
    string name;
    int costumers;
    int stations;
    int maxTime;
    int maxDistnace;
    int speed;
    int serviceTime;
    int refuelTime;

    // Variables para calcular la distancia
    double lat1; 
    double lon1; 
    double lat2; 
    double lon2;

    // Variables del main
    int loop;

    fstream newfile;

    newfile.open("AB101.dat",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string tp;

        getline(newfile, tp);
	
        stringstream s(tp); // Used for breaking words 
        string word; // to store individual words 
    
        s >> name;
        s >> costumers;
        s >> stations;
        s >> maxTime;
        s >> speed;
        s >> serviceTime;
        s >> refuelTime;


        while(getline(newfile, tp)){ //read data from file object and put it into string.
 
            //cout << tp << "\n"; //print the data of the string
        }
        newfile.close(); //close the file object.
    }
}