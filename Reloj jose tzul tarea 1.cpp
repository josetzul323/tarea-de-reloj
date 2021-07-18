#include <iostream>
#include <conio.h>
#include <stdio.h>  
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
 
using namespace std;

struct structAlarma
{
    char id[10];
    char nombre[10];
    int horas;
    int minutos;
    int segundos;
};

const bool debug = false;
const int debugSleep = 100;
const int anchoPantalla = 77;
const int altoPantalla = 24;

int horas, minutos, segundos;
    
enum eNumero {NUMERO_CERO, NUMERO_UNO, NUMERO_DOS, NUMERO_TRES, NUMERO_CUATRO, NUMERO_CINCO, NUMERO_SEIS, NUMERO_SIETE, NUMERO_OCHO, NUMERO_NUEVE};
enum eColumna {COLUMNA_CERO, COLUMNA_UNO, COLUMNA_DOS, COLUMNA_TRES, COLUMNA_CUATRO, COLUMNA_CINCO, COLUMNA_SEIS, COLUMNA_SIETE, COLUMNA_OCHO};
int columnas[11] = {0, 22, 28, 34, 36, 42, 48, 50, 54};
bool continuar = true;
int y = 0;

char charNSeparador[] = {' ', ' ', '*', ' ', '*'};
char charNCero[] = {'*', '*', '*', '*', '*', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*'};
char charNUno[] = {' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'};
char charNDos[] = {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*'};
char charNTres[] = {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*'};
char charNCuatro[] = {'*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'};
char charNCinco[] = {'*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*'};
char charNSeis[] = {'*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*'};
char charNSiete[] = {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'};
char charNOcho[] = {'*', '*', '*', '*', '*', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*'};
char charNNueve[] = {'*', '*', '*', '*', '*', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*'};

char charNCeroP[] = {'*', '*', '*', '*', ' ', '*', '*', ' ', '*', '*', ' ', '*', '*', '*', '*'};
char charNUnoP[] = {' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*'};
char charNDosP[] = {'*', '*', '*', ' ', ' ', '*', '*', '*', '*', '*', ' ', ' ', '*', '*', '*'};
char charNTresP[] = {'*', '*', '*', ' ', ' ', '*', '*', '*', '*', ' ', ' ', '*', '*', '*', '*'};
char charNCuatroP[] = {'*', ' ', '*', '*', ' ', '*', '*', '*', '*', ' ', ' ', '*', ' ', ' ', '*'};
char charNCincoP[] = {'*', '*', '*', '*', ' ', ' ', '*', '*', '*', ' ', ' ', '*', '*', '*', '*'};
char charNSeisP[] = {'*', '*', '*', '*', ' ', ' ', '*', '*', '*', '*', ' ', '*', '*', '*', '*'};
char charNSieteP[] = {'*', '*', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*'};
char charNOchoP[] = {'*', '*', '*', '*', ' ', '*', '*', '*', '*', '*', ' ', '*', '*', '*', '*'};
char charNNueveP[] = {'*', '*', '*', '*', ' ', '*', '*', '*', '*', ' ', ' ', '*', '*', '*', '*'};

//PROTOTIPADO DE FUNCIONES
void gotoxy(int,int);
void dibujarNumeroSeparador(eColumna, int, int);
void dibujarNumeroGrande(eColumna, int, int);
void dibujarNumeroPequenio(eColumna, int, int);
void iniciarReloj();
void menuOpciones();
void nuevaAlarma();
string GenerarIdAlarma();
bool consultarAlarmas();
//void eliminarAlarma();
bool guardarEnArchivo(string, string, int, int, int);
//bool eliminarDeArchivo(string);
 
int main() {
    y = (altoPantalla - 18) / 2;
    iniciarReloj();
    while(continuar)
    {   
        //SEPARADORES     
        dibujarNumeroSeparador(COLUMNA_TRES, y, segundos);
        dibujarNumeroSeparador(COLUMNA_SEIS, y, segundos);        
        
        //SEGUNDOS
        dibujarNumeroPequenio(COLUMNA_SIETE, y, segundos/10);
        if(segundos < 10) dibujarNumeroPequenio(COLUMNA_OCHO, y, segundos);
        else dibujarNumeroPequenio(COLUMNA_OCHO, y, segundos % 10);                                        
                            
        cout<<endl<<endl<<"          Presione la barra de espacio para acceder al menu de opciones...";
        cout<<endl<<endl;
        consultarAlarmas();
        if(debug) Sleep(debugSleep);
        else Sleep(1000);

        segundos++;
        if(segundos == 60) 
        {
                    segundos = 0;
                    minutos++;
                    if(minutos == 60) 
                    {
                               minutos = 0;
                               horas++;
                               if(horas == 24) horas = 0;
                    }
                    
                    //MINUTOS
                    dibujarNumeroGrande(COLUMNA_CUATRO, y, minutos/10);
                    if(minutos < 10) dibujarNumeroGrande(COLUMNA_CINCO, y, minutos);
                    else dibujarNumeroGrande(COLUMNA_CINCO, y, minutos % 10);                                                          
                    
                    //HORAS
                    dibujarNumeroGrande(COLUMNA_UNO, y, horas / 10);
                    if(horas < 10) dibujarNumeroGrande(COLUMNA_DOS, y, horas);
                    else dibujarNumeroGrande(COLUMNA_DOS, y, horas % 10);                    
        }
        if(kbhit()) if(GetAsyncKeyState(VK_SPACE)) 
        {
                    menuOpciones();
                    iniciarReloj();
        }
    }        
    getch();
}

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}

void dibujarNumeroSeparador(eColumna nColumna, int nFila, int numero)
{
     for(int i = 0; i < sizeof(charNSeparador); i++)
     {
             gotoxy(columnas[nColumna], nFila);
             if(numero % 2 == 0) cout<<charNSeparador[i];
             else 
             {
                  cout<<" ";
                  //Beep(440,500);
             }
             nFila++;
             if(debug) Sleep(debugSleep);
    }     
}

void dibujarNumeroGrande(eColumna nColumna, int nFila, int numero)
{
     int anchoNumero = 4;
     int altoNumero = 6;
     int contador = 0;
     for(int i = 0; i <= altoNumero; i++)
     {
             gotoxy(columnas[nColumna], nFila);
             for(int j = 0; j <= anchoNumero; j++) 
             {
                     switch(numero)     
                     {
                        case NUMERO_CERO:
                             cout<<charNCero[contador];
                        break;
                        case NUMERO_UNO:
                             cout<<charNUno[contador];
                        break;
                        case NUMERO_DOS:
                             cout<<charNDos[contador];
                        break;
                        case NUMERO_TRES:
                             cout<<charNTres[contador];
                        break;
                        case NUMERO_CUATRO:
                             cout<<charNCuatro[contador];
                        break;
                        case NUMERO_CINCO:
                             cout<<charNCinco[contador];
                        break;
                        case NUMERO_SEIS:
                             cout<<charNSeis[contador];
                        break;
                        case NUMERO_SIETE:
                             cout<<charNSiete[contador];
                        break;
                        case NUMERO_OCHO:
                             cout<<charNOcho[contador];
                        break;
                        case NUMERO_NUEVE:
                             cout<<charNNueve[contador];
                        break;                                                                                                                                                                        
                     } 
                     contador++;
                     if(debug) Sleep(debugSleep);
             }
             nFila++;
    }     
}

void dibujarNumeroPequenio(eColumna nColumna, int nFila, int numero)
{
     int anchoNumero = 2;
     int altoNumero = 4;
     int contador = 0;
     nFila = nFila + 2;
     for(int i = 0; i <= altoNumero; i++)
     {
             gotoxy(columnas[nColumna], nFila);
             for(int j = 0; j <= anchoNumero; j++) 
             {
                     switch(numero)     
                     {
                        case NUMERO_CERO:
                             cout<<charNCeroP[contador];
                        break;
                        case NUMERO_UNO:
                             cout<<charNUnoP[contador];
                        break;
                        case NUMERO_DOS:
                             cout<<charNDosP[contador];
                        break;                        
                        case NUMERO_TRES:
                             cout<<charNTresP[contador];
                        break;
                        case NUMERO_CUATRO:
                             cout<<charNCuatroP[contador];
                        break;
                        case NUMERO_CINCO:
                             cout<<charNCincoP[contador];
                        break;
                        case NUMERO_SEIS:
                             cout<<charNSeisP[contador];
                        break;
                        case NUMERO_SIETE:
                             cout<<charNSieteP[contador];
                        break;
                        case NUMERO_OCHO:
                             cout<<charNOchoP[contador];
                        break;
                        case NUMERO_NUEVE:
                             cout<<charNNueveP[contador];
                        break;
                     } 
                     contador++;
                     if(debug) Sleep(debugSleep);
             }
             nFila++;
    }     
}

void iniciarReloj()
{
     if(debug)
     {
          horas = 23;
          minutos = 59;
          segundos = 58;
     }
     else
     {         
         time_t now = time(0);
         tm * time = localtime(&now);
         segundos = time->tm_sec; // seconds of minutes from 0 to 61
         minutos = time->tm_min; // minutes of hour from 0 to 59
         horas = time->tm_hour; // hours of day from 0 to 24                     
     }
     dibujarNumeroSeparador(COLUMNA_TRES, y, NUMERO_CERO);        
     dibujarNumeroSeparador(COLUMNA_SEIS, y, NUMERO_CERO);
     
     //SEGUNDOS
     dibujarNumeroPequenio(COLUMNA_SIETE, y, segundos/10);
     if(segundos < 10) dibujarNumeroPequenio(COLUMNA_OCHO, y, segundos);
     else dibujarNumeroPequenio(COLUMNA_OCHO, y, segundos % 10);
     
     //MINUTOS
     dibujarNumeroGrande(COLUMNA_CUATRO, y, minutos/10);
     if(minutos < 10) dibujarNumeroGrande(COLUMNA_CINCO, y, minutos);
     else dibujarNumeroGrande(COLUMNA_CINCO, y, minutos % 10);     
     
     //HORAS
     dibujarNumeroGrande(COLUMNA_UNO, y, horas / 10);
     if(horas < 10) dibujarNumeroGrande(COLUMNA_DOS, y, horas);
     else dibujarNumeroGrande(COLUMNA_DOS, y, horas % 10);
}

void menuOpciones()
{
     enum opcionMenu {NADA, PROGRAMAR_ALARMA, ELIMINAR_ALARMA, REGRESAR, SALIR};
     int opcionUsuario = 0;
     system("CLS");
     cout<<"MENU DE OPCIONES"<<endl;
     cout<<"================"<<endl<<endl;
     cout<<"\t1. Crear alarma"<<endl;
     cout<<"\t2. Eliminar alarma"<<endl;
     cout<<"\t3. Regresar"<<endl;
     cout<<"\t4. Salir"<<endl<<endl;
     cout<<"Seleccione una opcion: ";
     cin>>opcionUsuario;
     
     switch(opcionUsuario)
     {
                          case PROGRAMAR_ALARMA:
                               nuevaAlarma();
                               break;
                          case ELIMINAR_ALARMA:
                               cout<<"ELIMINAR ALARMA";
                               break;
                          case REGRESAR:
                               system("CLS");                        
                               break;
                          case SALIR:
                               char salir;
                               cout<<endl<<endl<<"Seguro que desea salir (Y/N)... ";
                               cin>>salir;
                               if(salir == 'Y' || salir == 'y') exit(0);
                               else if(salir == 'N' || salir == 'n') menuOpciones();
                               else 
                               {
                                    cout<<"Opcion incorrecta, presione cualquier tecla para continuar... ";
                                    getch();
                                    menuOpciones();
                               }
                               break;
                          default:
                               cout<<"Opcion incorrecta, presione cualquier tecla para continuar... ";
                               getch();
                               menuOpciones();
                               break;
     }
}

void nuevaAlarma()
{
     bool continuar = true;
     char respuesta = 's';
     string idNA;
     string nombreNA;         
     int horasNA, minutosNA, segundosNA;
         
     while(continuar)
     {
         cin.get();
         system("CLS");                  
         consultarAlarmas();

         cout<<endl<<endl<<"NUEVA ALARMA"<<endl;
         cout<<"============"<<endl<<endl;                  
         idNA = GenerarIdAlarma();
         cout<<"Id: "<<idNA<<endl;
         cout<<"Nombre: ";
         getline(cin, nombreNA);
         cout<<"Horas: ";
         cin>>horasNA;
         cout<<"Minutos: ";
         cin>>minutosNA;
         cout<<"Segundos: ";
         cin>>segundosNA;
         
         if(horasNA >= 0 && horasNA <= 23 && minutosNA >= 0 && minutosNA <= 59 && segundosNA >= 0 && segundosNA <= 59)
         {
            bool resultado = guardarEnArchivo(idNA, nombreNA, horasNA, minutosNA, segundosNA);
            cout<<endl<<endl<<"Desea crear otra alarma Y/N? ";
            cin>>respuesta;
            
            if(respuesta == 's' || respuesta == 'S') continuar = true;
            else if (respuesta == 'n' || respuesta == 'N')
            {
                cout<<endl<<endl<<"Gracias por su preferencia.";
                cout<<endl<<endl;
                continuar = false;
                cin.get();
                system("CLS");
                //system("pause");
            }
            else
            {
                cout<<endl<<endl<<"Opcion incorrecta, intente de nuevo!";
                cout<<endl<<endl;
                continuar = false;
                cin.get();
                //system("pause");
            }
         }
         else
         {
             cout<<endl<<endl<<"Hora no válida, intente de nuevo!";
             cout<<endl<<endl;
             continuar = true;
             cin.get();
             //system("pause");
         }
     }
     
}

bool guardarEnArchivo(string idAlarma, string nombreAlarma, int horasAlarma, int minutosAlarma, int segundosAlarma)
{    
    //object of fstream class
    fstream file;    
    //opening file "sample.txt" in out(write) mode
    file.open("ARCHIVO_ALARMAS.txt",ios::out | ios::app);   
    if(!file)
    {
       cout<<"Error in creating file!!!"<<endl;
       return false;
   }
    
    file<<idAlarma<<","<<nombreAlarma<<","<<horasAlarma<<","<<minutosAlarma<<","<<segundosAlarma<<endl;       
    file.close();
        
    cout<<endl<<endl<<"Alarma almacenada exitosamente: "<<idAlarma<<endl;     
    return true;
}

string GenerarIdAlarma()
{
    time_t current_time;
    struct tm * time_info;
    char timeString[80];
    
    time(&current_time);
    time_info = localtime(&current_time);
    
    strftime(timeString, sizeof(timeString), "%d%m%Y%H%M%S", time_info);
    //puts(timeString);
    
    //cin.get();
    return timeString;
}

bool consultarAlarmas()
{
    cout<<"ALARMAS YA EXISTENTES"<<endl;
    cout<<"=================="<<endl<<endl;
    cout<<left<<setw(4)<<setfill(' ')<<"No."<<setw(21)<<setfill(' ')<<"Id"<<setw(25)<<setfill(' ')<<"Nombre"<<setw(17)<<setfill(' ')<<"Hora";
    
    int numero = 1;
    structAlarma alarma;
    
    // File pointer
    fstream fin;
    
    // Open an existing file
    fin.open("ARCHIVO_ALARMAS.txt", ios::in);    
    
    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word, temp;
    
    while (fin.good()) 
    {
        row.clear();
        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ',')) row.push_back(word);
                
        if(row.empty() == false)
        {
            cout<<endl;
            cout<<right<<setfill('0')<<setw(2)<<numero<<setfill(' ')<<setw(2)<<""<<left<<setw(21)<<row[0]<<setw(25)<<row[1]<<right<<setw(2)<<setfill('0')<<row[2]<<":"<<setw(2)<<setfill('0')<<row[3]<<":"<<setw(2)<<setfill('0')<<row[4];
            numero++;
        }        
    }       
}
