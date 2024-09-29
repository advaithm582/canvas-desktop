#include <stdlib.h>
#include <string.h>
#include "auth.h"


struct auth_token *canvas_init_token_bare(char* token, unsigned long expiry) {
    struct auth_token *new_auth;
    new_auth->token = malloc(strlen(token) + 1);
    strcpy(new_auth->token, token);
    new_auth->expiry = expiry;
    return new_auth;
}
