#include <qtlinguistics.h>

#if   defined(Q_OS_ANDROID)
#include <arpa/inet.h>
#elif defined(Q_OS_LINUX)
#include <arpa/inet.h>
#endif

N::IfoReader:: IfoReader(void)
{
}

N::IfoReader::~IfoReader(void)
{
}

bool N::IfoReader::addItem(QString line)
{
  int length  = line.length()                   ;
  nKickOut ( length < 2 , false )               ;
  int index   = line.indexOf('=')               ;
  nKickOut ( index  < 0 , false )               ;
  QString K   = line . left  (        index   ) ;
  QString V   = line . right ( length-index-1 ) ;
  K           = K.replace(" ","")               ;
  Pairs [ K ] = V                               ;
  return true                                   ;
}

bool N::IfoReader::Import(QString IfoFile)
{
  QFile  F  ( IfoFile                              ) ;
  nKickOut  ( !F.open(QIODevice::ReadOnly) , false ) ;
  QByteArray L                                       ;
  int        lineno = 0                              ;
  do                                                 {
    lineno ++                                        ;
    L = F.readLine()                                 ;
    if (L.size()>0)                                  {
      QString S = QString::fromUtf8(L)               ;
      S = S.replace("\n","")                         ;
      S = S.replace("\r","")                         ;
      if (lineno==1) Header = S ; else               {
        addItem ( S )                                ;
      }                                              ;
    }                                                ;
  } while (L.size()>0)                               ;
  F . close (                                      ) ;
  Ifo = IfoFile                                      ;
  QFileInfo FI(Ifo)                                  ;
  QString afp = FI.absolutePath()                    ;
  QString ibn = FI.baseName()                        ;
  QDir    afd (afp)                                  ;
  Idx  = QString("%1.idx" ).arg(ibn)                 ;
  Idx  = afd.absoluteFilePath(Idx )                  ;
  Dict = QString("%1.dict").arg(ibn)                 ;
  Dict = afd.absoluteFilePath(Dict)                  ;
  return true                                        ;
}

int N::IfoReader::Words(void)
{
  if (!Pairs.contains("wordcount")) return -1 ;
  QString V = Pairs["wordcount"]              ;
  bool okay  = false                          ;
  int  words = 0                              ;
  words = V.toInt(&okay)                      ;
  if (!okay) return -1                        ;
  return words                                ;
}

int N::IfoReader::IndexSize(void)
{
  if (!Pairs.contains("idxfilesize")) return -1 ;
  QString V = Pairs["idxfilesize"]              ;
  bool okay  = false                            ;
  int  idx = 0                                  ;
  idx = V.toInt(&okay)                          ;
  if (!okay) return -1                          ;
  return idx                                    ;
}

QString N::IfoReader::Name(void)
{
  if (!Pairs.contains("bookname")) return "" ;
  return Pairs["bookname"]                   ;
}

QStringList N::IfoReader::Keys(void)
{
  return Pairs.keys() ;
}

QString N::IfoReader::Item(QString key)
{
  if (!Pairs.contains(key)) return "" ;
  return Pairs[key]                   ;
}

QString N::IfoReader::Keyword(int index)
{
  SUID I = (SUID)index                    ;
  nKickOut ( !Keywords.contains(I) , "" ) ;
  return Keywords[I]                      ;
}

QByteArray N::IfoReader::Block(int index)
{
  SUID       I = (SUID)index             ;
  QByteArray B                           ;
  nKickOut ( !Keywords.contains(I) , B ) ;
  int offset = Offset[I]                 ;
  int size   = Sizes [I]                 ;
  B = Dictionary.mid(offset,size)        ;
  return B                               ;
}

bool N::IfoReader::Correct(void)
{
  nKickOut ( Dictionary.size() <= 0 , false ) ;
  return   ( Index.size() == IndexSize()    ) ;
}

bool N::IfoReader::Caching(void)
{
  File      F                               ;
  File      D                               ;
  QFileInfo I                               ;
  QFileInfo C                               ;
  Index      . clear()                      ;
  Dictionary . clear()                      ;
  ///////////////////////////////////////////
  I.setFile(Idx)                            ;
  if (I.exists())                           {
    F.setFileName(Idx)                      ;
  } else                                    {
    QString ni = QString("%1.gz").arg(Idx)  ;
    I.setFile(ni)                           ;
    if (!I.exists()) return false           ;
    F.setFileName(ni)                       ;
    F.adaptCompression()                    ;
  }                                         ;
  ///////////////////////////////////////////
  if (F.open(QIODevice::ReadOnly))          {
    Index      = F.readAll()                ;
    F.close()                               ;
  }                                         ;
  ///////////////////////////////////////////
  C.setFile(Dict)                           ;
  if (C.exists())                           {
    D.setFileName(Dict)                     ;
  } else                                    {
    QString ni = QString("%1.dz").arg(Dict) ;
    C.setFile(ni)                           ;
    if (!C.exists()) return false           ;
    D.setFileName(ni)                       ;
    D.adaptCompression()                    ;
  }                                         ;
  if (D.open(QIODevice::ReadOnly))          {
    Dictionary = D.readAll()                ;
    D.close()                               ;
  }                                         ;
  ///////////////////////////////////////////
  if (Index      . size()<=0) return false  ;
  if (Dictionary . size()<=0) return false  ;
  ///////////////////////////////////////////
  return true                               ;
}

int N::IfoReader::Indexing(QString encoding)
{
  QByteArray   EC = encoding.toUtf8()           ;
  QTextCodec * codec                            ;
  codec = QTextCodec::codecForName(EC)          ;
  if (IsNull(codec)) return 0                   ;
  Keywords . clear ()                           ;
  Offset   . clear ()                           ;
  Sizes    . clear ()                           ;
  int        index = 0                          ;
  SUID       ID    = 0                          ;
  const char zero  = 0                          ;
  char * data = (char *)Index.data()            ;
  do                                            {
    int end = Index.indexOf(zero,index)         ;
    if (end>=index)                             {
      unsigned int offset = 0                   ;
      unsigned int size   = 0                   ;
      int          length = end - index         ;
      QByteArray S                              ;
      if (length>0) S = Index.mid(index,length) ;
      index  = end + 1                          ;
      offset = *(unsigned int *)&data[index]    ;
      offset = ntohl(offset)                    ;
      index += sizeof(int)                      ;
      size   = *(unsigned int *)&data[index]    ;
      size   = ntohl(size)                      ;
      index += sizeof(int)                      ;
      QString w = codec->toUnicode(S)           ;
      Keywords [ID] = w                         ;
      Offset   [ID] = offset                    ;
      Sizes    [ID] = size                      ;
      ID ++                                     ;
    } else index = Index.size()                 ;
  } while (index<Index.size())                  ;
  return Keywords.count()                       ;
}

QStringList N::IfoReader::Unpack(QByteArray & Data,QString encoding)
{
  QStringList  L                               ;
  QByteArray   EC = encoding.toUtf8()          ;
  QTextCodec * codec                           ;
  codec = QTextCodec::codecForName(EC)         ;
  if (IsNull(codec)) return L                  ;
  int        index = 0                         ;
  const char zero  = 0                         ;
  do                                           {
    int end = Data.indexOf(zero,index)         ;
    if (end>=index)                            {
      int          length = end - index        ;
      QByteArray S                             ;
      if (length>0) S = Data.mid(index,length) ;
      index  = end + 1                         ;
      QString w = codec->toUnicode(S)          ;
      L << w                                   ;
    } else                                     {
      if (index<Data.size())                   {
        QByteArray S = Data.mid(index)         ;
        L << codec->toUnicode(S)               ;
      }                                        ;
      index = Data.size()                      ;
    }                                          ;
  } while (index<Data.size())                  ;
  return L                                     ;
}
