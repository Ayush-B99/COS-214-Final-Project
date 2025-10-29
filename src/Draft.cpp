#include "../include/Draft.h"

Draft::Draft(){

}

void Draft::submitted(Order* order) {
	// TODO - implement Draft::submitted
	throw "Not yet implemented";
}

void Draft::paid(Order* order) {
	// TODO - implement Draft::paid
	throw "Not yet implemented";
}

void Draft::cancelled(Order* order) {
	// TODO - implement Draft::cancelled
	throw "Not yet implemented";
}

void Draft::completed(Order* order) {
	// TODO - implement Draft::completed
	throw "Not yet implemented";
}

const string Draft::getName() {
	return "draft";
}

bool Draft::canEdit() {
	// TODO - implement Draft::canEdit
	throw "Not yet implemented";
}

bool Draft::canCancel() {
	// TODO - implement Draft::canCancel
	throw "Not yet implemented";
}
