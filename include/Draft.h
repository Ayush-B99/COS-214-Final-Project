#ifndef DRAFT_H
#define DRAFT_H

class Draft : OrderState {


public:
	void submitted(Order* order);

	void paid(Order* order);

	void cancelled(Order* order);

	void completed(Order* order);

	string getName();

	bool canEdit();

	bool canCancel();
};

#endif
