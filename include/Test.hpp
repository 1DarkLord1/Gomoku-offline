#pragma once
#include <stddef.h>
#define DO_CHECK(EXPR) check(EXPR, __FUNCTION__, __FILE__, __LINE__)

class Test {
protected:
	static int failedNum;
	static int totalNum;
                               
	static void check(bool expr, const char* func, const char* filename, size_t lineNum); 

public:
	static void showFinalResult();
    
	virtual void runAllTests() = 0;
};
