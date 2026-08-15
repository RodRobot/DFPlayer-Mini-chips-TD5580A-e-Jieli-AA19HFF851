# ESP32 + DFPlayer Mini – 4 Mensagens de Áudio MP3

Projeto utilizando **ESP32 + DFPlayer Mini + cartão microSD** para reproduzir quatro mensagens de áudio através de quatro botões mecânicos.

O projeto foi desenvolvido para demonstrar uma forma simples de reproduzir arquivos MP3 utilizando o ESP32 sem precisar converter os áudios para arrays e armazená-los na memória do microcontrolador.

---

## 🎯 Objetivo

Reproduzir quatro mensagens de áudio armazenadas em um cartão microSD.

Cada botão aciona uma mensagem diferente:

| Botão | GPIO ESP32 | Arquivo |
|---|---:|---|
| Botão 1 | GPIO 18 | `0001.mp3` |
| Botão 2 | GPIO 19 | `0002.mp3` |
| Botão 3 | GPIO 21 | `0003.mp3` |
| Botão 4 | GPIO 23 | `0004.mp3` |

---

## 🔊 Como funciona

O ESP32 não precisa processar diretamente o arquivo MP3.

Ele envia comandos para o DFPlayer Mini através da comunicação serial UART.

O DFPlayer:

1. Lê o arquivo no cartão microSD;
2. Decodifica o MP3;
3. Converte o áudio digital para analógico através do seu circuito de áudio interno;
4. Envia o sinal de áudio para a saída;
5. O sinal pode ser conectado a um amplificador e alto-falante.

### Fluxo do projeto

ESP32  
↓  
UART  
↓  
DFPlayer Mini  
↓  
Cartão microSD  
↓  
Decodificação MP3  
↓  
DAC  
↓  
Saída de áudio  
↓  
Amplificador  
↓  
Alto-falante

---

# 🧩 Componentes

- ESP32 DevKit
- DFPlayer Mini
- Cartão microSD
- 4 botões mecânicos
- Alto-falante
- Amplificador de áudio (opcional)
- Cabos jumper

---

# 🔌 Ligações

## DFPlayer Mini

| ESP32 | DFPlayer Mini |
|---|---|
| GPIO 17 (TX) | RX |
| GPIO 16 (RX) | TX |
| GND | GND |
| 5V | VCC |

> TX e RX devem ser ligados de forma cruzada.

### Comunicação UART

```text
ESP32 GPIO17 TX ───────> RX DFPlayer
ESP32 GPIO16 RX <─────── TX DFPlayer
ESP32 GND        ─────── GND

💾 Arquivos MP3

Os arquivos devem ser armazenados no cartão microSD.

Neste projeto:

0001.mp3
0002.mp3
0003.mp3
0004.mp3

Exemplo:

0001.mp3 → Sensor garagem
0002.mp3 → Sensor porta
0003.mp3 → Temperatura 30 graus
0004.mp3 → Aguarde um momento

O nome utilizado pelo programa é o número da faixa.

O texto da mensagem não precisa estar no nome do arquivo.

📚 Biblioteca utilizada

Neste projeto foi utilizada:

DFPlayerMini_Fast

A biblioteca foi escolhida após testes realizados com diferentes módulos DFPlayer Mini.

⚠️ Compatibilidade entre chips

Durante o desenvolvimento foram testados dois módulos DFPlayer Mini com chips diferentes.

Módulo com chip TD5580A

Funcionou utilizando:

DFRobotDFPlayerMini
Módulo com chip Jieli AA19HFF851

Funcionou utilizando:

DFPlayerMini_Fast
Resultado dos testes
Chip	              Biblioteca	               Resultado
TD5580A	              DFRobotDFPlayerMini	      ✅ Funcionou
Jieli AA19HFF851	  DFRobotDFPlayerMini	      ❌ Não funcionou corretamente
Jieli AA19HFF851	     DFPlayerMini_Fast	        ✅ Funcionou

Isso demonstra que módulos comercializados como DFPlayer Mini podem utilizar chips diferentes e apresentar diferenças de compatibilidade com determinadas bibliotecas.

Se o seu DFPlayer não funcionar com uma biblioteca, verifique o chip utilizado no módulo e teste outra biblioteca compatível.

🎵 Por que utilizar MP3?

Uma das grandes vantagens do DFPlayer Mini é que os arquivos podem permanecer no cartão microSD em formato MP3.

Não é necessário:

Converter o MP3 para WAV;
Transformar o áudio em array;
Colocar o áudio dentro do código;
Ocupar a memória do ESP32 com os dados das mensagens.

O ESP32 apenas envia o comando para o DFPlayer reproduzir determinada faixa.

Isso permite utilizar muitos arquivos de áudio, dependendo da capacidade do cartão e da organização dos arquivos.

🔊 DFPlayer Mini também possui DAC

O DFPlayer Mini é um dispositivo de áudio externo ao ESP32.

Além de ler e decodificar os arquivos MP3, ele possui internamente o circuito responsável pela conversão do áudio digital para um sinal analógico.

Por isso, podemos considerar o DFPlayer uma solução completa para reprodução de áudio:

MP3
 ↓
DFPlayer Mini
 ↓
Decodificação
 ↓
DAC
 ↓
Áudio analógico
 ↓
Amplificador
 ↓
Alto-falante
⚖️ DFPlayer Mini x UDA1334A

O DFPlayer Mini e o UDA1334A podem ser utilizados em projetos de áudio com ESP32, mas possuem propostas diferentes.

Característica	DFPlayer Mini	UDA1334A
Cartão microSD	✅	Depende do projeto
Reprodução MP3	✅	Depende do software
Decodificação MP3	Interna	ESP32/software
DAC	Interno	Externo
Comunicação	UART	I²S
Facilidade	⭐⭐⭐⭐⭐	⭐⭐⭐
Flexibilidade de áudio	⭐⭐⭐	⭐⭐⭐⭐⭐
Melhor para mensagens	✅	Pode ser utilizado
Melhor para estudar I²S	❌	✅
Processamento de áudio pelo ESP32	Baixo	Maior
DFPlayer Mini

Ideal quando o objetivo é:

Reproduzir mensagens;
Reproduzir MP3;
Criar alarmes;
Criar avisos sonoros;
Projetos com robôs;
Campainhas;
Projetos simples e práticos.
UDA1334A

Ideal quando o objetivo é:

Trabalhar com I²S;
Estudar áudio digital;
Utilizar um DAC externo;
Ter maior controle sobre o fluxo de áudio;
Desenvolver projetos de áudio com o ESP32.
🧠 O que este projeto demonstra?

Este projeto demonstra:

Comunicação UART com ESP32;
Controle do DFPlayer Mini;
Reprodução de arquivos MP3;
Utilização de cartão microSD;
Uso de INPUT_PULLUP;
Leitura de botões mecânicos;
Controle de áudio através de comandos;
Utilização de DAC externo ao ESP32;
Diferenças de compatibilidade entre chips e bibliotecas.
📁 Estrutura sugerida do projeto
ESP32-DFPlayer-4-Mensagens/
│
├── codigo/
│   └── ESP32_DFPlayer_4_Mensagens.ino
│
├── imagens/
│   └── montagem.jpg
│
├── README.md
│
└── LICENSE
🚀 Funcionamento

Ao pressionar um botão, o ESP32 envia o comando correspondente ao DFPlayer.

Botão 1 → GPIO18 → 0001.mp3
Botão 2 → GPIO19 → 0002.mp3
Botão 3 → GPIO21 → 0003.mp3
Botão 4 → GPIO23 → 0004.mp3

O DFPlayer realiza a reprodução diretamente do cartão microSD.

📺 Vídeo do projeto

Projeto apresentado no canal RodRobot.

🔗 YouTube:
https://www.youtube.com/

🌐 Projeto RodRobot

🔧 Eletrônica para Makers
🤖 Projetos práticos
📡 Arduino | ESP32 | Raspberry Pi

Blog:
https://rodrobot.blogspot.com/

Projetos:
https://rodrobot.blogspot.com/p/projetos.html

📜 Licença

Este projeto é disponibilizado para fins educacionais.

Você pode utilizar, modificar e adaptar o código para seus próprios projetos.

Autor

RodRobot

🔧 Eletrônica para Makers
🤖 Projetos práticos com Arduino e ESP32
