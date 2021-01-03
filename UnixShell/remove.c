#include<stdio.h> 
#include<unistd.h> 
#include<readline/readline.h> 
#include<readline/history.h> 
#include<string.h> 
#include<stdlib.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include <sys/stat.h> 	
int main(int c, char *argv[]) 
{ 
	char* flag="--help";
	if(strcmp(argv[1],flag)==0){
printf("%s\n","NAME\nrm - remove files or directories\nSYNOPSIS\nrm [OPTION]... [FILE]...\nDESCRIPTION\nThis manual page documents the GNU version of rm.  rm removes each specified file.  By default, it does not remove directories.\nIf  the -I or --interactive=once option is given, and there are more than three files or the -r, -R, or --recursive are given, then\nrm prompts the user for whether to proceed with the entire operation.  If the response is not affirmative, the  entire  command  is\naborted.\nOtherwise,  if a file is unwritable, standard input is a terminal, and the -f or --force option is not given, or the -i or --inter‐\nactive=always option is given, rm prompts the user for whether to remove the file.  If the response is not affirmative, the file is\nskipped.\nOPTIONS\nRemove (unlink) the FILE(s).\n-f, --force\nignore nonexistent files and arguments, never prompt\n-i     prompt before every removal\n-I     prompt  once before removing more than three files, or when removing recursively; less intrusive than -i, while still giving\nprotection against most mistakes\n--interactive[=WHEN]\nprompt according to WHEN: never, once (-I), or always (-i); without WHEN, prompt always\n--one-file-system\nwhen removing a hierarchy recursively, skip any directory that is on a file system different from that of the  corresponding\ncommand line argument\n--no-preserve-root\ndo not treat '/' specially\n--preserve-root\ndo not remove '/' (default)\n-r, -R, --recursive\nremove directories and their contents recursively\n-d, --dir\nremove empty directories\n-v, --verbose\nexplain what is being done\n--help display this help and exit\n--version\noutput version information and exit\nBy default, rm does not remove directories.  Use the --recursive (-r or -R) option to remove each listed directory, too, along with\nall of its contents.\nTo remove a file whose name starts with a '-', for example '-foo', use one of these commands:\nrm -- -foo\nrm ./-foo\nNote that if you use rm to remove a file, it might be possible to recover some of its contents, given sufficient  expertise  and/or\ntime.  For greater assurance that the contents are truly unrecoverable, consider using shred.\n");	}
	else
	{
		remove(argv[1]);	
	} 
return 0; 
}
