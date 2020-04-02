#include "TextMessage.h"

int TextMessage::getPriority() const {
	return priority;
}

std::string TextMessage::getFrom() const {
	return from;
}

std::string TextMessage::getTopic() const {
	return topic;
}

std::string TextMessage::getText() const {
	return text;
}

std::string TextMessage::toString() const {
	return "MESSAGE " + std::to_string(priority) + " " + from + " " + topic + " T " + text;
}