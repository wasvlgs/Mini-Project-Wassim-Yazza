#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct books {
    char titles[1000];
    char auteurs[1000];
    int prix;
    int quantity;
};

int counter = 0;

int main() {
    struct books book[1000];
    int stop = 0;

    do {
        printf("======= Ajouter un Livre au Stock '1' \n");
        printf("======= Afficher Tous les Livres Disponibles '2' \n");
        printf("======= Rechercher un livre par son titre '3' \n");
        printf("======= Supprimer un Livre du Stock entrer '4' \n");
        printf("======= Afficher le Nombre Total de Livres en Stock '5' \n");
        printf("======= Modifier les informations du livre '6' \n");
        printf("======= Get Out from the program 0 \n");

        int answer;
        printf("\nVotre choix est: ");
        scanf("%i", &answer);
        getchar();

        char chercher[100];
        int stop_chercher = 0;
        int somme = 0;



        switch (answer) {
            case 1:
            system("cls");
                    printf("\n======= Titre de livre: ");
                    fgets( book[counter].titles, sizeof(book[counter].titles), stdin);

                    printf("======= Auteur de livre: ");
                    fgets( book[counter].auteurs, sizeof(book[counter].auteurs), stdin);

                    printf(" ======= Prix du livre: ");
                    scanf("%d", &book[counter].prix);
                    
                    printf(" ======= Quantite du livre: ");
                    scanf("%d", &book[counter].quantity);
                    counter++;

                    printf("\n ========= Votre livre a ete ajoute avec succes ========== \n \n");
                break;

            case 2:
                    for (int i = 0; i < counter; i++){
                    printf("\n===== livre %d: \n \n",i +1);
                    printf("=== Titre: %s ", book[i].titles);
                    printf("=== Auteur: %s ", book[i].auteurs);
                    printf("=== prix: %d \n", book[i].prix);
                    printf("=== stock: %d \n \n", book[i].quantity);
                    
                }

                
                break;
            case 3:
            system("cls");
                    printf("Enter le titre de livre: ");
                    fgets(chercher, sizeof(chercher), stdin);
                    for (int i = 0; i < counter; i++)
                    {
                        if(strcmp(book[i].titles, chercher) == 0){
                            printf("\n===== le livre est: \n \n");
                            printf("=== Titre: %s ", book[i].titles);
                            printf("=== Auteur: %s ", book[i].auteurs);
                            printf("=== prix: %d \n", book[i].prix);
                            printf("=== stock: %d \n \n", book[i].quantity);
                            stop_chercher = 1;
                        }
                    }
                    if(stop_chercher == 0){
                        printf("\nYour search doesn't exict...\n");
                    }                 
                
                break;

                case 4:
                system("cls");
                    printf("Entrez le titre du livre à supprimer: ");
                    fgets(chercher, sizeof(chercher), stdin);
                    for (int i = 0; i < counter; i++)
                    {
                        if(strcmp(book[i].titles, chercher) == 0){
                            strcpy( book[i].titles, book[i + 1].titles);
                            strcpy( book[i].auteurs, book[i + 1].auteurs);
                            book[i].prix = book[i + 1].prix;
                            book[i].quantity = book[i + 1].quantity;
                            counter--;
                            printf("\n ========= Votre livre a ete supprimer avec succes ========== \n \n");
                        }
                    }
                    if(stop_chercher == 0){
                        printf("\nYour search doesn't exict...\n");
                    }   
                
                break;

                case 5:
                    
                    for (int i = 0; i < counter; i++){
                        printf("\n===== livre %d: \n \n",i +1);
                        printf("=== Titre: %s ", book[i].titles);
                        printf("=== Auteur: %s ", book[i].auteurs);
                        printf("=== prix: %d \n", book[i].prix);
                        printf("=== stock: %d \n \n", book[i].quantity);

                        somme += book[i].quantity;
                    }
                    
                    printf("\n ========= La somme de stock du livre est: %i ========== \n \n",somme);
                break;

                case 6:
                system("cls");
                    printf("Entrez le titre du livre que vous souhaitez modifier: ");
                    fgets(chercher, sizeof(chercher), stdin);

                    

                    for (int i = 0; i < counter; i++)
                    {
                        if(strcmp(book[i].titles, chercher) == 0){
                            printf("\n======= Titre de livre: ");
                            fgets( book[i].titles, sizeof(book[i].titles), stdin);

                            printf("======= Auteur de livre: ");
                            fgets( book[i].auteurs, sizeof(book[i].auteurs), stdin);

                            printf(" ======= Prix du livre: ");
                            scanf("%d", &book[i].prix);
                            
                            printf(" ======= Quantite du livre: ");
                            scanf("%d", &book[i].quantity);

                            printf("\n ========= Votre livre a ete modifier avec succes ========== \n \n");

                            stop_chercher = 1;
                                }
                    }
                    if(stop_chercher == 0){
                        printf("\nYour search doesn't exict...\n");
                    }   
                
                break;
                
            
            default:
            printf("\n====== MERCI POUR UTILISE LE PROGRAMME... =======\n");
                stop = 1;
                break;
        }
    } while (stop == 0);

    return 0;
}
