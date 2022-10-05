


/*
 *    Requeriments rMCU v0.1
 * 
 * - Guardar a la SD els missatges de CAN
 * - Informar en cas de error
 * - Informar del estat
 * - LIMITADOR_ON == 1 --> Parpadeig dels LED
 * - Activar/Desactivar funcio Parpadeig LED
 * - Activar/Desactivar la opcio de guardar missatges a la SD
 */

#include <mcp2515_can.h>
#include<SPI.h>
#include <SD.h>

#define BAUDRATE CAN_500KBPS

//LED RGB
int RED=3;
int GREEN=5;
int BLUE=6;
//LED (TIRA DE LEDs)
int LED=//Quina sortida?;
//SD
const int chipSelect=9;
File datFile;


int state = 0;
bool LIMITADOR_ON = 0;
MCP2515 mcp2515(10/*pin number where SPI CS is connected*/);

void initCAN()
{
  // PRE: Res
  // POS: Initialitzar el CAN i amb cas d'error informar al usuari via un print
  mcp2515.reset();
  mcp2515.setBitrate(BAUDRATE);
  mcp2515.setNormalMode();
  if (ERROR){ //Que poso aqui!!!
    Serial.println("ERROR initCAN");
  }
}

void initPIN()
{
  // PRE: Res
  // POS: Initcializar la placa amb tots els pins digitals
  Serial.begin(9600);
  //Inicializar els pins necessaris
  //LED RGB
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  //LED strip
  pinMode(LED,OUTPUT);
}

void initSD()
{
  // PRE: Res
  // POS: Initicializar la SD del shield
  SD.begin(chipSelected);
}

void initRTCC()
{
  // PRE: Res
  // POS: Initizalitzar el modul RTCC
  
}

void setup() {
  initCAN();
  initPIN();
  initSD();
  initRTCC();
}

void readCAN_Msg(CAN* CAN0, uint8_t* msg, uint8_t* dlc)
{
  // PRE: Pasarem la interfaz de lectura, el missatege a llegir y la seva longitut
  // POS: Llegirem el buffer de lectura y retornarem el valor llegit

}

int getTime()
{
  // PRE: Res
  // POS: Retornara el temps llegit del modul RTCC
 
}

void guardarSD(int temps, uint8_t* msg)
{
  // PRE: Pasarem el temps i el missatge a guardar
  // POS: Guardarem a la SD el missatge amb el temps passat
  File dataFile= SD.open("data.txt", FILE_WRITE);
  //Guardem a la SD el missatge
  dataFile.print("Missatge: ");
  dataFile.print(msg)//COM IMPRIMEIXO AIXÒOO!!!
  //Guardem a la SD el temps
  dataFile.print("Temps: ");
  dataFile.println(temps, DEC);
}

void informaState()
{
  // PRE: Res
  // POS: Informara del nou estat al usuari
}
void parpadea(){
  //PRE: Res
  //POS: Parpadeja la tira de LEDS: De moment només he posat un LED no se com fer una tira??
 digitalWrite(LED, HIGH);
 delay(500);
 digitalWrite(LED, LOW);
 delay(500);
}
void setState()
{
  // PRE: Res
  // POS: Actualizar las entradas y saldias del arduino

  if(LIMITADOR_ON == true)
    parpadea();
}

void loop() {
  // put your main code here, to run repeatedly:
  while(len(bufferCAN) > 0)
  {
    readCAN_Msg();
    getTime();
    guardarSD();
    processCAN_Msg();
  }
  setState();
}
