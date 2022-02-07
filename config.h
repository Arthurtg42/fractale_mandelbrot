#ifndef config_h
#define config_h
#include <stdio.h>

typedef struct Config
{
  unsigned int R_X ;
  unsigned int R_Y ;
  double C_X;
  double C_Y;
  double F_X;
  unsigned int MAX_ITER;
} t_config ;

//---------------------------------------------------------------------------
t_config* CreerConfig(char* nomFichier);
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void LibererConfig(t_config* config);
//---------------------------------------------------------------------------

#endif
