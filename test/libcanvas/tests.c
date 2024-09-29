#include <glib.h>
#include "tests.h"


int main(int argc, char** argv) {
    g_test_init(&argc, &argv, NULL);
    g_test_add_func("/test_canvas_init_token_bare",
            test_canvas_init_token_bare);
    return g_test_run();
}
