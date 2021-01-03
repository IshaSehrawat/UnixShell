#include <stdio.h> 
#include <signal.h> 
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{  
	char ch[1000];
	char* flag[3];
	flag[0]="Defualt";		//numbers
	flag[1]="AB";		//adds $ at the end
	flag[2]="CD";
	FILE *fp;
	printf("%s\n",argv[1]);
	fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		perror("Error while openingof file\n");
		exit(EXIT_FAILURE);
	}
	int index=1;
	if(strcmp(argv[2],flag[1])==0)
	{
		while(fgets(ch,1000,fp)!=NULL)
	{
		printf("%s$",ch);
		printf("\n");
	}	
	}

	else if(strcmp(argv[2],flag[2])==0)
	{
		while(fgets(ch,1000,fp)!=NULL)
			{
				printf("%d. %s\n",index++,ch);
			}
	}
	else
	{
		while(fgets(ch,1000,fp)!=NULL)
		{
			puts(ch);
		}
	}
	fclose(fp);
	return 0;
	
}
/*#include <stdio.h>

int main () {
   FILE *fp;
   char str[60];

   fp = fopen("file.txt" , "r");
   if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }
   if( fgets (str, 60, fp)!=NULL ) {
      puts(str);
   }
   fclose(fp);
   
   return(0);
}*/