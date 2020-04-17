//==============================================================
// Filename : MeasurementMessage.h
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : MeasurementMessage class member function prototypes
//==============================================================

#pragma once										// Preprocessor definition for header guard

#include "Message.h"								// Include user defined library
class MeasurementMessage : public Message {         //MeasurementMessage class initialisation inherits Message class
private:											//private member initialisation
	double m;										//variable m of type double
public:
	MeasurementMessage(int priority, const std::string &from, const std::string &topic, double m) : Message(priority, from, topic), m(m){};//constructor initialisation inherits Message class
	double getMeasurement();						//Function to get measurement
	virtual std::string toString();					//Virtual function to convert into string and concatenate information 
};

