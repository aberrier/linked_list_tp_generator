#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fcts.h"

/// Objectif : Realiser un programme qui permet l'ajout, la classification et la modification de donnees sur des {{name}} en listes chainees.
/// Possibilite de modifier et ajouter n'importe où un {{name}}
/// Possibilite de lire les donnees contenus a un endroit de la liste
/// Possibilite de chercher un {{name}}
/// Possibilite d'importer/exporter en fichier la liste chaine

int main()
{
    //Declaration variables
    int arret=0,choix,ajoutmiddle,modifmaillon,searchordre,val1,val2,choix2,del;
    char recherche[TAILLE_MAX];
    //Initialisation ancre et nouveau maillon
    Cell* ancre=NULL;
    ancre=(Cell*)malloc(1*sizeof(Cell));
    ancre=NULL;
    Cell* m=NULL;
    m=(Cell*)malloc(1*sizeof(Cell));
    m=NULL;

    //Menu
    printf("\n*****PROGRAMME DE GESTION DE BASE DE DONNES DE {{NAME}}S*****");
    do
    {
        fflush(stdin);
        printf("\n\n");
        printf(" 1 - Ajouter un {{name}} au debut de la liste\n");
        printf(" 2 - Ajouter un {{name}} a la fin de la liste\n");
        printf(" 3 - Ajouter un {{name}} dans un endroit de la liste\n");
        printf(" 4 - Modifier un {{name}} dans la liste\n");
        printf(" 5 - Rechercher un {{name}} dans la liste par son {{verbose_name}}\n");
        printf(" 6 - Rechercher un {{name}} dans la liste par son numero dans la liste\n");
        printf(" 7 - Changer la place de deux {{name}}s dans la liste\n");
        printf(" 8 - Importer une liste\n");
        printf(" 9 - Exporter la liste cree\n");
        printf(" 10 - Connaitre le nombre de {{name}}s dans la liste\n");
        printf(" 11 - Supprimer un {{name}}\n");
        printf(" 12 - Trier la liste par {{int_field_1}}\n");
        printf(" 13 - Trier la liste par {{int_field_2}}\n");
        printf(" 14 - Arreter le programme\n");
        printf("Votre choix : ");
        scanf("%d",&choix);
        system("cls");
        switch(choix)
        {
            case 1:
                m=SaisieData();
                ancre=AjoutTete(ancre,m);
                break;
            case 2:
                m=SaisieData();
                ancre=AjoutQueue(ancre,m);
                break;
            case 3:
                printf("Veuillez rentrer le numero de l'ordre voulu : ");
                scanf("%d",&ajoutmiddle);
                m=SaisieData();
                AjoutMiddle(ancre,m,ajoutmiddle);
                break;
            case 4:
                printf("Veuillez rentrer le numero du {{name}} que vous souhaitez modifier : ");
                scanf("%d",&modifmaillon);
                if (SearchOrdre(ancre,modifmaillon))
                {
                    printf("\nRentrez les nouvelles valeurs");
                    m=SaisieData();
                    ModifMaillon(ancre,m,modifmaillon);
                }
                break;
            case 5:
                printf("Veuillez rentrer le {{verbose_name}} du {{name}} : ");
                fflush(stdin);
                scanf("%s", &recherche);
                Search{{Verbose_name}}(ancre,recherche);
                break;
            case 6:
                printf("Veuillez rentrer le numero du {{name}} correspondant : ");
                scanf("%d",&searchordre);
                SearchOrdre(ancre,searchordre);
                system("cls");
                break;
            case 7:
                printf("Veuillez rentrer les deux numeros des {{name}}s\nNumero du premier {{name}} : ");
                scanf("%d",&val1);
                fflush(stdin);
                printf("Numero du second {{name}} : ");
                scanf("%d",&val2);
                if(val1==val2)
                {
                    printf("Les valeurs sont identiques ! Retour au menu...\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    if((SearchOrdre(ancre,val1))&&(SearchOrdre(ancre,val2)))
                    {
                        printf("\nConfirmer votre choix ? 1=OUI/0=NON : ");
                        scanf("%d",&choix2);
                        if(choix2)
                        {
                            ancre=PermutMaillon(ancre,val1,val2);
                        }
                        else
                        {
                            printf("Retour au menu..../n");
                            system("pause");
                            system("cls");
                        }
                    }
                }
                break;
            case 8:
                printf("\n\n****Vous allez importer la liste presente dans le fichier \"data.txt\"****\n");
                printf("****La liste actuelle va etre effacee !****\n***Confirmer votre choix ?(1=OUI,0=NON) : ");
                scanf("%d",&choix2);
                if(choix2!=1)
                {
                    if(choix!=0)
                    {
                        printf("Choix incorrect !\n");
                    }
                    printf("Retour au menu...\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    ancre=Import(ancre);
                }
                break;
            case 9:
                Export(ancre);
                break;
            case 10:
                NbMaillon(ancre);
                break;
            case 11:
                printf("Rentrez le numero du {{name}} a supprimer, 0 ou moins annule le choix : ");
                scanf("%d",&del);
                if(del>0)
                {
                    ancre=DeleteMaillon(ancre,del);
                }
                else
                {
                    printf("\nRetour au menu....\n");
                    system("pause");
                    system("cls");
                }


                break;
            case 12:
                ancre = Tri{{Int_field_1}}(ancre);
                break;
            case 13:
                ancre = TriTri{{Int_field_2}}(ancre);
                break;
            case 14:
                arret=1;
                break;
            default:
                printf("Saisie erronee veuillez reessayer \n");
        }
    }
    while(arret==0);

    return 0;
}
