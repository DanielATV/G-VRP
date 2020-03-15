#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath> 

using namespace std;

struct nodo
{
    char tipo;
    double latitud;
    double longitud;
    int id;
    int index;
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
    int contador = 0;
    char strTemp;
    string buffer;
    int id;
    char tipo;
    double longitud;
    double latitud;
    double result;

    fstream newfile;

    newfile.open("AB101.dat",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string tp;

        getline(newfile, tp);
        stringstream s(tp); // Used for breaking words 
    
        s >> name;
        s >> costumers;
        s >> stations;
        s >> maxTime;
        s >> speed;
        s >> serviceTime;
        s >> refuelTime;

        loop = costumers + stations;
        struct nodo nodArray[loop];
        
        double matrizDistancias[loop][loop];


        // Punto de partida
        getline(newfile, tp);
        s=std::stringstream();
        s.str(tp);

        s >> nodArray[contador].id;
        s >> nodArray[contador].tipo;
        s >> nodArray[contador].longitud;
        s >> nodArray[contador].latitud;
        nodArray[contador].index = contador;
        contador =  contador + 1;
        
        // Se salta f0 que es igual a d0
        getline(newfile, tp);

        while(contador < loop){
            getline(newfile, tp);
            s=std::stringstream();
            s.str(tp);

            s >> nodArray[contador].id;
            s >> nodArray[contador].tipo;
            s >> nodArray[contador].longitud;
            s >> nodArray[contador].latitud;
            nodArray[contador].index = contador;
            contador =  contador + 1;
        }

        newfile.close(); //close the file object.


        // Creacion de la matriz con las distancias
        for (int i = 0; i < loop -1; i++)
        {
            
            for (int j = i + 1 ; j < loop; j++)
            {
                  result = haversine(nodArray[i].latitud, nodArray[i].longitud,nodArray[j].latitud, nodArray[j].longitud);
                  matrizDistancias[i][i] = 0.0;
                  matrizDistancias[i][j] = result;
                  matrizDistancias[j][i] =  result;
            }
            
        }
        
        matrizDistancias[loop -1][loop -1] = 0.0;

         
         

        cout << matrizDistancias[3][4] << "\n";


        
    }
}