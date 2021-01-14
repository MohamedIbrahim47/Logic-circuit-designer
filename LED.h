#ifndef _LED_H
#define _LED_H

#include "Components/Gate.h"

class LED :public Gate
{
private:
	bool Is_h;
public:
	LED(const GraphicsInfo& r_GfxInfo, int r_FanOut, bool h = false);

	virtual void Operate();
	virtual void Draw(Output* pOut);
	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);


};

#endif
