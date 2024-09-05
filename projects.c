#include <stdio.h>
#include <stdlib.h>
#include <string.h>



    struct books{
        char titles[1000];
        char auteurs[1000];
        int prixs;
        int quantity;
    };
    
int counter=0;


int main(){
char rep;

        int stop = 1;
        struct books book[1000];
do
{
        printf("\nAjouter un Livre au Stock entrer 1 \n");
        printf("Afficher Tous les Livres Disponibles entrer 2 \n");
        printf("Rechercher un livre par son titre. 3 \n");
        printf("Supprimer un Livre du Stock entrer 4 \n");
        printf("Afficher le Nombre Total de Livres en Stock entrer 5 \n");
        printf("\nGet Out from the program 0 \n");


        int answer;
        printf("Votre choix est: ");
        scanf("%i", &answer);

        char title[100];
        char auteur[100];
        int prix;
        int stock;
        char search[100];
        int somme = 0;
        int test = 0;
        switch (answer){
            case 1:
                printf("Entrer le titre du livre: ");
                scanf("%s", &title);
                strcpy(book[counter].titles, title);

                printf("Entrer le nom de l auteur: ");
                scanf("%s", &auteur);
                strcpy(book[counter].auteurs, auteur);

                printf("Entrer le prix du livre: ");
                scanf("%i", &prix);
                book[counter].prixs = prix;

                printf("Entrer le stock du livre: ");
                scanf("%i", &stock);
                book[counter].quantity = stock;
                counter++;
                printf("\n ========= Votre livre a été ajouté avec succès ========== \n");
                break;
            case 2:
                for (int i = 0; i < counter; i++){
                    printf("\n Affichage de livre: \n");
                    printf("%i livre c'est %s l auteur est %s et son prix est %i il y a %i en stock.\n", i +1, book[i].titles, book[i].auteurs, book[i].prixs, book[i].quantity);
                }
                break;
            
            case 3:

                printf("Cherchez le livre que vous voulez: ");
                scanf("%99s", &search);
                for (int i = 0; i < counter; i++){
                    if(strcmp(book[i].titles, search) == 0){
                        printf("le livre c'est %s l auteur est %s et son prix est %i il y a %i en stock.", book[i].titles, book[i].auteurs, book[i].prixs, book[i].quantity);

                    }
                }
                
                break;
                case 4:

                printf("Cherchez le livre que vous voulez supprime: ");
                scanf("%99s", &search);
                for (int i = 0; i < counter; i++){
                    if(strcmp(book[i].titles, search) == 0){
                         strcpy(book[i].titles, "");
                         strcpy(book[i].titles, "");
                        book[i].prixs = 0;
                        book[i].quantity = 0;
                        counter = counter -1;
                        test = 1;

                    }
                }
                if (test == 0)
                {
                    printf("Ce livre n'est pas dans le tableau");
                }
                
                
                break;
            
            
                case 5:

                    
                    for (int i = 0; i < counter; i++){
                        somme = somme + book[i].quantity;
                    }
                    printf("========== La somme totale de stock est: %i  ===========", somme);
                
                break;
            
            default:
            stop = 0;
                break;
        }
} while (stop != 0);

    
    


return 0;
}