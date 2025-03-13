void checkEnc(){
  if (enc1.isRight()) {
    Serial.println("Right");
   if (prOK < 100)  prOK++;
   sysTray = "Необходимо подтверждение";
   drawScreen();
  }  

  if (enc1.isLeft())  { Serial.println("Left");
   if (prOK > 0)  prOK--;
   sysTray = "Необходимо подтверждение";
   drawScreen();
  }  
   
 if (enc1.isClick()) {
   sysTray = "Процент открытия";
   setTime();
   drawScreen();
  }  

  if (enc1.isRightH() && prOK < 90) {prOK += 10; Serial.println("Fast Right");drawScreen();}
  if (enc1.isLeftH() && prOK > 10) {prOK -= 10; Serial.println("Fast Left");drawScreen();} 
}