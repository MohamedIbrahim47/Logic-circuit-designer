#ifndef _BUFFER_H
#define _BUFFER_H

#include "Components/Gate.h"

class BUFFER :public Gate
{
private:
	bool Is_h;
public:
	BUFFER(const GraphicsInfo& r_GfxInfo, int r_FanOut, bool h = false);

	virtual void Operate();
	virtual void Draw(Output* pOut);

	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);


};

#endif