#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "filtrar.h"
#include <stdio.h>


int leer (){
        char ch[100];
      
        int leido, fd, tm;
         
        fd=open("./temp",O_RDWR| O_CREAT | O_TRUNC, 0777);
    
        if (fd<0){
                perror ("error:");
                return -1;             
        }
        
        while ((leido=read(0, ch, sizeof ch))>0)
            {
                lseek (fd, 0, SEEK_END); 
                write (fd, ch, leido);
         }
         tm=lseek (fd, 0, SEEK_END);
         
       return tm;

                                                                        
                                                                             
}   
