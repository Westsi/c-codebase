/* date = 29 Apr 2023 17:33 */

#include "base_string.h"
#include "../base_macros.h"
#include "../base_types.h"

String8 str8(U8 *str, U64 size) {
    String8 result = {str, size};
    return result;
}

String8 str8_range(U8 *first, U8 *opl) {
    // Implement
}

String8 str8_cstring(U8 *cstr) {
    // Implement
}


String8 str8_prefix(String8 str, U64 size) {
    U64 size_clamped = ClampTop(size, str.size);
    String8 result = {str.str, size_clamped};
    return result;
}

String8 str8_chop(String8 str, U64 amount) {
    U64 amount_clamped = ClampTop(amount, str.size);
    U64 remaining_size = str.size - amount_clamped;
    String8 result = {str.str, remaining_size};
    return result;
}

String8 str8_postfix(String8 str, U64 size) {
    U64 size_clamped = ClampTop(size, str.size);
    U64 skip_to = str.size - size_clamped;
    String8 result = {str.str + skip_to, size_clamped};
    return result;
}

String8 str8_skip(String8 str, U64 amount) {
    U64 amount_clamped = ClampTop(amount, str.size);
    U64 remaining_size = str.size - amount_clamped;
    String8 result = {str.str + amount_clamped, remaining_size};
    return result;
}

String8 str8_substr(String8 str, U64 first, U64 opl) {
    // Implement
}
