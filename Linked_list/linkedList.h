
typedef struct list{
	struct element *head;
	struct element *tail;
	int length;
} LinkedList;

typedef struct element{
	void *value;
	struct element *next;
} Element;

typedef void (*ElementProcessor)(void *);
typedef int (MatchFunc)(void *, void *);
typedef void (ConvertFunc)(void *, void *,void *);
typedef void *(Reducer)(void*, void*, void*);

LinkedList createList(void);
int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList);
void *get_last_element(LinkedList);
void forEach(LinkedList, ElementProcessor);
void *getElementAt(LinkedList, int);
int indexOf(LinkedList, void *);
void *deleteElementAt(LinkedList *, int);
int asArray(LinkedList, void **, int maxElements);
LinkedList  filter(LinkedList, MatchFunc, void *);
LinkedList reverse(LinkedList);
LinkedList map(LinkedList, ConvertFunc, void *);
void *reduce(LinkedList, Reducer, void *, void *);