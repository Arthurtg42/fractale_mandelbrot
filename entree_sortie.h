#ifndef entree_sortie_h
#define entree_sortie_h

//---------------------------------------------------------------------------
// Appelle system() pour executer la commande : eog nomFichier.
//---------------------------------------------------------------------------
void AfficherImage(char* nomFichier);
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Fait les allocations mémoire pour créer une structure image
// et la zone pour stocker les pixels,
// puis retourne l'adresse de la structure image
// remplie à partir du fichier nomFichier ou NULL en cas de problème.
//---------------------------------------------------------------------------
t_image* LireImage(char* nomFichier);
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Ouvre le fichier nomFichier et écrit (crée si nécessaire) dans ce fichier
// l'entete puis les pixels de im (nomFichier étant au format .pgm).
// La fonction retourne 1 si l'écriture réussit et 0 en cas d'échec
int EcrireImage(char* nomFichier, t_image im);
//---------------------------------------------------------------------------

#endif
