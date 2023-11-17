#ifndef OVERSIGHT_H
#define OVERSIGHT_H

#include "theme.h"
#include "overall.h"

void error(general_t *info);
void error_extra(general_t *info, char *extra);
char *message_selector(general_t info);

#endif

