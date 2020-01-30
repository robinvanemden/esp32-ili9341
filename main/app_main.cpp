#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "sdkconfig.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "app_main.h"
#include "nano_engine.h"

#include "ssd1306.h"
#include "ssd1306_console.h"

Ssd1306Console console;

extern "C" void app_main(void)
{

    ssd1306_setFixedFont(ssd1306xled_font6x8);
    
    ili9341_240x320_spi_init(5, 27, 32); 
    gpio_pad_select_gpio(GPIO_NUM_4);
    gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT);
    gpio_set_level(GPIO_NUM_4, 1);

    ili9341_setRotation(1);
    ssd1306_clearScreen();

    ssd1306_negativeMode();
    ssd1306_setColor(RGB_COLOR16(255,255,255));
    ssd1306_printFixed(0, 110, "Inverted bold", STYLE_BOLD);
    ssd1306_positiveMode();
    
    int x;
    char buffer[100];
    for ( x = 0; x < 6; x++ ) {
        sprintf(buffer,  "Testing one two ............ %d\n", x);
        ssd1306_print(buffer);
    }

    vTaskDelay(30 / portTICK_PERIOD_MS);
}
