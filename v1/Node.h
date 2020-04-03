#pragma once

#include <string>                                             //include standard string library
#include "TextMessage.h"                                      //include user defined library
//#include "MessageBus.h"
class MessageBus;                                           

class Node {                                                 //initialise Node class
private:                                                    //private data members
	std::string name;									    //name varibale of string type
	MessageBus* bus;										//bus pointer variable of MessageBus class type
public:
	Node(const std::string& name, MessageBus* bus) :          //constructor initialising node class
		name(name), bus(bus) {}
	std::string getName() const;                              //function to get name
	void sendMessage(TextMessage*);							  //function to store TextMessage information
	void acceptMessage(TextMessage*);						  //function to accept message 
	friend bool operator<(const Node&, const Node&);          //friend class function of bool type
};

