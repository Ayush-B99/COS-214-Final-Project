#ifndef WHITEOAK_H
#define WHITEOAK_H

class WhiteOak : LargePlant {


public:
	WhiteOak();

	WhiteOak(WhiteOak& other);

	~WhiteOak();

	Plant* clone();
};

#endif
