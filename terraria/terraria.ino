
const int analogs[] = {30, 30};
const int tempo[] = {500, 500};
const byte analogPorts[] = {0, 1};
const byte mOUT[][2] = {{7,8},{9, 10},{11, 12}};

void setup() {
  
  for(int a = 0; a < sizeof(mOUT); a++){
    for(int b = 0; b < 2; b++){
      pinMode(mOUT[a][b], OUTPUT);
    }
  }

}

void loop() {
  static byte estado = 0;
  ligarTimer(false, 1);
  for(int a = 0 ; a < 2 ; a++){
    if(analogRead(analogPorts[a]) < analogs[a])
      ligarTimer(true, a);
    else
      ligarTimer(false, a);
  }  
}

void ligarTimer(bool act, byte inst){

  static long t0[2];
  long tatual = millis();
  if(act){
    t0[inst] = millis();
    digitalWrite(mOUT[inst][0], HIGH);
    digitalWrite(mOUT[inst][1], LOW);  
  }else{
    if(t0[inst] - tatual >= tempo[inst]){
      digitalWrite(mOUT[inst][0], LOW);
      digitalWrite(mOUT[inst][1], HIGH);    
    }
  }
}

