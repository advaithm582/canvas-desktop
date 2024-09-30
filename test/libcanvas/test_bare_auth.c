#include <glib.h>
#include <libcanvas/auth.h>

/*
 * Test `canvas_init_token_bare`. In other words, mode must be `t` and
 * token must be whatever was provided (arbitary length).
 */
void test_canvas_init_token_bare() {
    AUTH *canvas_auth = canvas_init_token_bare("qwerty1234ASDFzxcvbnm", 632);
    /* now check if mode and token equal what you want it to be. */
    g_assert_cmpstr(canvas_auth->token, ==, "qwerty1234ASDFzxcvbnm");
    g_assert(canvas_auth->expires == 632UL);
}

