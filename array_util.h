typedef struct array{
  void *base;
  int typeSize;
  int length;
} ArrayUtil;

typedef int(*MatchFunc)(void *,void *);

ArrayUtil create(int,int);
int areEqual(ArrayUtil, ArrayUtil);
ArrayUtil resize(ArrayUtil, int);
int findIndex(ArrayUtil, void *);
void dispose(ArrayUtil);
int isEven(void *, void *);
void *findFirst(ArrayUtil, MatchFunc *, void *);
void *findLast(ArrayUtil, MatchFunc *, void *);
int count(ArrayUtil util, MatchFunc*, void* hint);