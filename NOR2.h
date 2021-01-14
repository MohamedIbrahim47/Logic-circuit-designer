#ifndef _NOR2_H
#define _NOR2_H

#include "Components/Gate.h"

class NOR2 :public Gate
{
private:
	bool Is_h;
public:
	NOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut, bool h = false);

	virtual void Operate();
	virtual void Draw(Output* pOut);

	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);


};

#endif