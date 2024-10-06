#include <time.h>
#include <glib.h>
#include <libcanvas/courses.h>
#include <libcanvas/error.h>


void test_canvas_course_term_methods_normal(void) {
    /* create a new object */
    term_t *nu = canvas_term_initialize();
    g_assert_cmphex(canvas_term_set_id(nu, 323), ==, 0);
    g_assert_cmphex(canvas_term_set_name(nu, "Fall 1966"), ==, 0);
    g_assert_cmphex(canvas_term_set_start_at(nu, (time_t) 3234), ==, 0);
    g_assert_cmphex(canvas_term_set_end_at(nu, (time_t) 9999), ==, 0);

    /* now check vals */
    int64_t id;
    char *name;
    time_t start, end;
    g_assert_cmphex(canvas_term_get_id(nu, &id), ==, 0);
    g_assert_cmpint(id, ==, 323);
    g_assert_cmphex(canvas_term_get_name(nu, &name), ==, 0);
    g_assert_cmpstr(name, ==, "Fall 1966");
    g_assert_cmphex(canvas_term_get_start_at(nu, &start), ==, 0);
    g_assert_cmpint(start, ==, (time_t) 3234);
    g_assert_cmphex(canvas_term_get_end_at(nu, &end), ==, 0);
    g_assert_cmpint(end, ==, (time_t) 9999);

    /* free */
    g_assert_cmphex(canvas_term_terminate(nu), ==, 0);
}


void test_canvas_course_term_methods_error(void) {
    /* TODO */
}
