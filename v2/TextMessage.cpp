//==============================================================
// Filename : TextMessage.cpp
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : TextMessage class member function defintions
//==============================================================

#include "TextMessage.h" //include user defined TextMesssage header

// GetPriority function definition
int TextMessage::getPriority() const
{
	return priority;
}

// GetFrom function definition
std::string TextMessage::getFrom() const
{
	return from;
}

// GetTopic function definition
std::string TextMessage::getTopic() const
{
	return topic;
}

// GetText function definition
std::string TextMessage::getText() const
{
	return text;
}

// toString function definition
std::string TextMessage::toString() const
{
	return "MESSAGE " + std::to_string(priority) + " " + from + " " + topic + " T " + text; //concatenates info of priority,from,topic,text
}
