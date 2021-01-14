#ifndef _ADD_BUFFER_GATE_H
#define _ADD_BUFFER_GATE_H

#include "Actions/Action.h"
#include "BUFFER.h"

class AddBUFFER : public Action
{
private:
	int Cx, Cy;
	int x1, y1, x2, y2;
	int abort;
public:
	AddBUFFER(ApplicationManager* pApp);
	virtual ~AddBUFFER(void);


	virtual void ReadActionParameters();

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif