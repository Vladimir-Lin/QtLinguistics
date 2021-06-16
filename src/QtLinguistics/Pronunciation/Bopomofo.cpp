#include <qtlinguistics.h>

#define BopomofoSize 208
static unsigned char BopomofoChars [ BopomofoSize ] =                          {
0xE3,0x84,0x85,0xE3,0x84,0x86,0xE3,0x84,0x87,0xE3,0x84,0x88,0xE3,0x84,0x89,0xE3,
0x84,0x8A,0xE3,0x84,0x8B,0xE3,0x84,0x8C,0xE3,0x84,0x8D,0xE3,0x84,0x8E,0xE3,0x84,
0x8F,0xE3,0x84,0x90,0xE3,0x84,0x91,0xE3,0x84,0x92,0xE3,0x84,0x93,0xE3,0x84,0x94,
0xE3,0x84,0x95,0xE3,0x84,0x96,0xE3,0x84,0x97,0xE3,0x84,0x98,0xE3,0x84,0x99,0xE3,
0x84,0x9A,0xE3,0x84,0x9B,0xE3,0x84,0x9C,0xE3,0x84,0x9D,0xE3,0x84,0x9E,0xE3,0x84,
0x9F,0xE3,0x84,0xA0,0xE3,0x84,0xA1,0xE3,0x84,0xA2,0xE3,0x84,0xA3,0xE3,0x84,0xA4,
0xE3,0x84,0xA5,0xE3,0x84,0xA6,0xE3,0x84,0xA7,0xE3,0x84,0xA8,0xE3,0x84,0xA9,0xE3,
0x84,0xAA,0xE3,0x84,0xAB,0xE3,0x84,0xAC,0xE3,0x84,0xAD,0xE3,0x86,0xA0,0xE3,0x86,
0xA1,0xE3,0x86,0xA2,0xE3,0x86,0xA3,0xE3,0x86,0xA4,0xE3,0x86,0xA5,0xE3,0x86,0xA6,
0xE3,0x86,0xA7,0xE3,0x86,0xA8,0xE3,0x86,0xA9,0xE3,0x86,0xAA,0xE3,0x86,0xAB,0xE3,
0x86,0xAC,0xE3,0x86,0xAD,0xE3,0x86,0xAE,0xE3,0x86,0xAF,0xE3,0x86,0xB0,0xE3,0x86,
0xB1,0xE3,0x86,0xB2,0xE3,0x86,0xB3,0xE3,0x86,0xB4,0xE3,0x86,0xB5,0xE3,0x86,0xB6,
0xE3,0x86,0xB7,0xE3,0x86,0xB8,0xE3,0x86,0xB9,0xE3,0x86,0xBA,0xCB,0xAA,0xCB,0xAB,
}                                                                              ;

QString N::Acoustics::Bopomofo(int category)
{
  QString BPMF = QString::fromUtf8(QByteArray((const char *)BopomofoChars,BopomofoSize)) ;
  QString P                        ;
  switch (category)                {
    case N::CLF::Consonants        :
      for (int i=0;i<21;i++)       {
        P.append(BPMF.at(i))       ;
      }                            ;
    return P                       ;
    case N::CLF::Medials           :
      for (int i=34;i<37;i++)      {
        P.append(BPMF.at(i))       ;
      }                            ;
    return P                       ;
    case N::CLF::Dialect           :
      for (int i=37;i<41;i++)      {
        P.append(BPMF.at(i))       ;
      }                            ;
    return P                       ;
    case N::CLF::Rhymes            :
      for (int i=13;i<34;i++)      {
        P.append(BPMF.at(i))       ;
      }                            ;
    return P                       ;
    case N::CLF::Formosan          :
      for (int i=41;i<65;i++)      {
        P.append(BPMF.at(i))       ;
      }                            ;
    return P                       ;
    case N::CLF::Hokkien           :
      for (int i=68;i<70;i++)      {
        P.append(BPMF.at(i))       ;
      }                            ;
    return P                       ;
    case N::CLF::MinNan            :
      for (int i=65;i<68;i++)      {
        P.append(BPMF.at(i))       ;
      }                            ;
    return P                       ;
  }                                ;
  return BPMF                      ;
}