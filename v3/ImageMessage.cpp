//==============================================================
// Filename : ImageMessage.cpp
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : ImageMessage class member function defintions
//==============================================================

#include "ImageMessage.h" //include user defined ImageMessage header

// GetImage function definition
std::string ImageMessage::getImage()
{
	// std::string str_to_vec(base64encoded.begin(), base64encoded.end());
	return base64encoded;
}

// toString function definition
std::string ImageMessage::toString()
{
	return "MESSAGE " + std::to_string(getPriority()) + " " + getFrom() + " " + getTopic() + " I " + getImage(); //concatenates info of priority,from,topic,text
}
