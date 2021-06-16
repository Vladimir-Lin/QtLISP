/****************************************************************************
 *                                                                          *
 * Copyright (C) 2015 Neutrino International Inc.                           *
 *                                                                          *
 * Author : Brian Lin <lin.foxman@gmail.com>, Skype: wolfram_lin            *
 *                                                                          *
 ****************************************************************************/

#ifndef QT_LISP_H
#define QT_LISP_H

#include <QtCore>
#include <QtNetwork>
#include <QtSql>
#ifndef QT_STATIC
#include <QtScript>
#endif

QT_BEGIN_NAMESPACE

#ifndef QT_STATIC
#  if defined(QT_BUILD_QTLISP_LIB)
#    define Q_LISP_EXPORT Q_DECL_EXPORT
#  else
#    define Q_LISP_EXPORT Q_DECL_IMPORT
#  endif
#else
#    define Q_LISP_EXPORT
#endif

typedef void * LispObject ;
typedef LispObject (*LispFunction) (void) ;

class Q_LISP_EXPORT QtLISP
{
  public:

    enum                     {
      LispStart       =  0   ,
      LispList        =  1   ,
      LispCharacter   =  2   ,
      LispFixNumber   =  3   ,
      LispBigNumber   =  4   ,
      LispRatio       =  5   ,
      LispFloat       =  6   ,
      LispDouble      =  7   ,
      LispComplex     =  8   ,
      LispSymbol      =  9   ,
      LispPackage     = 10   ,
      LispHash        = 11   ,
      LispArray       = 12   ,
      LispVector      = 13   ,
      LispString      = 14   ,
      LispBaseString  = 15   ,
      LispBitVector   = 16   ,
      LispStream      = 17   ,
      LispRandom      = 18   ,
      LispReadTable   = 19   ,
      LispPathname    = 20   ,
      LispBytecodes   = 21   ,
      LispBClosure    = 22   ,
      LispCFun        = 23   ,
      LispCFunFixed   = 24   ,
      LispCClosure    = 25   ,
      LispStructure   = 26   ,
      LispCodeBlock   = 27   ,
      LispForeign     = 28   ,
      LispFrame       = 29   ,
      LispWeakPointer = 30   ,
      LispEnd         = 31   ,
      LispOther       = 32   ,
      LispContiguous  = 33 } ;

    explicit                  QtLISP        (void) ;
    explicit                  QtLISP        (int argc,char ** argv) ;
    virtual                  ~QtLISP        (void) ;

    static void               Initialize    (int argc,char ** argv) ;
    static void               Initialize    (QStringList arguments) ;
    static void               Initialize    (void) ;
    static void               shutdown      (void) ;

    static bool               isEmpty       (LispObject lisp) ;

    static void               defun         (const char * name,LispFunction func,int args) ;
    static void               defvar        (LispObject s,LispObject v) ;
    static void               defparameter  (LispObject s,LispObject v) ;

    static LispObject         eval          (QString lisp) ;

    static int                LispType      (LispObject v) ;

    static LispObject         toObject      (bool               value ) ;
    static LispObject         toObject      (char               value ) ;
    static LispObject         toObject      (unsigned char      value ) ;
    static LispObject         toObject      (short              value ) ;
    static LispObject         toObject      (unsigned short     value ) ;
    static LispObject         toObject      (int                value ) ;
    static LispObject         toObject      (unsigned int       value ) ;
    static LispObject         toObject      (long long          value ) ;
    static LispObject         toObject      (unsigned long long value ) ;
    static LispObject         toObject      (float              value ) ;
    static LispObject         toObject      (double             value ) ;
    static LispObject         toObject      (long double        value ) ;
    static LispObject         toObject      (QString            string) ;

    static bool               toBool        (LispObject v) ;
    static char               toChar        (LispObject v) ;
    static unsigned char      toUChar       (LispObject v) ;
    static short              toShort       (LispObject v) ;
    static unsigned short     toUShort      (LispObject v) ;
    static int                toInt         (LispObject v) ;
    static unsigned int       toUInt        (LispObject v) ;
    static long long          toLongLong    (LispObject v) ;
    static unsigned long long toULongLong   (LispObject v) ;
    static float              toFloat       (LispObject v) ;
    static double             toDouble      (LispObject v) ;
    static long double        toLongDouble  (LispObject v) ;
    static QString            toString      (LispObject v) ;

    static void               SelectPackage (QString package) ;

    static LispObject         qversion      (void) ;
    static LispObject         ciosversion   (void) ;

    static LispObject         Allocate      (int type) ;

    static LispObject         FindSymbol    (QString    symbol) ;
    static int                SymbolType    (LispObject symbol) ;
    static void               setSymbolType (LispObject symbol,int type) ;
    static LispObject         SymbolValue   (LispObject symbol) ;
    static LispObject         SymbolName    (LispObject symbol) ;
    static LispObject         SymbolPackage (LispObject symbol) ;

    static LispObject         Call          (LispObject func ) ;
    static LispObject         Call          (LispObject func   ,
                                             LispObject arg  ) ;
    static LispObject         Call          (LispObject func   ,
                                             LispObject arg0   ,
                                             LispObject arg1 ) ;
    static LispObject         Call          (LispObject func   ,
                                             LispObject arg0   ,
                                             LispObject arg1   ,
                                             LispObject arg2 ) ;
    static LispObject         Call          (LispObject func   ,
                                             LispObject arg0   ,
                                             LispObject arg1   ,
                                             LispObject arg2   ,
                                             LispObject arg3 ) ;
    static LispObject         Call          (LispObject func   ,
                                             LispObject arg0   ,
                                             LispObject arg1   ,
                                             LispObject arg2   ,
                                             LispObject arg3   ,
                                             LispObject arg4 ) ;
    static LispObject         Call          (LispObject func   ,
                                             LispObject arg0   ,
                                             LispObject arg1   ,
                                             LispObject arg2   ,
                                             LispObject arg3   ,
                                             LispObject arg4   ,
                                             LispObject arg5 ) ;
    static LispObject         Call          (LispObject func   ,
                                             LispObject arg0   ,
                                             LispObject arg1   ,
                                             LispObject arg2   ,
                                             LispObject arg3   ,
                                             LispObject arg4   ,
                                             LispObject arg5   ,
                                             LispObject arg6 ) ;
    static LispObject         Call          (LispObject func   ,
                                             LispObject arg0   ,
                                             LispObject arg1   ,
                                             LispObject arg2   ,
                                             LispObject arg3   ,
                                             LispObject arg4   ,
                                             LispObject arg5   ,
                                             LispObject arg6   ,
                                             LispObject arg7 ) ;
    static LispObject         Call          (LispObject func   ,
                                             LispObject arg0   ,
                                             LispObject arg1   ,
                                             LispObject arg2   ,
                                             LispObject arg3   ,
                                             LispObject arg4   ,
                                             LispObject arg5   ,
                                             LispObject arg6   ,
                                             LispObject arg7   ,
                                             LispObject arg8 ) ;
    static LispObject         Call          (LispObject func   ,
                                             LispObject arg0   ,
                                             LispObject arg1   ,
                                             LispObject arg2   ,
                                             LispObject arg3   ,
                                             LispObject arg4   ,
                                             LispObject arg5   ,
                                             LispObject arg6   ,
                                             LispObject arg7   ,
                                             LispObject arg8   ,
                                             LispObject arg9 ) ;

  protected:

  private:

} ;

QT_END_NAMESPACE

#endif
