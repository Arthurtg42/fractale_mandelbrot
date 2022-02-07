#include <stdlib.h>
#include <stdio.h>
#include "image.h"

void LibererImage(t_image* image)
{
  free(image->pixels);
  free(image);
}

t_image* CreerImage(unsigned int largeur, unsigned int hauteur)
{
  t_image* image = NULL;
  image = (t_image *)malloc(sizeof(t_image));
  image->pixels = (unsigned char*)malloc(largeur*hauteur*sizeof(unsigned char));
  image->largeur = largeur;
  image->hauteur = hauteur;
  
  if(image->pixels == NULL)
  {
    fprintf(stderr, "Erreur dans la création de l'image.\n");
    return NULL;
  }
  return image;
}
