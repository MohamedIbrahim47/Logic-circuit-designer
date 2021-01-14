
#ifndef _NOT_H
#define _NOT_H

#include "Components/Gate.h"

class NOT :public Gate
{
private:
	bool Is_h;
public:
	NOT(const GraphicsInfo& r_GfxInfo, int r_FanOut, bool h = false);

	virtual void Operate();
	virtual void Draw(Output* pOut);

	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);   //no need to pass a parameter because not has only 1 input pin

	virtual void setInputPinStatus(int n,STATUS s);


};

#endif