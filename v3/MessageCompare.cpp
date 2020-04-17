//==============================================================
// Filename : MessageCompare.cpp
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : Messagebus class member function defintions
//==============================================================

#include <iostream> // Standard C++ library for input and output

#include "Message.h" //include Library with the Message members and functions

// TextMessageCompare class initialisation
class MessageCompare
{
public:
    // Overload the () operator to return the result of comparing the priorities
    // of Message A and B
    bool operator()(Message *a, Message *b)
    {
        return (a->getPriority() > b->getPriority());
    }
};