#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "auth.h"


struct auth_token *canvas_init_token_bare(char *url, char* token, time_t expiry)
{
    struct auth_token *new_auth = malloc(sizeof(struct auth_token));
    new_auth->url = malloc(strlen(url) + 1);
    strcpy(new_auth->url, url);
    new_auth->mode = 't';
    new_auth->token = malloc(strlen(token) + 1);
    strcpy(new_auth->token, token);
    new_auth->expires = expiry;
    new_auth->refresh = NULL;
    return new_auth;
}
