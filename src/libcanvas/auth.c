#include <time.h>
#include "auth.h"
#include "error.h"


CANVAS_ERROR canvas_get_access_token(struct auth_token *auth, char **token) {
    if (auth == NULL || token == NULL) {
        return CANVASE_GEN_NULL_PTR;
    }

    if (auth->mode == 't') {
        /* if the time has not passed */
        if (auth->expires <= (unsigned long) time(NULL)) {
            /* time has expired */
            return CANVASE_AUTH_BARE_EXPIRED_TOKEN;
        }
        /* otherwise, just return the token */
        *token = auth->token;
        return CANVASE_OK;
    } else {
        /* TODO: OAuth support before this */
        /* also, this should be an invalid object error than not implemented */
        return CANVASE_GEN_NOT_IMPLEMENTED;
    }
}
