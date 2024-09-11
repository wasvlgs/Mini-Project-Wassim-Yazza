#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct etudiant
{
    int id;
    char name[100];
    char date_de_naissance[100];
    char classe[100];
    int note;
};

int main()
{
    int programme_stop = 0;
    struct etudiant t[100];
    int counter = 0;

    do
    {
        printf("\n=========== Pour Ajoutez un eleve entrer '1'\n");
        printf("=========== Pour afficher les details de tout les etudiants entrer '2'\n");
        printf("=========== Pour modifier les informations d'un etudiant entrer '3'\n");
        printf("=========== Pour supprimer un eleve entrer '4'\n");
        printf("=========== Pour afficher les details d'un seul etudiant entrer '5'\n");
        printf("=========== Pour calculer la moyenne generale entrer '6'\n");
        printf("=========== Pour afficher statistiques entrer '7'\n");
        printf("=========== Pour rechercher un etudiant entrer '8'\n");
        printf("=========== Quitter le programme entrer '0'\n");

        int answer;
        printf("\n entrer votre choix: ");
        scanf("%i", &answer);

        int search_stop = 0;
        int class_type;
        int eleve_id;

        int counter_math = 0;
        int counter_physique = 0;
        int counter_informatique = 0;
        switch (answer)
        {
        case 1:
            // Ajoute un élève:
            system("cls");
            printf("===== Pour ajoute un eleve sur class Math entrer '1'\n");
            printf("===== Pour ajoute un eleve sur class Physique entrer '2'\n");
            printf("===== Pour ajoute un eleve sur class Informatique entrer '3'\n");
            printf("===== Retourn a la liste principale entrer '0'\n");

            printf("\n entrer votre choix: ");
            scanf("%i", &class_type);
            getchar();

            if (class_type == 1)
            {
                strcpy(t[counter].classe, "Math");
            }
            else if (class_type == 2)
            {
                strcpy(t[counter].classe, "Physique");
            }
            else if (class_type == 3)
            {
                strcpy(t[counter].classe, "Informatique");
            }
            else
            {
                break;
            }

            printf("\n\n========= Ajoutez un eleve =========\n\n");

            t[counter].id = counter + 1;
            printf("Entrer le nom et le prenom d'etudiant: ");
            fgets(t[counter].name, sizeof(t[counter].name), stdin);

            printf("\nEntrer la date de naissance d'etudiant ex(DD-MM-YYYY): ");
            fgets(t[counter].date_de_naissance, sizeof(t[counter].date_de_naissance), stdin);

            printf("\nEntrer la note d'etudiant (/20): ");
            scanf("%i", &t[counter].note);
            getchar();

            counter++;
            break;

        case 2:
            // affichage des eleves
            system("cls");
            printf("===== ===== Pour afficher tout les eleves entrer '1'\n");
            printf("===== Pour afficher tout les eleves de class Math entrer '2'\n");
            printf("===== Pour afficher tout les eleves de class Physique entrer '3'\n");
            printf("===== Pour afficher tout les eleves de class Informatique entrer '4'\n");
            printf("===== Pour afficher tout les eleves A-Z entrer '5'\n");
            printf("===== Pour afficher tout les eleves Z-A entrer '6'\n");
            printf("===== Retourn a la liste principale entrer '0'\n");

            int affichage_type;
            printf("\n entrer votre choix: ");
            scanf("%i", &affichage_type);
            getchar();


            switch (affichage_type)
            {
            case 1:
                for (int i = 0; i < counter; i++)
                {
                    printf("============ l'eleve ============\n");
                    printf("ID: %i\n", t[i].id);
                    printf("Nom et Prenom: %s", t[i].name);
                    printf("Date de naissance: %s", t[i].date_de_naissance);
                    printf("Class: %s\n", t[i].classe);
                    printf("La note: %i/20\n", t[i].note);
                }
                
                break;

            case 2:
                for (int i = 0; i < counter; i++)
                {
                    if(strcmp(t[i].classe,"Math") == 0){
                        printf("============ l'eleve ============\n");
                        printf("ID: %i\n", t[i].id);
                        printf("Nom et Prenom: %s", t[i].name);
                        printf("Date de naissance: %s", t[i].date_de_naissance);
                        printf("Class: %s\n", t[i].classe);
                        printf("La note: %i/20\n", t[i].note);
                    }
                }

                break;

            case 3:
                for (int i = 0; i < counter; i++)
                {
                    if (strcmp(t[i].classe, "Physique") == 0)
                    {
                        printf("============ l'eleve ============\n");
                        printf("ID: %i\n", t[i].id);
                        printf("Nom et Prenom: %s", t[i].name);
                        printf("Date de naissance: %s", t[i].date_de_naissance);
                        printf("Class: %s\n", t[i].classe);
                        printf("La note: %i/20\n", t[i].note);
                    }
                }

                break;
            case 4:
                for (int i = 0; i < counter; i++)
                {
                    if (strcmp(t[i].classe, "Informatique") == 0)
                    {
                        printf("============ l'eleve ============\n");
                        printf("ID: %i\n", t[i].id);
                        printf("Nom et Prenom: %s", t[i].name);
                        printf("Date de naissance: %s", t[i].date_de_naissance);
                        printf("Class: %s\n", t[i].classe);
                        printf("La note: %i/20\n", t[i].note);
                    }
                }

                break;
            case 5:
                char a[100];
                for (int i = 0; i < counter; i++)
                {
                    for (int j = 0; j < counter - 1; j++)
                    {
                        if(strcmp(t[i].name,t[i + 1].name) < 0){
                            strcpy(a, t[i].name);
                            strcpy(t[i].name, t[i + 1].name);
                            strcpy(t[i + 1].name, a);

                        }
                    }
                    
                }
                

                break;
            
            default:
                break;
            }

            
            break;

        case 3:
            system("cls");
            printf("Entrer l'ID d'un eleve: ");
            scanf("%i", &eleve_id);
            getchar();

            for (int i = 0; i < counter; i++)
            {
                if (t[i].id == eleve_id)
                {
                    system("cls");
                    printf("===== Pour modifier le nom d'un eleve entrer '1'\n");
                    printf("===== Pour modifier la date de naissance d'un eleve entrer '2'\n");
                    printf("===== Pour modifier la class d'un eleve entrer '3'\n");
                    printf("===== Pour modifier la note d'un eleve entrer '4'\n");
                    printf("===== Retourn a la liste principale entrer '0'\n");

                    int type_modifie;
                    printf("\n entrer votre choix: ");
                    scanf("%i", &type_modifie);
                    getchar();

                    switch (type_modifie)
                    {
                    case 1:

                        printf("\n\n======== Modifier les informations d'un etudiant ========\n\n");
                        printf("Entrer le nom et le prenom d'etudiant: ");
                        fgets(t[i].name, sizeof(t[i].name), stdin);

                        printf("\n\n======== les informations a ete modifie avec success ========\n\n");

                        search_stop = 1;

                        break;
                    case 2:

                        printf("\n\n======== Modifier les informations d'un etudiant ========\n\n");
                        printf("\nEntrer la date de naissance d'etudiant ex(DD-MM-YYYY): ");
                        fgets(t[i].date_de_naissance, sizeof(t[i].date_de_naissance), stdin);

                        printf("\n\n======== les informations a ete modifie avec success ========\n\n");
                        search_stop = 1;
                        break;
                    case 3:
                        printf("\n\n======== Modifier les informations d'un etudiant ========\n\n");

                        printf("===== Pour ajoute l'eleve sur class Math entrer '1'\n");
                        printf("===== Pour ajoute l'eleve sur class Physique entrer '2'\n");
                        printf("===== Pour ajoute l'eleve sur class Informatique entrer '3'\n");

                        printf("\n entrer votre choix: ");
                        scanf("%i", &class_type);
                        getchar();
                        if (class_type == 1)
                        {
                            strcpy(t[i].classe, "Math");
                        }
                        else if (class_type == 2)
                        {
                            strcpy(t[i].classe, "Physique");
                        }
                        else if (class_type == 3)
                        {
                            strcpy(t[i].classe, "Informatique");
                        }
                        else
                        {
                            break;
                        }
                        printf("\n\n======== les informations a ete modifie avec success ========\n\n");
                        search_stop = 1;
                        break;
                    case 4:

                        printf("\n\n======== Modifier les informations d'un etudiant ========\n\n");
                        printf("\nEntrer la note d'etudiant (/20): ");
                        scanf("%i", &t[i].note);

                        printf("\n\n======== les informations a ete modifie avec success ========\n\n");
                        search_stop = 1;
                        break;
                    default:
                        break;
                    }
                }
            }
            if (search_stop == 0)
            {
                printf("\n\n=========== Votre recherche n'execte pas ===========\n\n");
            }

            break;

        case 4:

            system("cls");
            printf("Entrer l'ID d'un eleve: ");
            scanf("%i", &eleve_id);
            getchar();

            for (int i = 0; i < counter; i++)
            {
                if (t[i].id == eleve_id)
                {
                    system("cls");

                    t[i].id = t[i + 1].id;
                    strcpy(t[i].name, t[i + 1].name);
                    strcpy(t[i].date_de_naissance, t[i + 1].date_de_naissance);
                    strcpy(t[i].classe, t[i + 1].classe);
                    t[i].note = t[i + 1].note;
                    counter--;

                    search_stop = 1;
                    printf("\n\n======== l'etudiant a ete supprimer avec success ========\n\n");
                }
            }
            if (search_stop == 0)
            {
                printf("\n\n=========== Votre recherche n'execte pas ===========\n\n");
            }

            break;

        case 5:

            system("cls");
            printf("Entrer l'ID d'un eleve: ");
            scanf("%i", &eleve_id);
            getchar();

            for (int i = 0; i < counter; i++)
            {
                if (t[i].id == eleve_id)
                {
                    printf("\n\n=========== Votre eleve est: ===========\n\n");
                    printf("ID: %i\n", t[i].id);
                    printf("Nom et Prenom: %s", t[i].name);
                    printf("Date de naissance: %s", t[i].date_de_naissance);
                    printf("Class: %s\n", t[i].classe);
                    printf("La note: %i/20\n", t[i].note);
                }
            }
            if (search_stop == 0)
            {
                printf("\n\n=========== Votre recherche n'execte pas ===========\n\n");
            }

            break;

        case 6:

            printf("\n\n=========== Les notes moyenne ===========\n\n");

            int notes_math = 0;
            int notes_physic = 0;
            int notes_informatique = 0;

            for (int i = 0; i < counter; i++)
            {
                if (strcmp(t[i].classe, "Math") == 0)
                {
                    notes_math += t[i].note;
                    counter_math++;
                }
                
            }
            for (int i = 0; i < counter; i++)
            {
                if (strcmp(t[i].classe, "Physique") == 0)
                {
                    notes_physic += t[i].note;
                    counter_physique++;
                }
            }
            for (int i = 0; i < counter; i++)
            {
                if (strcmp(t[i].classe, "Informatique") == 0)
                {
                    notes_informatique += t[i].note;
                    counter_informatique++;
                }
            }

            printf("===== La note moyenne de class Math est: %i/20 \n", notes_math / counter_math);
            printf("===== La note moyenne de class Physique est: %i/20\n", notes_physic / counter_physique);
            printf("===== La note moyenne de class Informatique est: %i/20\n", notes_informatique / counter_informatique);
            printf("===== La note moyenne globale est: %i/20\n", (notes_math + notes_physic + notes_informatique) / (counter_math + counter_physique + counter_informatique));

            break;

        case 7:

            printf("\n\n=========== Les notes moyenne ===========\n\n");
            int meilleur__math = 0;
            int meilleur__pc = 0;
            int meilleur__info = 0;

            for (int i = 0; i < counter; i++)
            {
                if (strcmp(t[i].classe, "Math") == 0)
                {
                    counter_math++;
                    if (t[i].note >= 10)
                    {
                        meilleur__math++;
                    }
                }
                else if (strcmp(t[i].classe, "Physique") == 0)
                {
                    counter_physique++;
                    if (t[i].note >= 10)
                    {
                        meilleur__pc++;
                    }
                }
                else if (strcmp(t[i].classe, "Informatique") == 0)
                {
                    counter_informatique++;
                    if (t[i].note >= 10)
                    {
                        meilleur__info++;
                    }
                }
                else
                {
                    break;
                }
            }

            printf("===== Le nombre d'etudiants ayant une note supérieure ou égale à 10/20 sur class Math: %i/20 => %i%%", meilleur__math, (meilleur__math * 100) / counter_math);
            printf("===== Le nombre d'etudiants ayant une note supérieure ou égale à 10/20 sur class Physique: %i/20 => %i%%", meilleur__pc, (meilleur__pc * 100) / counter_physique);
            printf("===== Le nombre d'etudiants ayant une note supérieure ou égale à 10/20 sur class Informatique: %i/20 => %i%%", meilleur__info, (meilleur__info * 100) / counter_informatique);
            printf("===== Le nombre des eleves de class Math est: %i => %i%% \n", counter_math, (counter_math * 100) / counter);
            printf("===== Le nombre des eleves de class Physique est: %i => %i%%\n", counter_physique, (counter_physique * 100) / counter);
            printf("===== Le nombre des eleves de class Informatique est: %i => %i%%\n", counter_informatique, (counter_informatique * 100) / counter);
            printf("===== Le nombre globale des eleves est: %i\n", counter);

            printf("======== les 3 étudiants ayant les meilleures notes sont: ========");

            break;

        default:
            programme_stop = 1;
            break;
        }

    } while (programme_stop == 0);

    return 0;
}