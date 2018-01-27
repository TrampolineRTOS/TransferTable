#include "tpl_os.h"

static const uint8_t grayDir = 0;
static const uint8_t redDir = 1;

void setDir(uint8_t inDir);

uint8_t direction();

void startMotor();

void stopMotor();

void resetPosition();

int32_t position();
