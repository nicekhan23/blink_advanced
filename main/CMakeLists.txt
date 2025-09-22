idf_component_register(SRCS "main.c" "blink.c" "console.c"
                       INCLUDE_DIRS "."
                       PRIV_REQUIRES driver
                                     esp_timer
                                     nvs_flash
                                     esp_system
                                     fatfs
                                     esp_event
                                     lwip
                       REQUIRES freertos)