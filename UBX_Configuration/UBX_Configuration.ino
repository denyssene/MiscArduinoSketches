#include <SoftwareSerial.h>

#define SS_RX_PIN 10
#define SS_TX_PIN 11
SoftwareSerial gpsSerial(SS_RX_PIN, SS_TX_PIN); // RX, TX

char disable_nmea_msg[97][11] = {
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0A, 0x00, 0x04, 0x23},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0A, 0x00, 0x04, 0x23},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0A, 0x00, 0x04, 0x23},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0A, 0x00, 0x04, 0x23},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0A, 0x00, 0x04, 0x23},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0A, 0x00, 0x04, 0x23},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0A, 0x00, 0x04, 0x23},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x09, 0x00, 0x03, 0x21},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x09, 0x00, 0x03, 0x21},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x09, 0x00, 0x03, 0x21},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x09, 0x00, 0x03, 0x21},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x09, 0x00, 0x03, 0x21},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x09, 0x00, 0x03, 0x21},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x09, 0x00, 0x03, 0x21},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x00, 0x00, 0xFA, 0x0F},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x00, 0x00, 0xFA, 0x0F},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x00, 0x00, 0xFA, 0x0F},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x00, 0x00, 0xFA, 0x0F},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x00, 0x00, 0xFA, 0x0F},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x00, 0x00, 0xFA, 0x0F},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x00, 0x00, 0xFA, 0x0F},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x01, 0x00, 0xFB, 0x11},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x01, 0x00, 0xFB, 0x11},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x01, 0x00, 0xFB, 0x11},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x01, 0x00, 0xFB, 0x11},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x01, 0x00, 0xFB, 0x11},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x01, 0x00, 0xFB, 0x11},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x01, 0x00, 0xFB, 0x11},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0D, 0x00, 0x07, 0x29},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0D, 0x00, 0x07, 0x29},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0D, 0x00, 0x07, 0x29},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0D, 0x00, 0x07, 0x29},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0D, 0x00, 0x07, 0x29},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0D, 0x00, 0x07, 0x29},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0D, 0x00, 0x07, 0x29},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x06, 0x00, 0x00, 0x1B},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x06, 0x00, 0x00, 0x1B},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x06, 0x00, 0x00, 0x1B},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x06, 0x00, 0x00, 0x1B},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x06, 0x00, 0x00, 0x1B},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x06, 0x00, 0x00, 0x1B},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x06, 0x00, 0x00, 0x1B},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x02, 0x00, 0xFC, 0x13},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x02, 0x00, 0xFC, 0x13},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x02, 0x00, 0xFC, 0x13},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x02, 0x00, 0xFC, 0x13},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x02, 0x00, 0xFC, 0x13},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x02, 0x00, 0xFC, 0x13},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x02, 0x00, 0xFC, 0x13},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x07, 0x00, 0x01, 0x1D},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x07, 0x00, 0x01, 0x1D},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x07, 0x00, 0x01, 0x1D},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x07, 0x00, 0x01, 0x1D},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x07, 0x00, 0x01, 0x1D},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x07, 0x00, 0x01, 0x1D},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x07, 0x00, 0x01, 0x1D},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x03, 0x00, 0xFD, 0x15},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x03, 0x00, 0xFD, 0x15},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x03, 0x00, 0xFD, 0x15},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x03, 0x00, 0xFD, 0x15},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x03, 0x00, 0xFD, 0x15},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x03, 0x00, 0xFD, 0x15},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x03, 0x00, 0xFD, 0x15},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x04, 0x00, 0xFE, 0x17},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x04, 0x00, 0xFE, 0x17},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x04, 0x00, 0xFE, 0x17},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x04, 0x00, 0xFE, 0x17},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x04, 0x00, 0xFE, 0x17},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x04, 0x00, 0xFE, 0x17},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x04, 0x00, 0xFE, 0x17},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0F, 0x00, 0x09, 0x2D},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0F, 0x00, 0x09, 0x2D},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0F, 0x00, 0x09, 0x2D},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0F, 0x00, 0x09, 0x2D},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0F, 0x00, 0x09, 0x2D},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0F, 0x00, 0x09, 0x2D},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x0F, 0x00, 0x09, 0x2D},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x05, 0x00, 0xFF, 0x19},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x05, 0x00, 0xFF, 0x19},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x05, 0x00, 0xFF, 0x19},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x05, 0x00, 0xFF, 0x19},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x05, 0x00, 0xFF, 0x19},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x05, 0x00, 0xFF, 0x19},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x05, 0x00, 0xFF, 0x19},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x08, 0x00, 0x02, 0x1F},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x08, 0x00, 0x02, 0x1F},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x08, 0x00, 0x02, 0x1F},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x08, 0x00, 0x02, 0x1F},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x08, 0x00, 0x02, 0x1F},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x08, 0x00, 0x02, 0x1F},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x08, 0x00, 0x02, 0x1F},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF1, 0x00, 0x00, 0xFB, 0x12},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF1, 0x01, 0x00, 0xFC, 0x14},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF1, 0x03, 0x00, 0xFE, 0x18},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF1, 0x04, 0x00, 0xFF, 0x1A},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF1, 0x05, 0x00, 0x00, 0x1C},
  {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF1, 0x06, 0x00, 0x01, 0x1E}
};

// enable message ubx posllhx
char cfg_ena_ubx[]={0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0x01, 0x02, 0x01, 0x0E, 0x47};

// configure msg rate to 1hz
char cfg_msg_rate_01hz[]={0xB5, 0x62, 0x06, 0x08, 0x06, 0x00, 0xE8, 0x03, 0x01, 0x00, 0x01, 0x00, 0x01, 0x39};
char cfg_msg_rate_05hz[]={0xB5, 0x62, 0x06, 0x08, 0x06, 0x00, 0xC8, 0x00, 0x01, 0x00, 0x01, 0x00, 0xDE, 0x6A};
char cfg_msg_rate_10hz[]={0xB5, 0x62, 0x06, 0x08, 0x06, 0x00, 0x64, 0x00, 0x01, 0x00, 0x01, 0x00, 0x7A, 0x12};

// rate config message
char cfg_msg_rate_x[]={0xB5, 0x62, 0x06, 0x08, 0x00, 0x00, 0x0E, 0x30};

// save current config message
char save_message[] = {0xB5, 0x62, 0x06, 0x09, 0x0D, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1D, 0xAB};

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
 
  //Serial.println("Disabling NMEA Messages...");
  //for (int i=0; i<97; i++) {
  //  gpsSerial.write(disable_nmea_msg[i],11);
  //  delay(10);
  //}

  Serial.println("Enabling UBX Message POSLLHX...");
  gpsSerial.write(cfg_ena_ubx,sizeof(cfg_ena_ubx));
  delay(10);
  
  Serial.println("Saving Current Configuration!");
  gpsSerial.write(save_message,sizeof(save_message));
  delay(1000);

}

void loop() {

  while (gpsSerial.available()) {
    Serial.print((char)gpsSerial.read());
  }

}
