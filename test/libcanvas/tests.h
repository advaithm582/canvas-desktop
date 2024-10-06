/**
 * Tests LibCanvas functions.
 *
 * @since 0.1.0
 * @author Advaith Menon
 */

#ifndef _LIBCANVASTEST_TESTS_H_
#define _LIBCANVASTEST_TESTS_H_

void test_canvas_init_token_bare();
void test_canvas_get_access_token_bareauth();
void test_canvas_get_access_token_null();

void test_canvas_error_is_category_primary();

void test_canvas_course_term_methods_normal(void);
void test_canvas_course_term_methods_error(void);

#endif /* _LIBCANVAS_TESTS_H_ */
