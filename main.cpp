#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath> 
#include <vector>
#include <limits>
#include <algorithm>

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
    float  maxTime;
    float maxDistance;
    float speed;
    int serviceTime;
    int refuelTime;

    //Variables de los nodos
    int nodId;
    string type;
    double longitude;
    double latitude;


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
    vector<int> solIncial;
    int flag = 0;
    int intBuffer;
    double dummyResult;
    int indexSave;
    int saveLast;
    float distanceLeft;
    float timeLeft;
    float travelDistance;
    float disExce;
    float tiemExce;
    float calculoAux;
    float calculoAux2;
    float calidadSol;
   
    fstream newfile;

    newfile.open("AB101.dat",ios::in);

    newfile >> name >> costumers >> stations >> maxTime >> maxDistance >> speed >> serviceTime >> refuelTime;


    loop = 1+costumers + stations;
    struct nodo nodArray[loop];
    double matrizDistancias[loop][loop];

    // Punto de partida f0

    newfile >> nodId >> type >> longitude >> latitude;

    nodArray[contador].id =  nodId;
    nodArray[contador].tipo = type;
    nodArray[contador].longitud = longitude;
    nodArray[contador].latitud = latitude;
    nodArray[contador].index = contador;
    contador =  contador + 1;

    // Se salta f0 que es igual a d0
    newfile >> nodId >> type >> longitude >> latitude;

    while(contador < loop){

            newfile >> nodId >> type >> longitude >> latitude;

            nodArray[contador].id =  nodId;
            nodArray[contador].tipo = type;
            nodArray[contador].longitud = longitude;
            nodArray[contador].latitud = latitude;
            nodArray[contador].index = contador;
            
            if(nodArray[contador].tipo == "f"){
                
                vEstaciones.push_back(nodArray[contador].index);

            } else {
                
                vClientes.push_back(nodArray[contador].index);
            }

            contador =  contador + 1;
            
    }

    newfile.close(); //close the file object.


    // Creacion de la matriz con las distancias
    for (int i = 0; i < loop; i++){
        for (int j = i + 1 ; j < loop; j++){
            result = haversine(nodArray[i].latitud, nodArray[i].longitud,nodArray[j].latitud, nodArray[j].longitud);
            matrizDistancias[i][i] = 0.0;
            matrizDistancias[i][j] = result;
            matrizDistancias[j][i] =  result;
        }
            
    }
        
    matrizDistancias[loop -1][loop -1] = 0.0;

    // Creacion de sol inicial

    solIncial.push_back(0);
    distanceLeft = maxDistance;
    timeLeft = maxTime;
    
    vector<int>::iterator buscador;
    while (vecTemp.size() != costumers){
        
        result = std::numeric_limits<double>::max();
        intBuffer = solIncial.back();
        for (int i =   stations; i < loop; i++){
            
            dummyResult = matrizDistancias[intBuffer][i];

            buscador = find(solIncial.begin(),solIncial.end(), i);

            if (buscador == solIncial.end()){
                    
                    saveLast = i;

                if (dummyResult <= result){

                    result = dummyResult;
                    indexSave = i;

                }
                    
            }
                

        }

        if( distanceLeft - matrizDistancias[intBuffer][indexSave] < 0 || timeLeft - serviceTime < 0){
            flag = 1;

        }
              
        if (flag == 0){

            distanceLeft = distanceLeft - matrizDistancias[intBuffer][indexSave];
            timeLeft = timeLeft - serviceTime;

            if (vecTemp.size() == costumers -1){

                solIncial.push_back(saveLast);
                vecTemp.push_back(saveLast);

            } else {
                solIncial.push_back(indexSave);
                vecTemp.push_back(indexSave);
            }  
        } else{
            flag = 0;
            solIncial.push_back(0);
            solIncial.push_back(0);

            distanceLeft = maxDistance;
            timeLeft = maxTime;

        }
        
        
        
    }
    
    solIncial.push_back(0);
    solIncial.push_back(0);
    //sort(solIncial.begin(),solIncial.end());
    // for (int i = 0; i < solIncial.size(); i++){
    //      cout << solIncial[i] - 22<< "\n";
    // }

    // Evaluar calidad

    distanceLeft = maxDistance;
    timeLeft = maxTime;
    travelDistance = 0.0;
    disExce = 0.0;
    tiemExce = 0.0;

    for (int i = 0; i < solIncial.size() -1; i++){
        
        if (solIncial[i] == 0 && solIncial[i+1] == 0){
            i = i +1;
        }
        if (i == solIncial.size()){
            break;
        }
        
        
        if (solIncial[i] != 0 && solIncial[i+1] == 0 ){
            
            calculoAux = distanceLeft - matrizDistancias[solIncial[i]][solIncial[i+1]];
            calculoAux2 = timeLeft - (matrizDistancias[solIncial[i]][solIncial[i+1]])/speed;
            travelDistance = travelDistance + matrizDistancias[solIncial[i]][solIncial[i+1]];

            if (calculoAux < 0){
                disExce = disExce + abs(calculoAux);
            }

            if (calculoAux2 < 0){
                tiemExce = tiemExce + abs(calculoAux2);
            }

            distanceLeft = maxDistance;
            timeLeft = maxTime;
            i = i +1;

        } else{
            if (solIncial[i] <= stations){

                calculoAux = distanceLeft - matrizDistancias[solIncial[i]][solIncial[i+1]];
                calculoAux2 = timeLeft - refuelTime;
                travelDistance = travelDistance + matrizDistancias[solIncial[i]][solIncial[i+1]];

                if (calculoAux < 0){
                    disExce = disExce + abs(calculoAux);
                }

                if (calculoAux2 < 0){
                    tiemExce = tiemExce + abs(calculoAux2);
                }                

                distanceLeft = maxDistance;

            } else{

                calculoAux = distanceLeft - matrizDistancias[solIncial[i]][solIncial[i+1]];
                calculoAux2 = timeLeft - serviceTime;
                travelDistance = travelDistance + matrizDistancias[solIncial[i]][solIncial[i+1]];

                if (calculoAux < 0){
                    disExce = disExce + abs(calculoAux);
                    distanceLeft = 0.0;
                } else{
                    distanceLeft = distanceLeft - calculoAux; 
                }
                

                if (calculoAux2 < 0){
                    tiemExce = tiemExce + abs(calculoAux2);
                    timeLeft = 0.0;
                } else{
                    timeLeft = timeLeft - calculoAux2;
                }
                
                

            }
            
            
        }
        
        
         
         
    }

    cout << travelDistance << "\n";

 


         
        
    
}