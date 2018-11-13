#include "TextBuffer.h"
#include <fstream>
#include <cassert>

#define NDEBUG

TextBuffer::TextBuffer(std::string init)
{
    current = init;
    previous.clear();
    next.clear();
}
TextBuffer::TextBuffer(const std::string& filename, bool from_file)
{
  std::ifstream read_from_file (filename);
  assert(read_from_file.is_open() != 0);
  std::string line;
  while(getline (read_from_file,line))
  {
    current += line;
  }
  read_from_file.close();
  previous.clear();
  next.clear();
}
void TextBuffer::Save(std::string& filename)
{
    std::ofstream outstream;
    outstream.open(filename, std::ios_base::app);
    outstream<<current;
}
bool TextBuffer::Insert(std::string sub, int pos)
{
    insertt(sub, pos);
    return true;        //success
}
bool TextBuffer::Append(std::string sub)
{
    insertt(sub);
    return true;        //success
}
bool TextBuffer::EraseAt(int pos, int n)
{
    errase(n, pos);
    return true;        //success
}
bool TextBuffer::EraseEnd(int n)
{
    errase(n);
    return true;        //success
}
bool TextBuffer::ReplaceAll(std::string to, std::string from)
{
    std::string temp = current;
    size_t pos = current.find(from);
    while(pos != std::string::npos)
    {
        current.replace(pos, from.size(), to);
        pos = current.find(from, pos+from.size());
    }
    update_states(previous, temp, current);
    next.clear();
    return true;                            //Success
}
bool TextBuffer::Undo()
{
    apply_states(previous, true);
    previous.clear();
    return true;                            //Success
}
bool TextBuffer::Redo()
{
    apply_states(next, false);
    next.clear();
    return true;                            //Success
}
TextBuffer::~TextBuffer()
{
    clear_all();
}
void TextBuffer::clear_all()
{
    current = "";
    previous.clear();
    next.clear();
}
void TextBuffer::insertt(const std::string& sub, int pos)
{
    std::string temp = current;
    if (pos == -1)
    {
        current.append(sub);
    }
    else
    {
        pos += 1;
        current.insert(pos,sub);
    }
    update_states(previous, temp, current);
    next.clear();
}
void TextBuffer::errase(int n, int pos)
{
    std::string temp = current;
    if (pos == -1)
    {
        pos = current.size() - n;
    }
    current.erase(pos,n);
    update_states(previous, temp, current);
    next.clear();
}
//This call should be called each time the string is modified with an appropriate state to hold the changes in the previous state
void TextBuffer::update_states(std::forward_list<std::pair<int,char> >& state, const std::string& temp, const std::string& current)
{
    //Complexity: O(N = MaxSize(temp, current))
    int i;
    state.clear();
    //Here the difference between previous and final string is stored at each index
    for (i = 0; i < current.size(); ++i)
    {
        if (i < temp.size())
        {
            if (temp[i] != current[i])
            {
                std::pair<int,char> p = std::make_pair(i,temp[i]);
                state.push_front(p);
            }
        }
        else break;
    }
    //If final string got bigger
    while (i < current.size())
    {
        std::pair<int,char> p = std::make_pair(((-1*i) - 1),temp[i]);   //These, are string to be removed from previous string. Hence, store as -ve indices
        state.push_front(p);
        i++;
    }
    //If final string got smaller
    while (i < temp.size())
    {
        std::pair<int,char> p = std::make_pair(i,temp[i]);
        state.push_front(p);
        i++;
    }
    //This is needed since a forward_list pushes the values at the front and so in a reverse order
    state.reverse();
}
//This call should be called each time a state is to be applied on the present string
void TextBuffer::apply_states(std::forward_list<std::pair<int,char> >& state, bool undo)
{
    //Complexity: O(N = MaxSize(state)) ~ O(N = MaxSize(string))
    std::string prev = current;                                 //Store the current string
    std::forward_list<std::pair<int,char> >::iterator it;
    //Here, the changes are applied on the prev string from the state only for indices which were present in previous string also (large->short string)
    for (it = state.begin(); it != state.end(); ++it)
    {
        std::pair<int,char> p = *it;
        int ind = p.first;
        char ch = p.second;
        if (ind >= 0)
        {
            //Case where we have common indices between previous and current string
            if (ind < prev.size())
            {
                prev[ind] = ch;
            }
            //Case where we have extra indices in the previous string (i.e., previous string was larger)
            else if (ind >= prev.size())
            {
                prev += ch;
            }
        }
    }
    int neg_start = 1, neg_end = 1;
    //Here I take care of the case, where current string got bigger than the previous one.
    //Negative indices' positions are searched
    for (it = state.begin(); it != state.end(); ++it)
    {
        std::pair<int,char> p = *it;
        int ind = p.first;
        //char ch = p.second;
        if (ind < 0)
        {
            if (neg_start > 0) neg_start = ind;
            neg_end = ind;
        }
    }
    neg_start += 1; neg_end += 1;
    neg_start *= -1; neg_end *= -1;
    std::string temp = "";
    //Here, I do not consider the values for negative indices' indices
    for (int j = 0; j < prev.size(); ++j)
    {
        if (!(j >= neg_start && j <= neg_end))
            temp += prev[j];
    }
    prev = temp;
    if (undo) update_states(next, current, prev);       //after an undo the next state needs to be updated for a possible redo
    else update_states(previous, prev, current);        //after a redo, previous state needs to be updated for a possible undo
    current = prev;
    state.clear();
}

