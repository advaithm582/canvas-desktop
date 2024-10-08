#include <time.h>
#include <unistd.h>
#include <glib.h>
#include <libcanvas/error.h>
#include <libcanvas/auth.h>
#include "tests.h"

/*
 * Test `canvas_init_token_bare`. In other words, mode must be `t` and
 * token must be whatever was provided (arbitary length).
 */
void test_canvas_init_token_bare() {
    AUTH *canvas_auth = canvas_init_token_bare("https://gatech.instructure.com",
            "qwerty1234ASDFzxcvbnm", 632);
    /* now check if mode and token equal what you want it to be. */
    /* important - the mode check */
    g_assert_cmpstr(canvas_auth->url, ==,
            "https://gatech.instructure.com");
    g_assert_true(canvas_auth->mode == 't');
    g_assert_cmpstr(canvas_auth->token, ==, "qwerty1234ASDFzxcvbnm");
    g_assert_true(canvas_auth->expires == 632UL);
}

/**
 * Test getting the access token with a bare token.
 */
void test_canvas_get_access_token_bareauth() {
    AUTH *auth = canvas_init_token_bare(
            "https://gatech.instructure.com",
            "demoTokenWillBeValidFor5Secs", 
            time(NULL) + 2);
    /* hopefully, this is not running on UNIVAC... */
    char *token = NULL;
    g_assert_cmphex(canvas_get_access_token(auth, &token), ==, CANVASE_OK);
    g_assert_cmpstr(token, ==, "demoTokenWillBeValidFor5Secs");
    g_assert_true(sleep(2) == 0UL);
    g_assert_cmphex(canvas_get_access_token(auth, &token),
                ==, CANVASE_AUTH_BARE_EXPIRED_TOKEN);
}

/**
 * Test getting access token with null input.
 */
void test_canvas_get_access_token_null() {
    AUTH *auth = canvas_init_token_bare(
            "https://gatech.instructure.com",
            "demoTokenWillBeValidFor5Secs", 
            293UL);
    char *token = NULL;
    g_assert_cmphex(canvas_get_access_token(NULL, NULL), ==,
           CANVASE_GEN_NULL_PTR);
    g_assert_cmphex(canvas_get_access_token(NULL, &token), ==,
           CANVASE_GEN_NULL_PTR);
    g_assert_cmphex(canvas_get_access_token(auth, NULL), ==,
           CANVASE_GEN_NULL_PTR);
}
