#ifndef OVERALL_H
#define OVERALL_H

#define _ENOENT          "No such file or directory"
#define _EACCES          "Permission denied"
#define _CMD_NOT_EXISTS  "not found"
#define _ILLEGAL_NUMBER  "Illegal number"
#define STDIN            0
#define STDOUT           1
#define STDERR           2
#define NON_INTERACTIVE  0
#define INTERACTIVE      1
#define _CODE_ENOENT           3
#define _CODE_EACCES           13
#define _CODE_CMD_NOT_EXISTS   132
#define _CODE_ILLEGAL_NUMBER   133
#define _TRUE            1
#define _FALSE           0
#define PERMISSIONS      1
#define NON_PERMISSIONS -1
#define _FILE            10
#define NON_FILE         -10

typedef struct __attribute__((__packed__))
{
	int argc;
	char **argv;
	int mode;
	int error_code;
	char *command;
	int n_commands;
	char *value_path;
	int is_current_path;
	int status_code;
	char *buffer;
	char **arguments;
	char *environment;
	int pid;
} general_t;

typedef struct __attribute__((__packed__))
{
	char *message;
	int code;
} error_t;

typedef struct __attribute__((__packed__))
{
	char *command;
	void (*func)(general_t *info, char **arguments);
} builtin_t;

#endif

