//==============================================================
// Filename : Node.cpp
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : Node class member function defintions
//==============================================================

#include <iostream> // standard C++ library for input and output

#include "Node.h"		 // include standard user defined library
#include "TextMessage.h" // include standard user defined library
#include "MessageBus.h"	 // include standard user defined library

// Get the name of the node
std::string Node::getName() const
{
	return name;
}

// Add message to bus queue
void Node::sendMessage(TextMessage *message)
{
	bus->acceptMessage(message);
}

// Print the message when accepting it
void Node::acceptMessage(TextMessage *message)
{
	std::cout << message->toString() << std::endl;
}

// Overloading the < operator to compare Left Hand and Right Hand notes
bool operator<(const Node &lhs, const Node &rhs)
{
	return lhs.name < rhs.name;
}
