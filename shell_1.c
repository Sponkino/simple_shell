#include "main.h"


int main(void)
{
    int i = 0;
    char *getl_buf;
    size_t bufsize = 32;
    int res;
    char *token;
    char *str[50];
    char *delim = " \n\t\r\a";
    pid_t child;

    getl_buf = malloc(sizeof(char) * bufsize);

    if (getl_buf == NULL)
    {
        dprintf(STDERR_FILENO, "Error");
        exit(EXIT_FAILURE);
    }

    while (res != EOF)
    {
        printf("#cisfun$ ");

        res = getline(&getl_buf, &bufsize, stdin);
        token = strtok(getl_buf, delim);
    
        while (token != NULL)
        {
            str[i] = token;
            printf("%s\n", str[i]);
            token = strtok(NULL, delim);
            i++;
        }
        
        child = fork();
        if(child == 0)
        {
          execve(str[0], str, NULL);
        }
        else
        {
            wait(&i);
        }
    
    }
    return (0);
}
