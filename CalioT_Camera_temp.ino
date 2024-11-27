
#include "camera.h"
#include "define.h"
#include "SSD.h"



int pictureNumber = 0;

camera_fb_t* takePhoto() {
    camera_fb_t* fb = esp_camera_fb_get();
    if (!fb) {
        Serial.println("Помилка захоплення зображення");
        return NULL;
    }
    return fb;
}

void setup() {
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); 
 
  Serial.begin(115200);
  
  camera_config();

  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Ошибка инициализации камеры 0x%x", err);
    return;
  }

  camera_fb_t * fb = NULL;
 
  camera_fb_t* fb = takePhoto();
  if (!fb) {
    return;
  }
  initializeEEPROM();

  
  String path = "/picture" + String(pictureNumber) +".jpg";

  fs::FS &fs = SD_MMC; 
  Serial.printf("Имя файла: %s\n", path.c_str());
  
  File file = fs.open(path.c_str(), FILE_WRITE);
  if(!file){
    Serial.println("Не удалось открыть файл для записи");
  } 
  else {
    file.write(fb->buf, fb->len); 
    Serial.printf("Файл сохранён по адресу: %s\n", path.c_str());
   
    EEPROM.write(0, pictureNumber);
    EEPROM.commit();
  }
  file.close();
  esp_camera_fb_return(fb); 
  
  
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  rtc_gpio_hold_en(GPIO_NUM_4);
  
  millis(2000);
  Serial.println("Модуль впадает в спячку до следующего нажатия кнопки");
  delay(2000);
  esp_deep_sleep_start();
}

void loop() {
  
}
