/* date = 29 Apr 2023 17:33 */

#ifndef BASE_STRING_H_
#define BASE_STRING_H_

#include "../base_types.h"

// String Types

typedef struct String8 {
    U8 *str;
    U64 size;
} String8;

typedef struct String8Node {
    int *next; // CAST TO String8Node before use!!!
    String8 string;
} String8Node;

typedef struct String8List {
    String8Node *first;
    String8Node *last;
    U64 node_count;
    U64 total_size;
} String8List;

// String Functions
String8 str8(U8 *str, U64 size);
String8 str8_range(U8 *first, U8 *opl);
String8 str8_cstring(U8 *cstr);

#define str8_lit(s) str8((U8*)(s), sizeof(s) - 1)

String8 str8_prefix(String8 str, U64 size);
String8 str8_chop(String8 str, U64 amount);
String8 str8_postfix(String8 str, U64 size);
String8 str8_skip(String8 str, U64 amount);
String8 str8_substr(String8 str, U64 first, U64 opl);

#define str8_expand(s) (int)((s).size), ((s).str)

#endif //BASE_STRING_H