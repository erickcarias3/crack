#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "md5.h"

int main( int argc, char *argv[] )
{
        
    if(argc<3){
        printf("please supply input and output file");
        exit(1);
    }
    
     if(strcmp(argv[1], argv[2]) == 0 )
    {
        printf("outputfile is same as input file");
        exit(1);
    }
    
    
    FILE *in = fopen(argv[1] , "r");
    
     if(!in){
        printf("cant open file %s for reading \n", argv[1]);
        exit(1);
    }
    
 
    FILE *out = fopen(argv[2] , "w");
    
    if(!out){
        printf("cant open file %s for reading \n", argv[2]);
        exit(1);
    }
    
    char line[100];
    
    while(fgets(line , 100 , in ) != NULL)
    {
        
        char *hash = md5( line , (strlen(line)-1) );
        fprintf(out , "hash: %s \n" , hash );
        free(hash);
    }
    
    fclose(out);
    fclose(in);
}