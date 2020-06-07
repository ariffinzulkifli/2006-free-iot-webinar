/*
 * Siri Webinar Practical Internet of Things
 * Connecting IoT Device to ThingSpeak
 * 3 Jun 2020 (Rabu)
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
 * 1. ESP8266WiFi
 * 2. SimpleDHT https://www.arduinolibraries.info/libraries/simple-dht
 * 
 */

// penggunaan WiFi library mikropengawal ESP8266
#include <ESP8266WiFi.h>

const char WIFI_SSID[] = "NamaWiFiSaya";      // nama pembolehubah global untuk nama dan password WiFi
const char WIFI_PASS[] = "WiFiSayaPassword";

// penggunaan HTTP Client library mikropengawal ESP8266
#include <ESP8266HTTPClient.h>

// penggunaan library untuk sensor DHT
#include <SimpleDHT.h>

int pinDHT11 = D5;            // IO NodeMCU yang bersambung pada DHT11 Data Pin
SimpleDHT11 dht11(pinDHT11);  // penamaan class library DHT kepada "dht11" dan nyatakan "pinDHT11"

void setup() {
  Serial.begin(9600); // arahan untuk initiate Serial Communication

  WiFi.begin(WIFI_SSID, WIFI_PASS); // arahan untuk mikropengawal mulakan sambung ke WiFi router

  // sewaktu mikropengawal cuba bersambung dengan WiFi router
  // status bagi function WiFi.status() masih tidak sama dengan WL_CONNECTED
  // penggunaan function while, menyebabkan mikropengawal kekal di loop selagi pernyataan sepadan
  // seperti dibawah, mikropengawal kekal print '.' selagi status WiFi tidak sepadan dengan WL_CONNECTED
  // dimana status WiFi WL_CONNECTED bermaksud WiFi mikropengawal sudah disambungkan dengan WiFi router
  while(WiFi.status() != WL_CONNECTED){ // nak tahu status WiFi yang lain? https://www.arduino.cc/en/Reference/WiFiStatus
    Serial.print(".");
    delay(250);
  }
  // apabila pernyataan while sudah tidak sepadan, mikropengawal akan meneruskan pelaksanaan arahan yang seterusnya.
  Serial.println(); // arahan print untuk line baru

  // apabila WiFi mikropengawal sudah bersambung WiFi router
  // WiFi router akan assign IP address, kita printkan IP Address nya
  Serial.println("NodeMCU connected to WiFi router!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP()); // arahan WiFi.localIP() kembalikan nilai IP Address mikropengawal

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

  // arahan untuk menghantar data ke ThingSpeak
  HTTPClient http;  // penamaan class library HTTP Client kepada "http"

  // HTTP API ThingSpeak untuk Update Data ke Channel --> GET http://api.thingspeak.com/update?api_key=YOURCHANNELAPIKEY&field1=0
  // ada dua data yang kita nak update, iaitu suhu dan kelambapan, masing2 merujuk kepada field1 dan field2
  // function http.begin() bagi menyatakan HTTP API daripada ThingSpeak dengan data suhu dan kelembapan
  http.begin("http://api.thingspeak.com/update?api_key=YOURCHANNELAPIKEY&field1=" + String(suhu) + "&field2=" + String(kelembapan));

  // seterusnya function http.GET(), merupakan arahan kepada mikropengawal mula buat permintaan untuk update data kepada ThingSpeak
  // selepas mikropengawal melaksanakan function http.GET(), mikropengawal akan menerima respon dari ThingSpeak dalam bentuk HTTP Code
  // apa itu HTTP Code? https://en.wikipedia.org/wiki/List_of_HTTP_status_codes
  // HTTP Code ini dalam bentuk nombor bulat, untuk itu kita sediakan satu pembolehubah untuk menyimpan respon ThingSpeak
  int httpCode = http.GET();

  // function if untuk membuat padanan jika httpCode lebih dari 0, bermaksud mikropengawal terima respon dari ThingSpeak
  if(httpCode > 0){
    String respon = http.getString(); // arahan mendapatkan HTTP reponse dari permintaan tadi
    Serial.println(respon);           // print maklumat respon
  }
  // jika padanan httpCode kurang dari 0, bermaksud tiada menerima apa-apa respon dari ThingSpeak
  // perkara ini berlaku tiada sambungan Internet atau server ThingSpeak down.
  else{
    Serial.println("HTTP Error!"); // print error dan mula periksa jika Internet ada atau tidak, atau server ThingSpeak yang down.
  }

  // selepas selesai permintaan update data ke ThingSpeak, kita tutup sambungan Internet mikropengawal dan ThingSpeak
  http.end();

  delay(20000); // arahan mikropengawal tunggu 20 saat sebelum laksanakan arahan seterusnya
  
  // mikropengawal akan meneruskan pelaksanaan arahan yang seterusnya.
  // jika tiada apa-apa arahan seterusnya, mikropengawal ulang semula pelaksaan arahan dari line 75
  // proses ini akan berulang sehingga mikropengawal tidak lagi menerima sumber kuasa

}
