/*
 * Version of environ for no OS.
 */

char *__env[1] = { 0 }; 
char **environ = __env;
int __argc = 0;
char **__argv;
int __envc = 0;
