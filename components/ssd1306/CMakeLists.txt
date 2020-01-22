FILE(GLOB SOURCES            "./src/*.c" 
                             "./src/ssd1306_hal/*.c" 
                             "./src/ssd1306_hal/esp/*.c" 
                             "./src/intf/*.c" 
                             "./src/intf/i2c/*.c" 
                             "./src/intf/spi/*.c" 
		             "./src/intf/vga/esp32/*.c"
                             "./src/intf/vga/*.c"
                             "./src/lcd/*.c" 
                             "./src/nano_engine/*.c")

idf_component_register(
    SRCS
        ${SOURCES}
    INCLUDE_DIRS 
        "./src" 
        "./src/ssd1306_hal" 
        "./src/ssd1306_hal/esp" 
        "./src/intf" 
        "./src/intf/i2c" 
        "./src/intf/spi" 
        "./src/intf/vga/esp32"
        "./src/intf/vga"
        "./src/lcd" 
        "./src/nano_engine"
)