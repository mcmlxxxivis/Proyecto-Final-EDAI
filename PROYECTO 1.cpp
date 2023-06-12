#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
	char NomCan[50];
	int num;
	struct nodo *Sig;
	struct nodo *Ant;
};

typedef struct nodo nodo;

nodo *Pri=NULL;
nodo *Ult=NULL;

int pos;

void MenuAgregar(), MenuEliminar(), Mostrar(); 

int main(){
	int op;
	do{
		printf("-----Reproductor de musica-----\n\n");
		printf("Bienvenido al menu principal\n");
		printf("Ingrese la opcion que desea realizar\n");
		printf("1. Men%c para agregar canciones\n2. Men%c para eliminar canciones\n3. Men%c de reproduccion\n4. Salir del reproductor\n",163,163,163);
		scanf("%d", &op);
		switch(op){
			case 1: MenuAgregar(); break;
			case 2: MenuEliminar(); break;
			case 3: Mostrar(); break;
			case 4: printf("Gracias por escuchar, hasta luego!"); break;
			default: printf("Ingrese una opcion valida"); break;
		}
	} while(op!=4);
	return 0;
}

void MenuAgregar(){
	int opa;
	char can[50],cadena[100],otro[100];
	system("cls");
	printf("Bienvenido al men%c para agregar canciones\n",163);
	do{
	printf("\nIngrese la opci%cn que desea realizar\n",162);
	printf("1. Agregar canci%cn al inicio de la playlist\n2. Agregar canci%cn al final de la playlist\n3. Elegir posici%cn a ingresar\n4. Regresar a men%c principal\n",162,162,162,163);
	scanf("%d", &opa);
	
	switch(opa){
		case 1:
			printf("**Ingresa el nombre de la canci%cn que deseas agregar al inicio de la playlist**\n",162);
			//crear nodos de nombre y numero de la cancion para agregar al inicio 
			nodo *Nuevo;
			Nuevo=(nodo*)malloc(sizeof(nodo));
			printf("Dame el nombre de la canci%cn: ",162);
			fflush(stdin);
			gets(Nuevo->NomCan);
			strcpy(cadena,Nuevo->NomCan);
			FILE *Arch;
			Arch=fopen("Nombre_de_canciones.txt","r");
			if(Arch==NULL)
				printf("Contacta al servicio tecnico para que te proporciones un catalogo de canciones");
			else{
				int exis=0;
				while(feof(Arch)==0){
					//fscanf(Arch,"%s",can);Corregir error, no lee toda la cadena.
					fgets(can,100,Arch);
					if(strcmp(cadena,can)==0)
						exis=1;
				}
				if(exis==1){
					printf("Si tenemos esa canci%cn\n",162);
					if(Pri==NULL){
						Pri=Nuevo;
						Ult=Nuevo;
						Pri->Ant=NULL;
						Pri->Sig=NULL;
					}else{
						Ult->Sig=Nuevo;
						Nuevo->Ant=Ult;
						Ult=Nuevo;
						Nuevo->Sig=NULL;
						Pri->Ant=NULL;
					}
				}else{
					printf("No tenemos esa canci%cn\n",162);	
				}
			}
		break;
		case 2:
			printf("Ingresa el nombre de la canci%c que deseas agregar al final de la playlist ",162);
			//crear nodo y agregar al final, sino la final se agrega al inicio
		break;
		case 3:
			printf("Ingresa la posici%cn en la que deseas agregar la canci%cn ",162,162);
			scanf("%d",pos);
			printf("Ingrese el nombre de la cancion");
			//NomCan = get();
			//crear nodo para agragar, debe de evaluar que exista la posiciòn
		break; 
		case 4: printf("Tu playlist se ha actualizado\n"); break;
		default: printf("Ingrese una opci%cn valida",162); break;
		}
	} while(opa!=4);
	printf("Se ha ingresado correctamente la canci%cn\n\n",162);
	system("pause");
	system("cls");
}

void MenuEliminar(){
	int ope;
	printf("Bienvenido al menu para eliminar canciones");
	do{
	printf("Ingrese la opcion que desea realizar");
	printf("1. Eliminar cancion al inicio de la playlist\n2. Eliminar cancion al final de la playlist\n3. Elegir posicion a eliminar\n4. Regresar a menu principal");
	scanf("%d", &ope);
	
	switch(ope){
		case 1:
			printf("Se eliminará la primer canción de la playlist",162);
			//
		break;
		case 2:
			printf("Se eliminará la ultima cancion de la playlist",162);
			//
		break;
		case 3:
			printf("Ingrese la posicion en la que se encuentra la cancion que desea eliminar",162,162);
			scanf("%d",pos);
			//
		break; 
		case 4: printf("Tu playlist se ha actualizado"); break;
		default: printf("Ingrese una opcion valida"); break;
		}
	} while(ope!=4);
	printf("Se ha eliminado correctamente la cancion");
}

void Mostrar(){
	int opm;
	printf("Bienvenido al menu de reproduccion");
	do{
		printf("Ingrese la opcion que desea realizar");
		printf("1. Mostrar playlist general\n2. Mostrar playlist aleatoria\n3. Regresar a menu principal\n");
		scanf("%d", &opm);
		switch(opm){
			case 1: printf("Playlist general\n");
					int opp;
					do{ printf("Ingrese la opcion que desea realizar");
					printf("1. Reproducir de inicio a fin\n 2. Reproducir en aleatorio\n3. Elegir cancion a reproducir\n4. Regresar a menu de reproduccion");
					scanf("%d", &opp);
					switch(opp){
						case 1: printf("Reproduccion de inicio a fin\n"); break;
						case 2: printf("Reproduccion en aleatorio\n"); break;
						case 3: printf("Elegir cancion\n"); break; 
						case 4: printf("Regresando a menu de reproduccion...\n"); break;
						default: printf("Ingrese una opcion valida\n"); break;
						}
					}while(opp!=4);
			break;
			 
			case 2: printf("Playlist aleatoria\n");
					//crear playlist
					int oppp;
					do{ printf("Ingrese la opcion que desea realizar");
					printf("1. Reproducir de inicio a fin\n 2. Reproducir en aleatorio\n3. Elegir cancion a reproducir\n4. Regresar a menu de reproduccion");
					scanf("%d", &oppp);
					switch(opp){
						case 1: printf("Reproduccion de inicio a fin\n"); break;
						case 2: printf("Reproduccion en aleatorio\n"); break;
						case 3: printf("Elegir cancion\n"); break; 
						case 4: printf("Regresando a menu de reproduccion...\n"); break;
						default: printf("Ingrese una opcion valida\n"); break;
						}
					}while(opp!=4);
			break;
			
			case 3: printf("Tu playlist se ha actualizado\n"); break;
			default: printf("Ingrese una opcion valida\n"); break;
		}
	} while (opm!=3);
}
