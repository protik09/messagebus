//==============================================================
// Filename : Message.cpp
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : Message class member function defintions
//==============================================================

#include "Message.h" //include user defined TextMesssage header

// GetPriority function definition
int Message::getPriority()
{
    return priority;
}

// GetFrom function definition
std::string Message::getFrom()
{
    return from;
}

// GetTopic function definition
std::string Message::getTopic()
{
    return topic;
}

// toString function definition
// This will need to be overridden in the child classes
std::string Message::toString()
{
    return "MESSAGE " + std::to_string(priority) + " " + from + " " + topic + " T Base Class (ERROR)"; //concatenates info of priority,from,topic,text
}
