void drawScreen(){
  oled.clear();
  //oled.flipV(true);
  //oled.flipH(true);
  oled.setScale(1);
  oled.setCursorXY(15, 0); oled.print(sysTray);
  oled.setCursorXY(0, 22); oled.print(/*"Г " + */String(data.prH));
  oled.setCursorXY(0, 52); oled.print(/*"Т " + */String(data.prB));
//  oled.setCursorXY(98, 22); oled.print(/*"Off " + */String(data.tOff));
//  oled.setCursorXY(98, 37); oled.print(/*"Cur " + */String(tC)); 
//  oled.setCursorXY(98, 52); oled.print(/*"On  " + */String(data.tOn));
  oled.setScale(3);
  if (prOK < 10)   oled.setCursorXY(50, 30);
  if (prOK > 9 && prOK < 100)   oled.setCursorXY(40, 30);
  if (prOK > 99) oled.setCursorXY(30, 30); 
  oled.print(prOK);
  oled.update();
}