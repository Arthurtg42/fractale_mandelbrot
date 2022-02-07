#include <stdlib.h>
#include <stdio.h>
#include "config.h"

//---------------------------------------------------------------------------
t_config* CreerConfig(char* nomFichier)
//---------------------------------------------------------------------------
{
  FILE *f;
  t_config* config;
  
  // ouverture du fichier de configuaration en lecture
  f = fopen(nomFichier, "r") ;
  if (!f)
  {
    fprintf(stderr,"Erreur ouverture du fichier de configuration\n") ;
    return(NULL) ;
  }
  
  // Allocation dynamique de la place pour la structure config
  config = (t_config *)malloc(sizeof(t_config));
  
  if(config)
  {
    // tests de lecture
    
    if (fscanf(f," %u", &(config->R_X)) == EOF)
    { fprintf(stderr,"Erreur lecture format\n"); fclose(f); return(NULL);}
    
    if (fscanf(f," %u", &(config->R_Y)) == EOF)
    { fprintf(stderr,"Erreur lecture format\n"); fclose(f); return(NULL);}
  
    if (fscanf(f," %lf", &(config->C_X)) == EOF)
    { fprintf(stderr,"Erreur lecture format\n"); fclose(f); return(NULL);}
  
    if (fscanf(f," %lf", &(config->C_Y)) == EOF)
    { fprintf(stderr,"Erreur lecture format\n"); fclose(f); return(NULL);}
    
    if (fscanf(f," %lf", &(config->F_X)) == EOF)
    { fprintf(stderr,"Erreur lecture format\n"); fclose(f); return(NULL);}
  
    if (fscanf(f," %u", &(config->MAX_ITER)) == EOF)
    { fprintf(stderr,"Erreur lecture format\n"); fclose(f); return(NULL);}
  
  }

  return config;
}
//---------------------------------------------------------------------------
void LibererConfig(t_config* config)
//---------------------------------------------------------------------------
{
  free(config);
}


