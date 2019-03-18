/*
 * pdata.h
 *
 *  Created on: 11 mrt. 2019
 *      Author: sande
 */
#include <stdint.h>

#ifndef PDATA_H_
#define PDATA_H_

class PData{
public:
	explicit PData();
	virtual ~PData();
public:
	void sendData_8(char data);
	void sendLoc();
	void uint16_handle_data_send(uint16_t data);
};
#endif /* PDATA_H_ */
