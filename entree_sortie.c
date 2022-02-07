#include "image.h"
#include "entree_sortie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AfficherImage(char* nomFichier)
{
  char nomCommande[4 + strlen(nomFichier)];
  sprintf(nomCommande, "eog %s", nomFichier);
  system(nomCommande);
}

t_image* LireImage(char* nomFichier)
{
  t_image* image = NULL;
  FILE *f = NULL;
  f = fopen(nomFichier, "r");
  if(f == NULL)
  {
    fprintf(stderr, "L'ouverture en r du fichier %s a échoué\n", nomFichier);
    return NULL;
  }
  // creerImage
  image = (t_image *)malloc(sizeof(t_image));
  // lecture entete
  char entete[10];
  int nuance_gris;
  if(fscanf(f, "%s %u %u %d", entete, &(image->largeur), &(image->hauteur), &nuance_gris)==EOF)
  {
    fprintf(stderr, "La lecture de l'entête du fichier %s a échoué\n", nomFichier);
    fclose(f);
    return NULL;
  }
  image->pixels = (unsigned char*)malloc((image->largeur)*(image->hauteur)*sizeof(unsigned char));
  if(image->pixels == NULL)
  {
    fprintf(stderr, "Erreur dans la création de l'image (dans LireImage).\n");
    fclose(f);
    return NULL;
  }
  // lecture pixels
  if(fread(image->pixels, sizeof(unsigned char), (image->largeur)*(image->hauteur), f)!=(image->largeur)*(image->hauteur))
  {
    fprintf(stderr, "Erreur dans la lecture des pixels du fichier %s (dans LireImage).\n", nomFichier);
    LibererImage(image);
    fclose(f);
    return NULL;
  }
  fclose(f);
  return image;
}

int EcrireImage(char* nomFichier, t_image image)
{
  FILE *f = NULL;
  f = fopen(nomFichier,"w+");
  if(f == NULL)
  {
    fprintf(stderr, "L'ouverture en w+ du fichier %s a échoué\n", nomFichier);
    return 0;
  }
  if(fprintf(f,"P5\n%d %d\n255\n", image.largeur, image.hauteur) == EOF)
  {
    fprintf(stderr, "L'écriture de la largeur et la hauteur du fichier %s a échoué\n", nomFichier);
    fclose(f);
    return 0;
  }
  if(fwrite(image.pixels, sizeof(unsigned char), image.largeur*image.hauteur, f) != image.largeur*image.hauteur)
  {
    fprintf(stderr, "L'écriture des pixels dans le fichier %s a échoué\n", nomFichier);
    fclose(f);
    return 0;
  }  
  fclose(f);
  return 1;
}
