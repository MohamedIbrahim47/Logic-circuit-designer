#ifndef _ADD_NOT_H
#define _ADD_NOT_H

#include "Actions/Action.h"
#include "NOT.h"

class AddNOT : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area

	int abort;
public:
	AddNOT(ApplicationManager* pApp);
	virtual ~AddNOT(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
