#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath> 
#include <vector>

using namespace std;

struct nodo
{
    string tipo;
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
    int maxDistance;
    float speed;
    int serviceTime;
    int refuelTime;

    //Variables de los nodos
    int nodId;
    string type;
    double longitude;
    double latitude;

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
    string tp;
    double result;
    vector<int> vClientes;
    vector<int> vEstaciones;
    vector<int> vecTemp;
   
    fstream newfile;

    newfile.open("AB101.dat",ios::in);

    newfile >> name >> costumers >> stations >> maxTime >> maxDistance >> speed >> serviceTime >> refuelTime;


    loop = costumers + stations;
    struct nodo nodArray[loop];
    double matrizDistancias[loop][loop];

    // Punto de partida

    newfile >> nodId >> type >> longitude >> latitude;

    nodArray[contador].id =  nodId;
    nodArray[contador].tipo = type;
    nodArray[contador].longitud = longitude;
    nodArray[contador].latitud = latitude;
    nodArray[contador].index = contador;
    contador =  contador + 1;

    cout << nodArray[0].id  << "\n";
    cout << nodArray[0].tipo  << "\n";
    cout << nodArray[0].longitud  << "\n";
    cout << nodArray[0].latitud  << "\n";
        
    // Se salta f0 que es igual a d0
    getline(newfile, tp);

        // while(contador < loop){
        //     getline(newfile, tp);
        //     s=std::stringstream();
        //     s.str(tp);
           
        //     s >> nodArray[contador].id;
        //     s >> nodArray[contador].tipo;
        //     nodArray[contador].tipo = "asd";
        //     s >> nodArray[contador].longitud;
        //     s >> nodArray[contador].latitud;
        //     nodArray[contador].index = contador;
        //     contador =  contador + 1;

            
        //     cout << nodArray[contador].tipo << "\n";

        //     if(nodArray[contador].tipo == 'f'){

        //         vEstaciones.push_back(nodArray[contador].index);

        //     }
        //     if(nodArray[contador].tipo == 'c')
        //     {
        //         vClientes.push_back(nodArray[contador].index);
        //     }
            
        // }

        // newfile.close(); //close the file object.


        // // Creacion de la matriz con las distancias
        // for (int i = 0; i < loop -1; i++)
        // {
            
        //     for (int j = i + 1 ; j < loop; j++)
        //     {
        //           result = haversine(nodArray[i].latitud, nodArray[i].longitud,nodArray[j].latitud, nodArray[j].longitud);
        //           matrizDistancias[i][i] = 0.0;
        //           matrizDistancias[i][j] = result;
        //           matrizDistancias[j][i] =  result;
        //     }
            
        // }
        
        // matrizDistancias[loop -1][loop -1] = 0.0;

        // // Creacion de sol inicial

        // for (int i = 0; i < vClientes.size(); i++)
        // {
        //     cout << vClientes[i] << "\n";
        // }

        // for (int i = 0; i < vEstaciones.size(); i++)
        // {
        //     cout << vEstaciones[i] << "\n";
        // }
        
         
        
    
}