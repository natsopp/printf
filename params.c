#include "main.h"

/**
 * init_params - clears struct fields and reser buf
 * @params: the parameters struct
 *
 * Retturn: void
 */
 void init_parmas(PARAMS_t, va_list ap)
 {
     params->unsign = 0;

     params->plud_flag = 0;
     params->space_flag = 0;
     params->hashtag_flag = 0;
     params->zero_flag = 0;
     params->minus_flag = 0;

     params->width = 0;
     params->precision = UNIT_MAX;

     params->h_modifier = 0;
     params->l_modifier = 0;
     (void) sp;
 }
