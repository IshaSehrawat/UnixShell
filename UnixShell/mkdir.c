#include<stdio.h> 
#include<unistd.h> 
#include<readline/readline.h> 
#include<readline/history.h> 
#include<string.h> 
#include<stdlib.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include <sys/stat.h> 	
int main(int argc, char *argv[])
{
	struct stat st = {0};
	char * PATH=argv[1];
	char * checko="--help";
	if(strcmp(checko,PATH)==0)
	{
printf("%s\n","MKDIR(1)                                                       User Commands                                                      MKDIR(1)\n\nNAME\nmkdir - make directories\nSYNOPSIS\nmkdir [OPTION]... DIRECTORY...\nDESCRIPTION\nCreate the DIRECTORY(ies), if they do not already exist.\nMandatory arguments to long options are mandatory for short options too.\n-m, --mode=MODE\nset file mode (as in chmod), not a=rwx - umask\n-p, --parents\nno error if existing, make parent directories as needed\n-v, --verbose\nprint a message for each created directory\n-Z     set SELinux security context of each created directory to the default type\n--context[=CTX]\nlike -Z, or if CTX is specified then set the SELinux or SMACK security context to CTX\n--help display this help and exit\n--version\noutput version information and exit");	}
	else{
	if(stat("/some/directory", &st) == -1)
	{
	    mkdir(PATH, 0700);
	}
}
	return 0;
}