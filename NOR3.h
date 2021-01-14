#ifndef _NOR3_H
#define _NOR3_H

#include "Components/Gate.h"

class NOR3 :public Gate
{
private:
	bool Is_h;
public:
	NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut, bool h = false);

	virtual void Operate();
	virtual void Draw(Output* pOut);

	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);


};

#endif