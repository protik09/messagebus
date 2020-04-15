//==============================================================
// Filename : MessageBus.cpp
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : MeasurementMessagebus class member function prototypes
//==============================================================

#pragma once											// Preprocessor definition for header guard
#include "Message.h"								    // Include user defined library
class MeasurementMessage : public Message {			    // TextMessage class initialisation inherits Message
private:											    // Private data members
	double m;											// m variable which is of type double
public:
	MeasurementMessage(int priority, const std::string& from, const std::string& topic, double m) : Message(priority, from, topic), m(m) {};// Constructor intialisation
	double getMeasurement();							//Function to get Measurement m										
	virtual std::string toString() const;               // Function to convert into string and concatenate information
};

