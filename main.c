#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <complex.h>

#include "image.h"
#include "entree_sortie.h"
#include "config.h"

#define SEUIL 2

// renvoi 255 si un terme de la suite z_n associée à z_0 dépasse le seuil
// renvoi 0 si aucun terme de la suite z_n associée à z_0 ne dépasse le seuil
//---------------------------------------------------------------------------
int calcul_z_n(double complex z_0, int max_iter)
//---------------------------------------------------------------------------
{
  // déclaration et initialisation de z_n
  double complex z_n = z_0;
  
  // déclaration et initialisation du compteur de la boucle while
  int compteur = 0;

  while(compteur < max_iter && cabsl(z_n) < SEUIL)
  {// C.I : compteur < MAX_ITER ET le module de z_n ne dépasse pas le seuil
    z_n = z_n*z_n + z_0;
    compteur++;
  }// sortie : compteur >= MAX_ITER OU le module de z_n a dépassé le seuil
  
  return (cabsl(z_n)>SEUIL)?255:0;
}


void Usage(char* prog)
{
  fprintf(stderr,"Usage: %s <fichier config .txt> <image .pgm>\n", prog);
  exit(EXIT_FAILURE);
}


int main(int argc, char* argv[]){

  // vérification du bon nombre d'arguments
  if(argc != 3)
    Usage(argv[0]);

  // création et initialisation d'un pointeur de type t_config
  t_config *config;
  config = CreerConfig(argv[1]);

  // déclaration et initialisation d'un pointeur de type t_image
  t_image *image = CreerImage(config->R_X, config->R_Y);

  if(image)
  {
    unsigned long taille=(unsigned int)(image->largeur*image->hauteur);

    // déclaration et initialisation de z_0
    double complex z_0 = (config->C_X - 0.5*config->F_X) + (config->C_Y + 0.5*config->F_X*config->R_Y/config->R_X)*I;
    
    // coloration du premier pixel
    image->pixels[0] = calcul_z_n(z_0,config->MAX_ITER);

    for(unsigned int i = 1; i < taille; i++)
    {
      // si le i ème pixel est un multiple de image->largeur 
      // on décrémente la partie imaginaire de z_0 de F_X/R_X et
      // on remet la partie réelle de z_0 à la valeur (C_X - 0.5*F_X) (bord gauche)
      if(i%(image->largeur)==0)
      {
        z_0 += -I*config->F_X/config->R_X;
        z_0 = (config->C_X - 0.5*config->F_X) + I*cimag(z_0);
      }
      // sinon on incrémente la partie réelle de z_0 de F_X/R_X
      else
        z_0 += config->F_X/config->R_X;
        
      // coloration du i+1 ème pixel
      image->pixels[i] = calcul_z_n(z_0,config->MAX_ITER);
    }

    if(!EcrireImage(argv[2],*image))
      printf("Erreur dans l'écriture des pixels dans le fichier %s.\n", argv[2]);
  }
  
  LibererConfig(config);
  LibererImage(image);
  
  return EXIT_SUCCESS;
}
