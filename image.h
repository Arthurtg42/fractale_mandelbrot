#ifndef image_h
#define image_h

typedef struct Image
{
  unsigned char* pixels ;
  unsigned int largeur ;
  unsigned int hauteur ;
} t_image ;

//---------------------------------------------------------------------------
// Libère la mémoire dynamiquement affectée de image.
//---------------------------------------------------------------------------
void LibererImage(t_image* image);
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Fait les allocations mémoire pour créer une structure image
// et la zone pour stocker les pixels,
// puis retourne l'adresse de la structure image
//---------------------------------------------------------------------------
t_image* CreerImage(unsigned int largeur, unsigned int hauteur);
//---------------------------------------------------------------------------

#endif
