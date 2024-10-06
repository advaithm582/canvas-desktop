#include <string.h>
#include <stdlib.h>
#include "courses.h"
#include "error.h"
#include "util.h"

struct term_t {
    int64_t id;
    char *name;
    time_t start_at;
    time_t end_at;
};


struct course_progress_t {
    int requirement_count;
    int requirement_completed_count;
    char *next_requirement_url;
    time_t completed_at;
};


struct course_t {
    int64_t id;
    char* sis_course_id;
    /* TODO: check if uuid is actually a uuid */
    char uuid[16];
    char *integration_id;
    int64_t sis_import_id;
    char *name;
    char *course_code;
    char *original_name;
    int64_t account_id;
    int64_t root_account_id;
    int64_t enrollment_term_id;
    /* TODO grading periods have been omitted */
    int64_t grading_standard_id;
    time_t created_at;

    /**
     * The start date of the course. Consider it null if set to 0.
     */
    time_t start_at;

    /**
     * The end date of the course. Consider it null if set to 0.
     */
    time_t end_at;
    /* TODO enrollments omitted */
    /* int should be enough? */
    int total_students;
    /* TODO calendar omitted */
    char *default_view;
    /* Syllabus omitted here to save storage space */
    int needs_grading_count;
    term_t *term;
    course_progress_t *course_progress;

    /**
     * Below is a boolean value. int is used since ANSI C lacks bool support.
     */
    int apply_assignment_group_weights;

    /* TODO Permissions is not supported since there is no HashMap
     * implementation yet.
     */

    int is_public;
    int is_public_to_auth_users;
    int public_syllabus;
    int public_syllabus_to_auth;

    char *public_description;
    int storage_quota_mb;
    int storage_quota_used_mb;

    /**
     * Whether to hide final grades or not.
     */
    int hide_final_grades;
    char *license;
    int allow_student_assignment_edits;
    int allow_wiki_comments;
    int allow_student_forum_attachments;
    int open_enrollment;
    int self_enrollment;
    int restrict_enrollment_to_course_dates;
    char *course_format;
    char *time_zone;
    /* last 4 options skipped due to lack of Hashmap and student utility */
};

term_t *canvas_term_initialize(void) {
    /* set all fields to their defaults */
    term_t *new_term = malloc(sizeof(term_t));
    new_term->id = 0;
    new_term->name = NULL;
    new_term->start_at = 0;
    new_term->end_at = 0;
    return new_term;
}


CANVAS_ERROR canvas_term_set_id(term_t *term, int64_t id) {
    if (canvas_util_ptrnul(term))
        return CANVASE_GEN_NULL_PTR;
    if (id < 0)
        /* this might not have been what was intended */
        return CANVASE_GEN_INVALID_OBJECT;
    /* just set it, no questions asked */
    term->id = id;
    return CANVASE_OK;
}


CANVAS_ERROR canvas_term_set_name(term_t *term, char *name) {
    if (canvas_util_ptrnul(term))
        return CANVASE_GEN_NULL_PTR;
    /* check if there is already a buffer, then free() it */
    if (term->name != NULL)
        free(term->name);
    /* if it is NULL, just set the pointer to null */
    if (name == NULL) {
        term->name = NULL;
        return CANVASE_OK;
    }
    term->name = malloc(strlen(name) + 1);
    strcpy(term->name, name);
    return CANVASE_OK;
}


CANVAS_ERROR canvas_term_set_start_at(term_t *term, time_t start_at) {
    if (canvas_util_ptrnul(term))
        return CANVASE_GEN_NULL_PTR;
    term->start_at = start_at;
    return CANVASE_OK;
}


CANVAS_ERROR canvas_term_set_end_at(term_t *term, time_t end_at) {
    if (canvas_util_ptrnul(term))
        return CANVASE_GEN_NULL_PTR;
    if (end_at < term->start_at)
        return CANVASE_GEN_INVALID_OBJECT;
    term->end_at = end_at;
    return CANVASE_OK;
}


CANVAS_ERROR canvas_term_get_id(term_t *term, int64_t *id) {
    if (canvas_util_ptrnul(term))
        return CANVASE_GEN_NULL_PTR;
    *id = term->id;
    return CANVASE_OK;
}


CANVAS_ERROR canvas_term_get_name(term_t *term, char **name) {
    if (canvas_util_ptrnul(term))
        return CANVASE_GEN_NULL_PTR;
    *name = term->name;
    return CANVASE_OK;
}


CANVAS_ERROR canvas_term_get_start_at(term_t *term, time_t *start_at) {
    if (canvas_util_ptrnul(term))
        return CANVASE_GEN_NULL_PTR;
    *start_at = term->start_at;
    return CANVASE_OK;
}


CANVAS_ERROR canvas_term_get_end_at(term_t *term, time_t *end_at) {
    if (canvas_util_ptrnul(term))
        return CANVASE_GEN_NULL_PTR;
    *end_at = term->end_at;
    return CANVASE_OK;
}


CANVAS_ERROR canvas_term_terminate(term_t *term) {
    if (canvas_util_ptrnul(term))
        return CANVASE_GEN_NULL_PTR;
    /* ensure that we free name */
    if (term->name != NULL) {
        free(term->name);
    }
    /* free the whole thing */
    free(term);
    return CANVASE_OK;
}
