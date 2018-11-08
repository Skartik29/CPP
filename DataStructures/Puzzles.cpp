#include "Puzzles.h"

ArrayPuzzles::ArrayPuzzles()
{
    arr[0] = 1;
    arr[1] = 10;
    arr[2] = 9;
    arr[3] = 3;
    arr[4] = 2;
    arr[5] = 5;
    arr[6] = 4;
    arr[7] = 2;
    arr[8] = 3;
    arr[9] = 7;

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            twoDArr[i][j] = i + j;

    sstck = new Stck();
    qque = new Que();
}
void ArrayPuzzles::PrintArray()
{
    for (int i = 0; i < 10; ++i)
        std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
}
void ArrayPuzzles::Print2DArray()
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            std::cout<<twoDArr[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}
void ArrayPuzzles::Reverse()
{
    int left = 0;
    int right = 9;
    while (left < right)
    {
        std::swap(arr[left], arr[right]);
        left++;
        right--;
    }
}
bool ArrayPuzzles::IsPalindrome()
{
    int left = 0;
    int right = 9;
    while (left < right)
    {
        if (arr[left] != arr[right]) return false;
        left++;
        right--;
    }
    return true;
}
bool ArrayPuzzles::IsPalind2D(int ind, bool rowOrCol)
{
    int left = 0, right = 4;
    while (left < right)
    {
        if (rowOrCol)
        {
            if (twoDArr[ind][left] != twoDArr[ind][right]) return false;
        }
        else
        {
            if (twoDArr[left][ind] != twoDArr[right][ind]) return false;
        }
        left++;
        right--;
    }
    return true;
}
bool ArrayPuzzles::Is2DPalindrome()
{
    for (int i = 0; i < 5; ++i)
        if (!IsPalind2D(i, true)) return false;
    for (int i = 0; i < 5; ++i)
        if (!IsPalind2D(i, false)) return false;
    return true;
}
void ArrayPuzzles::Decrement2D(int& row, int& col, int r)
{
    if (col < r)
    {
        col = r;
        row++;
        if (row > (5 - r - 1))
        {
            row = 5 - r - 1;
            col++;
        }
    }
}
void ArrayPuzzles::Increment2D(int& row, int& col, int r)
{
    if (col > (5 - r - 1))
    {
        col = 5 - r - 1;
        row++;
        if (row > (5 - r - 1))
        {
            row = 5 - r - 1;
            col--;
        }
    }
}
void ArrayPuzzles::Push2D(int pos, int row)
{
    int t = twoDArr[row][pos];
    int curr_row = row, curr_col = pos;
    int prev_row = row, prev_col = pos - 1;
    Decrement2D(prev_row, prev_col, row);
    int stop_row = row, stop_col = pos + 1;
    Increment2D(stop_row, stop_col, row);
    while (!(stop_row == curr_row && stop_col == curr_col))
    {
        twoDArr[curr_row][curr_col] = twoDArr[prev_row][prev_col];
        curr_col--;
        Decrement2D(curr_row, curr_col, row);
        prev_col--;
        Decrement2D(prev_row, prev_col, row);
    }
    twoDArr[stop_row][stop_col] = t;
}
void ArrayPuzzles::Push(int ind)
{
    int t = arr[ind];
    int current = ind;
    int previous = current - 1;
    if (previous == -1) previous = 9;
    int stop = ind + 1;
    if (stop == 10) stop = 0;
    while (current != stop)
    {
        arr[current] = arr[previous];
        current--;
        if (current == -1) current = 9;
        previous--;
        if (previous == -1) previous = 9;
    }
    arr[stop] = t;
}
void ArrayPuzzles::Pull(int ind)
{
    int t = arr[ind];
    int current = ind;
    int after = current + 1;
    if (after == 10) after = 0;
    int stop = ind - 1;
    if (stop == -1) stop = 9;
    while (current != stop)
    {
        arr[current] = arr[after];
        current++;
        if (current == 10) current = 0;
        after++;
        if (after == 10) after = 0;
    }
    arr[stop] = t;
}
void ArrayPuzzles::ClockwiseRotation(int pos)
{
    if (pos <= 0 || pos > 9) return;
    int ct = 9 - pos + 1;
    for (int i = 0; i < ct; ++i)
    {
        Push(pos + i);
    }
}
void ArrayPuzzles::AnticlockwiseRotation(int pos)
{
    if (pos < 0 || pos >= 9) return;
    int ct = pos + 1;
    for (int i = 0; i < ct; ++i)
    {
        Pull(pos + i);
    }
}
void ArrayPuzzles::RotateRow(int row)
{
    int start = row, stop = 5 - row - 1;
    for (int i = 0; i < stop - start; ++i)
    {
        int t = twoDArr[stop - i][start];
        twoDArr[stop - i][start] = twoDArr[stop][stop - i];
        twoDArr[stop][stop - i] = twoDArr[start + i][stop];
        twoDArr[start + i][stop] = twoDArr[start][start + i];
        twoDArr[start][start + i] = t;
    }
}
void ArrayPuzzles::Rotate90DegreeClockwise()
{
    /*for (int i = 0; i < 2; ++i)
    {
        int ct = 4 - 2 * i + 1;
        for (int j = 0; j < ct; ++j)
            Push2D(i + j, i);
    }*/
    for (int i = 0; i < 2; ++i)
        RotateRow(i);
}
QueueUsingStacks::QueueUsingStacks()
{
    curr = 1;
    state = true;
}
void QueueUsingStacks::Enqueue(int item)
{
    if (state)
    {
        if (curr == 1) s1.push(item);
        else s2.push(item);
    }
    else
    {
        state = true;
        if (curr == 1)
        {
            curr = 2;
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        else if (curr == 2)
        {
            curr = 1;
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
}
int QueueUsingStacks::Dequeue()
{
    int last = -1;
    bool updated = false;
    if (state)
    {
        state = !state;
        if (curr == 1)
        {
            curr = 2;
            while (!s1.empty())
            {
                if (s1.size() > 1)
                    s2.push(s1.top());
                last = s1.top();
                updated = true;
                s1.pop();
            }
        }
        else if (curr == 2)
        {
            curr = 1;
            while (!s2.empty())
            {
                if (s2.size() > 1)
                    s1.push(s2.top());
                last = s2.top();
                updated = true;
                s2.pop();
            }
        }
    }
    else
    {
        if (curr == 1)
        {
            if (!s1.empty())
            {
                last = s1.top();
                updated = true;
                s1.pop();
            }
        }
        else if (curr == 2)
        {
            if (!s2.empty())
            {
                last = s2.top();
                updated = true;
                s2.pop();
            }
        }
    }
    if (!updated) std::cout<<"Empty queue\n";
    return last;
}
StackUsingQueues::StackUsingQueues()
{
    curr = 1;
}
void StackUsingQueues::Push(int item)
{
    if (curr == 1) q1.push(item);
    else q2.push(item);
}
int StackUsingQueues::Pop()
{
    int last = -1;
    bool updated = false;
    if (curr == 1)
    {
        curr = 2;
        while (!q1.empty())
        {
            if (q1.size() > 1)
                q2.push(q1.front());
            last = q1.front();
            updated = true;
            q1.pop();
        }
    }
    else if (curr == 2)
    {
        curr = 1;
        while (!q2.empty())
        {
            if (q2.size() > 1)
                q1.push(q2.front());
            last = q2.front();
            updated = true;
            q2.pop();
        }
    }
    if (!updated) std::cout<<"Empty stack\n";
    return last;
}
