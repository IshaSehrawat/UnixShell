#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
#include<dirent.h>
#include<errno.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    printf("arg2 %s\n",argv[2]);
    if(strcmp(argv[2],"YES")==0)
    {
            write(1,argv[1],strlen(argv[1]));
            if (argc<1){
                exit(EXIT_FAILURE);
                return 0;
            }

            struct dirent *d;
            DIR *dir;
            if (strcmp(argv[1],"")==0)
            {
                dir = opendir(".");
            }
            else
            {
                dir = opendir(argv[1]);
            }
            
            if (!dir){
               write(1,argv[1],strlen(argv[1]));
                perror ("Une to read directory");
                exit(EXIT_FAILURE);
            }

            while ((d=readdir(dir))!=NULL){

                if (d->d_name[0] == '.'){
                    continue;
                }

                printf("%s  ", d->d_name);
            }

            printf("\n");
    }

    else if(strcmp(argv[2],"NO")==0){
        printf("LS(1)\tUser Commands\tLS(1)\nNAME\n\tls - list directory contents\n\tSYNOPSIS\n\tls [OPTION]... [FILE]...\n\tDESCRIPTION\n\tList information about the FILEs (the current directory by default).  Sort entries alphabetically if none of -cftuvSUX nor --sort is specified.\nMandatory arguments to long options are mandatory for short options too.\n\t-a, --all\n\tdo not ignore entries starting with .\n-A, --almost-all\n\tdo not list implied . and ..\n\t--author\n\twith -l, print the author of each file\n\t-b, --escape\n\tprint C-style escapes for nongraphic characters\n\t--block-size=SIZE\n\tscale sizes by SIZE before printing them; e.g., '--block-size=M' prints sizes in units of 1,048,576 bytes; see SIZE format below\n\t-B, --ignore-backups do not list implied entries ending with ~\n\t-c     with -lt: sort by, and show, ctime (time of last modification of file status information); with -l: show ctime and sort by name; otherwise: sort by ctime, newest first\n\t-C     list entries by columns\n");
    }
    else
    {
        printf("Not a valid flag\n");
    }

    return 0;   
}