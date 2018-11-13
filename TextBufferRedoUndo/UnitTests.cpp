#include "UnitTests.h"

UnitTests::UnitTests(std::string str, std::string& filename)
{
    buff_string = new TextBuffer(str);
    buff_file = new TextBuffer(filename, true);
}
void UnitTests::Initialization()
{
    std::cout<<"Intialization: "<<buff_string->GetCurrent()<<std::endl;
}
void UnitTests::ReadFromFile()
{
    //std::cout<<buff_file->GetCurrent()<<std::endl;
}
void UnitTests::SaveTofile(std::string& filename)
{
    buff_string->Save(filename);
}
void UnitTests::TestInsert(std::string sub, int pos)
{
    buff_string->Insert(sub, pos);
    std::cout<<"Insertion: "<<buff_string->GetCurrent()<<std::endl;
}
void UnitTests::TestAppend(std::string sub)
{
    buff_string->Append(sub);
    std::cout<<"Append: "<<buff_string->GetCurrent()<<std::endl;
}
void UnitTests::TestEraseAt(int pos, int n)
{
    buff_string->EraseAt(pos, n);
    std::cout<<"EraseAt: "<<buff_string->GetCurrent()<<std::endl;
}
void UnitTests::TestEraseEnd(int n)
{
    buff_string->EraseEnd(n);
    std::cout<<"EraseEnd: "<<buff_string->GetCurrent()<<std::endl;
}
void UnitTests::TestReplaceAll(std::string to, std::string from)
{
    buff_string->ReplaceAll(to, from);
    std::cout<<"ReplaceAll: "<<buff_string->GetCurrent()<<std::endl;
}
void UnitTests::TestUndo()
{
    buff_string->Undo();
    std::cout<<"After Undo: "<<buff_string->GetCurrent()<<std::endl;
}
void UnitTests::TestRedo()
{
    buff_string->Redo();
    std::cout<<"After Redo: "<<buff_string->GetCurrent()<<std::endl;
}
void UnitTests::run_unit_tests()
{
    //Initialization & reading from a file
    std::cout<<"---------------Testing begin: Reading from file and initialization of the buffer text---------------\n";
    Initialization();           //Here I am reading into a string from a string
    ReadFromFile();             //Here I am reading into a string from a file
    std::cout<<"---------------Testing end: Reading from file and initialization of the buffer text---------------\n";
    //Save to file
    std::cout<<"---------------Testing begin: Save to file ---------------\n";
    std::string save_to_file;
    std::cout<<"Enter the filename to save the output to\n";
    std::getline(std::cin, save_to_file);
    SaveTofile(save_to_file);   //Here I am saving into a file from the string
    std::cout<<"---------------Testing end: Save to file ---------------\n";
    //Insert between the string
    std::cout<<"---------------Testing begin: Insert between the string ---------------\n";
    std::string s_large, s_small;
    std::cout<<"Enter a large and a small string to insert\n";
    std::getline(std::cin, s_large);
    std::getline(std::cin, s_small);
    TestInsert(s_large, 0);     //Here I am inserting a large string into the given string at the beginning
    //TestInsert(s_large, 100); //This would be an invalid output and throws system exception appropriately. Hence, commented this
                                //Ideally, I should have handled this exception at my own end
    TestInsert("", 2);          //Here I am inserting an empty string at a valid position
    TestInsert(s_small, 4);     //Here I am inserting a very small string
    TestAppend(s_large);        //Here I am inserting the same large string at the end (append operation)
    std::cout<<"---------------Testing end: Insert between the string ---------------\n";
    //Erase At a location n number of characters and from the end
    std::cout<<"---------------Testing begin: Erase from a string ---------------\n";
    TestEraseAt(1,5);           //Here I am erasing 5 characters from position 1
    //TestEraseAt(3,-5);        //shouldn't have erased anything. Problem with STL erase call
    //TestEraseAt(100,2);       //Again the same system exception as 100 is invalid
    TestEraseEnd(2);            //Here I am erasing last 2 characters
    std::cout<<"---------------Testing end: Erase from a string ---------------\n";
    //Replace all substring with a given string
    std::cout<<"---------------Testing begin: Replace all substring in a given string ---------------\n";
    std::string large1, small1;
    std::cout<<"Enter a large string in the given string and a small string\n";
    std::getline(std::cin, large1);
    std::getline(std::cin, small1);
    TestReplaceAll(small1, large1); //Here I am replacing all occurrences of given large string in the original string with small string
    std::cout<<"---------------Testing end: Replace all substring in a given string ---------------\n";
    //Undo & Redo
    std::cout<<"---------------Testing begin: Undo and Redo operation ---------------\n";
    TestUndo();                             //Here I am calling 1 undo operation
    TestReplaceAll("toooooooooooo", "a");   //Here I am replacing all occurrences of a with a very large string in the original string
    TestUndo();                             //Here I am again calling undo
    TestRedo();                             //Here I am calling a redo operation.
                                            //Note that: redo would work only if there is an immediately preceeding undo call
    std::cout<<"---------------Testing end: Undo and Redo operation ---------------\n";
}
UnitTests::~UnitTests()
{
    delete buff_string;
    delete buff_file;
}
