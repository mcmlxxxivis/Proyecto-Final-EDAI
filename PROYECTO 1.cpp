#include <stdio.h>
#include <windows.h>

struct nodo{
	char NomCan;
	int num;
	struct nodo *sig;
	struct nodo *ant;
};

typedef struct nodo nodo;

int pos;

void MenuAgregar(), MenuEliminar(), Mostrar(), CrearAleatoria(); 

int main(){
	int op;
	printf("-----Reproductor de musica-----");
	do{
	printf("Bienvenido al menu principal");
	printf("Ingrese la opcion que desea realizar");
	printf("1. Menú para agregar canciones\n2. Menú para eliminar canciones\n3. Menu de reproduccion\n4. Salir del reproductor");
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
	printf("Bienvenido al menu para agregar canciones");
	do{
	printf("Ingrese la opcion que desea realizar");
	printf("1. Agregar cancion al inicio de la playlist\n2. Agregar cancion al final de la playlist\n3. Elegir posicion a ingresar\n4. Regresar a menu principal");
	scanf("%d", &opa);
	
	switch(opa){
		case 1:
			printf("Ingresa el nombre de la canci%c que deseas agregar al inicio de la playlist",162);
			//crear nodos de nombre y numero de la cancion para agregar al inicio 
		break;
		case 2:
			printf("Ingresa el nombre de la canci%c que deseas agregar al final de la playlist",162);
			//crear nodo y agregar al final, sino la final se agrega al inicio
		break;
		case 3:
			printf("Ingresa la posicion en la que deseas agregar la cancion",162,162);
			scanf("%d",pos);
			printf("Ingrese el nombre de la cancion")
			NomCan = get();
			//crear nodo para agragar, debe de evaluar que exista la posiciòn
		break; 
		case 4: printf("Tu playlist se ha actualizado"); break;
		default: printf("Ingrese una opcion valida"); break;
		}
	} while(op!=4);
	printf("Se ha ingresado correctamente la cancion");
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
	} while(op!=4);
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
