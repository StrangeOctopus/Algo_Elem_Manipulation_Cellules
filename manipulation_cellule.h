#ifndef MAN_CELL
#define MAN_CELL

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct cellule{
  int val;
  struct cellule *suiv;
}CELLULE, *PTRCELLULE;

PTRCELLULE creation(int val);
PTRCELLULE suppression(PTRCELLULE aux);
PTRCELLULE insertionTete(PTRCELLULE tete, PTRCELLULE element);
PTRCELLULE suppression_tete(PTRCELLULE *adrTete);
PTRCELLULE insertionTriee(PTRCELLULE tete, PTRCELLULE element);
int suppression_element(PTRCELLULE *adrTete, PTRCELLULE element);
void affiche(PTRCELLULE tete);

#endif
