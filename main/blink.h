#ifndef BLINK_H
#define BLINK_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "portmacro.h"

BaseType_t blink_init(void);
BaseType_t blink_deinit(void);

#endif // BLINK_H