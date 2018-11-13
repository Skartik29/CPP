--------------------By Kartik Srivastava -------------------------------------------- (11082018)
This is an instruction document for using the textbuffer
Most of the explanations are self-explanatory in the comments section in the source code
User may essentially, carry out most of the operations with ease. 
Invalid and out of bounds are not handled now, so care should be taken at user's end
When reading data from file, the program shall abort if o file present
A single undo and redo operations are supported here
1.] The design could easily be extended to support for multiple undo and redo:
A wrapper builder class could easily be written that would compose an object of TextBuffer and a
stack to hold forward_list<std::pair<int, char> > as it does now.
These forward lists essentially shall store the changes which could be applied repeatedly using the exisiting
update_state and apply_state calls. 
Only, considerations to be kept in mind when using the builder wrapper would be to handle the memory efficiently,
since TextBuffer object is large (possibly, load builder at doc loading time; but initialize buffer object only when doc used)
2.] As some additional improvements:
- better design patterns could be used to separate the logic of calculating 
difference between strings (or what extra was to be in previous/next string)
- A better algorithm to find the difference between two strings is highly desirable here as per me (ref: github revision control algorithm)
- Some exception handlings would be good with appropriate code control flow redistribution
- In a practical environment, all the behind operations would be run on a separate thread than the main thread asynchronously
