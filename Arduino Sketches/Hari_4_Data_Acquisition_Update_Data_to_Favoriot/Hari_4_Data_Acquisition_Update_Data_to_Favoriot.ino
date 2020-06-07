/*
 * Siri Webinar Practical Internet of Things
 * Connecting IoT Device to Favoriot
 * 4 Jun 2020 (Khamis)
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
 * Tools > Board: > NodeMCU 1.0 (ESP12-E Module)
 * 
 * Sambungan Elektronik:
 * ----------------------------
 * | DHT11     | NodeMCU      |
 * ----------------------------
 * | DHT VS   --> 3V3         |
 * | DHT D    --> D6          |
 * | DHT NC   --> NOT CONNECT |
 * | DHT GND  --> GND         |
 * ----------------------------
 * 
 * Library:
 * 1. FavoriotHTTP https://github.com/ariffinzulkifli/FavoriotHTTP
 * 2. SimpleDHT https://www.arduinolibraries.info/libraries/simple-dht
 * 
 */

// penggunaan Favoriot HTTP library untuk mikropengawal ESP8266/ESP32
#include <FavoriotHTTP.h>

FavoriotHTTP favoriot;  // class FavoriotHTTP sebagai favoriot

const char WIFI_SSID[] = "NamaWiFiSaya";                // nama pembolehubah global untuk nama dan password WiFi
const char WIFI_PASS[] = "WiFiSayaPassword";
const char DEVICE_ACCESS_TOKEN[] = "DeviceAccessToken"; // nama pembolehubah global untuk Favoriot Device Access Token

// penggunaan library untuk sensor DHT
#include <SimpleDHT.h>

int pinDHT11 = D5;            // IO NodeMCU yang bersambung pada DHT11 Data Pin
SimpleDHT11 dht11(pinDHT11);  // penamaan class library DHT kepada "dht11" dan nyatakan "pinDHT11"

void setup() {
  Serial.begin(9600); // arahan untuk initiate Serial Communication

  favoriot.begin(WIFI_SSID, WIFI_PASS, DEVICE_ACCESS_TOKEN);  // arahan mikropengawal untuk berhubung dengan WiFi router dan Favoriot

}

void loop() {
  // membuat pembolehubah suhu dan kelembapan dengan nilai asal = 0 bagi setiap loop
  byte suhu = 0;
  byte kelembapan = 0;

  // dengan arahan dht11.read mikropengawal akan ke Pin D5 untuk mendapatkan data suhu dan kelembapan
  // namun jika berlaku error semasa dapatan data, mikropengawal akan masuk ke function if dan buat pelaksaan arahan print error dan return
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&suhu, &kelembapan, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err=");  //  mikropengawal akan print "error" dan tunggu 0.5 saat
    Serial.println(err);
    delay(500); 
    
    return;                                   // mikropengawal akan ulang semula ke line 72 dan tidak meneruskan ke arahan seterusnya  
  }
  // jika mikropengawal berjaya mendapatkan data, mikropengawal akan meneruskan ke arahan seterusnya
  
  favoriot.deviceId("FavoriotDeviceDeveloperIdSaya");     // arahan untuk mikropengawal menyatakan Favoriot Device Developer Id
  favoriot.dataStream("suhu", String(suhu));              // arahan untuk mikropengawal update data suhu dan kelembapan
  favoriot.dataStream("kelembapan", String(kelembapan));
  // jika ada tambahan data boleh tambah dibahagian ini
  // uncomment contoh dibawah untuk tambah data
  // favoriot.dataStream("sensor", String(nilaiSensor));
  favoriot.dataStreamEnd();                               // arahan untuk mikropengawal mula buat permintaan update data ke Favoriot
  
  delay(10000); // arahan mikropengawal tunggu 10 saat sebelum laksanakan arahan seterusnya
  
  // mikropengawal akan meneruskan pelaksanaan arahan yang seterusnya.
  // jika tiada apa-apa arahan seterusnya, mikropengawal ulang semula pelaksaan arahan dari line 75
  // proses ini akan berulang sehingga mikropengawal tidak lagi menerima sumber kuasa

}
