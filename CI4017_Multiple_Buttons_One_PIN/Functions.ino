
void releasePulses() {
  /*
     Cria os pulsos de ALTO e BAIXO para ativar o clock do CI 4017.
  */

  if (millis() - actualTimePulse >= delayBetweenPulses) { //Alterar variável "delayBetweenPulses" para alterar a frequencia dos pulsos.
    if (highLowCounter % 2 == 0) {
      digitalWrite(pinOutputPulse, 1);
      buttonCounter++;
    } else {
      digitalWrite(pinOutputPulse, 0);
    }
    highLowCounter++;
    actualTimePulse = millis();
    if (buttonCounter >= buttonsAmmount + 1) {
      buttonCounter = 0;
    }
  }
}

void testInputs() {
  /*
     Analisa os pulsos recebidos para saber qual botão foi pressionado, e a partir disto,
     gera as funcionalidades desejadas.

     Para adicionar botões, basta criar mais "cases" para cada um, e dentro deles, adicionar
     qual ação será executada. O programa aceita até 10 botões para cada CI 4017,
     é necessário somente alterar a quantidade de botões, na variável "buttonsAmmount".
  */

  if (inputState == 0) {
    releasePulses();
  } else { //Adicionar ou remover os botões, além de definir cada ação a ser executada.
    switch (buttonCounter) {
      case 1:
        Serial.println("B1");
        break;
      case 2:
        Serial.println("B2");
        break;
      case 3:
        Serial.println("B3");
        break;
      case 4:
        Serial.println("B4");
        break;
    }
  }
}
