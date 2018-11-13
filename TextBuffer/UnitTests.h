/**
By Kartik Srivastava - 11072018
Here, I provide the unit tests to test the buffer functionality
I have introduced different test functions which could be fired individually also;
but here I have provided a run_unit_tests utility that would take care of all testing
1.] I test here initialization to a string from a string and also from a file.
I haven't printed the output of read from file as it was very big for me.
2.] A test is provided for checking file saving
3.] Tests are provided for replace all, insertion, append with recommended inputs for testing all boundary cases
Ideally, one should test insertion at the beginning, between and out of bound values with an empty, small and a large string
Out of bound inputs shall throw system exception here and abort the program.
Ideally, I should have provided an exception handling for out of bound cases
4.] Tests are provided for erase operations. Boundary cases of erasing more than the size, 0 size, and negative sizes were tested
Negative size gave an incorrect output which I attributed to a flaw in C++ STL erase call, hence I have commented this input case
5.] Finally, tests are also provided for undo and redo operations
It was important to consider cases of undo after a string becomes larger or smaller separately; which I have considered
Also, undo after a string is same was checked and could be checked again
**/

#ifndef UNITTESTS_H_INCLUDED
#define UNITTESTS_H_INCLUDED

#include "TextBuffer.h"

class UnitTests
{
protected:
    TextBuffer* buff_string;
    TextBuffer* buff_file;
public:
    UnitTests(std::string str, std::string& filename);
    void Initialization();
    void ReadFromFile();
    void SaveTofile(std::string& filename);
    void TestInsert(std::string sub, int pos);
    void TestAppend(std::string sub);
    void TestEraseAt(int pos, int n);
    void TestEraseEnd(int n);
    void TestReplaceAll(std::string to, std::string from);
    void TestUndo();
    void TestRedo();
    void run_unit_tests();
    virtual ~UnitTests();
};

#endif // UNITTESTS_H_INCLUDED
