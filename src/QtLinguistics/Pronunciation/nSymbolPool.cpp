#include <qtlinguistics.h>

N::SymbolPool:: SymbolPool (void)
{
  configure ( ) ;
}

N::SymbolPool::~SymbolPool (void)
{
}

void N::SymbolPool::configure(void)
{
  #define MPAIR(A,B) FullSymbols [ A ] =          QChar((ushort)B) ; \
                     Symbols           . append ( QChar((ushort)B) )

  MPAIR ( " "  , 0x3000 ) ;
  MPAIR ( "!"  , 0xFF01 ) ;
  MPAIR ( "\"" , 0xFF02 ) ;
  MPAIR ( "#"  , 0xFF03 ) ;
  MPAIR ( "$"  , 0xFF04 ) ;

  MPAIR ( "%"  , 0xFF05 ) ;
  MPAIR ( "&"  , 0xFF06 ) ;
  MPAIR ( "'"  , 0xFF07 ) ;
  MPAIR ( "("  , 0xFF08 ) ;
  MPAIR ( ")"  , 0xFF09 ) ;

  MPAIR ( "*"  , 0xFF0A ) ;
  MPAIR ( "+"  , 0xFF0B ) ;
  MPAIR ( ","  , 0xFF0C ) ;
  MPAIR ( "-"  , 0xFF0D ) ;
  MPAIR ( "."  , 0xFF0E ) ;

  MPAIR ( "/"  , 0xFF0F ) ;
  MPAIR ( "0"  , 0xFF10 ) ;
  MPAIR ( "1"  , 0xFF11 ) ;
  MPAIR ( "2"  , 0xFF12 ) ;
  MPAIR ( "3"  , 0xFF13 ) ;

  MPAIR ( "4"  , 0xFF14 ) ;
  MPAIR ( "5"  , 0xFF15 ) ;
  MPAIR ( "6"  , 0xFF16 ) ;
  MPAIR ( "7"  , 0xFF17 ) ;
  MPAIR ( "8"  , 0xFF18 ) ;

  MPAIR ( "9"  , 0xFF19 ) ;
  MPAIR ( ":"  , 0xFF1A ) ;
  MPAIR ( ";"  , 0xFF1B ) ;
  MPAIR ( "<"  , 0xFF1C ) ;
  MPAIR ( "="  , 0xFF1D ) ;

  MPAIR ( ">"  , 0xFF1E ) ;
  MPAIR ( "?"  , 0xFF1F ) ;
  MPAIR ( "@"  , 0xFF20 ) ;
  MPAIR ( "A"  , 0xFF21 ) ;
  MPAIR ( "B"  , 0xFF22 ) ;

  MPAIR ( "C"  , 0xFF23 ) ;
  MPAIR ( "D"  , 0xFF24 ) ;
  MPAIR ( "E"  , 0xFF25 ) ;
  MPAIR ( "F"  , 0xFF26 ) ;
  MPAIR ( "G"  , 0xFF27 ) ;

  MPAIR ( "H"  , 0xFF28 ) ;
  MPAIR ( "I"  , 0xFF29 ) ;
  MPAIR ( "J"  , 0xFF2A ) ;
  MPAIR ( "K"  , 0xFF2B ) ;
  MPAIR ( "L"  , 0xFF2C ) ;

  MPAIR ( "M"  , 0xFF2D ) ;
  MPAIR ( "N"  , 0xFF2E ) ;
  MPAIR ( "O"  , 0xFF2F ) ;
  MPAIR ( "P"  , 0xFF30 ) ;
  MPAIR ( "Q"  , 0xFF31 ) ;

  MPAIR ( "R"  , 0xFF32 ) ;
  MPAIR ( "S"  , 0xFF33 ) ;
  MPAIR ( "T"  , 0xFF34 ) ;
  MPAIR ( "U"  , 0xFF35 ) ;
  MPAIR ( "V"  , 0xFF36 ) ;

  MPAIR ( "W"  , 0xFF37 ) ;
  MPAIR ( "X"  , 0xFF38 ) ;
  MPAIR ( "Y"  , 0xFF39 ) ;
  MPAIR ( "Z"  , 0xFF3A ) ;
  MPAIR ( "["  , 0xFF3B ) ;

  MPAIR ( "\\" , 0xFF3C ) ;
  MPAIR ( "]"  , 0xFF3D ) ;
  MPAIR ( "^"  , 0xFF3E ) ;
  MPAIR ( "_"  , 0xFF3F ) ;
  MPAIR ( "`"  , 0xFF40 ) ;

  MPAIR ( "a"  , 0xFF41 ) ;
  MPAIR ( "b"  , 0xFF42 ) ;
  MPAIR ( "c"  , 0xFF43 ) ;
  MPAIR ( "d"  , 0xFF44 ) ;
  MPAIR ( "e"  , 0xFF45 ) ;

  MPAIR ( "f"  , 0xFF46 ) ;
  MPAIR ( "g"  , 0xFF47 ) ;
  MPAIR ( "h"  , 0xFF48 ) ;
  MPAIR ( "i"  , 0xFF49 ) ;
  MPAIR ( "j"  , 0xFF4A ) ;

  MPAIR ( "k"  , 0xFF4B ) ;
  MPAIR ( "l"  , 0xFF4C ) ;
  MPAIR ( "m"  , 0xFF4D ) ;
  MPAIR ( "n"  , 0xFF4E ) ;
  MPAIR ( "o"  , 0xFF4F ) ;

  MPAIR ( "p"  , 0xFF50 ) ;
  MPAIR ( "q"  , 0xFF51 ) ;
  MPAIR ( "r"  , 0xFF52 ) ;
  MPAIR ( "s"  , 0xFF53 ) ;
  MPAIR ( "t"  , 0xFF54 ) ;

  MPAIR ( "u"  , 0xFF55 ) ;
  MPAIR ( "v"  , 0xFF56 ) ;
  MPAIR ( "w"  , 0xFF57 ) ;
  MPAIR ( "x"  , 0xFF58 ) ;
  MPAIR ( "y"  , 0xFF59 ) ;

  MPAIR ( "z"  , 0xFF5A ) ;
  MPAIR ( "{"  , 0xFF5B ) ;
  MPAIR ( "|"  , 0xFF5C ) ;
  MPAIR ( "}"  , 0xFF5D ) ;
  MPAIR ( "~"  , 0xFF5E ) ;

  #undef  MPAIR

  // 0x2200 - 0x22FF , 0x2A00 - 0x2AFF , 0x27C0 - 0x27EF , 0x2980 - 0x29FF
  #define MSYM(A,B) FullMath [ A ] = QChar((ushort)B)

  MSYM ( "not"           , 0x00AC ) ;
  MSYM ( "error"         , 0x00B1 ) ;
  MSYM ( "multify"       , 0x00D7 ) ;
  MSYM ( "division"      , 0x00F7 ) ;

  MSYM ( "forall"        , 0x2200 ) ;
  MSYM ( "partial"       , 0x2202 ) ;
  MSYM ( "exists"        , 0x2203 ) ;
  MSYM ( "coproduct"     , 0x2210 ) ;
  MSYM ( "summation"     , 0x2211 ) ;
  MSYM ( "bullet"        , 0x2219 ) ;
  MSYM ( "infinity"      , 0x221E ) ;
  MSYM ( "integral"      , 0x222B ) ;
  MSYM ( "approximation" , 0x2248 ) ;
  MSYM ( "equiv"         , 0x2261 ) ;

//  MSYM ( "negation"  , 0x222B ) ; logic negation

  MSYM ( "keyboard" , 0x2328 ) ;

  #undef  MSYM

  for (int i=0x2200;i<=0x22FF;i++) MathSymbols . append ( QChar ( (ushort) i ) ) ;
  for (int i=0x2A00;i<=0x2AFF;i++) MathSymbols . append ( QChar ( (ushort) i ) ) ;
  for (int i=0x27C0;i<=0x27EF;i++) MathSymbols . append ( QChar ( (ushort) i ) ) ;
  for (int i=0x2980;i<=0x29FF;i++) MathSymbols . append ( QChar ( (ushort) i ) ) ;

  // Units  , 0x2100 - 0x214F
  for (int i=0x2100;i<=0x214F;i++) Units       . append ( QChar ( (ushort) i ) ) ;

  // Arrows , 0x2190 - 0x21FF , 0x27F0 - 0x27FF , 0x2900 - 0x297F
  for (int i=0x2190;i<=0x21FF;i++) Arrows      . append ( QChar ( (ushort) i ) ) ;
  for (int i=0x27F0;i<=0x27FF;i++) Arrows      . append ( QChar ( (ushort) i ) ) ;
  for (int i=0x2900;i<=0x297F;i++) Arrows      . append ( QChar ( (ushort) i ) ) ;

  // Greek , 0x03B1 - 0x03C9 , 0x0391 - 0x03A9
  // 0x0370 - 0x03FF , 0x1F00 - 0x1FFF
  for (int i=0x03B1;i<=0x03C9;i++) Greek       . append ( QChar ( (ushort) i ) ) ;
  for (int i=0x0391;i<=0x03A9;i++) Greek       . append ( QChar ( (ushort) i ) ) ;
  for (int i=0x0370;i<=0x03FF;i++)                                               {
    QChar z ( (ushort) i )                                                       ;
    if ( ! Greek . contains ( z ) ) Greek . append  ( z )                        ;
  }                                                                              ;
  for (int i=0x1F00;i<=0x1FFF;i++) Greek       . append ( QChar ( (ushort) i ) ) ;

  Bopomofo                = Acoustics::Bopomofo            (                         ) ;
  JapaneseAlphabet        = Acoustics::JpAlphabetSwap      (                         ) ;
  JapaneseAlphabetPhoneme = Acoustics::JpAlphabetToPhoneme (                         ) ;
  Hiragana                = Acoustics::Hiragana            (                         ) ;
  Katakana                = Acoustics::Katakana            (                         ) ;
  JapanesePhoneme         = Acoustics::JapanesePhonemes    (                         ) ;
  RussianCapital          = Acoustics::Russian             ( Speak::RussianCapital   ) ;
  RussianMinuscule        = Acoustics::Russian             ( Speak::RussianMinuscule ) ;
  FullJapanese            = Katakana         + Hiragana                                ;
  FullRussian             = RussianMinuscule + RussianCapital                          ;

}

QString N::SymbolPool::operator [] (QString latin)
{
  if (!FullSymbols.contains(latin)) return latin ;
  return FullSymbols [ latin ]                   ;
}

QString N::SymbolPool::Math(QString symbol)
{
  QString l = symbol.toLower()             ;
  if (!FullMath.contains(l)) return symbol ;
  return FullMath [ l ]                    ;
}

bool N::SymbolPool::isSubset(QString & message,QString & set)
{
  int L = message . length ( )        ;
  for (int i=0;i<L;i++)               {
    if (!set.contains(message.at(i))) {
      return false                    ;
    }                                 ;
  }                                   ;
  return true                         ;
}

bool N::SymbolPool::isLatin(QString & message)
{
  int L = message . length ( )       ;
  for (int i=0;i<L;i++)              {
    if (message.at(i).unicode()>255) {
      return false                   ;
    }                                ;
  }                                  ;
  return true                        ;
}

bool N::SymbolPool::isJapanese(QString & message)
{
  return isSubset ( message , FullJapanese ) ;
}

bool N::SymbolPool::isKatakana(QString & message)
{
  return isSubset ( message , Katakana ) ;
}

bool N::SymbolPool::isHiragana(QString & message)
{
  return isSubset ( message , Hiragana ) ;
}

bool N::SymbolPool::isRussian(QString & message)
{
  return isSubset ( message , FullRussian ) ;
}

bool N::SymbolPool::isBopomofo(QString & message)
{
  return isSubset ( message , Bopomofo ) ;
}

bool N::SymbolPool::isHan(unsigned short unicode,bool withSymbol)
{
  return isHan ( QChar ( unicode ) , withSymbol ) ;
}

bool N::SymbolPool::isHan(QChar c,bool withSymbol)
{
  if (withSymbol && Symbols.contains(c)) return true              ;
  /////////////////////////////////////////////////////////////////
  unsigned short u = c.unicode()                                  ;
  #define BETWEENC(a,b) if ( ( a >= u ) && ( u <= b ) ) return true

  BETWEENC ( 0x3400 , 0x4DFF )                                    ;
  BETWEENC ( 0x4E00 , 0x9FFF )                                    ;

// 0x20000 - 0x2B734 ( 0x20000 - 0x2A6FF , 0x2A700 - 0x2B734 )
// 0x2B740 - 0x2B81F

  #undef  BETWEENC
  return false                                                    ;
}

bool N::SymbolPool::isHan(QString & message)
{
  int L = message . length ( ) ;
  for (int i=0;i<L;i++)        {
    if (!isHan(message.at(i))) {
      return false             ;
    }                          ;
  }                            ;
  return true                  ;
}

QString N::SymbolPool::Comma(void)
{
  QString C                                ;
  C . append ( ','                       ) ; // 0x002C
  C . append ( QChar ( (ushort) 0xFF0C ) ) ;
  return C                                 ;
}

QString N::SymbolPool::Period(void)
{
  QString C                                ;
  C . append ( '.'                       ) ; // 0x002E
  C . append ( QChar ( (ushort) 0x3002 ) ) ;
  C . append ( QChar ( (ushort) 0xFE12 ) ) ;
  C . append ( QChar ( (ushort) 0xFF61 ) ) ;
  C . append ( QChar ( (ushort) 0xFE0E ) ) ;
  C . append ( QChar ( (ushort) 0xFE52 ) ) ;
  return C                                 ;
}

QString N::SymbolPool::Space(void)
{
  QString C                                ;
  C . append ( QChar ( (ushort) 0x0020 ) ) ;
  C . append ( QChar ( (ushort) 0x3000 ) ) ;
  C . append ( QChar ( (ushort) 0x00A0 ) ) ;
  C . append ( QChar ( (ushort) 0x1680 ) ) ;
  C . append ( QChar ( (ushort) 0x180E ) ) ;
  C . append ( QChar ( (ushort) 0x2002 ) ) ;
  C . append ( QChar ( (ushort) 0x2003 ) ) ;
  C . append ( QChar ( (ushort) 0x2004 ) ) ;
  C . append ( QChar ( (ushort) 0x2005 ) ) ;
  C . append ( QChar ( (ushort) 0x2006 ) ) ;
  C . append ( QChar ( (ushort) 0x2007 ) ) ;
  C . append ( QChar ( (ushort) 0x2008 ) ) ;
  C . append ( QChar ( (ushort) 0x2009 ) ) ;
  C . append ( QChar ( (ushort) 0x200A ) ) ;
  C . append ( QChar ( (ushort) 0x200B ) ) ;
  C . append ( QChar ( (ushort) 0x200C ) ) ;
  C . append ( QChar ( (ushort) 0x200D ) ) ;
  C . append ( QChar ( (ushort) 0x202F ) ) ;
  C . append ( QChar ( (ushort) 0x205F ) ) ;
  C . append ( QChar ( (ushort) 0x2060 ) ) ;
  C . append ( QChar ( (ushort) 0xFEFF ) ) ;
  return C                                 ;
}

QString N::SymbolPool::LeftParentheses(void)
{
  QString C                                ;
  C . append ( '('                       ) ; // 0x0028
  C . append ( QChar ( (ushort) 0xFF08 ) ) ;
  return C                                 ;
}

QString N::SymbolPool::RightParentheses(void)
{
  QString C                                ;
  C . append ( ')'                       ) ; // 0x0029
  C . append ( QChar ( (ushort) 0xFF09 ) ) ;
  return C                                 ;
}

QString N::SymbolPool::LeftSquare(void)
{
  QString C                                ;
  C . append ( '['                       ) ; // 0x005B
  C . append ( QChar ( (ushort) 0xFF3B ) ) ;
  return C                                 ;
}

QString N::SymbolPool::RightSquare(void)
{
  QString C                                ;
  C . append ( ']'                       ) ; // 0x005D
  C . append ( QChar ( (ushort) 0xFF3D ) ) ;
  return C                                 ;
}

QString N::SymbolPool::LeftBracket(void)
{
  QString C                                ;
  C . append ( '{'                       ) ; // 0x007B
  C . append ( QChar ( (ushort) 0xFF5B ) ) ;
  return C                                 ;
}

QString N::SymbolPool::RightBracket(void)
{
  QString C                                ;
  C . append ( '}'                       ) ; // 0x007D
  C . append ( QChar ( (ushort) 0xFF5D ) ) ;
  return C                                 ;
}
