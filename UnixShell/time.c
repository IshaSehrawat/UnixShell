/*EXEC.c 
  
#include<stdio.h> 
#include<unistd.h> 
  
int main() 
{ 
    int i; 
      
    printf("I am EXEC.c called by execvp() "); 
    printf("\n"); 
      
    return 0; 
}*/
#include<stdio.h>
#include<time.h>
#include<string.h>

int main(int argc, char *argv[])
{

    time_t t;
    time(&t);
    if(strcmp("no",argv[1])==0)
    printf("%s", ctime(&t));
    return 0;
}
