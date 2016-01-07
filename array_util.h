typedef struct array{
  void *base;
  int typeSize;
  int length;
} ArrayUtil;

typedef int(*MatchFunc)(void *,void *);
typedef void(ConvertFunc)(void *,void *, void *);

ArrayUtil create(int,int);
void insert(int *,int);
int areEqual(ArrayUtil, ArrayUtil);
ArrayUtil resize(ArrayUtil, int);
int findIndex(ArrayUtil, void *);
void dispose(ArrayUtil);
int isEven(void *, void *);
void *findFirst(ArrayUtil, MatchFunc *, void *);
void *findLast(ArrayUtil, MatchFunc *, void *);
int count(ArrayUtil, MatchFunc*, void* hint);
int filter(ArrayUtil, MatchFunc *, void *, void **, int);
void map(ArrayUtil, ArrayUtil, ConvertFunc*, void*);
void square(void*, void*, void*);
