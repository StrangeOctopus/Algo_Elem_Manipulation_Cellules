#include"manipulation_cellule.h"

/*---------------------------------------------------------------------------*/
/*             Créé une nouvelle cellule et renvoie un pointeur              */
/*                          vers cette-dernière                              */
/*---------------------------------------------------------------------------*/

PTRCELLULE creation(int val){
  PTRCELLULE aux = malloc(sizeof(CELLULE));
  if(!aux)
    return NULL;

  aux->val = val;
  aux->suiv = NULL;
  return aux;
}

/*---------------------------------------------------------------------------*/
/*          Supprime de la mémoire la cellule passée en paramètre            */
/*                                                                           */
/*---------------------------------------------------------------------------*/

PTRCELLULE suppression(PTRCELLULE aux){
  free(aux);
  return NULL;
}

/*---------------------------------------------------------------------------*/
/*             Insert l'élément passé en paramètre en tête de la             */
/*                         liste pointée par 'tete'                          */
/*---------------------------------------------------------------------------*/

PTRCELLULE insertionTete(PTRCELLULE tete, PTRCELLULE element){
  if(!element)
    return NULL;

  element->suiv = tete;
  return element;
}

/*---------------------------------------------------------------------------*/
/*     Supprime l'élément en tete de la liste dont l'adresse est passée      */
/*             en paramètre, puis retourne l'élément supprimé                */
/*---------------------------------------------------------------------------*/

PTRCELLULE suppression_tete(PTRCELLULE *adrTete){
  PTRCELLULE aux = (*adrTete);
  if(!(*adrTete))
    return NULL;

  (*adrTete) = aux->suiv;
  aux->suiv = NULL;
  return aux;
}

/*---------------------------------------------------------------------------*/
/*          Insert l'élément dans la liste chainée de manière triée          */
/*              dans l'ordre croissant des valeurs des cellules              */
/*---------------------------------------------------------------------------*/

PTRCELLULE insertionTriee(PTRCELLULE tete, PTRCELLULE element){
  PTRCELLULE aux = tete;
  PTRCELLULE tmp;
  if(!tete)
    return element;

  if(element->val <= tete->val)
    return insertionTete(tete, element);

  while(aux->suiv){
    if(element->val <= aux->suiv->val){
      tmp = aux->suiv;
      aux->suiv = element;
      element->suiv = tmp;
      return tete;
    }
    else{
      aux = aux->suiv;
    }
  }
  aux->suiv = element;
  element->suiv = NULL;
  return tete;
}

/*----------------------------------------------------------------------------*/
/* Supprime l'élément passé en paramètre de la liste dont la tete est pointée */
/*      par adrTete, où la liste est une liste triée par ordre croissant      */
/*----------------------------------------------------------------------------*/

int suppression_element(PTRCELLULE *adrTete, PTRCELLULE element){
  PTRCELLULE aux = (*adrTete);
  if(!(*adrTete))
    return 0;

  if((*adrTete) == element){
    suppression_tete(adrTete);
    return 1;
  }

  while(aux->suiv){
    if(aux->suiv == element){
      aux->suiv = element->suiv;
      element->suiv = NULL;
      return 1;
    }
    else{
      aux = aux->suiv;
    }
  }
  return 0;
}

/*---------------------------------------------------------------------------*/
/*      Affiche les valeurs des cellules de la liste pointée par tete        */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void affiche(PTRCELLULE tete){
  if(tete){
    printf("%d\t", tete->val);
    affiche(tete->suiv);
  }
}

/*---------------------------------------------------------------------------*/
/*          Insert l'élément dans la liste chainée de manière triée          */
/*      dans l'ordre croissant des valeurs des cellules (Récursivement)      */
/*---------------------------------------------------------------------------*/

PTRCELLULE insertionTrieeREC(PTRCELLULE tete, PTRCELLULE element){
  if(!tete){
    element->suiv = NULL;
    return element;
  }
  if(tete->val >= element->val){
    element->suiv = tete;
    return element;
  }
  tete->suiv = insertionTrieeREC(tete->suiv, element);
  return tete;
}

/*---------------------------------------------------------------------------*/
/*          Tri la liste pointée par tete avec l'algorithme du tri           */
/*                      par insertion (Récursivement)                        */
/*---------------------------------------------------------------------------*/

PTRCELLULE triInsertionREC(PTRCELLULE tete){
  PTRCELLULE res;
  if(!tete){
    return NULL;
  }
  if(!tete->suiv)
    return tete;

  res = triInsertionREC(tete->suiv);
  res = insertionTrieeREC(res, tete);
  return res;
}

/*---------------------------------------------------------------------------*/
/*          Retourne l'adresse de la cellule de la liste pointée par         */
/*                   tete ayant la valeur la plus élevée                     */
/*---------------------------------------------------------------------------*/

PTRCELLULE rechercheMax(PTRCELLULE tete){
  PTRCELLULE aux;
  if(!tete)
    return NULL;
  if(!tete->suiv)
    return tete;
  aux = rechercheMax(tete->suiv);
  if(aux->val > tete->val)
    return aux;
  else
    return tete;
}

/*---------------------------------------------------------------------------*/
/*          Supprime l'élément passé en paramètre de la liste pointée        */
/*                      par le pointeur d'adresse adrTete                    */
/*---------------------------------------------------------------------------*/

PTRCELLULE supprimeElement(PTRCELLULE *adrTete, PTRCELLULE element){
  if(!(*adrTete))
    return NULL;
  if(*adrTete == element){
    *adrTete = element->suiv;
    element->suiv = NULL;
    return element;
  }
  return supprimeElement(&(*adrTete)->suiv, element);
}

/*---------------------------------------------------------------------------*/
/*          Tri la liste pointée par tete avec l'algorithme du tri           */
/*                      par selection (Récursivement)                        */
/*---------------------------------------------------------------------------*/

PTRCELLULE triSelectionREC(PTRCELLULE tete){
  PTRCELLULE aux;
  PTRCELLULE max;
  if(!tete)
    return NULL;
  if(!tete->suiv)
    return tete;

  max = rechercheMax(tete);
  supprimeElement(&tete, max);
  tete = triSelectionREC(tete);
  aux = tete;
  while(aux->suiv){
    aux = aux->suiv;
  }
  aux->suiv = max;
  return tete;
}
