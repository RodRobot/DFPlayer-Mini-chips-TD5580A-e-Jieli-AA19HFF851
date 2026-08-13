/*
===========================================================
  Projeto : ESP32 + DFPlayer Mini
  Função  : Reproduzir 4 mensagens MP3 com 4 botões
  Autor   : RodRobot
===========================================================

Ligação dos botões
------------------
GPIO18 -> Botão 1
GPIO19 -> Botão 2
GPIO21 -> Botão 3
GPIO23 -> Botão 4

Cada botão deve ser ligado ao GND.
Será utilizado INPUT_PULLUP.

Ligação do DFPlayer Mini
------------------------
ESP32 TX (GPIO17) -> RX DFPlayer
ESP32 RX (GPIO16) -> TX DFPlayer
5V -> VCC
GND -> GND

Arquivos no cartão SD
---------------------
0001.mp3
0002.mp3
0003.mp3
0004.mp3
*/

#include <HardwareSerial.h>
#include <DFRobotDFPlayerMini.h>

HardwareSerial mp3Serial(2);          // UART2 do ESP32
DFRobotDFPlayerMini player;

//-------------------------
// Pinos dos botões
//-------------------------
const int botao1 = 18;    // Mensagem 1
const int botao2 = 19;    // Mensagem 2
const int botao3 = 21;    // Mensagem 3
const int botao4 = 23;    // Mensagem 4

void setup()
{
  Serial.begin(115200);                               // Monitor Serial

  pinMode(botao1, INPUT_PULLUP);                      // Botão 1
  pinMode(botao2, INPUT_PULLUP);                      // Botão 2
  pinMode(botao3, INPUT_PULLUP);                      // Botão 3
  pinMode(botao4, INPUT_PULLUP);                      // Botão 4

  mp3Serial.begin(9600, SERIAL_8N1, 16, 17);          // RX=16 TX=17

  if (!player.begin(mp3Serial))
  {
    Serial.println("Erro ao encontrar DFPlayer!");
    while (true);
  }

  player.volume(20);                                  // Volume (0 a 30)

  Serial.println("Sistema pronto.");
}

void loop()
{
  if (digitalRead(botao1) == LOW)                     // Botão 1 pressionado
  {
    player.play(1);                                   // Toca 0001.mp3
    Serial.println("Mensagem 1");
    delay(300);                                       // Debounce
  }

  if (digitalRead(botao2) == LOW)                     // Botão 2 pressionado
  {
    player.play(2);                                   // Toca 0002.mp3
    Serial.println("Mensagem 2");
    delay(300);                                       // Debounce
  }

  if (digitalRead(botao3) == LOW)                     // Botão 3 pressionado
  {
    player.play(3);                                   // Toca 0003.mp3
    Serial.println("Mensagem 3");
    delay(300);                                       // Debounce
  }

  if (digitalRead(botao4) == LOW)                     // Botão 4 pressionado
  {
    player.play(4);                                   // Toca 0004.mp3
    Serial.println("Mensagem 4");
    delay(300);                                       // Debounce
  }
}