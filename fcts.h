#ifndef FCTS_H_INCLUDED
#define FCTS_H_INCLUDED
#define TAILLE_MAX 20 //Limite de la taille des noms et prenoms

//Structure informations sur etudiant
typedef struct Info
{
    int id;
    char nom[TAILLE_MAX];
    char prenom[TAILLE_MAX];
    int age;
    int promo;
    int TD;
}Info;

//Structure Maillon
typedef struct cell
{
    Info data;
    struct cell* suiv;
}Cell;

Cell *SaisieData();
void NbMaillon(Cell*);
Cell *AjoutTete(Cell*,Cell*);
Cell *AjoutQueue(Cell*,Cell*);
void AjoutMiddle(Cell*,Cell*,int);
int SearchOrdre(Cell*,int);
void SearchName(Cell*,char nom[TAILLE_MAX]);
Cell *PermutMaillon(Cell*,int,int);
Cell *DeleteMaillon(Cell*,int);
void Export(Cell*);
int verifCode();
Cell *ImportTransfert(Cell*,int,char nom[TAILLE_MAX],char prenom[TAILLE_MAX],int,int,int);
Cell *Import(Cell*);

#endif // FCTS_H_INCLUDED
