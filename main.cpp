#include "debug.h"
#define NDEBUG
int is_prime(int n) {
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i != 0) continue;
		return 0;
	}
    return 1;
}

TEST(test, is_prime) {
	EXPLICT(is_prime(1), 1);
	EXPLICT(is_prime(2), 1);
	EXPLICT(is_prime(3), 1);
	EXPLICT(is_prime(12), 1);
	ASSERT(is_prime(12) == 0);
	ASSERT(is_prime(11) == 1);
}
int main() {

	return START_ALL_TEST();
}
