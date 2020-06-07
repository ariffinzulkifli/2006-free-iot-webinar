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
 * | LED L1   --> 2           |
 * | LED L2   --> 3           |
 * | LED L3   --> 4           |
 * | LED L4   --> 5           |
 * | LED GND  --> GND         |
 * ----------------------------
 * 
 */

void setup() {
  pinMode(2, HIGH);
  pinMode(3, HIGH);
  pinMode(4, HIGH);
  pinMode(5, HIGH);

}

void loop() {
  // sentiasa ingat pelaksanaan arahan bermula dari atas kebawah

  // arahan nyalaan & tiada nyalaan LED L1 dengan selang masa 1 saat
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  delay(1000);

  // arahan nyalaan & tiada nyalaan LED L2 dengan selang masa 1 saat
  digitalWrite(3, HIGH);
  delay(1000);
  digitalWrite(3, LOW);
  delay(1000);

  // arahan nyalaan & tiada nyalaan LED L3 dengan selang masa 1 saat
  digitalWrite(4, HIGH);
  delay(1000);
  digitalWrite(4, LOW);
  delay(1000);

  // arahan nyalaan & tiada nyalaan LED L4 dengan selang masa 1 saat
  digitalWrite(5, HIGH);
  delay(1000);
  digitalWrite(5, LOW);
  delay(1000);

  // mikropengawal ulang semula pelaksaan arahan dari line 42
  // proses ini akan berulang sehingga mikropengawal tidak lagi menerima sumber kuasa

}
