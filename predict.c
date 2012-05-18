/**
 
  EXERCICE
  Créer un programme qui permet de générer les journées et les rencontres d'une compétition de football.
  On définit le nombre d'équipes à 16.
  
  APPROFONDISSEMENT 
  Prévoir le cas où le nombre d'équipes est impair.
  
  
  PROGRAMME Predict
    
    CONST Nombre_Equipes  = 16
    CONST Nombre_Journees = 15
    CONST Nombre_Matchs_par_Journee   = 8
    CONST Total_Matchs    = 120
    
    
    TYPE Liste_Equipes  : TABLEAU[Nombre_Equipes] ENTIERS
    
    
    
    TYPE Liste_Journees : TABLEAU[Nombre_Journees, Nombre_Matchs_par_Journee] ENTIERS    
    
    // Une matrice 120, 2 pour contenir tous les matchs de la saison
    
    TYPE Liste_Matchs   : TABLEAU[Total_Matchs, 2] ENTIERS 
    
    VAR equipes : Liste_Equipes    
    VAR journee : Liste_Journees
    
    VAR i, j, k, domicile, visiteur : ENTIERS
    
    
  DEBUT
  
    // On initialise les equipes chacune recoit un id allant de 1 à 16
    POUR i ALLANT DE 1 à Nombre_Equipes FAIRE
      Liste_Equipes[i] = i
    FIN POUR
    
    k <---- 1 // L'index du match dans le tableau des matchs
  
    POUR i ALLANT de 1 à Nombre_Journees FAIRE

      POUR j ALLANT de 1 à Nombre_Matchs_par_Journee FAIRE
        
        Liste_Journees[i,j] <------- k
        
        domicile  <--- (i+j) mod (Nombre_Equipes -1)
        exterieur <--- (Nombre_Equipes -1 -j + i) mod (Nombre_Equipes -1)
        
        SI j = 0 ALORS
          exterieur = Nombre_Equipes -1
        FIN SI        
        
        // Pour les journées impaires lon intervetit l'ordre domicile exterieur
        
        SI (i%2)==1 && j==0 ALORS
        
          Liste_Matchs[k, 1]  <------- exterieur
          Liste_Matchs[k, 2]  <------- domicile
          
        SINON

          Liste_Matchs[k, 1]  <------- domicile
          Liste_Matchs[k, 2]  <------- exterieur        
        
        FIN SI
        
        k <---- k +1
        
      FIN POUR

    FIN POUR
  
  FIN
 
 */

#include <stdio.h>
#include <stdlib.h>
    
#define Nombre_Equipes 16
#define Nombre_Journees 15
#define Nombre_Matchs_par_Journee 8
#define Total_Matchs 120
 
int main (int argc, char *argv[])
{

  int Equipes[Nombre_Equipes], 
      Journees[Nombre_Journees][Nombre_Matchs_par_Journee], 
      Matchs[Total_Matchs][2],
      i,j,k, domicile, exterieur;
 
  /**
   *
   */
  for (i = 0; i < Nombre_Equipes; i += 1) // start for loop
  {
    Equipes[i] = i;
  } // end for loop
  
  k = 0;
 
  /**
   * Création des journées et des matches
   *
   */
  for (i = 0; i < Nombre_Journees; i += 1) // start for loop
  {
    for (j = 0; j < Nombre_Matchs_par_Journee; j += 1) // start for loop
    {
    
      Journees[i][j] = k;
      
      domicile  = (i+j) % (Nombre_Equipes -1);
      exterieur = (Nombre_Equipes -1 -j + i) % (Nombre_Equipes -1);

      if (j==0)
      {
        exterieur = Nombre_Equipes -1;
      }

      if ((i%2)==1 && j==0) 
      {        
        Matchs[k][1] = domicile;      
        Matchs[k][0] = exterieur;
      }
      else
      {    
        Matchs[k][0] = domicile;      
        Matchs[k][1] = exterieur;
      }
      
      
      
      k++;
      
    } // end for loop
  } // end for loop
  
  
  /**
   * Algorithme d'affichage
   *
   */
  for (i = 0; i < Nombre_Journees; i += 1) // start for loop
  {
  
    printf("Journée:%2d --- ", i);
  
    for (j = 0; j < Nombre_Matchs_par_Journee; j += 1) // start for loop
    {
    
      k = Journees[i][j];
      
      printf("%d#%d ", Matchs[k][0], Matchs[k][1]);
      
    } // end for loop
    
    printf("\n");
    
  } // end for loop
 
 
  
  return 0;
} 
 
 
