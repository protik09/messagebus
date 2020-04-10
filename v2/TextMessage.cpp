#include "TextMessage.h"                      //include user defined TextMesssage  header

int TextMessage::getPriority() const {                   //getPriority function definition
	return priority;
}

std::string TextMessage::getFrom() const {				 //getFrom function definition
	return from;
}

std::string TextMessage::getTopic() const {				 //getTopic function definition
	return topic;
}

std::string TextMessage::getText() const {				//getText function definition
	return text;
}

std::string TextMessage::toString() const {             //toString function definition
	return "MESSAGE " + std::to_string(priority) + " " + from + " " + topic + " T " + text;     //concatenates info of priority,from,topic,text
}