// CppUtilities.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "CppUtilities.h"

using namespace std;

// Test function to trigger clang-tidy warnings
void test_function() {
    int magic_number = 42;  // clang-tidy: magic number
    int* ptr = NULL;        // clang-tidy: use nullptr
    
    for(int i=0;i<10;++i) { // clang-tidy: spacing
        cout << magic_number << endl;
    }
}

int main()
{
	cout << "Hello CMake." << endl;
	test_function();
	return 0;
}
