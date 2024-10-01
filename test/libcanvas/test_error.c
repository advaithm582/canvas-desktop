#include <glib.h>
#include <libcanvas/error.h>
#include "tests.h"

void test_canvas_error_is_category_primary() {
    g_assert_true(canvas_error_is_category_primary(0x00000000UL, 0x00UL));
    g_assert_true(canvas_error_is_category_primary(0x012345FFUL, 0x01UL));
    g_assert_false(canvas_error_is_category_primary(0x00F2F3F4UL, 0x01UL));
}
