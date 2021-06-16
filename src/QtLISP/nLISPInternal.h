#ifndef NLISPINTERNAL_HPP
#define NLISPINTERNAL_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef void (*LispFunc) (void) ;

namespace LISP
{

int                boot          (int argc,char ** argv) ;
void               shutdown      (void) ;
void               defun         (const char * name,LispFunc func,int args) ;
void               defvar        (void * s,void * v) ;
void               defparameter  (void * s,void * v) ;
void            *  eval          (const char * call) ;
void            *  toObject      (char               value ) ;
void            *  toObject      (unsigned char      value ) ;
void            *  toObject      (short              value ) ;
void            *  toObject      (unsigned short     value ) ;
void            *  toObject      (int                value ) ;
void            *  toObject      (unsigned int       value ) ;
void            *  toObject      (long long          value ) ;
void            *  toObject      (unsigned long long value ) ;
void            *  toObject      (float              value ) ;
void            *  toObject      (double             value ) ;
void            *  toObject      (long double        value ) ;
void            *  toObject      (const char       * string) ;
int                toType        (void * clo) ;
char               toChar        (void * clo) ;
unsigned char      toUChar       (void * clo) ;
short              toShort       (void * clo) ;
unsigned short     toUShort      (void * clo) ;
int                toInt         (void * clo) ;
unsigned int       toUInt        (void * clo) ;
long long          toLongLong    (void * clo) ;
unsigned long long toULongLong   (void * clo) ;
float              toFloat       (void * clo) ;
double             toDouble      (void * clo) ;
long double        toLongDouble  (void * clo) ;
int             *  toString      (void * clo) ;
void               SelectPackage (void * clo) ;
void            *  Allocate      (int    type  ) ;
void            *  FindSymbol    (char * symbol) ;
int                SymbolType    (void * clo) ;
void               setSymbolType (void * clo,int type) ;
void            *  SymbolValue   (void * clo) ;
void            *  SymbolName    (void * clo) ;
void            *  SymbolPackage (void * clo) ;
void            *  Call          (void * func ) ;
void            *  Call          (void * func   ,
                                  void * arg  ) ;
void            *  Call          (void * func   ,
                                  void * arg0   ,
                                  void * arg1 ) ;
void            *  Call          (void * func   ,
                                  void * arg0   ,
                                  void * arg1   ,
                                  void * arg2 ) ;
void            *  Call          (void * func   ,
                                  void * arg0   ,
                                  void * arg1   ,
                                  void * arg2   ,
                                  void * arg3 ) ;
void            *  Call          (void * func   ,
                                  void * arg0   ,
                                  void * arg1   ,
                                  void * arg2   ,
                                  void * arg3   ,
                                  void * arg4 ) ;
void            *  Call          (void * func   ,
                                  void * arg0   ,
                                  void * arg1   ,
                                  void * arg2   ,
                                  void * arg3   ,
                                  void * arg4   ,
                                  void * arg5 ) ;
void            *  Call          (void * func   ,
                                  void * arg0   ,
                                  void * arg1   ,
                                  void * arg2   ,
                                  void * arg3   ,
                                  void * arg4   ,
                                  void * arg5   ,
                                  void * arg6 ) ;
void            *  Call          (void * func   ,
                                  void * arg0   ,
                                  void * arg1   ,
                                  void * arg2   ,
                                  void * arg3   ,
                                  void * arg4   ,
                                  void * arg5   ,
                                  void * arg6   ,
                                  void * arg7 ) ;
void            *  Call          (void * func   ,
                                  void * arg0   ,
                                  void * arg1   ,
                                  void * arg2   ,
                                  void * arg3   ,
                                  void * arg4   ,
                                  void * arg5   ,
                                  void * arg6   ,
                                  void * arg7   ,
                                  void * arg8 ) ;
void            *  Call          (void * func   ,
                                  void * arg0   ,
                                  void * arg1   ,
                                  void * arg2   ,
                                  void * arg3   ,
                                  void * arg4   ,
                                  void * arg5   ,
                                  void * arg6   ,
                                  void * arg7   ,
                                  void * arg8   ,
                                  void * arg9 ) ;

}

#endif // NLISPINTERNAL_HPP
