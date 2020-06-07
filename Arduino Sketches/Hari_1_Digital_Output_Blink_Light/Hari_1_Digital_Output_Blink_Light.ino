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
 * Menggunakan LED sedia ada atas development board yang bersambung pada Pin 13
 */

// apabila mikropengawal diberi sumber kuasa
// pelaksanaan arahan bermula dari function setup
void setup() {
  // arahan disini dilaksanakan sekali sahaja
  // pelaksanaan arahan bermula dari atas satu per satu kebawah

  // bermmula pelaksanaan arahan dari arahan pertama
  pinMode(13, OUTPUT);  //  menjadikan Pin 13, sebagai OUTPUT
  // selesai pelaksanaan arahan terakhir
  // mikropengawal terus ke function loop

}

void loop() {
  // arahan disini dilaksanakan berulang kali
  // pelaksanaan arahan bermula dari atas satu per satu kebawah
  
  // bermmula pelaksanaan arahan dari arahan pertama
  digitalWrite(13, HIGH); // mikropengawal mengeluarkan 5V pada Pin 13
  delay(1000);  // mikropengawal tunggu 1 saat sebelum melaksanakan arahan seterusnya

  digitalWrite(13, LOW);  // mikropengawal mengeluarkan 0V pada Pin 13
  delay(1000);  // mikropengawal tunggu 1 saat sebelum melaksanakan arahan seterusnya
  // selesai pelaksanaan arahan terakhir
  // mikropengawal ulang semula melaksanakan tugasan dari line 23
  // proses ini akan berulang sehingga mikropengawal tidak lagi menerima sumber kuasa

}
