#include <qtlisp.h>
// #include "nLISPInternal.h"

#define CIOSVERSION "1.6.0"

QtLISP:: QtLISP(void)
{
//  Initialize ( ) ;
}

QtLISP:: QtLISP(int argc,char ** argv)
{
//  Initialize ( argc , argv ) ;
}

QtLISP::~QtLISP(void)
{
//  LISP::shutdown ( ) ;
}

void QtLISP::Initialize(int argc,char ** argv)
{
//  LISP::boot ( argc , argv ) ;
}

void QtLISP::Initialize(QStringList args)
{
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  int     argc = args . count ( )                             ;
  char ** argv = new char * [ argc ]                          ;
  for (int i=0;i<args.count();i++)                            {
    QString    s = args [ i ]                                 ;
    QByteArray b = s . toUtf8 ( )                             ;
    argv [ i ] = new char [ b . size ( ) + 1 ]                ;
    ::memset ( argv [ i ] , 0            , b . size ( ) + 1 ) ;
    ::memcpy ( argv [ i ] , b . data ( ) , b . size ( ) + 1 ) ;
  }                                                           ;
  /////////////////////////////////////////////////////////////
  LISP::boot ( argc , argv )                                  ;
  /////////////////////////////////////////////////////////////
  for (int i=0;i<args.count();i++)                            {
    delete [] argv [ i ]                                      ;
  }                                                           ;
  delete [ ] argv                                             ;
#endif
}

void QtLISP::Initialize(void)
{
//  Initialize ( QCoreApplication::arguments ( ) ) ;
}

void QtLISP::shutdown(void)
{
//  LISP::shutdown ( ) ;
}

bool QtLISP::isEmpty(LispObject lisp)
{
  return true ;
//  return ( NULL == lisp ) ;
}

void QtLISP::defun(const char * name,LispFunction func,int args)
{
//  LISP::defun ( name , (LispFunc) func , args ) ;
}

void QtLISP::defvar(LispObject s,LispObject v)
{
//  LISP::defvar ( s , v ) ;
}

void QtLISP::defparameter(LispObject s,LispObject v)
{
//  LISP::defparameter ( s , v ) ;
}

LispObject QtLISP::eval(QString lisp)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  if ( lisp . length ( ) <= 0 ) return NULL ;
  QByteArray   L    = lisp . toUtf8    ( )  ;
  const char * call = L    . constData ( )  ;
  return (LispObject) LISP::eval ( call )   ;
#endif
}

LispObject QtLISP::toObject(bool value)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  int v = value ? 1 : 0                    ;
  return (LispObject) LISP::toObject ( v ) ;
#endif
}

LispObject QtLISP::toObject(char value)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return (LispObject) LISP::toObject ( value ) ;
#endif
}

LispObject QtLISP::toObject(unsigned char value)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return (LispObject) LISP::toObject ( value ) ;
#endif
}

LispObject QtLISP::toObject(short value)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return (LispObject) LISP::toObject ( value ) ;
#endif
}

LispObject QtLISP::toObject(unsigned short value)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return (LispObject) LISP::toObject ( value ) ;
#endif
}

LispObject QtLISP::toObject(int value)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return (LispObject) LISP::toObject ( value ) ;
#endif
}

LispObject QtLISP::toObject(unsigned int value)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return (LispObject) LISP::toObject ( value ) ;
#endif
}

LispObject QtLISP::toObject(long long value)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return (LispObject) LISP::toObject ( value ) ;
#endif
}

LispObject QtLISP::toObject(unsigned long long value)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return (LispObject) LISP::toObject ( value ) ;
#endif
}

LispObject QtLISP::toObject(float value)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return (LispObject) LISP::toObject ( value ) ;
#endif
}

LispObject QtLISP::toObject(double value)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return (LispObject) LISP::toObject ( value ) ;
#endif
}

LispObject QtLISP::toObject(long double value)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return (LispObject) LISP::toObject ( value ) ;
#endif
}

LispObject QtLISP::toObject(QString string)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  QByteArray   L   = string . toUtf8    ( )  ;
  const char * str = L      . constData ( )  ;
  return (LispObject) LISP::toObject ( str ) ;
#endif
}

int QtLISP::LispType(LispObject v)
{
  return 0 ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  if ( NULL == v ) return -1 ;
  return LISP::toType ( v )  ;
#endif
}

bool QtLISP::toBool(LispObject v)
{
  return false ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  if ( NULL == v ) return 0 ;
  int b = LISP::toInt ( v ) ;
  return ( 0 != b )         ;
#endif
}

char QtLISP::toChar(LispObject v)
{
  return 0 ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  if ( NULL == v ) return 0 ;
  return LISP::toChar ( v ) ;
#endif
}

unsigned char QtLISP::toUChar(LispObject v)
{
  return 0 ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  if ( NULL == v ) return 0  ;
  return LISP::toUChar ( v ) ;
#endif
}

short QtLISP::toShort(LispObject v)
{
  return 0 ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  if ( NULL == v ) return 0  ;
  return LISP::toShort ( v ) ;
#endif
}

unsigned short QtLISP::toUShort(LispObject v)
{
  return 0 ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  if ( NULL == v ) return 0   ;
  return LISP::toUShort ( v ) ;
#endif
}

int QtLISP::toInt(LispObject v)
{
  return 0 ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  if ( NULL == v ) return 0 ;
  return LISP::toInt ( v )  ;
#endif
}

unsigned int QtLISP::toUInt(LispObject v)
{
  return 0 ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  if ( NULL == v ) return 0 ;
  return LISP::toUInt ( v ) ;
#endif
}

long long QtLISP::toLongLong(LispObject v)
{
  return 0 ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  if ( NULL == v ) return 0     ;
  return LISP::toLongLong ( v ) ;
#endif
}

unsigned long long QtLISP::toULongLong(LispObject v)
{
  return 0 ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  if ( NULL == v ) return 0      ;
  return LISP::toULongLong ( v ) ;
#endif
}

float QtLISP::toFloat(LispObject v)
{
  return 0 ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  if ( NULL == v ) return 0  ;
  return LISP::toFloat ( v ) ;
#endif
}

double QtLISP::toDouble(LispObject v)
{
  return 0 ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  if ( NULL == v ) return 0   ;
  return LISP::toDouble ( v ) ;
#endif
}

long double QtLISP::toLongDouble(LispObject v)
{
  return 0 ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  if ( NULL == v ) return 0       ;
  return LISP::toLongDouble ( v ) ;
#endif
}

QString QtLISP::toString (LispObject v)
{
  return "" ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  if ( NULL == v ) return ""        ;
  int * p = LISP::toString ( v )    ;
  if ( NULL == p ) return ""        ;
  QString s                         ;
  int     i = 0                     ;
  while ( p [ i ] != 0 )            {
    s .append ( QChar ( p [ i ] ) ) ;
    i++                             ;
  }                                 ;
  delete [ ] p                      ;
  return  s                         ;
#endif
}

void QtLISP::SelectPackage(QString package)
{
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  LispObject pkg = toObject ( package ) ;
  LISP::SelectPackage       ( pkg     ) ;
#endif
}

LispObject QtLISP::qversion(void)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  QString vs = QString::fromUtf8(qVersion()) ;
  return (LispObject) toObject ( vs )        ;
#endif
}

LispObject QtLISP::ciosversion(void)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return (LispObject) toObject ( QString ( CIOSVERSION ) ) ;
#endif
}

LispObject QtLISP::Allocate(int type)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return LISP::Allocate(type) ;
#endif
}

LispObject QtLISP::FindSymbol(QString symbol)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  if ( symbol . length ( ) <= 0 ) return NULL       ;
  QByteArray B = symbol . toUtf8 ( )                ;
  return LISP::FindSymbol ( (char *) B . data ( ) ) ;
#endif
}

int QtLISP::SymbolType(LispObject symbol)
{
  return 0 ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return LISP::SymbolType ( symbol ) ;
#endif
}

void QtLISP::setSymbolType(LispObject symbol,int type)
{
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  LISP::setSymbolType ( symbol , type ) ;
#endif
}

LispObject QtLISP::SymbolValue(LispObject symbol)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return (LispObject) LISP::SymbolValue ( symbol ) ;
#endif
}

LispObject QtLISP::SymbolName(LispObject symbol)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return (LispObject) LISP::SymbolName ( symbol ) ;
#endif
}

LispObject QtLISP::SymbolPackage(LispObject symbol)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return (LispObject) LISP::SymbolPackage ( symbol ) ;
#endif
}

LispObject QtLISP::Call(LispObject func)
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return LISP::Call ( func ) ;
#endif
}

LispObject QtLISP::Call(LispObject func ,
                        LispObject arg  )
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return LISP::Call ( func , arg ) ;
#endif
}

LispObject QtLISP::Call(LispObject func ,
                        LispObject arg0 ,
                        LispObject arg1 )
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return LISP::Call ( func   ,
                      arg0   ,
                      arg1 ) ;
#endif
}

LispObject QtLISP::Call(LispObject func ,
                        LispObject arg0 ,
                        LispObject arg1 ,
                        LispObject arg2 )
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return LISP::Call ( func   ,
                      arg0   ,
                      arg1   ,
                      arg2 ) ;
#endif
}

LispObject QtLISP::Call(LispObject func ,
                        LispObject arg0 ,
                        LispObject arg1 ,
                        LispObject arg2 ,
                        LispObject arg3 )
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return LISP::Call ( func   ,
                      arg0   ,
                      arg1   ,
                      arg2   ,
                      arg3 ) ;
#endif
}

LispObject QtLISP::Call(LispObject func ,
                        LispObject arg0 ,
                        LispObject arg1 ,
                        LispObject arg2 ,
                        LispObject arg3 ,
                        LispObject arg4 )
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return LISP::Call ( func   ,
                      arg0   ,
                      arg1   ,
                      arg2   ,
                      arg3   ,
                      arg4 ) ;
#endif
}

LispObject QtLISP::Call(LispObject func ,
                        LispObject arg0 ,
                        LispObject arg1 ,
                        LispObject arg2 ,
                        LispObject arg3 ,
                        LispObject arg4 ,
                        LispObject arg5 )
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return LISP::Call ( func   ,
                      arg0   ,
                      arg1   ,
                      arg2   ,
                      arg3   ,
                      arg4   ,
                      arg5 ) ;
#endif
}

LispObject QtLISP::Call(LispObject func ,
                        LispObject arg0 ,
                        LispObject arg1 ,
                        LispObject arg2 ,
                        LispObject arg3 ,
                        LispObject arg4 ,
                        LispObject arg5 ,
                        LispObject arg6 )
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return LISP::Call ( func   ,
                      arg0   ,
                      arg1   ,
                      arg2   ,
                      arg3   ,
                      arg4   ,
                      arg5   ,
                      arg6 ) ;
#endif
}

LispObject QtLISP::Call(LispObject func ,
                        LispObject arg0 ,
                        LispObject arg1 ,
                        LispObject arg2 ,
                        LispObject arg3 ,
                        LispObject arg4 ,
                        LispObject arg5 ,
                        LispObject arg6 ,
                        LispObject arg7 )
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return LISP::Call ( func   ,
                      arg0   ,
                      arg1   ,
                      arg2   ,
                      arg3   ,
                      arg4   ,
                      arg5   ,
                      arg6   ,
                      arg7 ) ;
#endif
}

LispObject QtLISP::Call(LispObject func ,
                        LispObject arg0 ,
                        LispObject arg1 ,
                        LispObject arg2 ,
                        LispObject arg3 ,
                        LispObject arg4 ,
                        LispObject arg5 ,
                        LispObject arg6 ,
                        LispObject arg7 ,
                        LispObject arg8 )
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return LISP::Call ( func   ,
                      arg0   ,
                      arg1   ,
                      arg2   ,
                      arg3   ,
                      arg4   ,
                      arg5   ,
                      arg6   ,
                      arg7   ,
                      arg8 ) ;
#endif
}

LispObject QtLISP::Call(LispObject func ,
                        LispObject arg0 ,
                        LispObject arg1 ,
                        LispObject arg2 ,
                        LispObject arg3 ,
                        LispObject arg4 ,
                        LispObject arg5 ,
                        LispObject arg6 ,
                        LispObject arg7 ,
                        LispObject arg8 ,
                        LispObject arg9 )
{
  return NULL ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXX
  return LISP::Call ( func   ,
                      arg0   ,
                      arg1   ,
                      arg2   ,
                      arg3   ,
                      arg4   ,
                      arg5   ,
                      arg6   ,
                      arg7   ,
                      arg8   ,
                      arg9 ) ;
#endif
}
