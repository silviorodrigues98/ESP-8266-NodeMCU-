int buttonsAmmount = 4; //Quantidade de botões a ser utilizada.

/*DEFINA AQUI OS PINOS DE ENTRADA E SAÍDA*/
#define pinOutputPulse 4  //D2
#define pinInputPulse 5  //D1
/*DEFINA AQUI OS PINOS DE ENTRADA E SAÍDA*/

/*----------NÃO ALTERAR------------------*/
unsigned long actualTimePulse;
int inputState;
int buttonCounter;
unsigned long highLowCounter = 2;
int delayBetweenPulses = 15; //Tempo de espera entre os pulsos, em mS.
/*----------NÃO ALTERAR------------------*/

void setup() {
  Serial.begin(115200);
  pinMode(pinOutputPulse, OUTPUT);
  pinMode(pinInputPulse, INPUT);
  //releasePulses();
}

void loop() {
  inputState = digitalRead(pinInputPulse);
  testInputs();
}
