# Marcador de padel arduino

## Codigo para subir a WemosD1 mini, para montar un marcador de padel sencillo

> El marcador consta de una pantalla matrix de 16x32 controlada con registros de deplazamientos max7219.  Conectada a las pines D7 D6 D5

1. Conexiones Display matrix
    * D7 -> DIN
    * D6 -> CS
    * D5 -> CLK

> La primera fase del proyecto, el control de los puntos se hace mediante switches con la idea de poder mejorar, estos switches generan una interrupcion a los pines 

# Interrupciones
1. Tipos de interrupciones
    * **LOW**, La interrupción se dispara cuando el pin es LOW.
    * **CHANGE**, Se dispara cuando pase de HIGH a LOW o viceversa.
    * **RISING**, Dispara en el flanco de subida (Cuando pasa de LOW a HIGH).
    * **FALLING**, Dispara en el flanco de bajada (Cuando pasa de HIGH a LOW).
    * **HIGH**, se dispara cuando el pin esta HIGH.

## D1 miniPinOut

|Pin | Function | ESP-8266 Pin | 
|-|-|-|
|TX		|TXD			|TXD                                  |
|RX		|RXD		|RXD                                      |
|A0		|Analog input, max 3.2V	|A0                           |
|D0		|IO	|GPIO16                                           |
|D1		|IO, SCL	|GPIO5                                    |
|D2		|IO, SDA	|GPIO4                                    |
|D3		|IO, 10k Pull-up	|GPIO0                            |
|D4		|IO, 10k Pull-up, BUILTIN_LED	|GPIO2                |
|D5		|IO, SCK	|GPIO14                                   |
|D6		|IO, MISO	|GPIO12                                   |
|D7		|IO, MOSI	|GPIO13                                   |
|D8		|IO, 10k Pull-down, SS	|GPIO15                       |
|G		|Ground	|GND                                          |
|5V		|5V	|-                                                |
|3V3	|3.3V	|3.3V                                         |
|RST	|Reset	|RST                                          |
															  