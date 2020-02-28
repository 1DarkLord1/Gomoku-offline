#include <cstdio>
#include "Test.hpp"

int Test::failedNum = 0;
int Test::totalNum = 0;

void Test::check(bool expr, const char* func, const char* filename, size_t lineNum) {
	totalNum++;
	if (expr) {
		printf("Test passed\n");
	}
	else {
		failedNum++;
		printf("Test failed\n");
		printf("In file %s, function %s, line %zu\n", filename, func, lineNum);    
	}
} 

void Test::showFinalResult() {
	if (failedNum == 0) {
		printf("All %d tests passed\n", totalNum);
	}
	else{
		printf("Failed %d / %d tests\n", failedNum, totalNum);
	}
}
