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
struct auth_token {
    /**
     * The authentication mode to use. Current modes are:
     * t (116) - use bare token, no refresh, after expiry its useless
     * o (111) - use OAuth, after 1 hour from issue, auto renew
     */
    char mode;

    /**
     * The authentication token itself, as a pointer to a string.
     */
    char *token;

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
struct auth_token *canvas_init_token_bare(char* token, unsigned long expiry);

#endif /* _LIBCANVAS_AUTH_H */
