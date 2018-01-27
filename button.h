#include "tpl_os.h"

typedef enum { OFF, PRESS, ON, UNPRESS } button_state;

typedef struct {
	button_state state;
	uint8_t		 port;
	uint8_t		 line;
} button;

extern button button1;
extern button button2;
extern button button3;
extern button sw0;

button_state readButton(button *b);