#include <string.h>
#include <stdlib.h>
#include "util.h"


char *canvas_util_strdc(char *string) {
    char *nu = malloc(strlen(string) + 1);
    strcpy(nu, string);
    return nu;
}


int canvas_util_ptrnul(void *ptr) {
    return ptr == NULL;
}
