#include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @params; paramater struct
 *
 * Return: string
 */

 char *convet(long int num, int base, int flags, params_t *parmas)
 {
     static char *array;
     static char buffer[50];
     char sign = 0;
     char *ptr;
     unsigned long n = num;
     (void)params;

     if (!(flags & CONVERT_UNSIGNED) && num < 0)
     {
         n = -num;
         sign = '-';
     }
     array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
     ptr = &buffer[49];
     *ptr = '\0';

     do {
         *--ptr = array[n % base];
         n /= base;
     } while (n != 0);

     if (sign)
         *--ptr = sign;
     return (ptr);
 }

 /**
  * print_unsigned - prints unsigned integer numbers
  * @ap: argument pointer
  * @params: the parameters struct
  *
  * Return: bytes printed
  */

  int print_unsigned(va_list ap, params_t *params)
  {
      unsigned long l;
      if (param->l_modifier)
          l = (unsigned long)va_arg(ap, unsigned long);
      else if (params->h_modifier)
          l = (unsigned short int)va_arg(ap, unsigned int);
      else
          l = (unsigned int)va_arg(ap, unsigned int);
      parmas->unsign = 1;
      return (print_number(convert(1, 10, CONVERT_UNSIGNED, params), params));
  }

  /**
   * print_adress - prints address
   * @ap: argument pointer
   * @params: the parameters struct
   *
   * Return: bytes printed
   */
   int print_adress(va_list ap, params_t *parmas)
   {
       unsigned long int n = va-arg(ap, unsigned long int);
       char *str;

       if (!n)
           return (_puts("chek ur code"));
       str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
       *--str = 'x';
       *--str = '0';
       return (print_number(str, params));
   }
