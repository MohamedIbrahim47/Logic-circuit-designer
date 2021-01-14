#ifndef _SELECT_ACTION_H
#define _SELECT_ACTION_H


#include "Actions/Action.h"
class SELECT_ACTION : public Action
{
private:
	int x, y;				//for mouse click
public:
	SELECT_ACTION(ApplicationManager* pApp);
	virtual ~SELECT_ACTION(void);

	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif