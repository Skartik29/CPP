/**
By Kartik Srivastava - 11072018
This is a simple text buffer utility providing interfaces like reading, insertion, erasing and replacing texts.
File operations are supported as well.
Undo and Redo works only for immediate changes. Hence, redo would be applicable only after an immediate preceeding undo
A state of indices and values that changes before/after an operation are stored in a forward_list to facilitate undo/redo operations
Such, a scheme takes care of memory considerations; since for a large buffer text; only the changes need be stored after an operation
Most of the interfaces uses stl string operations inside
Improvements:
1.] This design could be easily extended to multiple undo and redo by writing a wrapper builder class
This builder class shall hold a current state of TextBuffer as a pointer and a stack of forward_list to keep changes in a similar fashion as done now
Such, builder class would be owner of the TextBuffer object and would be loaded at the time of document load
This builder class will provide mapping functions over the interfaces provided here in the TextBuffer class
2.] Also, there could possibly be better ways to ascertain a difference in a string after an operation
Existing mechanism compares almost all the indices in most of the common cases
Some difference logic, e.g.: used by git revision control could possibly be used
**/

#ifndef TEXTBUFFER_H_INCLUDED
#define TEXTBUFFER_H_INCLUDED

#include <iostream>
#include <forward_list>
#include <utility>
#include <cstring>

class TextBuffer
{
protected:
    //Helper functions
    void clear_all();                                   //clears the buffer
    void insertt(const std::string& sub, int pos = -1); //insert substring at given position. -1 stands for append at the end
    void errase(int n, int pos = -1);                   //erase n characters starting and including given position. -1 stands for erase from the end
    void update_states(std::forward_list<std::pair<int,char> >& state, const std::string& temp, const std::string& current); //update previous states diff with current
    void apply_states(std::forward_list<std::pair<int,char> >& state, bool undo);                               //Apply the previous or next state over the string
    //Member variables
    std::string current;                                //current string
    std::forward_list<std::pair<int,char> > previous;   //previous state of the string: only the changes
    std::forward_list<std::pair<int,char> > next;       //next state of the string: only the changes
public:
    //Constructors
    TextBuffer(std::string init);
    TextBuffer(const std::string& filename, bool from_file);
    //Interfaces
    void Save(std::string& filename);
    bool Insert(std::string sub, int pos);
    bool Append(std::string sub);
    bool EraseAt(int pos, int n);
    bool EraseEnd(int n);
    bool ReplaceAll(std::string to, std::string from);
    bool Undo();
    bool Redo();
    std::string GetCurrent() const {return current;}
    //Destructor
    virtual ~TextBuffer();
};

#endif // TEXTBUFFER_H_INCLUDED
