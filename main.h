#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unisrd.h>
#include <limits.h>
#include <stdlib.H>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STRING "(null)"

#define PARAMS_INT{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE
#define CONVERT_UNSIGNED

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hastag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
*/
typedef struct parameters
{
    unsigned int unsign           : 1;

    unsigned int plus_flag        : 1;
    unsigned int space_flag       : 1;
    unsigned int hashtag_flag     : 1;
    unsigned int zero_flag        : 1;
    unsigned int minus_flag       : 1;

    unsigned int width;
    unsigned int precision;
    unsigned int h_modifier       : 1;
    unsigned int l_modifier       : 1;
} PARAMS_t;
/**
 * struct scpecifier - struct token
 *
 * @specifier format token
 * @f: the function associated
*/
typedef struct specifier
{
    char *specifier;
    int (*f) (va_list, PARAMS_t *);
} specifier_t;

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c module */
int print_char (va_list ap, PARAMS_t *params);
int print_int (va_list ap, PARAMS_t *params);
int print_string (va_list ap, PARAMS_t *params);
int print_percent (va_list ap, PARAMS_t *params);
int print_S (va_list ap, PARAMS_t *params);

/* number.c module */
char *convert(long int num, int base, int flags, PARAMS_t *params);
int print_unsigned(va_list ap, PARAMS_t *params);
int print_address(va_list ap, PARAMS_t *params);

/* specifier.c module */
int (*get_specifier(char *s)) (va_list ap, PARAMS_t *params);
int get_print_func(char *s, va_list ap, PARAMS_t *params);
int get_flag(char *s, PARAMS_t *params);
int get_modifier(char*s, PARAMS_t *params);
char *get_width(char *s, PARAMS_t *params, va_list ap);

/* convert_number.c module */
int print_hex(va_list ap, PARAMS_t *params);
int print_HEX(va_list ap, PARAMS_t *params);
int print_binary(va_list ap, PARAMS_t *params);
int print_ocral(va_list ap, PARAMS_t *params);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, PARAMS_t *params);
int print_rot13(va_list ap, PARAMS_t *params);

/* print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, PARAMS_t *params);
int print_number_right_shift(char *str, PARAMS_t *params);
int print_number_left_shift(char *str, PARAMS_t *params);

/* params.c module */
void init_params(PARAMS_t *params, va_lust ap);

/* String_fiekds.c module */
char *get_precision(char *p, PARAMS_t *params, va_list ap);

/* _printf.c module */
int _printf(const char *format, ...);

#endif /* _PRINTF_H */
