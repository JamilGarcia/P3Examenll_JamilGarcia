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
    //cout << "lista: " << lista[0] << endl; 
    int PGan = stoi(lista[1]);
    //cout << "lista: " << lista[1] << endl; 
    int PEmp = stoi(lista[2]);
    //cout << "lista: " << lista[2] << endl; 
    int PPer = stoi(lista[3]);
    //cout << "lista: " << lista[3] << endl; 
    int Gfav = stoi(lista[4]);
    //cout << "lista: " << lista[4] << endl; 
    int Gcon = stoi(lista[5]);
    //cout << "lista: " << lista[5] << endl; 
    Equipo* equip = new Equipo(nombre, PGan, PEmp, PPer, Gfav, Gcon);
    equip ->to_string(); 
    return equip;
}

int main()
{
    string argv = "Prueba.txt";
    string Stemp = lectura(argv), temporal, nuevo;
    vector<string> listaAtri;
    listaAtri.resize(6);
    int contTemp = 0;
    cout << Stemp << endl;
    nodo* topepila = nullptr;
    bool inicioDeLista = false;
    nodo* primerNodo = nullptr;

    for (int i = 0; i < Stemp.length(); i++)
    {
        if (Stemp[i] == '\n')
        {
            if (!inicioDeLista)
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
    
}