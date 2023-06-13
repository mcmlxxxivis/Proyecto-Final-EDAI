#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

struct nodo {
    int num;
    char Artista[50];
    char Album[50];
    char NomCan[50];
    char URL[300];
    struct nodo* Sig;
    struct nodo* Ant;
};

typedef struct nodo nodo;

nodo *Pri=NULL;
nodo *Ult=NULL;
nodo *ObtenerNodoPorIndiceNumero(nodo* lista, int indiceNumero);

void Cuenta(), Playlist();

int main(){

	int op;
	do{
	    system("cls");
        printf("\033[1;33m");
		printf("\t\t            =========================\n");
		printf("\t\t              Reproductor de m%csica\n",163);
		printf("\t\t            =========================\n");
		printf("Recuerda que es necesario crear una cuenta para comenzar a usar el reproductor\n");
		printf("Ingrese la opci%cn que desea realizar\n",162);
		printf("1. Crear o eliminar cuenta\n2. Men%c de playlist\n3. Salir del reproductor\n",163);
		scanf("%d", &op);

		switch(op){
			case 1: Cuenta(); break;
			case 2: Playlist(); break;
			case 3: printf("Gracias por escuchar, hasta luego!\n"); break;
			default: printf("Ingrese una opci%cn correcta\n",162); break;
		}
	}while(op!=3);
	return 0;
}

void Cuenta(){
	int o;
	system("cls");
	do{
    printf("\033[1;34m");
	printf("\t\nGesti%cn de cuenta del usuario\n",162);
	printf("Ingrese la opci%cn que desea realizar\n",162);
	printf("1. Crear cuenta\n2. Eliminar cuenta\n3. Regresar a men%c principal\n",163);
	scanf("%d", &o);
	switch(o){
		case 1:
		system("cls");
		printf("Comencemos a crear tu cuenta...\n");
		//Solicita nombre de usuario
		//Usuario ingresa su nombre
		//Se le asigna un numero de cuenta al usuario
		printf("Tu cuenta ha sido creada con %cxito, no olvides tu n%cmero de cuenta ya que lo necesitar%cs para acciones futuras\n",130,163,160);
		break;

		case 2:
		system("cls");
		printf("\033[1;32m");
		printf("Ingresa el n%cmero de cuenta que deseas eliminar\n",163);
		//eliminar
		printf("La cuenta se ha eliminado con %cxito\n",130);
		break;

		case 3: printf("Regresando a men%c principal...\n",163);  break;
		default: printf("Ingrese una opcion v%clida\n",160); break;
		}
	}while(o!=3);
	printf("Los cambios realizados se han guardado\n");
}


void Playlist(){
	int p,i;
	char datos[50];
	nodo *Actual=NULL;
	system("cls");
	do {
    printf("\033[1;36m");
	printf("\n--------Bienvenido al reproductor de m%csica--------\n",163);
	printf("Cat%clogo de canciones\n",160);
	//imprimir todas las canciones
	FILE* Arch;
    nodo* Nuevo;
    Arch=fopen("Catalogo.txt","r");
	if(Arch==NULL){
		printf("No se encuentra el catalogo");
	}else{
		rewind(Arch);
		while(feof(Arch)==0) {//Muestra catalogo
			fgets(datos,100,Arch);
			printf("%s\n",datos);
		}
		fclose(Arch);
	}
	Arch = fopen("Catalogo_dat.txt", "r");
    if (Arch == NULL) {
        printf("No se encuentra el catálogo\n");
    } else {
        nodo* Actual = NULL;
        while (feof(Arch)==0) {
            Nuevo = (nodo*)malloc(sizeof(nodo));
            if (fscanf(Arch, "%d,%[^,],%[^,],%[^,],%[^\n]", &(Nuevo->num), Nuevo->Artista, Nuevo->Album, Nuevo->NomCan, Nuevo->URL) == 5) {
				if(Pri==NULL) {
					Pri=Nuevo;
					Ult=Nuevo;
					Pri->Ant=Ult;
					Ult->Sig=NULL;
				} else {
					Ult->Sig=Nuevo;
					Nuevo->Ant=Ult;
					Ult=Nuevo;
					Ult->Sig=NULL;
				}	
            } else {
                free(Nuevo);
                break;
            }
        }
        fclose(Arch);
    }
	printf("\nIngresa la opci%cn que deseas realizar\n",162);
	printf("1. Reproducir de inicio a fin\n2. Reproducir aleatoria\n3. Seleccionar canci%cn a reproducir\n4. Regresar a men%c principal\n",162,163);
	scanf("%d", &p);

	switch(p){
		case 1:
		system("cls");
		printf("A continuaci%cn se van a reproducir las canciones de principio a fin...\n",162);
		//reproducir canciones de principio a fin
		Actual=Pri;
		char url[300];
		while(Actual != NULL){
			strcpy(url,Actual->URL);
			printf("\n%s - %s\n",Actual->Artista,Actual->NomCan);
			sndPlaySound(url,0);
			Actual=Actual->Sig;
			system("cls");
		}
		break;

		case 2:
		system("cls");
		printf("A continuaci%cn se van a reproducir las canciones de forma aleatoria...\n",162);
		//reproducir aleatorio
		int total = 0;
	    nodo* actual = Pri;
	    while (actual != NULL) {
	        total++;
	        actual = actual->Sig;
	    }
	    srand(time(NULL));
	    actual = Pri;
	    for (i = 0; i < total; i++) {
	        int randomIndex = rand() % (total - i) + 1;
	        nodo* NodoAleatorio = ObtenerNodoPorIndiceNumero(actual, randomIndex);
	        printf("\nReproduciendo canci%cn aleatoria: %s - %s\n",162, NodoAleatorio->Artista,NodoAleatorio->NomCan);
	        sndPlaySound(NodoAleatorio->URL, 0);
	        nodo* temp = actual;
	        while (temp != NULL) {
	            if (temp == NodoAleatorio) {
	                if (temp == Pri) {
	                    Pri = Pri->Sig;
	                    if (Pri != NULL)
	                        Pri->Ant = NULL;
	                    free(temp);
	                    temp = Pri;
	                }else if (temp == Ult){
	                    Ult = Ult->Ant;
	                    Ult->Sig = NULL;
	                    free(temp);
	                    temp = NULL;
	                } else {
	                    temp->Ant->Sig = temp->Sig;
	                    temp->Sig->Ant = temp->Ant;
	                    nodo* siguiente = temp->Sig;
	                    free(temp);
	                    temp = siguiente;
	                }
	                break;
	            }
	            temp = temp->Sig;
	        }
		}
		system("cls");
		break;

		case 3:
		system("cls");
		
		printf("Seleccione la canci%cn que desea reproducir\n",162);
		//reproducir cancion seleccionada
		int numcan;
	    printf("%cCuantas canciones quieres? ", 168);
	    scanf("%d", &numcan);
	    for (i = 0; i < numcan; i++) {
	    	Arch=fopen("Catalogo.txt","r");
			if(Arch==NULL){
				printf("No se encuentra el catalogo");
			}else{
				rewind(Arch);
				while(feof(Arch)==0) {//Muestra catalogo
					fgets(datos,100,Arch);
					printf("%s\n",datos);
				}
				fclose(Arch);
			}
	        printf("\nDame el n%cmero de la canci%cn: ", 163, 162);
	        int numeroCancion;
	        scanf("%d", &numeroCancion);
	        nodo* NodoSeleccionado = ObtenerNodoPorIndiceNumero(Pri, numeroCancion);
	        if (NodoSeleccionado != NULL) {
	        	system("cls");
	            printf("\nReproduciendo canci%cn seleccionada: %s - %s\n",162,NodoSeleccionado->Artista,NodoSeleccionado->NomCan);
	            sndPlaySound(NodoSeleccionado->URL, 0);
	            nodo* temp = Pri;
	            while (temp != NULL) {
	                if (temp == NodoSeleccionado) {
	                    if (temp == Pri) {
	                        Pri = Pri->Sig;
	                        if (Pri != NULL)
	                            Pri->Ant = NULL;
	                        free(temp);
	                        temp = Pri;
	                    } else if (temp == Ult) {
	                        Ult = Ult->Ant;
	                        Ult->Sig = NULL;
	                        free(temp);
	                        temp = NULL;
	                    } else {
	                        temp->Ant->Sig = temp->Sig;
	                        temp->Sig->Ant = temp->Ant;
	                        nodo* siguiente = temp->Sig;
	                        free(temp);
	                        temp = siguiente;
	                    }
	                    break;
	                }
	                temp = temp->Sig;
	            }
	        } else {
	            printf("Número de canción inválido.\n");
	        }
	        system("cls");
	    }
		break;

		case 4: printf("Regresando a men%c principal...\n",1633); break;
		default: printf("Ingrese una opci%cn v%alida\n",162,160); break;
		}
	}while(p!=4);
}
nodo* ObtenerNodoPorIndiceNumero(nodo* lista, int indiceNumero) {
    int contador = 1;
    nodo* temp = lista;
    while (temp != NULL) {
        if (contador == indiceNumero) {
            return temp;
        }
        temp = temp->Sig;
        contador++;
    }
    return NULL;
}
