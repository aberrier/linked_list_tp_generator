#ifndef FCTS_H_INCLUDED
#define FCTS_H_INCLUDED
#define TAILLE_MAX 20 //Limite de la taille des {{verbose_name}}s et pre{{verbose_name}}s

//Structure informations sur {{name}}
typedef struct {{name}}
{
    int id;
    char {{verbose_name}}[TAILLE_MAX];
    char {{char_field}}[TAILLE_MAX];
    int {{int_field_1}};
    int {{int_field_2}};
    int {{int_field_3}};
}{{Name}};

//Structure Maillon
typedef struct cell
{
    {{Name}} data;
    struct cell* suiv;
}Cell;

Cell *SaisieData();
void NbMaillon(Cell*);
Cell *AjoutTete(Cell*,Cell*);
Cell *AjoutQueue(Cell*,Cell*);
void AjoutMiddle(Cell*,Cell*,int);
int SearchOrdre(Cell*,int);
void Search{{Verbose_name}}(Cell*,char {{verbose_name}}[TAILLE_MAX]);
Cell *PermutMaillon(Cell*,int,int);
Cell *DeleteMaillon(Cell*,int);
void Export(Cell*);
int verifCode();
Cell *ImportTransfert(Cell*,int,char {{verbose_name}}[TAILLE_MAX],char {{char_field}}[TAILLE_MAX],int,int,int);
Cell *Import(Cell*);

#endif // FCTS_H_INCLUDED
