//==============================================================
// Filename : Node.h
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : Node class member data and function prototypes
//==============================================================

#pragma once // Preprocessor definition for header guard

#include <string>		 // Include standard string library
#include "TextMessage.h" // Include user defined library
// #include "MessageBus.h"
class MessageBus;

// Initialise Node class
class Node
{
private:			  // Private class members
	std::string name; // Name variable of string type
	MessageBus *bus;  // Bus pointer variable of MessageBus class type
public:				  // Public class members
	Node(const std::string &name, MessageBus *bus) : //  Empty constructor initialising the node class
													 name(name), bus(bus)
	{
	}
	std::string getName() const;					   // Function to get name
	void sendMessage(TextMessage *);				   // Function to store TextMessage information
	void acceptMessage(TextMessage *);				   // Function to accept message
	friend bool operator<(const Node &, const Node &); // Friend class function of bool type
};
