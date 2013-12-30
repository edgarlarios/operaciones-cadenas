//nombre: EDGAR CELESTINO LARIOS AMEZCUA
  
#include <cstdlib>
#include <iostream>
#include<cstdio>
#define strg 100

using namespace std;

 char A[strg]="";
 char B[strg]="";
 int contador=0;
 int longitud=0;
 bool resultado= true;
 int num=0;
  
 //tamaño de la cadena
 int length(char *str){     //recibe como argumento una cadena ingresada
     contador=0;             //y con el contador determinar la cantidad de caracteres 
    while(*str != '\0'){     //de la cadena por medio del while
               contador++;   //retornando al final el valor de contador. 
               str++;
               
               }
               return contador;
}

char *pow(char *s, int n){                   //recibe como argumento una cadena y un numero entero
                                             //y al momento de ejecucion de este  crea un arreglo dinamico
    contador= 0;                             //con el tamaño exacto de la nueva palabra calculando la longitud.
    int j= 0, i= 0;                           //de la cadena multiplicada por su potencia ingresada.
    int len= (length(s) *n) +1;                //utilizando dos for para pasar los valores de la cadena 
    char *resultado = (char*) malloc (len);    //al nuevo arreglo dinamico las veces indicadas para despues retornarlo.
    int contador2=0;
    
    for(j=0; j<n;j++){
        for(i= 0; i<length(s); i++){              
               resultado[contador2]= s[i];
               contador2++;                            
        }   
    }  
    resultado[contador2]='\0';
    return resultado;    
}   


char *cat(char *cad1,char *cad2){
     
     int len=((length(cad1))+(length(cad2))+1);  //recibe como parametro dos cadenas diferentes o iguales
     char *conca= new char[len];                //con el fin de concatenarlas creando un arreglo dinamico
     int w=0;                                   //con la longitud obtenida de las dos cadenas
     while(*cad1 != '\0'){                      //y guardar las cadenas en el con la longitud que se necesite.
                conca[w]=*cad1;
                cad1++;
                w++;
     }
     while(*cad2 != '\0'){
                conca[w]=*cad2;
                cad2++;
                w++;
     }
     conca[w]='\0';
     return conca;
}
 
                
bool equals(char *str, char *str1){
    bool resultado = false;                 //recibe como parametro 2 cadenas que son comparadas
                                             //caracter por caracter para determinar si son iguales o no                                             //
    while((*str !='\0')&&(*str1 !='\0')){    //al momento que no coincidan los caracteres retorna false          
         if(*str==*str1){
               str++;
               str1++;
               resultado= true;
         }
         if(*str != *str1){
               resultado=false;
               break;
         } 
    }
    return resultado;
}   


void alpha(char *str2){              //funcion para la obtencion del alfabeto minimo
                                     //recibe como parametro una cadena donde se almacena en otro arreglo
    char temp;                       //de caracteres por medio de un while.
    char cadena[strg]="";            //por el metodo burbuja se ordenaran las letras de la cadena
    int m=0,l=0;                      //para despues ser comparado el primer caracter con el segundo y si son
    int longCad = length(str2);      //iguales recorrer los caracteres un espacion anterior para dejar
                                     //solo los caracteres sin repeticion.
    while(*str2 != '\0' ){
		  cadena[l]=*str2;
		  str2++;
		  l++;
     } 
     
    for(int i=0; i<longCad-1; i++){
            for(int j=0; j<longCad-1; j++){
                    if(cadena[j] > cadena[j+1]){                                                           
                              temp= cadena[j];
                              cadena[j]=cadena[j+1];
                              cadena[j+1]=temp;                               
                     }         
             }                  
    }  
      
    l=0,m=0;    
    while( l <= longCad){ 
                
       if((cadena[l]==cadena[l+1]) && (cadena[l] != '\0')){                                      
          for(int i=m; i<longCad; i++){
                 cadena[i]=cadena[i+1];                 
          }        
       }
       else{           
          m++;
          l++;
       }
     }
     
    l=0;     
    cout<<"alfabeto de la cadena: [";     
   while(cadena[l] != '\0' ){
       cout<<cadena[l]<<",";
       l++;
      
    } 
    cout<<"]"<<endl;
   
}             
                                            


int main()
   {
        
    int opc=0,potenciaN;                
    while(opc!=6){
           
      cout<<" presiona 1 para ingresar una cadena"<<endl;
      cout<<" presiona 2 para mostrar el alfabeto minimo y longitud de la cadena"<<endl; 
      cout<<" presiona 3 para determinar si ambas cadenas son iguales"<<endl; 
      cout<<" presiona 4 para calcular la concatenacion de ambas cadenas y su longitud "<<endl;
      cout<<" presiona 5 para calcular la n-esima potencia de ambas cadenas"<<endl;
      cout<<" presione 6 para salir"<<endl;       
      cin>>opc;
      
      switch(opc){
        
        case 1: 
             num=0;         
             cout<<"presione 1 para ingresar cadena A "<<endl;
             cout<<"presione 2 para ingresar cadena B "<<endl;
             cin>>num;
     
             if(num==1){
                num=0;
                cout<<"ingrese cadena A: ";
                cin>>A;
                cout<<" presiona 3 para regresar al menu ";
                cin>>num;
                
                if(num==3){
                            system("cls");
                }
             }
             if(num==2){
                num=0;
                cout<<"ingrese cadena B: ";
                cin>>B; 
                cout<<" presiona 3 para regresar al menu ";
                cin>>num;
                if(num==3){
                            system("cls");
                }
             }            
             break;
             
         case 2:  
             alpha(A);
             longitud=0;
             longitud= length(A);
             cout<<"longitud de A: "<<longitud;
             cout<<endl; 
             cout<<endl;                             
              
             alpha(B); 
             longitud=0;
             longitud= length(B);
             cout<<"longitud de B: "<<longitud;
             cout<<endl;
             num=0;     
             cout<<" presiona 3 para regresar al menu ";
             cin>>num;
             if(num==3){
                        system("cls");
              }      
                            
             break;
                                
         case 3:
            
             resultado= equals(A,B);
             if(resultado==true){
                                 cout<<"las cadenas A y B son iguales"<<endl;
             }
             else{
                   cout<<"las cadenas A y B no son iguales"<<endl;
             }
             num=0;     
             cout<<" presiona 3 para regresar al menu ";
             cin>>num;
             if(num==3){
                        system("cls");
              }         
             break;           
                         
         case 4:
             
              cout<<A<<endl;
              char *concaten;
              concaten=cat(A,B);
              cout<<"la concatenacion de A con B es: "<<concaten<<endl; 
              longitud=0;
              longitud= length(concaten);
              cout<<"la longitud es: "<<longitud<<endl;
              delete(concaten);
              cout<<endl; 
              cout<<B<<endl;             
              concaten=cat(B,A);
              cout<<"la concatenacion de B con A es: "<<concaten<<endl; 
              longitud=0;
              longitud= length(concaten);
              cout<<"la longitud es: "<<longitud<<endl;
              delete(concaten); 
              
              num=0;
              cout<<" presiona 3 para regresar al menu ";
              cin>>num;
              if(num==3){
                            system("cls");
              }                                   
              break;                         
                         
       case 5:
              cout<<"ingrese potencia: ";
              cin>>potenciaN; 
              char*potencia1;
              potencia1= pow(A ,potenciaN);
              cout<<"la potencia "<<potenciaN<<" de la cadena A es: "<<potencia1; 
              cout<<endl;
               
              char*potencia2;
              potencia2= pow(B,potenciaN);
              cout<<"la potencia "<<potenciaN<<" de la cadena B es: "<<potencia2; 
              cout<<endl; 
               
              num=0;
              cout<<" presiona 3 para regresar al menu ";
              cin>>num;
              if(num==3){
                            system("cls");
              }              
              break;                       
       }
    }             
    system("PAUSE>nul");
    return EXIT_SUCCESS;
   
}

     


     
     







