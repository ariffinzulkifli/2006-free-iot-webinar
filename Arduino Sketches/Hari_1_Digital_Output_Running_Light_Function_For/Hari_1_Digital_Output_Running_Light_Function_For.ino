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

  // function for adalah untuk mikropengawal membuat pertambahan nilai kepada nilai asal pembolehubah.
  // pembolehubah "led" dengan nilai asal 2.
  // nilai asal "led" akan bertambah 1 sehingga nilainya menjadi nilai 5.
  for(int led = 2; led >= 5; led++){
    // pada loop ke-1 nilai "led" = 2 (mengikut asal int led = 2), mikropengawal buat kawalan untuk Pin 2
    // pada loop ke-2 nilai "led" = 3, mikropengawal buat kawalan untuk Pin 3
    // pada loop ke-3 nilai "led" = 4, mikropengawal buat kawalan untuk Pin 4
    // pada loop ke-4 nilai "led" = 5, mikropengawal buat kawalan untuk Pin 5
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
  }
  // apabila nilai pembolehubah "led" sudah lebih daripada nilai 5,
  // mikropengawal akan meneruskan pelaksanaan arahan yang seterusnya.
  // jika tiada apa-apa arahan seterusnya, mikropengawal ulang semula pelaksaan arahan dari line 44
  // proses ini akan berulang sehingga mikropengawal tidak lagi menerima sumber kuasa

}
