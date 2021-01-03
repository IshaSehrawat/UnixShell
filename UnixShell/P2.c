#include<stdio.h> 
#include<unistd.h> 
#include<readline/readline.h> 
#include<readline/history.h> 
#include<string.h> 
#include<stdlib.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include <sys/stat.h> 	
#define clear() printf("\033[H\033[J")

int CD(char* c)
{
	chdir(c);
	return 0;
}

int ECHO(char* c)
{
	printf("%s\n",c);
	return 0;
}

int HISTORY(char* c[1000],int index)
{
	int i=0;
	while(i<index)
	{
		printf("%s\n",c[i]);
		i++;
	}
	return 0;
}

int PWD()
{
	char cwd[1024]; 
	getcwd(cwd, sizeof(cwd)); 
	printf("Dir: %s", cwd);
	printf("\n");
	return 0;
}

int main()
{
	clear();
	int index=0;
	char input[1000];
	char* history[1000];
	char* buf1;
	char* Commands[10];
	Commands[0]="cd";		// --help and ..
	Commands[1]="echo";		//-n and --help
	Commands[2]="history";	// !! and --help
	Commands[3]="pwd";		//-L and --help
	Commands[4]="exit";		//none
	Commands[5]="ls";		//--help
	Commands[6]="cat";		//-n and -E
	Commands[7]="date";		//--help
	Commands[8]="rm";		//--help
	Commands[9]="mkdir";	//--help
	do
	{
		buf1=readline(">>");
		if(strlen(buf1)!=0)
		{
			history[index]=buf1;
			strcpy(input, buf1);		//input has the command
			index++;
		}
		char * token = strtok(input, " ");

		if(strcmp(token,Commands[0])==0)
		{
			char* flag[2];
			flag[0]="--help";
			token = strtok(NULL, " ");
			if(token!=NULL)
			{
				if(strcmp(token,flag[0])==0)
				{
					printf("cd: cd [-L|[-P [-e]] [-@]] [dir]\nChange the shell working directory.\nChange the current directory to DIR.  The default DIR is the value of the HOME shell variable.\n The variable CDPATH defines the search path for the directory containing DIR.  Alternative directory names in CDPATH are separated by a colon (:). A null directory name is the same as the current directory.  If DIR begins with a slash (/), then CDPATH is not used.\nIf the directory is not found, and the shell option `cdable_vars' is set, the word is assumed to be  a variable name.  If that variable has a value, its value is used for DIR.\nOptions:\n\t-L	force symbolic links to be followed: resolve symbolic links in DIR after processing instances of `..'\n\t-P	use the physical directory structure without following symbolic links: resolve symbolic links in DIR before processing instances of `..'\n\t-e	if the -P option is supplied, and the current working directory cannot be determined successfully, exit with a non-zero status\n\t-@	on systems that support it, present a file with extended attributes as a directory containing the file attributes\nThe default is to follow symbolic links, as if `-L' were specified. `..' is processed by removing the immediately previous pathname component back to a slash or the beginning of DIR.\nExit Status: Returns 0 if the directory is changed, and if $PWD is set successfully when -P is used; non-zero otherwise.\n");
				}
				else
				CD(token);
			}
		}
		else if(strcmp(token,Commands[1])==0)
		{
			char* flag[2];
			flag[0]="-n";
			flag[1]="--help";
			token = strtok(NULL, " ");
			if(strcmp(flag[0],token)==0)
			{
				while(token!=NULL)
				{
					printf("%s ",token);
					token = strtok(NULL, " ");
				}
			}
			else if(strcmp(flag[1],token)==0)
			{
				printf("%s\n","NAME\necho - Write arguments to the standard output.\nSYNOPSIS\necho [-neE] [arg ...]\nDESCRIPTION\nWrite arguments to the standard output.\nDisplay the ARGs, separated by a single space character and followed by a\nnewline, on the standard output.\nOptions:\n-n	do not append a newline\n-e	enable interpretation of the following backslash escapes\n-E	explicitly suppress interpretation of backslash escapes\n`echo' interprets the following backslash-escaped characters:\n\a	alert (bell)\n\b	backspace\n	suppress further output\n\e	escape character\n escape character\n\f	form feed\n\\n	new line\n\r	carriage return\n\t	horizontal tab\n\v	vertical tab\n\\	backslash\n\0nnn	the character whose ASCII code is NNN (octal).  NNN can be\n0 to 3 octal digits\n the eight-bit character whose value is HH (hexadecimal).  HH\ncan be one or two hex digits\nHHHH	the Unicode character whose value is the hexadecimal value HHHH.\ncan be one to four hex digits.\nthe Unicode character whose value is the hexadecimal value\ncan be one to eight hex digits.\nExit Status:\nReturns success unless a write error occurs.\n");			}
			//char* buffer;
			else
			{
				while(token!=NULL)
				{
					printf("%s ",token);
					token = strtok(NULL, " ");
				}
				printf("\n");
			}
			//if(token!=NULL)
			//ECHO(token);
		}
		else if(strcmp(token,Commands[2])==0)
		{
			char* flag[2];
			flag[0]="!!";
			flag[1]="--help";
			token=strtok(NULL," ");
			if(token==NULL)
			HISTORY(history,index);
			else
			{
				if(strcmp(token,flag[0])==0)
				{
					if(index>2)
					printf("%s\n",history[index-2]);
				}
				else if(strcmp(token,flag[1])==0)
				{
					printf("%s\n","history: history [-c] [-d offset] [n] or history -anrw [filename] or history -ps arg [arg...]\nDisplay or manipulate the history list.\nDisplay the history list with line numbers, prefixing each modified\nentry with a `*'.  An argument of N lists only the last N entries.\nOptions:\n-c	clear the history list by deleting all of the entries\n-d offset	delete the history entry at position OFFSET.\n-a	append history lines from this session to the history file\n-n	read all history lines not already read from the history file\nand append them to the history list\n-r	read the history file and append the contents to the history\nlist\n-w	write the current history to the history file\n-p	perform history expansion on each ARG and display the result\nwithout storing it in the history list\n-s	append the ARGs to the history list as a single entry\nIf FILENAME is given, it is used as the history file.  Otherwise,\nif HISTFILE has a value, that is used, else ~/.bash_history.\nIf the HISTTIMEFORMAT variable is set and not null, its value is used\nas a format string for strftime(3) to print the time stamp associated\nwith each displayed history entry.  No time stamps are printed otherwise.\nExit Status:\nReturns success unless an invalid option is given or an error occurs.\n");
				}
				else
				{
					printf("Enter Valid Command\n");
				}
			}
		}
		else if(strcmp(token,Commands[3])==0)
		{
			char* subhandle[8];
			subhandle[0]="-L";
			subhandle[1]="--help";
			token=strtok(NULL," ");
			//printf("token %s\n",token);
			if(token!=NULL)
			{
				//printf("in if\n");
				if(strcmp(token,subhandle[0])==0)
				{
					PWD();
				}
				else if(strcmp(token,subhandle[1])==0)
				{
					printf("PWD(1)\t\t\tUser Commands\t\t\tPWD(1)\nNAME\n\tpwd - print name of current/working directory\nSYNOPSIS\npwd [OPTION]...\nDESCRIPTION\nPrint the full filename of the current working directory.\n\t-L, --logical use PWD from environment, even if it contains symlinks\n\t-P, --physical avoid all symlinks\n\t--help display this help and exit\n\t--version output version information and exit\n\tIf no option is specified, -P is assumed.\n");
				}
				else
				{
					printf("Enter valid command\n");
				}
			}
			else
			{
				//printf("in else\n");
				PWD();
			}

		}
		else if(strcmp(token,Commands[4])==0)
		{
			//exitcondition=1;
			exit(0);
		}
		else if(strcmp(token,Commands[5])==0)
		{
			int pd=fork();
        	int status;
        	char * str1;
        	char * str2;
        	char * FLAG="YES";
        	char * toto="--help";
        	//printf("hi\n");
        	if (pd==0)
       		{ 	
       			token=strtok(NULL," ");
       			//printf("token%s\n",token);
       			if(token==NULL)
       				{
       					FLAG="YES";
       					str1=getcwd(str2,100);
       					char *args[]={"./ls",str1,FLAG,NULL}; 
        				execvp(args[0],args); 
       				}
       			else if(strcmp(token,toto)==0)
       				{
       					//printf("ohoo\n");
       					str1=getcwd(str2,100);
       					//printf("yoho0\n");
       					FLAG="NO";
       					//printf("cop\n");
       					char *args[]={"./ls",str1,FLAG,NULL}; 
        				execvp(args[0],args); 
       				}
       			else
       				{
       					FLAG="CD";
       					str1=getcwd(str2,100);
       					char *args[]={"./ls",str1,FLAG,NULL}; 
        				execvp(args[0],args); 
       				}
       			//printf("hello im here\n");
       			//str1=getcwd(str2,100);
       			//printf("FLAG L %s\n",FLAG);
       			//char *args[]={"./ls",str1,FLAG,NULL}; 
        		//execvp(args[0],args); 
    		}
         	waitpid(pd, &status, 0);
		}
		else if(strcmp(token,Commands[6])==0)
		{
			char* flag[2];
			flag[0]="-n";		//numbers
			flag[1]="-E";		//adds $ at the end
			char* FLAG="Default";
			int pd=fork();
        	int status;
        	if (pd==0)
       		{
       		 	token=strtok(NULL," ");
       		 	printf("token here%s\n",token);
       		 	if(token!=NULL)
       		 	{
       		 		char * duptok=token;
       		 		token=strtok(NULL," ");
       		 		printf("token inside %s\n",token);
       		 		if(token==NULL){FLAG="Default";char *args[]={"./cat",duptok,FLAG,NULL}; 
        			execvp(args[0],args); }
       		 		else if(strcmp(token,flag[0])==0){FLAG="AB";char *args[]={"./cat",duptok,FLAG,NULL}; 
        			execvp(args[0],args); }
       		 		else if(strcmp(token,flag[1])==0){FLAG="CD";char *args[]={"./cat",duptok,FLAG,NULL}; 
        			execvp(args[0],args); }
       		 		else{FLAG="DONT";char *args[]={"./cat",duptok,FLAG,NULL}; 
        			execvp(args[0],args); }
        		}
    		}
         	waitpid(pd, &status, 0);
		}
		else if(strcmp(token,Commands[7])==0)
		{
			char* flag[1];
			flag[0]="--help";
			char* FLAG="no";
			token=strtok(NULL," ");
			//printf("token i s%s\n",token);
			if(token!=NULL)
			if(strcmp(token,flag[0])==0)
			{
				printf("DATE(1)\tUser Commands\tDATE(1)\nNAME\n\tdate - print or set the system date and time\n\tSYNOPSIS\n \tdate [OPTION]... [+FORMAT]\n\tdate [-u|--utc|--universal] [MMDDhhmm[[CC]YY][.ss]]\nDESCRIPTION\nDisplay the current time in the given FORMAT, or set the system date.\nMandatory  arguments  to  long  options are mandatory for short options too.\n\t-d, --date=STRING\n\tdisplay time described by STRING, not 'now'\n\t--debug\nannotate the parsed date, and warn about questionable  usage  to stderr\n-f, --file=DATEFILE\n");				FLAG="yes";
			}
			
				int pd=fork();
	        	int status;
	        	if (pd==0)
	       		{ char *args[]={"./time",FLAG,NULL}; 
	        	execvp(args[0],args); 
	    		}
	         	waitpid(pd, &status, 0);
         	
		}
		else if(strcmp(token,Commands[8])==0)
		{
			int pd=fork();
			int status;
			char* flag="--help";
			if(pd==0)
			{	
				char str[1024];
	         	char *file=getcwd(str, 100);
	   			char path[strlen(file)+1];
	   			int check=0;
				strcpy(path,file);
				char slash[1]="/";
				path[strlen(file)]='/';
				token = strtok(NULL, " ");
				if(strcmp(token,flag)==0){
				strcpy(path,flag);
				check=1;}
				if(check==0)
				if(token!=NULL){
				int kp=strlen(token);
				char final[kp];
				strcpy(final,token);
				strcat(path,final);
				}
				char *args[]={"./remove",path,NULL};
				execvp(args[0],args);
				
			}
			waitpid(pd, &status, 0);

		}
		else if(strcmp(token,Commands[9])==0)
		{
			int pd=fork();
			int status;
			char* flag="--help";
			if(pd==0)
			{
				char str[1024];
				int check=0;
	         	char *file=getcwd(str, 100);
	   			char path[strlen(file)+1];
				strcpy(path,file);
				char slash[1]="/";
				//strcat(path,slash);
				path[strlen(file)]='/';
				token = strtok(NULL, " ");
				if(strcmp(token,flag)==0){
					strcpy(path,flag);
					check=1;
				}
				if(check==0)
				if(token!=NULL){
				int kp=strlen(token);
				char final[kp];
				//printf("token is %s\n",token);
				strcpy(final,token);
				strcat(path,final);
				}
				char *args[]={"./mkdir",path,NULL};
				execvp(args[0],args);
				//mkdir(path,0777);
				
			}
			waitpid(pd, &status, 0);
		}
		else
		{
			printf("Enter a valid command !!\n");
		}
	}while(1);
	return 0;
}