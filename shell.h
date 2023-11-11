#ifndef MAIN_H
#define MAIN_H

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <sys/types.h>

/*array of pointers to environment variables*/
extern char **environ;
int _putchar(char c);
void _putchars(const char *str);
void exefork(const char *cmd, char *const args[]);
char **spliter(const char *input);
void exepath(const char *cmd, char *const args[]);
void print_env(void);
void exefin(char **av, char **envp);
void set_p(char **envp);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
char *_strdup(char *str);
char *_strstr(char *hystack, char *needle);
char *_getenv(char *var_name);
char *getcmd(char *cmd);
char** allpaths();

#endif
