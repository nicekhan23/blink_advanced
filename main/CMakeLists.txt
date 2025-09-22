idf_component_register(SRCS "main.c" "blink.c" "console.c" "cmd_nvs.c" "cmd_system.c" "cmd_wifi.c" "cmd_fatfs.c" "cmd_esp_console.c"
                       INCLUDE_DIRS "."
                       PRIV_REQUIRES driver
                                     esp_timer
                                     nvs_flash
                                     esp_console
                                     console
                                     esp_system
                                     fatfs
                                     esp_driver_usb_serial_jtag
                                     esp_usb_cdc_rom_console
                                     cmd_system
                                     cmd_wifi
                                     cmd_nvs
                                     cmd_fatfs
                                     cmd_esp_console
                                     esp_event
                                     lwip
                                     uart
                       REQUIRES freertos)
