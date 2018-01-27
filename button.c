#include "button.h"
#include "sam.h"
#include <pinAccess.h>
#include "tpl_os.h"

button button1 = { OFF, PORTA, 28 };
button button2 = { OFF, PORTA, 2 };
button button3 = { OFF, PORTA, 3 };
button sw0 = { OFF, PORTA, 15 };

button_state readButton(button *b)
{
	uint8_t hs = digitalRead(b->port, b->line);
	
	switch (b->state)
	{
	  case OFF:
	    if (hs == 0) b->state = PRESS;
	    break;
	  case PRESS:
	    b->state = ON;
	    break;
	  case ON:
	    if (hs == 1) b->state = UNPRESS;
	    break;
	  case UNPRESS:
	    b->state = OFF;
	    break;
	}
	return b->state;
}
