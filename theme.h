#ifndef THEME_H
#define THEME_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "store.h"
#include "overall.h"


void start_prompt(general_t *info);
void prompt(general_t *info);
char *read_prompt();
void sigintHandler(int sig_num);


int _strlen(char *msg);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);


char *to_string(int number);
int is_numerical(unsigned int n);
int _atoi(char *s);
int contains_letter(char *s);


int _putchar_to_fd(char l, int fd);
int print_to_fd(char *msg, int fd);
int _putchar(char c);
int print(char *msg);

int print_err(char *msg);

char **split_words(char *line, const char *sep);
char *join_words(char *word1, char *word2, char *word3, const char *sep);
void analyze_patterns(general_t *info, char **arguments);
char *pattern_handler(general_t *info, char *string);
char *replace_value(general_t *info, int *index, char *string);
char *replacement(general_t *info, int *index, char *string);
char *replace_env(general_t *info, char *environment);
#endif

