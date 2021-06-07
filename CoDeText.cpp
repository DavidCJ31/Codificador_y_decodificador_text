#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;
class Coleccion {
private:
	char frase[250];
	int tamano;
	int cantidad;
public:
	Coleccion(int n) {
		cantidad=0;
		tamano= n;
		for(int i=0;i< tamano;i++)
			frase[i]=' '; }
	~Coleccion(){}
	int getCantidad(){
		return this->cantidad;}
	int getTamano(){
		return this->tamano; }
	void setCantidad(int cantidad){
		this->cantidad=cantidad; }
	void setTamano(int tamano){
		this->tamano=tamano; }
	void InsertarElemento(char elem ){
		if (cantidad < tamano){
			frase[cantidad]=elem;
			cantidad++;}
		else
			cout<<"no hay mas espacio en el vector"<<endl; }
	string toString(){
	stringstream s;
	for(int i=0;i<cantidad;i++)
		s<<frase[i];
		s<<endl;
	return s.str(); 
	}
	bool Repetidos(char letra, int pos){
		for(int i = 0; i < pos; i++ ){
			if(letra == frase[i])
				return true;
		}
		return false;
	}
	void generarClave(){
		char letra;
		for(int i = 0; i < 95; i++){
			do{
				letra = 32 + rand() % ((126 + 1) - 32);
			}while(Repetidos(letra , i ) == true);
			frase[i] = letra;
			setCantidad(cantidad + 1);
		}
	}
	
	void Ordenar(){
		int aux;
		for(int i = 0; i < cantidad; i++){
			for(int j = i + 1; j < cantidad; j++){
				if( frase[i] > frase[j]){
					aux = frase[j];
					frase[j] = frase[i];
					frase[i] = aux;
				}
			}
		}
	}
	void codificar(Coleccion alfa, Coleccion cla, Coleccion &fra){
		for(int i = 0; i < fra.getCantidad(); i++){
			for(int j = 0; j < alfa.getCantidad(); j++){
				if(fra.frase[i] == alfa.frase[j]){
					fra.frase[i] = cla.frase[j];
					break;
				}
			}
		}
	}
	void decodificar(Coleccion alfa, Coleccion cla, Coleccion &fra){
		for(int i = 0; i < fra.getCantidad(); i++){
			for(int j = 0; j < alfa.getCantidad(); j++){
				if(fra.frase[i] == cla.frase[j]){
				fra.frase[i] = alfa.frase[j];
				break;
				}
			}
		}
	}
	void vaciar(){
		for(int i=0;i<cantidad;i++)
			frase[i]=' ';
	}
};
int main() {
	char c;
	int op;
	char resp='s';
	Coleccion fra(250);
	Coleccion cla(180);
	Coleccion alfa(180);
	alfa.generarClave();
	alfa.Ordenar();
	cla.generarClave();
	do
	{
			cout<<"**********************************"<<endl;
			cout<<"\t MENU PRINCIPAL"<<endl;
			cout<<"**********************************"<<endl;
			cout<<"1. INGRESAR TEXTO A CODIFICAR"<<endl;
			cout<<"2. CODIFICAR"<<endl;
			cout<<"3. DECODIFICAR"<<endl;
			cout<<"4. SALIR"<<endl;
			cout<<"\nDigite opcion: "<<endl;
			cin>>op;
			system("cls");
			if(op==1){
				cout<<"******************************************************************"<<endl;
				cout<<"\tTEXTO A CODIFICAR (250 CARACTERES MAXIMO)"<<endl;
				cout<<"\t\tDIGITE | PARA TERMINAR TEXTO"<<endl;
				cout<<"******************************************************************"<<endl;
				cin>>c;
				while (c!='|')
				{
					fra.InsertarElemento(c);
					cin.get(c);}
				if(c=='|')
					resp='s';
				system("pause");
				system("cls");
			}
			else
			   if(op==2){
				cout<<"*****************************"<<endl;
				cout<<"\tCODIFICADA"<<endl;
				cout<<"*****************************"<<endl;
				fra.codificar(alfa,cla,fra);
				cout<<fra.toString();
				cout<<"*****************************"<<endl;
				system("pause");
			resp='s';
				system("cls");
			}
			   else
				  if(op==3){
				cout<<"*****************************"<<endl;
				cout<<"\tDESCODIFICADA"<<endl;
				cout<<"*****************************"<<endl;
				fra.decodificar(alfa,cla,fra);
				cout<<fra.toString();
				cout<<"*****************************"<<endl;
				system("pause");
				resp='s';
				system("cls");
			   }
				  else
					 if(op==4)
				resp='N';
			else
				if(op!=1&&op!=2&&op!=3&&op!=4){
				cout<<"Solo se pueden usar 1,2,3,4"<<endl;
				resp='s';
				system("pause");
				system("cls");
			}
			system("cls");
	}
	while(resp!='N');
	return 0; 
}
