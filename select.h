#ifndef _SELECT_H
#define _SELECT_H


#include "Actions/Action.h"
class SELECT :	public Action
{
private:
	int x, y;				//for mouse click
public:
	SELECT(ApplicationManager* pApp);
	virtual ~SELECT(void);

	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif