#include "cppunitlite/TestHarness.h"
#include "utShapes.h"
#include "utVisitor.h"
#include "utBuilder.h"
#include "utFile.h"
#include "utCommand.h"

int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);

    return 0;
}
