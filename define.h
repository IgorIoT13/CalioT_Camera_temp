#ifndef DEFINE_SECTION
#define DEFINE_SECTION

#include "esp_camera.h"
#include "Arduino.h"
#include "FS.h"                   // Для работы с файловой системой SD Card
#include "SD_MMC.h"               // Работа с MMC
#include "soc/soc.h"              // Избавляемся с проблемами при отключении
#include "soc/rtc_cntl_reg.h"     // Избавляемся с проблемами при отключении
#include "driver/rtc_io.h"
#include <EEPROM.h>   


#define EEPROM_SIZE 1             // Количество байт 1 позволяет сохранить до 256 фотографий

#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27

#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22


#endif