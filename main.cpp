#include "cppunitlite/TestHarness.h"
#include "utShapes.h"
#include "Circle.h"
#include "Rectangle.h"
#include <iostream>

using namespace std;

int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);

    return 0;
}
