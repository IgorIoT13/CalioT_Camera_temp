#ifndef SSD
#define SSD

if(!SD_MMC.begin()){
    Serial.println("SD Card не работает");
    return;
    }
  
uint8_t cardType = SD_MMC.cardType();
if(cardType == CARD_NONE){
    Serial.println("SD Card не найдена");
    return;
  }

#endif