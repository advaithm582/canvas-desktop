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


void test_canvas_course_term_constructor(void) {
    int64_t id;
    char *name = "HELL";
    time_t start, end;
    term_t *nu = canvas_term_initialize();
    g_assert_cmphex(canvas_term_get_id(nu, &id), ==, 0);
    g_assert_cmpint(id, ==, 0);
    g_assert_cmphex(canvas_term_get_name(nu, &name), ==, 0);
    g_assert_null(name);
    g_assert_cmphex(canvas_term_get_start_at(nu, &start), ==, 0);
    g_assert_cmpint(start, ==, (time_t) 0);
    g_assert_cmphex(canvas_term_get_end_at(nu, &end), ==, 0);
    g_assert_cmpint(end, ==, (time_t) 0);
}

void test_canvas_course_term_methods_error(void) {
    /* first test null input argument */
    g_assert_cmphex(canvas_term_set_id(NULL, 121), ==, CANVASE_GEN_NULL_PTR);
    g_assert_cmphex(canvas_term_set_name(NULL, "demo"), ==,
            CANVASE_GEN_NULL_PTR);
    g_assert_cmphex(canvas_term_set_start_at(NULL, (time_t) 12), ==,
            CANVASE_GEN_NULL_PTR);
    g_assert_cmphex(canvas_term_set_end_at(NULL, (time_t) 12), ==,
            CANVASE_GEN_NULL_PTR);
    g_assert_cmphex(canvas_term_set_end_at(NULL, (time_t) 10), ==,
            CANVASE_GEN_NULL_PTR);

    int64_t id;
    char *name;
    time_t start, end;
    g_assert_cmphex(canvas_term_get_id(NULL, &id), ==, CANVASE_GEN_NULL_PTR);
    g_assert_cmphex(canvas_term_get_name(NULL, &name), ==,
            CANVASE_GEN_NULL_PTR);
    g_assert_cmphex(canvas_term_get_start_at(NULL, &start), ==,
            CANVASE_GEN_NULL_PTR);
    g_assert_cmphex(canvas_term_get_end_at(NULL, &end), ==,
            CANVASE_GEN_NULL_PTR);
    g_assert_cmphex(canvas_term_terminate(NULL), ==, CANVASE_GEN_NULL_PTR);

    term_t *nu = canvas_term_initialize();

    /* now test with invalid args */
    g_assert_cmphex(canvas_term_set_id(nu, -666), ==,
            CANVASE_GEN_INVALID_OBJECT);
    g_assert_cmphex(canvas_term_get_id(nu, &id), ==, 0);
    g_assert_cmpint(id, ==, 0);
    canvas_term_set_start_at(nu, 12);
    g_assert_cmphex(canvas_term_set_end_at(nu, 5), ==,
            CANVASE_GEN_INVALID_OBJECT);
    g_assert_cmphex(canvas_term_get_end_at(nu, &end), ==, 0);
    g_assert_cmpint(end, ==, (time_t) 0);
}
