#ifndef _AND3_H
#define _AND3_H

#include "Components/Gate.h"

class AND3 :public Gate
{
private:
	bool Is_h;
public:
	AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut, bool h = false);

	virtual void Operate();
	virtual void Draw(Output* pOut);

	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);


};

#endif