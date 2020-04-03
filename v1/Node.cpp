#include <iostream>												  //standard C++ library for input and output

#include "Node.h"												  //include standard user defined library
#include "TextMessage.h"										  //include standard user defined library			
#include "MessageBus.h"											  //include standard user defined library

std::string Node::getName() const {								 //getName function definition returns name 
	return name;
}

void Node::sendMessage(TextMessage* message)  {                 //sendMessage function definition points to messagebus acceptmessage function
	bus->acceptMessage(message);
}

void Node::acceptMessage(TextMessage* message) {               //acceptMessage funcction definition  to print message information
	std::cout << message->toString() << std::endl;
}

bool operator<(const Node& lhs, const Node& rhs) {             //operator function definition 
	return lhs.name < rhs.name;
}