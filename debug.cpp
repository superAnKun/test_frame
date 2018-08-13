#include "debug.h"
struct TEST_CASE_LINK_NODE ___head = {0, 0}, *___tail = &___head;
int START_ALL_TEST() {
	struct TEST_CASE_LINK_NODE *head = ___head.next;
	while (head) {
		TEST_CASE_DATA data = {0, 0};
		printf("test: %s func: %s \n", head->data.name, head->data.func_name);
		head->data.func(&data);
		printf("total: %d,  expect: %d \n", data.total, data.expect_cnt);
		head = head->next;
	}
	return 0;
}

void panic_spin(string filename, int line, const char* func, const char* condition) {
	printf("\n\n\n!!!!!!ERROR!!!!!!\n");
	printf("filename:%s\n", filename.c_str());
	printf("line:0x%x\n", line);
	printf("func: %s\n", func);
	printf("condition:%s\n", condition);
	while(1);
}

