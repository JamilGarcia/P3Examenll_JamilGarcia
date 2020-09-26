#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "nodo.hpp"
using namespace std;

string lectura(string nArchv)
{
    ifstream archivo;
    string texto, textoTot = "";

    archivo.open(nArchv.c_str(), ios::in);

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    while (!archivo.eof())
    {
        getline(archivo, texto);
        textoTot += texto + '\n';
    }

    archivo.close();
    return textoTot;
}

Equipo *CrearEquip(vector<string> lista)
{
    string nombre = lista[0]; 
    int PGan = stoi(lista[1]);
    int PEmp = stoi(lista[2]);
    int PPer = stoi(lista[3]);
    int Gfav = stoi(lista[4]);
    int Gcon = stoi(lista[5]);
    Equipo* equip = new Equipo(nombre, PGan, PEmp, PPer, Gfav, Gcon);
    equip ->to_string(); 
    return equip;
}

void Ordenamiento(nodo* Node){
    int TempPun = Node->getEquipo()->getPuntos(); 
    nodo *Node2 = Node->next_node(); 
    int TempPun2 = Node2->getEquipo()->getPuntos(); 
    while(Node != nullptr){
        if(TempPun <= TempPun2){
            Node2 = Node2->next_node(); 
            TempPun2 = Node2->getEquipo()->getPuntos(); 
        } else if(TempPun > TempPun2){
            TempPun = TempPun2; 
            Node = Node2; 
            Node2 = Node2->next_node(); 
            TempPun2 = Node2->getEquipo()->getPuntos(); 
        }
    }

    //Imprimir Ordenado
    Node->to_Nstring(); 

}

int main()
{
    string argv = "Prueba.txt";
    string Stemp = lectura(argv), temporal, nuevo;
    vector<string> listaAtri;
    listaAtri.resize(6);
    int contTemp = 0;
    nodo* topepila = nullptr;
    bool inicioDeLista = false;
    nodo* primerNodo;

    cout << "            " << "PJ   G   E   P  GA  GC  DG  PTS" <<endl; 
    for (int i = 0; i < Stemp.length(); i++)
    {
        if (Stemp[i] == '\n')
        {
            if (inicioDeLista == false)
            {
                listaAtri[contTemp] = temporal;
                Equipo *Equip = CrearEquip(listaAtri);
                primerNodo = new nodo(Equip);
                primerNodo->setNext_node(topepila);
                topepila = primerNodo;
                temporal = "";
                contTemp = 0;
                inicioDeLista = true;
            }
            else
            {
                //cout << "Temp " << temporal << endl; 
                listaAtri[contTemp] = temporal;
                Equipo *Equip = CrearEquip(listaAtri);
                nodo *nuevo = new nodo(Equip);
                nuevo->setNext_node(topepila);
                topepila = nuevo;
                temporal = "";
                contTemp = 0;
            }
        }
        else if (Stemp[i] == ',')
        {
            //cout << "temp " << temporal << endl; 
            listaAtri[contTemp] = temporal;
            temporal = "";
            contTemp++;
        }
        else
        {
            temporal += Stemp[i];
        }
    }
    
    primerNodo->to_Nstring(); 
    Ordenamiento(primerNodo); 
    
    
    
}