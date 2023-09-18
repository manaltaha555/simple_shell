#include"shell.h"
int main(int argc, char **argv)
{
	char *cmd = NULL, char *token = NULL, char *arg;
	size_t n = 0;
	char *delim = " \n";

	while (true){
		cmd = _getline(); /*reading the input */
		token = _strtok(cmd); // split the command line
		arg = _strtok_cp(cmd, argc); /*copy to the arg array*/
		if (_check_for_cmd(token[0]) == NULL)
			perror("%s: No such file or directory", argv[0]);
        else
		/* execute the program with fork and excev and write the function codes */
		printf("executed");
                
	}
	return (0);

}
