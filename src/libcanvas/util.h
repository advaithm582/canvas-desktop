/**
 * Utility functions for LibCanvas. These include data structures and other
 * repetitive stuff.
 */

#ifndef _LIBCANVAS_UTIL_H_
#define _LIBCANVAS_UTIL_H_


/**
 * Deep-copy a string. Equivalent to strdup().
 *
 * @param string The string to copy.
 * @return A duplicated string allocated from the heap.
 */
char *canvas_util_strdc(char *string);


/**
 * Check if a given pointer is null.
 *
 * @param ptr Pointer to check if it is null.
 * @return True if the ptr was null.
 */
int canvas_util_ptrnul(void *ptr);

#endif
