/*
 * Telnet.cpp
 *
 *  Created on: Feb 2, 2013
 *      Author: kurios
 */

#include "Telnet.h"
#include <thread>

namespace knet {
	//Telnet Class Methods

	Telnet::Telnet(uint16_t port) {
		this->port = port;
	}

	uint8_t Telnet::open() {
		//TODO write net code

		return 0;
	}

	Message * Telnet::getMessage(){
		if( hasMessage() ){
			return this->msgList.pop_front();
		}
		return NULL;
	}

	uint8_t Telnet::sendMessage(Message * message){
		//TODO write SendMessage
		return 0;
	}

	bool Telnet::hasMessage(){
		return msgList.empty();
	}

	Telnet::~Telnet() {
	}


 //Message Class Methods
	Message::Message(){
		this->connection = 0;
		this->msg = (new std::string);
	}

	Message::Message(std::string * string, uint16_t connectionId){
		this->connection = connectionId;
		this->msg = string;
	}

	Message::~Message()
	{
		delete this->msg;
	}



} /* namespace knet */
