/*
 * native_funcs.c
 *
 * Code file for the functions wrapping c library
 * functions in order to make them available
 * as native functions to the XPVM.
 *
 * Author: Jeffrey Picard.
 */

#include <stdio.h>
#include <stdarg.h>

#include "xpvm.h"

int print_int( uint64_t x )
{
  printf("%" PRId64 "\n", x );
  return 1;
}

int print_string( char *s )
{
  printf("%s\n", s );
  return 1;
}

int xpvm_printf( const char *format, ... )
{
  uint8_t *ptr = blk_2_ptr( (uint8_t *) format, 0, CHECK_WRITE | CHECK_READ );
  printf("%c\n", *ptr );
  va_list ap;
  int i;
  va_start( ap, format );
  i = vprintf( format, ap );
  return i;
}