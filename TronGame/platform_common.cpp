struct Button_state {
	bool is_down;
	bool changed;
};

enum { //You must at any buttons you wish to use here as well as in win32_platform.cpp
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_LEFT,
	BUTTON_RIGHT,
	BUTTON_A,
	BUTTON_W,
	BUTTON_S,
	BUTTON_D,
	BUTTON_ENTER,
	BUTTON_COUNT, //this should be the Last item
};

struct Input {
	Button_state buttons[BUTTON_COUNT];
};