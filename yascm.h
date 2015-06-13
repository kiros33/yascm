#ifndef _YASCM_H
#define _YASCM_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
	FIXNUM,
	FLOATNUM,
	BOOL,
	CHAR,
	STRING,
	PAIR,
	SYMBOL,
	ENV,
} object_type;

typedef struct object_s object;
struct object_s {
	object_type type;
	union {
		int64_t int_val; /* FIXNUM */
		long double float_val; /* FLOATNUM */
		bool bool_val; /* BOOL */
		char char_val; /* CHAR */
		char *string_val; /* STRING */
		struct { /* PAIR */
			object *car;
			object *cdr;
		};
	} data;
};

typedef object *Primitive(object *env, object *args);

object *make_fixnum(int64_t val);
void object_print(const object *obj);

#endif