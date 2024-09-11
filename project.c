#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct etudiant
{
    int id;
    char name[100];
    char date_de_naissance[100];
    char class[100];
    int note;
};

int main()
{

    int programme_stop = 0;

    do
    {
        struct etudiant t[100];
        int counter = 0;

        printf("\n=========== Pour Ajoutez un eleve entrer '1'\n");
        printf("=========== Pour modifier les informations d'un etudiant entrer '2'\n");
        printf("=========== Pour supprimer un eleve entrer '3'\n");
        printf("=========== Pour afficher les details d'un etudiant entrer '4'\n");
        printf("=========== Pour calculer la moyenne generale entrer '5'\n");
        printf("=========== Pour afficher statistiques entrer '6'\n");
        printf("=========== Pour rechercher un etudiant entrer '7'\n");
        printf("=========== Quitter le programme entrer '0'\n");

        int answer;
        printf("\n entrer votre choix: ");
        scanf("%i", &answer);

        switch (answer)
        {
        case 1:
            // Ajoute un élève:

            system("cls");
            printf("===== Pour ajoute un eleve sur class Math entrer '1'\n");
            printf("===== Pour ajoute un eleve sur class Physique entrer '2'\n");
            printf("===== Pour ajoute un eleve sur class informatique entrer '3'\n");
            printf("===== Retourn a la liste principale entrer '0'");

            int class_type;
            printf("\n entrer votre choix: ");
            scanf("%i", &class_type);

            switch (class_type)
            {
            case 1:
                system("cls");
                printf("\n\n========= Ajoutez un eleve =========\n\n");

                t[counter].id = counter;
                printf("Entrer le nom et le prenom d'etudiant: ");
                fgets(t[counter].name, sizeof(t[counter].name), stdin);
                getchar();

                printf("\nEntrer la date de naissance d'etudiant ex(DD-MM-YYYY): ");
                fgets(t[counter].date_de_naissance, sizeof(t[counter].date_de_naissance), stdin);
                getchar();

                strcpy(t[counter].class, "Math");

                printf("\nEntrer la note d'etudiant (/20): ");
                scanf("%i", t[counter].note);
                getchar();

                counter++;

                break;
            case 2:
                system("cls");
                printf("\n\n========= Afficher les eleves =========\n\n");

                for (int i = 0; i < counter; i++)
                {
                    printf("ID: %i\n", t[i].id);
                    printf("Nom et prenom: %s\n", t[i].name);
                    printf("Date de naissance: %s\n", t[i].date_de_naissance);
                    printf("class: %s\n", t[i].class);
                    printf("La note: %i\n", t[i].note);

                }
                

                break;

            default:
                break;
            }

            break;

        default:
            programme_stop = 1;
            break;
        }

    } while (programme_stop == 0);

    return 0;
}