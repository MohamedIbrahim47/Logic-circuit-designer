#ifndef ADD_XNOR2_H
#define ADD_XNOR2_H

#include "Components/Gate.h"

class XNOR2 :public Gate
{
private:
	bool Is_h;
public:
	XNOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut,bool h = false);

	virtual void Operate();
	virtual void Draw(Output* pOut);

	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);


};

#endif