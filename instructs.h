#ifndef INSTRUCTS_H
#define INSTRUCTS_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

#include "store.h"
#include "parts.h"
#include "oversight.h"
#include "theme.h"
#include "overall.h"

extern char **environ;



void execute(char *commands, char **arguments, general_t *info, char *buff);
int current_directory(char *cmd, char **arguments, char *buff,
		general_t *info);

void analyze(char **arguments, general_t *info, char *buff);

int is_executable(char *filename);
int is_file(char *command);

void is_current_path(char *path, general_t *info);
void get_full_env(void);
char *_getenv(const char *name);
char *which(char *filename, general_t *info);
#endif
