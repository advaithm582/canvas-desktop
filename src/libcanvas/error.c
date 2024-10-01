#include "error.h"


int canvas_error_is_category_primary(CANVAS_ERROR code, CANVAS_ERROR category) {
    return (code >> 24 == category);
}
