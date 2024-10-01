#include <glib.h>
#include "tests.h"


int main(int argc, char** argv) {
    g_test_init(&argc, &argv, NULL);
    g_test_add_func("/Auth/InitTokenBare", test_canvas_init_token_bare);
    g_test_add_func("/Auth/GetAccessTokenBareauth",
            test_canvas_get_access_token_bareauth);
    g_test_add_func("/Auth/GetAccessTokenNull",
            test_canvas_get_access_token_null);

    g_test_add_func("/Error/IsCategoryPrimary",
            test_canvas_error_is_category_primary);
    return g_test_run();
}
