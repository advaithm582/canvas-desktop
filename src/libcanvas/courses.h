/**
 * Contains functions to deal with the Canvas Courses API.
 *
 * General principle for strings: if it is nullable, make it a pointer.
 * If it will <i>always</i> have a value, make it an array.
 *
 * @author Advaith Menon
 * @since 0.1.0
 */

#ifndef _LIBCANVAS_COURSES_H_
#define _LIBCANVAS_COURSES_H_
#include <stdint.h>
#include <time.h>
#include "error.h"

/* for struct docs, please refer to canvas lms docs */


/**
 * Represents a Term object.
 * 
 * For actual implementation, see course_methods.c
 */
typedef struct term_t term_t;


/**
 * Represents a Course Progress object.
 */
typedef struct course_progress_t course_progress_t;


/**
 * Represents a Course object.
 */
typedef struct course_t course_t;


/* functions for term */

/**
 * Initialize a new term.
 *
 * @return a term_t object with its default values
 */
term_t *canvas_term_initialize(void);

/**
 * Set the term's ID.
 *
 * @param term The term to set the ID of.
 * @param id The ID to set.
 */
CANVAS_ERROR canvas_term_set_id(term_t *term, int64_t id);

/**
 * Set the term's name.
 */
CANVAS_ERROR canvas_term_set_name(term_t *term, char *name);

/**
 * Set the term's start time.
 */
CANVAS_ERROR canvas_term_set_start_at(term_t *term, time_t start_at);

/**
 * Set the term's end time.
 *
 * @param term The term in question.
 * @param end_at the end time to set.
 */
CANVAS_ERROR canvas_term_set_end_at(term_t *term, time_t end_at);


/**
 * Get a term's ID.
 *
 * @param term The term whose ID to get.
 * @param id The ID to put into.
 */
CANVAS_ERROR canvas_term_get_id(term_t *term, int64_t *id);


/**
 * Get a term's name.
 *
 * @param term The term whose name to get.
 * @param name The name to put into.
 */
CANVAS_ERROR canvas_term_get_name(term_t *term, char **name);


/**
 * Get a term's start date.
 *
 * @param term The term whose start date to get.
 * @param start_at The start to put into.
 */
CANVAS_ERROR canvas_term_get_start_at(term_t *term, time_t *start_at);


/**
 * Get a term's end date.
 *
 * @param term The term whose end date to get.
 * @param end_at The end to put into.
 */
CANVAS_ERROR canvas_term_get_end_at(term_t *term, time_t *end_at);


/**
 * Destroy a term object.
 *
 * WARNING: NOT destroying a term object in this manner implies a memory leak!
 *
 * @param term The term object to destroy.
 */
CANVAS_ERROR canvas_term_terminate(term_t *term);

#endif
