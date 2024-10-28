#include <stdio.h>
#include <string.h>

#define MAX_TACHES 100

typedef struct {
    int jours;
    int mois;
    int annee;
} date;

typedef enum {
    Faible,
    Normale,
    Importante,
    TresImportante
} PrioriteEnum;

typedef struct {
    PrioriteEnum Priorite;
    char Description[100];
    date Date;
} Tache;

Tache ListeTaches[MAX_TACHES];
int countTaches = 0;

void  AjouterTache() {
    if (countTaches < MAX_TACHES) {
        Tache nouvelleTache;

        printf("Donner la description de la tache : ");
        scanf(" %[^\n]s", nouvelleTache.Description);

        printf("Donner la date de la tache (Format: jour-mois-annee) : ");
        scanf("%d-%d-%d", &nouvelleTache.Date.jours, &nouvelleTache.Date.mois, &nouvelleTache.Date.annee);

        printf("Donner la prioritee de la tache (0: Faible, 1: Normale, 2: Importante, 3: TresImportante) : ");
        scanf("%d", (int*)&nouvelleTache.Priorite);

        ListeTaches[countTaches++] = nouvelleTache;
        printf("Tache ajoutee avec succes!\n");
    } else {
        printf("La liste de taches est pleine. Impossible d'ajouter plus de taches.\n");
    }
}

void AfficherListeTaches() {
    int i;
	if(countTaches > 0){
    printf("Liste des taches :\n");
    for (i = 0; i < countTaches; i++) {
        printf("Tache %d :\n", i + 1);
        printf("Description : %s\n", ListeTaches[i].Description);
        printf("Date : %d-%d-%d\n", ListeTaches[i].Date.jours, ListeTaches[i].Date.mois, ListeTaches[i].Date.annee);

       
        switch (ListeTaches[i].Priorite) {
            case Faible:
                printf("Priorite : Faible\n");
                break;
            case Normale:
                printf("Priorite : Normale\n");
                break;
            case Importante:
                printf("Priorite : Importante\n");
                break;
            case TresImportante:
                printf("Priorite : TresImportante\n");
                break;
            default:
                printf("Priorite inconnue\n");
        }
        printf("\n");
    }
    }else{
    	printf("Aucune tache a afficher!\n");
	 
}
}

void ModifierTache() {
    if (countTaches > 0) {
        int numeroTache;
        printf("Donner le numero de la tache a modifier: ");
        scanf("%d", &numeroTache);
        if (numeroTache > 0 && numeroTache <= countTaches) {
            Tache *modifierTache = &ListeTaches[numeroTache - 1];

            printf("Entrez la nouvelle description de la tache : ");
            scanf(" %[^\n]s", modifierTache->Description);

            printf("Entrez la nouvelle date de la tache (Format: jour-mois-annee) : ");
            scanf("%d-%d-%d", &modifierTache->Date.jours, &modifierTache->Date.mois, &modifierTache->Date.annee);

            printf("Entrez la nouvelle prioritee de la tache (0: Faible, 1: Normale, 2: Importante, 3: TresImportante) : ");
            scanf("%d", (int*)&modifierTache->Priorite);

            printf("Tache modifiee avec succes!\n");
        } else {
            printf("Aucune tache a modifier!\n");
        }
    } else {
        printf("Aucune tache a modifier!\n");
    }
}

void SupprimerTache() {
    if (countTaches > 0) {
        int i;
        int numeroTache;
        printf("Entrez le numero de la tache a supprimer : ");
        scanf("%d", &numeroTache);

        if (numeroTache > 0 && numeroTache <= countTaches) {
            for (i = numeroTache - 1; i < countTaches ; i++) {
                ListeTaches[i] = ListeTaches[i + 1];
            }

            countTaches--;
            printf("Tache supprimee avec succes!\n");
        } else {
            printf("Numero de tache invalide.\n");
        }
    } else {
        printf("Aucune tache a supprimer!\n");
    }
}

void TriCroissante() {
    int i, j;
    if (countTaches > 0) {
        for (i = 0; i < countTaches ; i++) {
            for (j = i + 1; j < countTaches; j++) {
                if (ListeTaches[i].Date.annee > ListeTaches[j].Date.annee ||
                    (ListeTaches[i].Date.annee == ListeTaches[j].Date.annee &&
                     (ListeTaches[i].Date.mois > ListeTaches[j].Date.mois ||
                      (ListeTaches[i].Date.mois == ListeTaches[j].Date.mois &&
                       ListeTaches[i].Date.jours > ListeTaches[j].Date.jours)))) {
                    Tache temp = ListeTaches[i];
                    ListeTaches[i] = ListeTaches[j];
                    ListeTaches[j] = temp;
                }
            }
        }

        printf("Taches ordonnees par date croissante!\n");
    } else {
        printf("Aucune tache a ordonner!\n");
    }
}

void TriDecroissante() {
    int i, j;
    if (countTaches > 0) {
        for (i = 0; i < countTaches ; i++) {
            for (j = i + 1; j < countTaches; j++) {
                if (ListeTaches[i].Date.annee < ListeTaches[j].Date.annee ||
                    (ListeTaches[i].Date.annee == ListeTaches[j].Date.annee &&
                     (ListeTaches[i].Date.mois < ListeTaches[j].Date.mois ||
                      (ListeTaches[i].Date.mois == ListeTaches[j].Date.mois &&
                       ListeTaches[i].Date.jours < ListeTaches[j].Date.jours)))) {
                    Tache temp = ListeTaches[i];
                    ListeTaches[i] = ListeTaches[j];
                    ListeTaches[j] = temp;
                }
            }
        }

        printf("Taches ordonnees par date decroissante!\n");
    } else {
        printf("Aucune tache a ordonner!\n");
    }
}

void FiltrerParPriorite(PrioriteEnum priorite) {
    int i;
    if (countTaches > 0) {
        printf("Taches avec priorite %d :\n", priorite);
        for (i = 0; i < countTaches; i++) {
            if (ListeTaches[i].Priorite == priorite) {
                printf("Tache %d :\n", i + 1);
                printf("Description : %s\n", ListeTaches[i].Description);
                printf("Date : %d-%d-%d\n", ListeTaches[i].Date.jours, ListeTaches[i].Date.mois, ListeTaches[i].Date.annee);

             
                switch (ListeTaches[i].Priorite) {
                    case Faible:
                        printf("Priorite : Faible\n");
                        break;
                    case Normale:
                        printf("Priorite : Normale\n");
                        break;
                    case Importante:
                        printf("Priorite : Importante\n");
                        break;
                    case TresImportante:
                        printf("Priorite : Tres Importante\n");
                        break;
                    default:
                        printf("Priorite inconnue\n");
                }

                printf("\n");
            }
        }
    } else {
        printf("Aucune tache a afficher!\n");
    }
}

void FiltrerParDate() {
    date dateFiltre;
    printf("Entrez la date de filtre (Format: jour-mois-annee) : ");
    scanf("%d-%d-%d", &dateFiltre.jours, &dateFiltre.mois, &dateFiltre.annee);

    int i;
    int count = 0;

    printf("Taches avec la date %d-%d-%d :\n", dateFiltre.jours, dateFiltre.mois, dateFiltre.annee);

    for (i = 0; i < countTaches; i++) {
        if (ListeTaches[i].Date.jours == dateFiltre.jours &&
            ListeTaches[i].Date.mois == dateFiltre.mois &&
            ListeTaches[i].Date.annee == dateFiltre.annee) {
            count = 1;

            printf("Tache %d :\n", i + 1);
            printf("Description : %s\n", ListeTaches[i].Description);
            printf("Date : %d-%d-%d\n", ListeTaches[i].Date.jours, ListeTaches[i].Date.mois, ListeTaches[i].Date.annee);

            switch (ListeTaches[i].Priorite) {
                case Faible:
                    printf("Priorite : Faible\n");
                    break;
                case Normale:
                    printf("Priorite : Normale\n");
                    break;
                case Importante:
                    printf("Priorite : Importante\n");
                    break;
                case TresImportante:
                    printf("Priorite : Tres Importante\n");
                    break;
                default:
                    printf("Priorite inconnue\n");
            }

            printf("\n");
        }
    }

    if (!count) {
        printf("Aucune tache trouvee pour la date specifiee.\n");
    }
}



int main() {
    int choix;

    do {
        printf("\nMenu:\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher la liste des taches\n");
        printf("3. Modifier une tache\n");
        printf("4. Supprimer une tache\n");
        printf("5. Trie les taches par date croissante\n");
        printf("6. Trie les taches par date decroissante\n");
        printf("7. Filtrer par priorite\n");
        printf("8. Filtrer par la date\n");
        printf("0. Quitter\n");

        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                AjouterTache();
                break;
            case 2:
                AfficherListeTaches();
                break;
            case 3:
                ModifierTache();
                break;
            case 4:
                SupprimerTache();
                break;
            case 5:
                TriCroissante();
                break;
            case 6:
                TriDecroissante();
                break;
            case 7: {
                int priorite;
                printf("Entrez la priorite (0: Faible, 1: Normale, 2: Importante, 3: TresImportante) : ");
                scanf("%d", (int*)&priorite);
                FiltrerParPriorite((PrioriteEnum)priorite);
            } break;
            case 8:
            	FiltrerParDate();
            case 0:
                printf("Programme termine!\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 0 et 8.\n");
        }
    } while (choix != 0);

    return 0;
}
