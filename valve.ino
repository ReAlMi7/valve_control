void relayControl(){
if (offTime.onRestart()){
digitalWrite(relay, 1);
offTime.stop();
onTime.restart();
//Serial.println("offT restart, relay ON");
}
if (onTime.onRestart()){
digitalWrite(relay, 0); 
onTime.stop();
offTime.restart();
//Serial.println("onT restart, relay OF");
}
}

void setTime(){
  onTime.setTimeout(prOK*10*period);
  offTime.setTimeout((period * 1000) - (prOK*10*period));
 // Serial.println("onTime " + String(onTime.getTimeout()));
 // Serial.println("offTime " + String(offTime.getTimeout()));
  if (onTime.getTimeout() > dTime) {
    if (!digitalRead(relay)) {onTime.restart();digitalWrite(relay, 1);}
    else offTime.restart();
    }
  else {offTime.stop(); onTime.stop(); digitalWrite(relay, 0);}
}