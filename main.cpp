// Plantilla de un Menú de Opciones

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


//credenciales
string usuario = "PROGRAMADOR";
string clave = "Sust1" ;

int femeninas = 0;
int masculinos = 0;
int noPrecisaGenero = 0;

int femeninasConMochila = 0;
int masculinosConMochila = 0;
int noPrecisaGeneroConMochila = 0;

int menoresDeDiecinueve = 0;
int mayoresIgualesDeDiecinueve = 0;

int factorialMenoresDeDiecinueve = 1;
int factorialMayoresIgualesDeDiecinueve = 1;

int montoTotalRecaudado=0;

//prototipos de las funciones
void autentificarse();

void menu();
void subMenu();
void registrarAlumnos();
void registrarDonaciones();
void reporteTotal();

void evaluarGenero(char genero);
void evaluarMochila(char genero, char mochila);
void evaluarEdad(int edad);
void evaluarMonto(float monto);
long double factorial(int);



int main()
{
    menu(); 
    return 0;
}

void menu()
{
    int opcion;
   	bool repetir = true;

    do
    {
		system("cls");
	
	    cout << "\n\n\t\t\t MENU DE OPCIONES" << endl;
	    cout << "\t\t\t--------------" << endl;
	    cout << "\t   [1] AUTENTICARSE" << endl;
	    cout << "\t   [4] SALIR DEL PROGRAMA" << endl;
	
		cout << "\n";
	    cout << "\t Ingrese una opcion: ";
	    cin >> opcion;
	    cout << "\n";
	
	    switch (opcion)
	    {
	        case 1:
	            autentificarse();
	            break;
	
	        case 4:
	            cout << "\n\t GRACIAS SUSTITUTORIO";
	            repetir = false;
	            break;
	    }
	} while (repetir);
}

//definiciones de las funciones
void autentificarse(){
	
	string user = "";
	string password = "";
	
	cout << "\n";
	
	cout << "\t Ingrese su usuario: ";
    cin >> user;
    
    cout << "\t Ingrese su clave: ";
    cin >> password;
    
    if(user == usuario && password == clave ){
    	  cout << "\t Login Exitoso ";
    	  subMenu();
	}else{
		cout << "\t Error en las credenciales ";
	}
    
}


void subMenu()
{
    int opcion;
   	bool repetir = true;

    do
    {
		system("cls");
	
	    cout << "\n\n\t\t\t SUB MENU DE OPCIONES" << endl;
	    cout << "\t\t\t--------------" << endl;
	    cout << "\t   [2] REGISTRAR DONACIONES" << endl;
	    cout << "\t   [3] REPORTE TOTAL" << endl;
	    cout << "\t   [4] SALIR DEL PROGRAMA" << endl;
	
	    cout << "\n\tIngrese una opcion: ";
	    cin >> opcion;
	
	    switch (opcion)
	    {
	        case 2:
	            registrarDonaciones();
	            break;
	        case 3:
	            reporteTotal();
	            break;	
	        case 4:
	            cout << "\n\t GRACIAS SUSTITUTORIO";
	            repetir = false;
	            break;
	    }
	} while (repetir);
	
	exit(0);
}



void registrarDonaciones()
{
    system("cls");
    
    int numeroSecciones, numeroAlumnos;

	cout << "\n\t[REGISTRO DE DONACIONES]";
    cout << "\n\t========================\n";

    do {
    	cout << "\t Numero de secciones: ";
    	cin >> numeroSecciones;
		if(numeroSecciones <= 0 || numeroSecciones > 2){
        	cout << "\t Dato ingresado incorrecto, el numero de secciones es incorrecto  \n";
		}		  	
	}while(numeroSecciones <= 0 || numeroSecciones > 2);
	
	cout << "\n";
	
	do {
    	cout << "\t Numero de alumnos: ";
    	cin >> numeroAlumnos;
		if(numeroAlumnos <= 0){
        	cout << "\t Dato ingresado incorrecto, el numero de alumnos es incorrecto  \n";
		}		  	
	}while(numeroAlumnos <= 0);

    
    for (int i = 0; i < numeroAlumnos; i++)
    {
        registrarAlumnos();
    }

    
    subMenu();
}

void registrarAlumnos()
{
	string nombres = "";
	string apellidos = "";
	string dni = "";
	char genero = '0';
	char mochila = '0';
	int edad = 0;
	float monto = 0.0f;
	
		
	cout << "\n";
	cout<<"\t -------------------------------------------------------------------------- \n";
	
	do {
	    cout << "\t * Ingrese sus nombres:";
    	cin >> nombres;
		if(nombres == ""){
			cout<<"\t Dato ingresado incorrecto";
		}		  	
	}while(nombres == "");
	
	cout << "\n";
	
	do {
	    cout << "\t * Ingrese sus apellidos:";
    	cin >> apellidos;
		if(apellidos == ""){
			cout<<"\t Dato ingresado incorrecto";
		}		  	
	}while(apellidos == "");
	
	cout << "\n";
	
	do {
	    cout << "\t * Ingrese su DNI:";
    	cin >> dni;
		if(dni.length() < 4 || dni.length() > 4 ){
			cout<<"\t Dato ingresado incorrecto, debe ingresar 4 digitos \n";
		}	
	}while(dni.length() < 4 || dni.length() > 4 );
	
	cout << "\n";
	
	do {
	    cout << "\t * Ingrese su genero [Masculino (M), Femenino (F), No precisa (N)]:";
    	cin >> genero;
		if(genero != 'M' && genero != 'F' && genero != 'N'){
			cout<<"\t Dato ingresado incorrecto, debe ingresar M o F o N\n";
		}		  	
	}while(genero != 'M' &&  genero != 'F' && genero != 'N' );
	
	evaluarGenero(genero);
	
	cout << "\n";

	do {
	    cout << "\t * Usa mochila? SI (S) y NO (N):";
    	cin >> mochila;
		if(mochila != 'S' && mochila != 'N'){
			cout<<"\t Dato ingresado incorrecto, debe ingresar S o N \n";
		}	
	}while(mochila != 'S' &&  mochila != 'N' );
	
	evaluarMochila(genero, mochila);
	
	cout << "\n";

	do {
	    cout << "\t * Ingrese su edad:";
    	cin >> edad;
		if(edad < 0 || edad > 18){
			cout<<"\t Dato ingresado incorrecto, debe ingresar menor o igual a 18 años \n";
		}	
	}while(edad < 0 ||  edad > 18);
	
	evaluarEdad(edad);
	
	cout << "\n";

	do {
	    cout << "\t * Ingrese su monto:";
    	cin >> monto;
		if(monto < 0){
			cout<<"\t Dato ingresado incorrecto, debe ingresar mayor a 0 \n";
		}	
	}while(monto <= 0 );
	
	evaluarMonto(monto);
	
	cout << "\n";
	
}

void evaluarGenero(char genero){
	if(genero == 'M'){
		masculinos++;	
	}
	
	if(genero == 'F'){
		femeninas++;
	}
	
	if(genero == 'N'){
		noPrecisaGenero++;
	}
}

void evaluarMochila(char genero, char mochila)
{
	if(genero == 'F' && mochila == 'S'){
		femeninasConMochila++;
	}
	
	if(genero == 'M' && mochila == 'S'){
		masculinosConMochila++;
	}
	
	if(genero == 'N' && mochila == 'S'){
		noPrecisaGeneroConMochila++;
	}
}


void evaluarEdad(int edad)
{
	if(edad < 19){
		menoresDeDiecinueve++;
	}
	
	if(edad >= 19){
		mayoresIgualesDeDiecinueve++;
	}
}

void evaluarMonto(float monto)
{
	montoTotalRecaudado += monto;
}

long double factorial(int n)
{
    long double fact;
    if (n==0)
        return 1;
    else
         return n*factorial(n-1);
}


void reporteTotal(){
	cout<<"\t Cantidad de alumnas femeninas: "<<femeninas<<endl;
	cout<<"\t Cantidad de alumnos masculinos: "<<masculinos<<endl;
	cout<<"\t Cantidad de alumnos que no precisa su genero: "<<noPrecisaGenero<<endl;
	cout<<"\t Cantidad de alumnas con mochila: "<<femeninasConMochila<<endl;
	cout<<"\t Cantidad de alumnos con mochila: "<<masculinosConMochila<<endl;
	cout<<"\t Cantidad de alumnos que no precisa su genero con mochila: "<<noPrecisaGeneroConMochila<<endl;
	cout<<"\t Cantidad de alumnos menores de 19: "<<menoresDeDiecinueve<<endl;
	cout<<"\t Cantidad de alumnos mayores o igual a 19: "<<mayoresIgualesDeDiecinueve<<endl;
	cout<<"\t Factorial de alumnos menores de 19: "<<factorial(menoresDeDiecinueve)<<endl;
	cout<<"\t Factorial de alumnos mayores o igual a 19: "<<factorial(mayoresIgualesDeDiecinueve)<<endl;
	cout<<"\t Monto total recaudado / 2: "<<montoTotalRecaudado / 2<<endl;
	
	system("pause>nul");
	
}


