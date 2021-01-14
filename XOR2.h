#ifndef ADD_XOR2_H
#define ADD_XOR2_H

#include "Components/Gate.h"

class XOR2 :public Gate
{
private:
	bool Is_h;
public:
	XOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut, bool h = false);

	virtual void Operate();
	virtual void Draw(Output* pOut);

	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);


};

#endif