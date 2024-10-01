/**
 * Error management in LibCanvas
 *
 * Whenever a function can fail, it returns an error code in an integer
 * variable. If this variable is 0, it means the function succeded, else, it
 * means one of the below errors occured. This header defines macros to describe
 * error codes.
 *
 * NEVER rely on numeric auth codes - they can, and will change anytime!
 */

#ifndef _LIBCANVAS_ERROR_H_
#define _LIBCANVAS_ERROR_H_

#define CANVAS_ERROR unsigned int

#define CANVASE_OK 0 /* all good */

/* Error primary categories (first byte) */
/*
 * Generic errors (null pointer, invalid argument etc.
 * EPCAT = error primary category
 */
#define CANVASEPCAT_GENERIC                                 0x00U
#define CANVASEPCAT_AUTH                                    0x01U

/* Category 0: Generic Errors */
#define CANVASE_GEN_NULL_PTR                                0x00000001U
#define CANVASE_GEN_INVALID_OBJECT                          0x00000002U
#define CANVASE_GEN_INVALID_STATE                           0x00000003U
#define CANVASE_GEN_NOT_IMPLEMENTED                         0x00000004U

/* Category 1: Auth Errors */
/* define category first */
#define CANVASECAT_AUTH_GENERIC                             0x0100U
#define CANVASECAT_AUTH_OAUTH                               0x0101U
#define CANVASECAT_AUTH_BARE                                0x0102U

/* Generic errors have the same error codes across all secondary categories.
 * This means if their first, and third bytes are equal, they are the
 * same error.
 * Values 0-31 (ie 50 codes) are reserved for this purpose. All other generic
 * codes may either not have a specific error code equivalent or may not be
 * numbers immediately after 31.
 */
#define CANVASE_AUTH_GEN_INVALID_TOKEN                      0x01000000U

/* Category 1.1: OAuth Errors */
/* TODO: Since this is not implemented, these are only for representative
 * purposes and will be subject to change. */
/* server declined the token - least specific error code */
#define CANVASE_AUTH_OAUTH_INVALID_TOKEN                    0x01010000U
/* Categroy 1.2: Bare Auth Errors */
#define CANVASE_AUTH_BARE_INVALID_TOKEN                     0x01020000U
#define CANVASE_AUTH_BARE_EXPIRED_TOKEN                     0x01020100U


/**
 * Check an error's primary category. This is useful for generic error handling.
 *
 * @param code The error code of the failed object
 * @param category Check if the function is in this category
 * @return a boolean result if it is the case or not
 */
int canvas_error_is_category_primary(CANVAS_ERROR code, CANVAS_ERROR category);

#endif
