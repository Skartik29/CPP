#include <iostream>
#include "UnitTests.h"

using namespace std;

int main()
{
    //Initial setup
    std::string current_string;
    std::string read_from_file;
    std::cout<<"Enter a string to add to the buffer\n";
    std::getline(std::cin, current_string);
    std::cout<<"Enter a filename to read from\n";   //TextBufferFile.rtf (will abort program if file not present)
    std::getline(std::cin, read_from_file);
    //Testing
    UnitTests *test_suite_0 = new UnitTests(current_string, read_from_file);
    test_suite_0->run_unit_tests();
    delete test_suite_0;

    return 0;
}
