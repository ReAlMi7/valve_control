void buttonControl(){
  if (setH.isClick()){prOK = data.prH;sysTray = "Необходимо подтверждение";drawScreen();}
  if (setH.isHolded()){data.prH = prOK; EEPROM.put(0, data); drawScreen();}

  if (setB.isClick()){prOK = data.prB;sysTray = "Необходимо подтверждение";drawScreen();}
  if (setB.isHolded()){data.prB = prOK; EEPROM.put(0, data); drawScreen();}
}