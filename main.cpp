#include "cppunitlite/TestHarness.h"
#include "utShapes.h"
#include <iostream>

using namespace std;

int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);

    return 0;
}
