#ifndef _ADD_OR_GATE_H
#define _ADD_OR_GATE_H

#include "Actions/Action.h"
#include "OR2.h"

class AddORgate2 : public Action
{
private:
	int Cx, Cy;
	int x1, y1, x2, y2;
	//
	int abort;
public:
	AddORgate2(ApplicationManager* pApp);
	virtual ~AddORgate2(void);


	virtual void ReadActionParameters();

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif