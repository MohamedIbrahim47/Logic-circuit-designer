#ifndef _COPY_ACTION_H
#define _COPY_ACTION_H


#include "Actions/Action.h"
class COPY_ACTION : public Action
{
private:
	int x, y;
public:
	COPY_ACTION(ApplicationManager* pApp);
	virtual ~COPY_ACTION(void);

	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif