#include "Message.h"

int Message::getPriority() const {                   //getPriority function definition
	return priority;
}

std::string Message::getFrom() const {				 //getFrom function definition
	return from;
}

std::string Message::getTopic() const {				 //getTopic function definition
	return topic;
}


virtual std::string Message::toString() const
{                                                                 //toString function definition
	return "MESSAGE " + std::to_string(priority) + " " + from + " " + topic ;     //concatenates info of priority,from,topic
}