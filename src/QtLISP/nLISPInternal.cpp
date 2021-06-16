#include "nLISPInternal.h"
#undef  slots
#define slots slotz
// #define SLOTS SLOTX
// #define SLOT  SLOTZ
#include <ecl/ecl.h>

#define CLO ((cl_object)clo)

namespace LISP
{

int boot(int argc,char ** argv)
{
  return cl_boot ( argc , argv ) ;
}

void shutdown(void)
{
  cl_shutdown ( ) ;
}

void defun(const char * name,LispFunc func,int args)
{
  cl_def_c_function ( c_string_to_object(name) ,
                      (cl_objectfn_fixed) func ,
                      args                   ) ;
}

void defvar(void * s,void * v)
{
  ecl_defvar ( (cl_object) s , (cl_object) v ) ;
}

void defparameter(void * s,void * v)
{
  ecl_defparameter ( (cl_object) s , (cl_object) v ) ;
}

void * eval(const char * call)
{
  return (void *) cl_safe_eval ( c_string_to_object(call),Cnil,Cnil) ;
}

void * toObject(char value)
{
  return (void *) ecl_make_int8_t ( value ) ;
}

void * toObject(unsigned char value)
{
  return (void *) ecl_make_uint8_t ( value ) ;
}

void * toObject(short value)
{
  return (void *) ecl_make_int16_t ( value ) ;
}

void * toObject(unsigned short value)
{
  return (void *) ecl_make_uint16_t ( value ) ;
}

void * toObject(int value)
{
  return (void *) ecl_make_int32_t ( value ) ;
}

void * toObject(unsigned int value)
{
  return (void *) ecl_make_uint32_t ( value ) ;
}

void * toObject(long long value)
{
  return (void *) ecl_make_long_long ( value ) ;
}

void * toObject(unsigned long long value)
{
  return (void *) ecl_make_ulong_long ( value ) ;
}

void * toObject(float value)
{
  return (void *) ecl_make_single_float ( value ) ;
}

void * toObject(double value)
{
  return (void *) ecl_make_double_float ( value ) ;
}

void * toObject(long double value )
{
  #ifdef ECL_LONG_FLOAT
  return (void *) ecl_to_long_double ( value ) ;
  #else
  return (void *) ecl_make_double_float ( value ) ;
  #endif
}

void * toObject(const char * s)
{
  return (void *) c_string_to_object ( s ) ;
}

int toType(void * clo)
{
  int ei = ECL_IMMEDIATE ( CLO )     ;
  if ( 0 == ei ) return CLO -> d . t ;
  return ei                          ;
}

char toChar(void * clo)
{
  return (char) ecl_to_int8_t ( CLO ) ;
//  char ch = 0                                  ;
//  if ( CHARACTERP ( CLO ) )                    {
//    ch = (char) toInt ( cl_char_code ( CLO ) ) ;
//  }                                            ;
//  return ch                                    ;
}

unsigned char toUChar(void * clo)
{
  return (unsigned char) ecl_to_uint8_t ( CLO ) ;
//  unsigned char ch = 0                                  ;
//  if ( CHARACTERP ( CLO ) )                             {
//    ch = (unsigned char) toInt ( cl_char_code ( CLO ) ) ;
//  }                                                     ;
//  return ch                                             ;
}

short toShort(void * clo)
{
  return (short) ecl_to_int16_t ( CLO ) ;
}

unsigned short toUShort(void * clo)
{
  return (unsigned short) ecl_to_uint16_t ( CLO ) ;
}

int toInt(void * clo)
{
  return (int) ecl_to_int32_t ( CLO ) ;
//  int i = 0                       ;
//  if ( cl_integerp ( CLO ) == Ct) {
//    i = fixint     ( CLO )        ;
//  }                               ;
//  return i                        ;
}

unsigned int toUInt(void * clo)
{
  return (unsigned int) ecl_to_uint32_t ( CLO ) ;
//  unsigned int i = 0              ;
//  if ( cl_integerp ( CLO ) == Ct) {
//    i = fixnnint   ( CLO )        ;
//  }                               ;
//  return i                        ;
}

long long toLongLong(void * clo)
{
  return (long long) ecl_to_long_long ( CLO ) ;
//  int i = 0                       ;
//  if ( cl_integerp ( CLO ) == Ct) {
//    i = fixint     ( CLO )        ;
//  }                               ;
//  return i                        ;
}

unsigned long long toULongLong(void * clo)
{
  return (unsigned long long) ecl_to_ulong_long ( CLO ) ;
//  unsigned int i = 0              ;
//  if ( cl_integerp ( CLO ) == Ct) {
//    i = fixnnint   ( CLO )        ;
//  }                               ;
//  return i                        ;
}

float toFloat(void * clo)
{
  return (float) ecl_to_float ( CLO ) ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
  float f = 0                         ;
  if ( ECL_SINGLE_FLOAT_P ( CLO ) )   {
    f = sf ( CLO ) ;
  } else
  if ( ECL_DOUBLE_FLOAT_P ( CLO ) )   {
    f = df( CLO );
  }
  #ifdef ECL_LONG_FLOAT
  else
  if ( ECL_LONG_FLOAT_P   ( CLO ) )   {
    f = ecl_long_float    ( CLO )     ;
  }
  #endif
  else
  if ( cl_integerp ( CLO ) == Ct  )   {
    f = fixint     ( CLO )            ;
  } else                              {
    cl_object l_f                     ;
    l_f = cl_float ( 1 , CLO )        ;
    if ( ECL_DOUBLE_FLOAT_P ( l_f ) ) {
      f = df ( l_f )                  ;
    } else
    if ( ECL_SINGLE_FLOAT_P ( l_f ) ) {
      f = sf ( l_f )                  ;
    }
#ifdef ECL_LONG_FLOAT
    else
    if ( ECL_LONG_FLOAT_P   ( l_f ) ) {
      f = ecl_long_float    ( l_f )   ;
    }                                 ;
#endif
  }                                   ;
  return f                            ;
#endif
}

double toDouble(void * clo)
{
  return (double) ecl_to_double ( CLO ) ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
  double f = 0                        ;
  if ( ECL_SINGLE_FLOAT_P ( CLO ) )   {
    f = sf( CLO );
  } else
  if ( ECL_DOUBLE_FLOAT_P ( CLO ) )   {
    f = df( CLO );
  }
  #ifdef ECL_LONG_FLOAT
  else
  if ( ECL_LONG_FLOAT_P   ( CLO ) )   {
    f = ecl_long_float    ( CLO )     ;
  }
  #endif
  else
  if ( cl_integerp ( CLO ) == Ct  )   {
    f = fixint     ( CLO )            ;
  } else                              {
    cl_object l_f                     ;
    l_f = cl_float ( 1 , CLO )        ;
    if ( ECL_DOUBLE_FLOAT_P ( l_f ) ) {
      f = df ( l_f )                  ;
    } else
    if ( ECL_SINGLE_FLOAT_P ( l_f ) ) {
      f = sf ( l_f )                  ;
    }
#ifdef ECL_LONG_FLOAT
    else
    if ( ECL_LONG_FLOAT_P   ( l_f ) ) {
      f = ecl_long_float    ( l_f )   ;
    }                                 ;
#endif
  }                                   ;
  return f                            ;
#endif
}

long double toLongDouble(void * clo)
{
  long double f = 0                   ;
  if ( ECL_SINGLE_FLOAT_P ( CLO ) )   {
    f = sf( CLO );
  } else
  if ( ECL_DOUBLE_FLOAT_P ( CLO ) )   {
    f = df( CLO );
  }
  #ifdef ECL_LONG_FLOAT
  else
  if ( ECL_LONG_FLOAT_P   ( CLO ) )   {
    f = ecl_long_float    ( CLO )     ;
  }
  #endif
  else
  if ( cl_integerp ( CLO ) == Ct  )   {
    f = fixint     ( CLO )            ;
  } else                              {
    cl_object l_f                     ;
    l_f = cl_float ( 1 , CLO )        ;
    if ( ECL_DOUBLE_FLOAT_P ( l_f ) ) {
      f = df ( l_f )                  ;
    } else
    if ( ECL_SINGLE_FLOAT_P ( l_f ) ) {
      f = sf ( l_f )                  ;
    }
#ifdef ECL_LONG_FLOAT
    else
    if ( ECL_LONG_FLOAT_P   ( l_f ) ) {
      f = ecl_long_float    ( l_f )   ;
    }                                 ;
#endif
  }                                   ;
  return f                            ;
}

int * toString (void * clo)
{
  cl_object       cls = (cl_object) clo       ;
  int           * str = NULL                  ;
  int             len = 0                     ;
  ecl_base_char * lsc                         ;
  if ( ECL_STRINGP ( cls ) )                  {
    len = cls -> base_string . fillp          ;
    if ( len > 0 )                            {
      lsc = cls -> base_string . self         ;
      str = new int [ len + 1  ]              ;
      str [ len ] = 0                         ;
      for (int i = 0 ; i < len ; ++i )        {
        str [ i ] = ( (int *) lsc ) [ i ]     ;
      }                                       ;
    }                                         ;
  }                                           ;
  return str                                  ;
}

void SelectPackage(void * clo)
{
  if ( Cnil == cl_find_package ( CLO ) ) {
    cl_make_package ( 1 , CLO )          ;
  }                                      ;
  si_select_package (     CLO )          ;
}

void * Allocate(int type)
{
  return (void *) ecl_alloc_object ( (cl_type) type ) ;
}

void * FindSymbol(char * symbol)
{
  return (void *) cl_intern                                         (
                    1                                               ,
                    make_constant_base_string ( (char *) symbol ) ) ;
}

int SymbolType(void * clo)
{
  return ecl_symbol_type ( CLO ) ;
}

void setSymbolType (void * clo,int type)
{
  ecl_symbol_type_set ( CLO , type ) ;
}

void * SymbolValue(void * clo)
{
  return (void *) ecl_symbol_value ( CLO ) ;
}

void * SymbolName(void * clo)
{
  return (void *) ecl_symbol_name ( CLO ) ;
}

void * SymbolPackage(void * clo)
{
  return (void *) ecl_symbol_package ( CLO ) ;
}

void * Call(void * func)
{
  return (void *) cl_funcall ( 1 , (cl_object) func ) ;
}

void * Call(void * func,void * arg)
{
  return (void *) cl_funcall ( 2 , (cl_object) func , (cl_object) arg ) ;
}

void * Call(void * func ,
            void * arg0 ,
            void * arg1 )
{
  return (void *) cl_funcall ( 3                  ,
                               (cl_object) func   ,
                               (cl_object) arg0   ,
                               (cl_object) arg1 ) ;
}

void * Call(void * func ,
            void * arg0 ,
            void * arg1 ,
            void * arg2 )
{
  return (void *) cl_funcall ( 4                  ,
                               (cl_object) func   ,
                               (cl_object) arg0   ,
                               (cl_object) arg1   ,
                               (cl_object) arg2 ) ;
}

void * Call(void * func ,
            void * arg0 ,
            void * arg1 ,
            void * arg2 ,
            void * arg3 )
{
  return (void *) cl_funcall ( 5                  ,
                               (cl_object) func   ,
                               (cl_object) arg0   ,
                               (cl_object) arg1   ,
                               (cl_object) arg2   ,
                               (cl_object) arg3 ) ;
}

void * Call(void * func ,
            void * arg0 ,
            void * arg1 ,
            void * arg2 ,
            void * arg3 ,
            void * arg4 )
{
  return (void *) cl_funcall ( 6                  ,
                               (cl_object) func   ,
                               (cl_object) arg0   ,
                               (cl_object) arg1   ,
                               (cl_object) arg2   ,
                               (cl_object) arg3   ,
                               (cl_object) arg4 ) ;
}

void * Call(void * func ,
            void * arg0 ,
            void * arg1 ,
            void * arg2 ,
            void * arg3 ,
            void * arg4 ,
            void * arg5 )
{
  return (void *) cl_funcall ( 7                  ,
                               (cl_object) func   ,
                               (cl_object) arg0   ,
                               (cl_object) arg1   ,
                               (cl_object) arg2   ,
                               (cl_object) arg3   ,
                               (cl_object) arg4   ,
                               (cl_object) arg5 ) ;
}

void * Call(void * func ,
            void * arg0 ,
            void * arg1 ,
            void * arg2 ,
            void * arg3 ,
            void * arg4 ,
            void * arg5 ,
            void * arg6 )
{
  return (void *) cl_funcall ( 8                  ,
                               (cl_object) func   ,
                               (cl_object) arg0   ,
                               (cl_object) arg1   ,
                               (cl_object) arg2   ,
                               (cl_object) arg3   ,
                               (cl_object) arg4   ,
                               (cl_object) arg5   ,
                               (cl_object) arg6 ) ;
}

void * Call(void * func ,
            void * arg0 ,
            void * arg1 ,
            void * arg2 ,
            void * arg3 ,
            void * arg4 ,
            void * arg5 ,
            void * arg6 ,
            void * arg7 )
{
  return (void *) cl_funcall ( 9                  ,
                               (cl_object) func   ,
                               (cl_object) arg0   ,
                               (cl_object) arg1   ,
                               (cl_object) arg2   ,
                               (cl_object) arg3   ,
                               (cl_object) arg4   ,
                               (cl_object) arg5   ,
                               (cl_object) arg6   ,
                               (cl_object) arg7 ) ;
}

void * Call(void * func ,
            void * arg0 ,
            void * arg1 ,
            void * arg2 ,
            void * arg3 ,
            void * arg4 ,
            void * arg5 ,
            void * arg6 ,
            void * arg7 ,
            void * arg8 )
{
  return (void *) cl_funcall ( 10                 ,
                               (cl_object) func   ,
                               (cl_object) arg0   ,
                               (cl_object) arg1   ,
                               (cl_object) arg2   ,
                               (cl_object) arg3   ,
                               (cl_object) arg4   ,
                               (cl_object) arg5   ,
                               (cl_object) arg6   ,
                               (cl_object) arg7   ,
                               (cl_object) arg8 ) ;
}

void * Call(void * func ,
            void * arg0 ,
            void * arg1 ,
            void * arg2 ,
            void * arg3 ,
            void * arg4 ,
            void * arg5 ,
            void * arg6 ,
            void * arg7 ,
            void * arg8 ,
            void * arg9 )
{
  return (void *) cl_funcall ( 11                 ,
                               (cl_object) func   ,
                               (cl_object) arg0   ,
                               (cl_object) arg1   ,
                               (cl_object) arg2   ,
                               (cl_object) arg3   ,
                               (cl_object) arg4   ,
                               (cl_object) arg5   ,
                               (cl_object) arg6   ,
                               (cl_object) arg7   ,
                               (cl_object) arg8   ,
                               (cl_object) arg9 ) ;
}

}
