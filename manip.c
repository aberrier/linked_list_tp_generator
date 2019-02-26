#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fcts.h"

Cell *SaisieData()
{
    //Creation maillon temporaire vide
    Cell* nouveau=NULL;
    nouveau=(Cell*)malloc(1*sizeof(Cell));
    fflush(stdin);
    //Saisie des données
    printf("\n***** SAISIE DE DONNNES *****\n");
    printf("Identifiant : ");
    scanf("%d",&nouveau->data.id);
    fflush(stdin);
    printf("Nom : ");
    gets(nouveau->data.nom);
    fflush(stdin);
    printf("Prenom : ");
    gets(nouveau->data.prenom);
    fflush(stdin);
    printf("Age : ");
    scanf("%d",&nouveau->data.age);
    fflush(stdin);
    printf("Promotion : ");
    scanf("%d",&nouveau->data.promo);
    fflush(stdin);
    printf("Groupe de TD : ");
    scanf("%d",&nouveau->data.TD);
    fflush(stdin);
    //Mise à NULL du pointeur du maillon
    nouveau->suiv=NULL;
    return nouveau;


}

void NbMaillon(Cell* ancre)
{
    Cell* explo=ancre;
    int cpts=0;
    // Cas liste vide
    if(explo==NULL)
    {
        printf("\nLa liste est vide\n");
    }
    else
    {
        //Exploration jusqu'a l'avant dernier
        while(explo->suiv!=NULL)
        {
            explo=explo->suiv;
            cpts=cpts+1;
        }
        //Mis au dernier
        cpts=cpts+1;
        printf("\nLa liste contient %d etudiant(s)\n",cpts);
    }
    system("pause");
    system("cls");
}

Cell *AjoutTete(Cell* ancre, Cell* m)
{
    //Si liste vide
    if(ancre==NULL)
    {
        m->suiv=NULL;
        ancre=m;
    }
    else //Si liste non vide
    {
        m->suiv=ancre;
        ancre=m;
    }
    printf("\nValeurs ajoutees au debut\n");
    system("pause");
    system("cls");
    return ancre;
}
Cell *AjoutQueue(Cell* ancre, Cell* m)
{
    //Creation pointeur explorateur
    Cell* explo=ancre;
    //Si liste vide
    if(ancre==NULL)
    {
        m->suiv=NULL;
        ancre=m;
    }
    else //Si liste non vide
    {
        //Exploration jusqu'au dernier maillon
        while(explo->suiv!=NULL)
        {
            explo=explo->suiv;
        }
        explo->suiv=m;
        m->suiv=NULL;
    }
    printf("\nValeurs ajoutees a la fin\n");
    system("pause");
    system("cls");
    return ancre;

}

void AjoutMiddle(Cell* ancre, Cell* m, int val)
{

    //Mise du compteur à 0
    int cpts=0,none=0;
    //Creation pointeur explorateur
    Cell* explo=ancre;
    //Si liste vide
    if(ancre==NULL)
    {
        printf("\nLa liste est vide ! Ajoutez des valeurs avant de continuer !");
    }
    else //Liste non vide
    {
        do
        {

            //Si la chaine n'est pas assez longue
            if(explo->suiv==NULL)
            {
                printf("\nLa liste est trop petite !");
                cpts=val-2;
                none=1;
            }
            else
            {
                //Exploration jusqu'a tomber sur la valeur voulue
                explo=explo->suiv;
                cpts=cpts+1;
            }
        }
        while(cpts<val-2);
        //Si la chaine n'était pas trop petite
        if(none==0)
        {
            //Incrémentation du maillon
            m->suiv=explo->suiv;
            explo->suiv=m;
            printf("\nElement ajoute a la liste");
        }
        printf("\n");
        system("pause");
        system("cls");

    }
}

int SearchOrdre(Cell* ancre,int val)
{
    //Programme pseudo-booléen qui renvoie 1 si le maillon correspondant existe et qui affiche ce maillon
    Cell* explo=ancre;
    int cpts=0;
    if((ancre==NULL)||(val<=0))
    {
        printf("\nLa liste est vide ou la valeur saisie est erronée\n");
        system("pause");
        system("cls");
        return 0;
    }
    while(cpts<val-1)
    {
        if(explo==NULL)
        {
            printf("\nLa liste est trop petite pour contenir l'element numero %d !\n",val);
            system("pause");
            system("cls");
            return 0;
        }
        explo=explo->suiv;
        cpts=cpts+1;
    }
    printf("\n*****DONNEES PRESENTES AU NUMERO %d *****",val);
    printf("\nIdentifiant : %d",explo->data.id);
    printf("\nNom : %s",explo->data.nom);
    printf("\nPrenom : %s",explo->data.prenom);
    printf("\nAge : %d",explo->data.age);
    printf("\nPromo : %d",explo->data.promo);
    printf("\nTD : %d\n",explo->data.TD);
    system("pause");
    return 1;

}

void ModifMaillon(Cell* ancre, Cell* m, int val)
{

    //Programme à executer si existence du maillon verifié
    Cell* explo=ancre;
    int cpts=0;
    while(cpts<val-1)
    {
        //Verification deja faite avec SearchOrdre();
        //Positionnement au pointeur du maillon voulu
        explo=explo->suiv;
        cpts=cpts+1;
    }
    //Changement des valeurs
    explo->data.age=m->data.age;
    explo->data.id=m->data.id;
    strcpy(explo->data.nom,m->data.nom);
    strcpy(explo->data.prenom,m->data.prenom);
    explo->data.promo=m->data.promo;
    explo->data.TD=m->data.TD;
    //
    printf("\n Valeurs modifiees\n");
    system("pause");
    system("cls");


}

void SearchName(Cell* ancre,char name[TAILLE_MAX])
{
    //Programme qui va afficher le maillon correspond aux maillons. Ne gere pas quand plusieurs personnes ont le meme nom, prend la 1ere personne dans la liste
    Cell* explo=ancre;
    int found=0,cpts=0;
    if(ancre==NULL)
    {
        printf("\nLa liste est vide ! \n");
        system("pause");
        system("cls");
        return;
    }
    while((explo!=NULL)&&(found==0))
    {
        if(!(strcmp(explo->data.nom,name))) /// !strcmp() renvoie 1 si les 2 chaines sont identiques
        {
            found=1;
            printf("\n*****DONNEES PRESENTES POUR LE NOM \"%s\" *****",name);
            printf("\nIdentifiant : %d",explo->data.id);
            printf("\nNom : %s",explo->data.nom);
            printf("\nPrenom : %s",explo->data.prenom);
            printf("\nAge : %d",explo->data.age);
            printf("\nPromo : %d",explo->data.promo);
            printf("\nTD : %d\n",explo->data.TD);
            printf("\n***Numero*** : %d\n",cpts+1);
        }
        explo=explo->suiv;
        cpts=cpts+1;
    }
    if (found==0)
    {
        printf("\nIl n'y a pas d'etudiant correspondant au nom \"%s\" dans la liste\n",name);
    }
    system("pause");
    system("cls");
}
Cell* PermutMaillon(Cell* ancre,int val1,int val2)
{
    Cell* tmp1=NULL;
    Cell* tmp2=NULL;
    Cell* tmp3=NULL;
    Cell* explo1=ancre;
    Cell* explo2=ancre;

    int cpts=0;
    ///4 cas différents avec 2 situations : 1er situation - permutation avec 1er maillon, 2eme situation - permutation de 2 membres cote à cote,

    // Cas permutation avec 2 maillons différents du premier maillon
    if((val1!=1)&&(val2!=1))
    {
        //Cas permutation de maillons cote à cote
        if((val1==val2+1)||(val1==val2-1))
        {
            //val1 prend la valeur la plus petite
            if(val2<val1)
            {
                val1=val2;
                val2=val1-1;
            }
            // Exploration jusqu'au maillon precedent val1
            while(cpts<val1-2)
            {
                explo1=explo1->suiv;
                cpts++;
            }
            //Permutation
            tmp1=explo1->suiv;
            tmp2=explo1->suiv->suiv;
            tmp3=explo1->suiv->suiv->suiv;
            explo1->suiv->suiv->suiv=tmp1;
            explo1->suiv->suiv=tmp3;
            explo1->suiv=tmp2;
        }
        //Cas general
        else
        {
            // Exploration jusqu'au maillon precedent val1
            while(cpts<val1-2)
            {
                explo1=explo1->suiv;
                cpts++;
            }
            cpts=0;
            //Exploration jusqu'au maillon precedent val2
            while(cpts<val2-2)
            {
                explo2=explo2->suiv;
                cpts++;
            }
            ///explo1 contient le maillon précedent le maillon à val1
            ///explo2 contient le maillon précedent le maillon à val2

            //Permutation des 2 pointeurs de fin
            tmp1=explo2->suiv->suiv;
            explo2->suiv->suiv=explo1->suiv->suiv;
            explo1->suiv->suiv=tmp1;
            //Permutation des 2 pointeurs de debut
            tmp2=explo2->suiv;
            explo2->suiv=explo1->suiv;
            explo1->suiv=tmp2;

        }
    }
    // Cas permutation avec un maillon égal au premier maillon
    else
    {
        //On se met au cas general val1=1, val2!=1
        if(val2==1)
        {
            val2=val1;
            val1=1;
        }
        //Cas permutation maillons cote à cote (maillons 1 et 2)
        if(val2==2)
        {
            ///Exploration non necessaire
            //Permutation
            tmp1=ancre;
            tmp2=ancre->suiv;
            tmp3=ancre->suiv->suiv;
            ancre->suiv->suiv=tmp1;
            ancre->suiv=tmp3;
            ancre=tmp2;
        }
        //Cas Permutation non cote à cote avec le premier maillon
        else
        {
            //Exploration jusqu'au maillon val2
            while(cpts<val2-2)
            {
                explo2=explo2->suiv;
                cpts++;
            }
            //Permutation avec les 2 pointeurs de fin
            tmp1=explo2->suiv->suiv;
            explo2->suiv->suiv=ancre->suiv;
            ancre->suiv=tmp1;
            //Permutation avec l'ancre et le pointeur de debut;
            tmp2=explo2->suiv;
            explo2->suiv=ancre;
            ancre=tmp2;
        }
    }
    printf("Permutation effectuee\n");
    system("pause");
    system("cls");
    return ancre;

}
void Export(Cell* ancre)
{
    Cell* explo=ancre;
    FILE*liste=NULL;
    //Ouverture du fichier et ecriture du code de reconnaissance
    liste=fopen("data.ber","w");

    //Cas liste vide
    if(ancre==NULL)
    {
        printf("Il n'y a rien a importer\n");
        system("pause");
        system("cls");
        return;
    }
    //Cas liste avec un maillon
    if(ancre->suiv==NULL)
    {
        fputs("3S3HQxTFk4dh29u\nNe pas modifier ce fichier !\n",liste);
        //Ecriture des donnees
        fprintf(liste,"%d",ancre->data.id);
        fputs("\n",liste);
        fputs(ancre->data.nom,liste);
        fputs("\n",liste);
        fputs(ancre->data.prenom,liste);
        fputs("\n",liste);
        fprintf(liste,"%d",ancre->data.age);
        fputs("\n",liste);
        fprintf(liste,"%d",ancre->data.promo);
        fputs("\n",liste);
        fprintf(liste,"%d",ancre->data.TD);
        fputs("\n",liste);

    }
    //Cas general
    else
    {
        fputs("3S3HQxTFk4dh29u\nNe pas modifier ce fichier !\n*************************",liste);
        if(explo==NULL)
        {
            fputs("\n",liste);
        }
        while(explo!=NULL)
        {
            //Ecriture des donnees
            fputs("\n",liste);
            fprintf(liste,"%d",explo->data.id);
            fputs("\n",liste);
            fputs(explo->data.nom,liste);
            fputs("\n",liste);
            fputs(explo->data.prenom,liste);
            fputs("\n",liste);
            fprintf(liste,"%d",explo->data.age);
            fputs("\n",liste);
            fprintf(liste,"%d",explo->data.promo);
            fputs("\n",liste);
            fprintf(liste,"%d",explo->data.TD);
            //Exploration jusqu'a fin de la chaine
            explo=explo->suiv;
        }
    }
    fclose(liste);
    printf("\nExportation effectuee avec succes dans le fichier \"data.ber\"\n");
    system("pause");
    system("cls");


}
Cell* ImportTransfert(Cell* ancre,int id,char nom[TAILLE_MAX], char prenom[TAILLE_MAX], int age, int promo, int TD)
{
    Cell* new=NULL;
    Cell* explo=ancre;
    //Allocation du maillon m;
    new=(Cell*)malloc(1*sizeof(Cell));
    //Chargement des valeurs
    new->data.age=age;
    new->data.id=id;
    strcpy(new->data.nom,nom);
    strcpy(new->data.prenom,prenom);
    new->data.promo=promo;
    new->data.TD=TD;
    //Mise en queue du nouveau maillon
    new->suiv=NULL;
    explo=ancre;
    //Si liste vide
    if(ancre==NULL)
    {
        new->suiv=NULL;
        ancre=new;
    }
    else //Si liste non vide
    {
        //Exploration jusqu'au dernier maillon
        while(explo->suiv!=NULL)
        {
            explo=explo->suiv;
        }
        explo->suiv=new;
        new->suiv=NULL;
    }
    return ancre;

}
Cell* Import(Cell* ancre)
{
    FILE*liste=NULL;
    char chaine1[30];
    char chaine2[30];
    char chaine3[30];
    int id;
    char nom[TAILLE_MAX];
    char prenom[TAILLE_MAX];
    int age;
    int promo;
    int TD;
    char tampon;
    //Ouverture du fichier et ecriture du code de reconnaissance
    liste=fopen("data.ber","r+");
    if(liste==NULL)
    {
        printf("Fichier inexistant ! Positionnez le fichier dans le meme repertoire que le programme puis reessayez\n");
        system("pause");
        system("cls");
        return ancre;
    }
    else
    {
        fgets(chaine1,sizeof(chaine1),liste);
        fgets(chaine2,sizeof(chaine2),liste);
        fgets(chaine3,sizeof(chaine3),liste);
        if((!(strcmp(chaine1,"3S3HQxTFk4dh29u\n"))&&(!(strcmp(chaine2,"Ne pas modifier ce fichier !\n")))&&(!(strcmp(chaine3,"*************************\n")))))
        {
            while (!feof(liste))
            {
                //Lecture des valeurs
                fscanf(liste,"%d",&id);
                tampon=fgetc(liste);
                fgets(nom,sizeof(nom),liste);
                fgets(prenom,sizeof(prenom),liste);
                fscanf(liste,"%d",&age);
                fscanf(liste,"%d",&promo);
                fscanf(liste,"%d",&TD);
                //Ajustement des valeurs
                nom[strlen(nom)-1]='\0';
                prenom[strlen(prenom)-1]='\0';
                //Ajout en tete des donnees
                ancre=ImportTransfert(ancre,id,nom,prenom,age,promo,TD);
                /**      test
                printf("\n###\n%d\n",new->data.id);
                printf("%s\n",new->data.nom);
                printf("%s\n",new->data.prenom);
                printf("%d\n",new->data.age);
                printf("%d\n",new->data.promo);
                printf("%d\n",new->data.TD);
                printf("###\n");*/
            }
            printf("\n***Importation effectuee avec success***\n");
            system("pause");
            system("cls");
            fclose(liste);
            return ancre;
        }
        else
        {
            printf("Fichier corrompu !\n");
            system("pause");
            system("cls");
            fclose(liste);
            return ancre;
        }
    }
}

Cell* DeleteMaillon(Cell* ancre,int val)
{
    Cell* explo=ancre;
    int cpts=0;

    //Si premier maillon
    if(val==1)
    {
        ancre=ancre->suiv;
    }
    else
    {
        //Exploration jusqu'au maillon precedent le maillon val
        while(cpts<val-2)
        {
            explo=explo->suiv;
            cpts++;
        }
        explo->suiv=explo->suiv->suiv;
    }
    printf("\n Element supprimme avec success\n");
    system("pause");
    system("cls");
    return ancre;
}


