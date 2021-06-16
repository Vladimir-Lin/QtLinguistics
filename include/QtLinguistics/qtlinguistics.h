/****************************************************************************
 *                                                                          *
 * Copyright (C) 2015 Neutrino International Inc.                           *
 *                                                                          *
 * Author : Brian Lin <lin.foxman@gmail.com>, Skype: wolfram_lin            *
 *                                                                          *
 ****************************************************************************/

#ifndef QT_LINGUISTICS_H
#define QT_LINGUISTICS_H

#include <QtCore>
#include <QtNetwork>
#include <QtSql>
#include <QtScript>
#include <Essentials>
#include <Mathematics>
#include <QtFFmpeg>
#include <QtAudio>
#include <AudioIO>
#include <QtNLP>
#include <QtMatcher>

QT_BEGIN_NAMESPACE

#ifndef QT_STATIC
#    if defined(QT_BUILD_QTLINGUISTICS_LIB)
#      define Q_LINGUISTICS_EXPORT Q_DECL_EXPORT
#    else
#      define Q_LINGUISTICS_EXPORT Q_DECL_IMPORT
#    endif
#else
#    define Q_LINGUISTICS_EXPORT
#endif


namespace N
{

/*****************************************************************************
 *                                                                           *
 *                        Computational Linguistics                          *
 *                                                                           *
 *                 Natural Language Processing and Corpus                    *
 *                                                                           *
 *****************************************************************************/

class Q_LINGUISTICS_EXPORT SymbolPool       ;
class Q_LINGUISTICS_EXPORT DictionaryParser ;
class Q_LINGUISTICS_EXPORT IfoReader        ;

namespace Acoustics
{

Q_LINGUISTICS_EXPORT QString     Bopomofo            (int category = 0) ;
Q_LINGUISTICS_EXPORT QString     Russian             (int category = 0) ;
Q_LINGUISTICS_EXPORT QString     Hiragana            (void) ;
Q_LINGUISTICS_EXPORT QString     Katakana            (void) ;
Q_LINGUISTICS_EXPORT QStringList JapanesePhonemes    (void) ;
Q_LINGUISTICS_EXPORT KMAPs       JpAlphabetToPhoneme (void) ;
Q_LINGUISTICS_EXPORT KMAPs       JpAlphabetSwap      (void) ;

}

class Q_LINGUISTICS_EXPORT SymbolPool
{
  public:

    KMAPs       FullSymbols             ;
    KMAPs       FullMath                ;
    QString     Symbols                 ;
    QString     MathSymbols             ;
    QString     Bopomofo                ;
    KMAPs       JapaneseAlphabet        ;
    KMAPs       JapaneseAlphabetPhoneme ;
    QString     Greek                   ;
    QString     FullJapanese            ;
    QString     Hiragana                ;
    QString     Katakana                ;
    QStringList JapanesePhoneme         ;
    QString     FullRussian             ;
    QString     RussianCapital          ;
    QString     RussianMinuscule        ;
    QString     Units                   ;
    QString     Arrows                  ;

    explicit     SymbolPool       (void) ;
    virtual     ~SymbolPool       (void) ;

    QString      operator []      (QString latin ) ; // half width to full width
    QString      Math             (QString symbol) ; // math name to math symbol

    bool         isSubset         (QString & message,QString & set) ;
    bool         isLatin          (QString & message) ;
    bool         isJapanese       (QString & message) ;
    bool         isKatakana       (QString & message) ;
    bool         isHiragana       (QString & message) ;
    bool         isRussian        (QString & message) ;
    bool         isBopomofo       (QString & message) ;

    bool         isHan            (unsigned short unicode,bool withSymbol = true) ;
    bool         isHan            (QChar c,bool withSymbol = true) ;
    bool         isHan            (QString & message) ;

    QString      Comma            (void) ;
    QString      Period           (void) ;
    QString      Space            (void) ;

    QString      LeftParentheses  (void) ;
    QString      RightParentheses (void) ;
    QString      LeftSquare       (void) ; // left square bracket
    QString      RightSquare      (void) ; // right square bracket
    QString      LeftBracket      (void) ;
    QString      RightBracket     (void) ;

  protected:

    virtual void configure   (void) ;

  private:

};

/*****************************************************************************
 *                                                                           *
 *                             Linguistic widgets                            *
 *                                                                           *
 *****************************************************************************/

class Q_LINGUISTICS_EXPORT DictionaryParser
{
  public:

    explicit DictionaryParser (void) ;
    virtual ~DictionaryParser (void) ;

  protected:

  private:

};

class Q_LINGUISTICS_EXPORT IfoReader
{
  public:

    QString    Header     ;
    KMAPs      Pairs      ;
    NAMEs      Keywords   ;
    RMAPs      Offset     ;
    RMAPs      Sizes      ;
    QByteArray Index      ;
    QByteArray Dictionary ;

    explicit    IfoReader (void) ;
    virtual    ~IfoReader (void) ;

    bool        Import    (QString IfoFile) ;
    bool        Caching   (void) ;
    bool        Correct   (void) ;
    int         Indexing  (QString encoding = "UTF-8") ;

    int         Words     (void) ;
    int         IndexSize (void) ;

    QStringList Keys      (void) ;
    QString     Item      (QString key) ;
    QString     Name      (void) ;

    QString     Keyword   (int index) ;
    QByteArray  Block     (int index) ;
    QStringList Unpack    (QByteArray & Data,QString encoding = "UTF-8") ;

  protected:

    QString Ifo  ;
    QString Idx  ;
    QString Dict ;

    bool        addItem   (QString line) ;

  private:

};

}

QT_END_NAMESPACE

#endif
