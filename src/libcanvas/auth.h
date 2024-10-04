/**
 * Authentication manager for Canvas.
 *
 * These functions allow to get access tokens irrespective of whether
 * OAuth is used or whether the token was just given directly.
 * @since 0.1.0
 * @author Advaith Menon
 */

#ifndef _LIBCANVAS_AUTH_H_
#define _LIBCANVAS_AUTH_H_

#include <time.h>

#include "error.h"


struct auth_token {
    /**
     * The URL of this Canvas Instance. Includes everything but a trailing
     * slash.
     */
    char* url;

    /**
     * The authentication mode to use. Current modes are:
     * t (116) - use bare token, no refresh, after expiry its useless
     * o (111) - use OAuth, after 1 hour from issue, auto renew
     */
    char mode;

    /**
     * The authentication token itself, as a pointer to a string.
     * This, in particular, will always be the access token.
     */
    char *token;

    /**
     * The refresh token. Use only when there is OAuth.
     */
    char *refresh;

    /**
     * The expiry time, as epoch seconds. 0 indicates no expiry.
     */
    unsigned long expires;
};

#define AUTH struct auth_token

/**
 * Create an auth_token with the given token (t mode)
 *
 * @param token The 'bare' authentication token to use directly.
 * @param expiry The expiry of this token w.r.t epoch time.
 * @return a pointer to an auth structure.
 */
struct auth_token *canvas_init_token_bare(char* url, char* token, 
        time_t expiry);


/**
 * Get the authentication token to use with any API request. Normally, this call
 * will be done internally, since we will pass the AUTH object around.
 *
 * <b>WARNING!</b> Don't modify or free() the token returned by this object,
 * since it points to the internal token (it is not a copy!)
 *
 * @param auth The authentication object
 * @param token A pointer to the token string.
 * @return An error code as defined in error.h.
 */
CANVAS_ERROR canvas_get_access_token(struct auth_token *auth, char **token);

#endif /* _LIBCANVAS_AUTH_H */
