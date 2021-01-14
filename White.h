#ifndef ADD_White_H
#define ADD_White_H

#include "Components/Gate.h"

class White :public Gate
{
private:
public:
	White(const GraphicsInfo& r_GfxInfo, int r_FanOut);

	virtual void Operate();
	virtual void Draw(Output* pOut);

	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);


};

#endif