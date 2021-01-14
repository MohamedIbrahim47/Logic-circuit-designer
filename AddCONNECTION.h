#ifndef _ADD_CONNECTION_H
#define _ADD_CONNECTION_H

#include "Actions/Action.h"

class AddCONNECTION : public Action
{
private:
	int x, y;				//for mouse click
	int x1, x2, y1, y2;		//(x1,y1) for source pin , (x2,y2) for distination pin
public:
	AddCONNECTION(ApplicationManager* pApp);
	virtual ~AddCONNECTION(void);


	virtual void ReadActionParameters();

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif