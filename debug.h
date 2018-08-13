#ifndef __DEBUG_H_
#define __DEBUG_H_
#include <cstdio>
#include <cstdlib>
#include <string>
using std::string;
typedef void (*TEST_FUNC)(struct TEST_CASE_DATA *);

struct TEST_CASE {
	const char *name;
	const char *func_name;
	TEST_FUNC func;
};

struct TEST_CASE_DATA {
	int expect_cnt;
	int total;
};

struct TEST_CASE_LINK_NODE {
	struct TEST_CASE data;
	struct TEST_CASE_LINK_NODE *next;
};
//struct TEST_CASE_LINK_NODE ___head = {0, 0}, *___tail = &___head;
extern struct TEST_CASE_LINK_NODE ___head, *___tail;

int START_ALL_TEST();
#define TEST(a, b) void a##b(struct TEST_CASE_DATA *); \
__attribute__((constructor)) void ADD##a##_##b() { \
	    struct TEST_CASE_LINK_NODE *temp = (TEST_CASE_LINK_NODE*)malloc(sizeof(TEST_CASE_LINK_NODE)); \
	    temp->data.name = #a; \
	    temp->data.func_name = #b; \
	    temp->data.func = a##b; \
	    ___tail->next = temp; \
	    temp->next = NULL; \
	    ___tail = temp; \
	} \
void a##b(struct TEST_CASE_DATA *__data)

void panic_spin(string filename, int line, const char* func, const char* condition);

#define PANIC(...) panic_spin(__FILE__, __LINE__, __func__, __VA_ARGS__)
#ifdef NDEBUG
    #define ASSERT(CONDITION) ((void)0)
    #define EXPLICT(a, b){}
#else
    #define EXPLICT(a, b) { \
	       	__data->total++;  \
		    printf("%s == %s %s\n", #a, #b, a == b ? "TRUE" : "FLASE"); \
		    __data->expect_cnt++; \
    }

    #define ASSERT(CONDITION) \
	    if(CONDITION) {} else { \
		    PANIC(#CONDITION); \
	    } 
#endif

#endif
