//==============================================================
// Filename : TextMessage.cpp
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : Message class member function defintions
//==============================================================

#include "TextMessage.h" //include user defined TextMessage header

// GetText function definition
std::string TextMessage::getText()
{
	return text;
}

// toString function definition
std::string TextMessage::toString()
{
	return "MESSAGE " + std::to_string(getPriority()) + " " + getFrom() + " " + getTopic() + " T " + text; //concatenates info of priority,from,topic,text
}
