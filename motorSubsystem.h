#include "tpl_os.h"

static const uint8_t grayDir = 1;
static const uint8_t redDir = 0;

void setDir(uint8_t inDir);

void startMotor();

void stopMotor();

void resetPosition();

int32_t position();
