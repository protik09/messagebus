//==============================================================
// Filename : MessageBus.cpp
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : ImageMessage class member function definitions
//==============================================================
#include "ImageMessage.h"                        // Include user defined library    

std::vector<unsigned char> getImage()             //get image function definition
{
	return base64_decode(base64encoded);
}

virtual std::string toString()					 //toString function definition of type virtual
{
	return "MESSAGE " + std::to_string(Message::getPriority()) + " " + Message::getFrom()+ " " + Message::getTopic()+ " I " /*+ m*/;     //concatenates info of priority,from,topic
}          