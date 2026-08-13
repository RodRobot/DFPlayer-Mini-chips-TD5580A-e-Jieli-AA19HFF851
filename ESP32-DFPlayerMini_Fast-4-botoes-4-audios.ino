/*
===========================================================
  Projeto : ESP32 + DFPlayer Mini
  Função  : Reproduzir 4 mensagens MP3 com 4 botões
  Biblioteca: DFPlayerMini_Fast
  Chip DFPlayer: Jieli AA19HFF851

  Autor: RodRobot

  BOTÕES
  GPIO18 -> Botão 1
  GPIO19 -> Botão 2
  GPIO21 -> Botão 3
  GPIO23 -> Botão 4

  DFPLAYER MINI
  GPIO16 -> RX do ESP32
  GPIO17 -> TX do ESP32

  ARQUIVOS NO CARTÃO SD
  0001.mp3 -> Mensagem 1
  0002.mp3 -> Mensagem 2
  0003.mp3 -> Mensagem 3
  0004.mp3 -> Mensagem 4

  Os botões utilizam o resistor PULL-UP interno
  do ESP32 e devem ser ligados ao GND.
===========================================================
*/

#include <HardwareSerial.h>                 // Comunicação UART
#include <DFPlayerMini_Fast.h>              // Biblioteca DFPlayer

//===========================================================
// UART utilizada pelo DFPlayer
//===========================================================

HardwareSerial mp3Serial(2);                // UART2 do ESP32
DFPlayerMini_Fast player;                   // Objeto DFPlayer


//===========================================================
// Pinos dos botões
//===========================================================

const int BOTAO1 = 18;                      // Botão 1
const int BOTAO2 = 19;                      // Botão 2
const int BOTAO3 = 21;                      // Botão 3
const int BOTAO4 = 23;                      // Botão 4


//===========================================================
// Pinos da comunicação com o DFPlayer
//===========================================================

const int DFPLAYER_RX = 16;                 // RX do ESP32
const int DFPLAYER_TX = 17;                 // TX do ESP32


//===========================================================
// Configuração inicial
//===========================================================

void setup()
{
  Serial.begin(115200);                     // Monitor Serial

  // Configura os botões com PULL-UP interno
  pinMode(BOTAO1, INPUT_PULLUP);            // Botão 1
  pinMode(BOTAO2, INPUT_PULLUP);            // Botão 2
  pinMode(BOTAO3, INPUT_PULLUP);            // Botão 3
  pinMode(BOTAO4, INPUT_PULLUP);            // Botão 4

  // Inicializa a comunicação UART com o DFPlayer
  mp3Serial.begin(
    9600,                                   // Velocidade
    SERIAL_8N1,                             // Formato serial
    DFPLAYER_RX,                            // RX
    DFPLAYER_TX                             // TX
  );

  delay(1000);                              // Aguarda o DFPlayer

  player.begin(mp3Serial);                  // Inicia o DFPlayer

  player.volume(20);                        // Volume de 0 a 30 -> maximo que suporta no teste foi 20

  Serial.println("DFPlayer iniciado!");
  Serial.println("Sistema pronto.");
}


//===========================================================
// Loop principal
//===========================================================

void loop()
{
  //=========================================================
  // Botão 1
  //=========================================================

  if (digitalRead(BOTAO1) == LOW)           // Botão pressionado
  {
    player.play(1);                         // Reproduz 0001.mp3

    Serial.println("Botao 1 -> 0001.mp3");

    delay(300);                             // Debounce
  }


  //=========================================================
  // Botão 2
  //=========================================================

  if (digitalRead(BOTAO2) == LOW)           // Botão pressionado
  {
    player.play(2);                         // Reproduz 0002.mp3

    Serial.println("Botao 2 -> 0002.mp3");

    delay(300);                             // Debounce
  }


  //=========================================================
  // Botão 3
  //=========================================================

  if (digitalRead(BOTAO3) == LOW)           // Botão pressionado
  {
    player.play(3);                         // Reproduz 0003.mp3

    Serial.println("Botao 3 -> 0003.mp3");

    delay(300);                             // Debounce
  }


  //=========================================================
  // Botão 4
  //=========================================================

  if (digitalRead(BOTAO4) == LOW)           // Botão pressionado
  {
    player.play(4);                         // Reproduz 0004.mp3

    Serial.println("Botao 4 -> 0004.mp3");

    delay(300);                             // Debounce
  }
}