/*
 * Siri Webinar Practical Internet of Things
 * Basic Arduino Digital Input Output
 * 1 Jun 2020 (Isnin)
 * 
 * Trainer: Mohamad Ariffin Zulkifli (Myinvent Technologies Sdn Bhd)
 * https://myduino.com
 * 
 * Webinar Platform: ZOOM
 * 
 * Group Telegram (https://t.me/joinchat/Fht1QxkL-0GOwyo_nX86Tg)
 * 
 * Training Kit:
 * Myduino IoT Training Kit (https://myduino.com/product/myd-002/)
 * 
 * Development Board:
 * Tools > Board: > Arduino NANO
 * 
 * Sambungan Elektronik:
 * ----------------------------
 * | LEDs      | Arduino NANO |
 * ----------------------------
 * | LED L1         > 2       |
 * | LED GND        > GND     |
 * |                          |
 * | Pushbutton VS  > 5V      |
 * | Pushbutton GND > GND     |
 * | Pushbutton S   > 5       |
 * ----------------------------
 * 
 */

void setup() {
  pinMode(2, INPUT); // menjadikan Pin 2 sebagai INPUT
  pinMode(5, OUTPUT);  // menjadikan Pin 5 sebagai OUTPUT

}

void loop() {
  // arahan mikropengawal membaca status Pin 2
  // mikropengawal akan mengubah nilai pembolehubah "statusPushbutton" mengikut status Pin 2
  int statusPushbutton = digitalRead(2);  // jika ada voltan 2V-5V pada Pin 2 "statusPushbutton" = 1
                                          // jika ada voltan 0V-0.8V pada Pin 2 "statusPushbutton" = 0
                                          // fahami Logic Level - https://learn.sparkfun.com/tutorials/logic-levels/all#what-is-a-logic-level
  
  // hantar nilai pembolehubah "statusPushbutton" kepada Serial
  // nilai "statusPushbutton" 1 / 0, di Serial Monitor.
  Serial.println(statusPushbutton);
  
  // menggunakan function if
  // mikropengawal akan masuk ke function if dan melaksanakan arahan dalam function tersebut, jika pernyataan sepadan
  // pernyataan if jika "statusPushbutton" sepadan dengan nilai 1 bermaksud kita sedang menekan Pushbutton dan Pin 2 mempunyai 5V dan nilai logik 1
  if(statusPushbutton == 1){
    digitalWrite(5, HIGH);  // arahan mikropengawal mengeluarkan 5V kepada Pin 5
  }
  // pernyataan else jika "statusPushbutton" sepadan dengan selain daripada nilai 1 bermaksud kita sedang melepaskan Pushbutton dan Pin 2 mempunyai 0V dan nilai logik 0
  else{
    digitalWrite(5, LOW);  // arahan mikropengawal mengeluarkan 0V kepada Pin 5
  }

  // mikropengawal akan meneruskan pelaksanaan arahan yang seterusnya.
  // jika tiada apa-apa arahan seterusnya, mikropengawal ulang semula pelaksaan arahan dari line 40
  // proses ini akan berulang sehingga mikropengawal tidak lagi menerima sumber kuasa

}
