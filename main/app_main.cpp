#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "sdkconfig.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "app_main.h"

#include "ssd1306.h"
#include "ssd1306_console.h"

Ssd1306Console console;

template <typename... Args>
void c_printf(const char *fmt, Args... args)
{
    char buffer[80];
    sprintf(buffer, fmt, args...);
    printf(buffer);
    console.print(buffer);
}

extern "C" void app_main(void)
{
    ssd1306_setFixedFont(ssd1306xled_font6x8);
    
    // this code works on ssd1306 device:

    // ssd1306_128x64_i2c_init();
    // ssd1306_flipHorizontal(1);
    // ssd1306_flipVertical(1);
    // ssd1306_clearScreen();


    // but this throws error on ili9341:

    ili9341_240x320_spi_init(5, 27, 32);

    c_printf("Test\n");

    vTaskDelay(30 / portTICK_PERIOD_MS);
}
