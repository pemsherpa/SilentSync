const int w1 = 27; // Assuming the IR sensor is connected to pin A0
const int f1 = 14;
const int w2 = 25;
const int f2 = 26;
const int w3 = A4;
const int f3 = A5;
const int w4 = A6;
const int f4 = A7;
const int w5 = A0;
const int f5 = A3;

void setup() {
  Serial.begin(9600);
  pinMode(w1, INPUT); // Set the IR sensor pin as an input
  pinMode(f1, INPUT);
  pinMode(w2, INPUT);
  pinMode(f2, INPUT);
  pinMode(w3, INPUT); 
  pinMode(f3, INPUT);
  pinMode(w4, INPUT);
  pinMode(f4, INPUT);
  pinMode(w5, INPUT); 
  pinMode(f5, INPUT);
}

void loop() {
  int w1_val, f1_val, w2_val, f2_val, w3_val, f3_val, w4_val, f4_val, w5_val, f5_val;
  int thumb,index,middle,ring,pinky;
  //Thumb
  // Serial.print("\nThumb::\n");
  w1_val = analogRead(w1); // Read analog value from the IR sensor pin
  // Serial.print("wrist 1::");
  // Serial.println(w1_val);
  // Serial.print("finger 1::");
  f1_val = analogRead(f1);
  // Serial.println(f1_val);

  if ((w1_val>=100 && w1_val<=130)&&(f1_val>=95 && f1_val<=115))
  {
    // Serial.print("Finger is straight::");
    thumb = 0;

  }
  else if((w1_val>=120 && w1_val<=150)&&(f1>=0 && f1<=0))
  {
    // Serial.print("Finger is half bent");
    thumb = 1;
  }
  else if((w1_val>=110 && w1_val<=125)&&(f1>=0 && f1<=0))
  {
    // Serial.print("Finger is hook");
    thumb = 2;
  }
  else
  {
    // Serial.print("fist");
    thumb = 3;
  }
  



  //Index finger
  // Serial.print("\nIndex finger::\n");
  w2_val = analogRead(w2); // Read analog value from the IR sensor pin
  // Serial.print("wrist 2::");
  // Serial.println(w2_val);
  // Serial.print("finger 2::");
  f2_val = analogRead(f2);
  // Serial.println(f2_val);

  if ((w2_val>=350 && w2_val<=545)&&(f2_val>= 50 && f2_val<= 80))//use value for finger
  {
    // Serial.print("Finger is straight::");
    index = 0;

  }
  else if((w2_val>=210 && w2_val<=310)&&(f2_val>=60 && f2_val<=80))
  {
    // Serial.print("Finger is half bent");
    index = 1;
  }
  else if((w2_val>=600 && w2_val<=730)&&(f2_val>=120 && f2_val<=270))
  {
    // Serial.print("Finger is hook");
    index = 2;
  }
  else
  {
    // Serial.print("fist");
    index = 3;
  }

  //Middle finger
  // Serial.print("\nMiddle Finger::\n");
  w3_val = analogRead(w3); // Read analog value from the IR sensor pin
  // Serial.print("wrist 3::");
  // Serial.println(w3_val);
  // Serial.print("finger 3::");
  f3_val = analogRead(f3);
  // Serial.println(f3_val);

  if ((w3_val>=790 && w3_val<=2310)&&(f3_val>=150 && f3_val<=360))
  {
    //Serial.print("Finger is straight::");
    middle = 0;

  }
  else if((w3_val>=2120 && w3_val<=2300)&&(f3_val>=140 && f3_val<=180))
  {
    //Serial.print("Finger is half bent");
    middle = 1;
  }
  else if((w3_val>=2220 && w3_val<=2360)&&(f3_val>=600 && f3_val<=730))
  {
    //Serial.print("Finger is hook");
    middle = 2;
  }
  else
  {
    //Serial.print("fist");
    middle = 3;
  }

  // Ring finger
  // Serial.print("\nRing finger::\n");
  w4_val = analogRead(w4); // Read analog value from the IR sensor pin
  // Serial.print("wrist 4::");
  // Serial.println(w4_val);
  // Serial.print("finger 4::");
  f4_val = analogRead(f4);
  // Serial.println(f4_val);
  
  if ((w4_val>=2700 && w4_val<=3000)&&(f4_val>=70 && f4_val<=90))
  {
    //Serial.print("Finger is straight::");
    ring = 0;

  }
  else if((w4_val>=2170 && w4_val<= 3270)&&(f4>=70 && f4<=90))
  {
    //Serial.print("Finger is half bent");
    ring = 1;
  }
  else if((w4_val>=3250 && w4_val<= 3330)&&(f4>=2200 && f4<=2450))
  {
    //Serial.print("Finger is hook");
    ring = 2;
  }
  else
  {
    //Serial.print("fist");
    ring = 3;
  }


  //Pinky finger
  // Serial.print("\nPinky Finger::\n");
  w5_val = analogRead(w5); // Read analog value from the IR sensor pin
  // Serial.print("wrist 5::");
  // Serial.println(w5_val);
  // Serial.print("finger 5::");
  f5_val = analogRead(f5);
  // Serial.println(f5_val);

 if ((w5_val>=100 && w5_val<=160)&&(f5_val>=0 && f5_val<=16))
  {
    // Serial.print("Finger is straight::");
    pinky = 0;

 }
  else if((w5_val>=90 && w5_val<=120)&&(f5_val>=0 && f5_val<=15))
  {
    //Serial.print("Finger is half bent");
    pinky = 1;
  }
  else if((w5_val>=90 && w5_val<=110)&&(f5_val>=1400 && f5_val<=1600))
  {
    //Serial.print("Finger is hook");
    pinky = 2;
  }
  else
  {
   //Serial.print("fist");
   pinky = 3;
  }


  // Alphabets start
  if (thumb == 0 && index == 3 && middle == 3 && ring == 3 && pinky == 3)
  {
      Serial.print("a");
  }
  else if (thumb == 3 && index == 0 && middle == 0 && ring == 0 && pinky == 0)
  {
      Serial.print("b");
  }
  else if (thumb == 2 && index == 2 && middle == 2 && ring == 2 && pinky == 2)
  {
      Serial.print("c");
  }
  else if (thumb == 3 && index == 0 && middle == 3 && ring == 3 && pinky == 3)
  {
      Serial.print("d");
  }
  else if (thumb == 3 && index == 2 && middle == 2 && ring == 2 && pinky == 2)
  {
      Serial.print("e");
  }
  else if (thumb == 3 && index == 3 && middle == 0 && ring == 0 && pinky == 0)
  {
      Serial.print("f");
  }
  else if (thumb == 0 && index == 1 && middle == 3 && ring == 3 && pinky == 3)
  {
      Serial.print("g");
  }
  else if (thumb == 3 && index == 0 && middle == 0 && ring == 3 && pinky == 3)
  {
      Serial.print("h");
  }
  else if (thumb == 3 && index == 3 && middle == 3 && ring == 3 && pinky == 0)
  {
      Serial.print("i");
  }
  // else if (thumb == 0 && index == 1 && middle == 1 && ring == 1 && pinky == 0)
  // {
  //     Serial.print("j");
  // }
  else if (thumb == 0 && index == 0 && middle == 0 && ring == 3 && pinky == 3)
  {
      Serial.print("k");
  }
  else if (thumb == 0 && index == 0 && middle == 3 && ring == 3 && pinky == 3)
  {
      Serial.print("l");
  }
  // else if (thumb == 1 && index == 0 && middle == 1 && ring == 1 && pinky == 0)
  // {
  //     Serial.print("m");
  // }
  // else if (thumb == 1 && index == 1 && middle == 0 && ring == 0 && pinky == 1)
  // {
  //     Serial.print("n");
  // }
  else if (thumb == 3 && index == 3 && middle == 3 && ring == 3 && pinky == 3)
  {
      Serial.print("o");
  }
  else if (thumb == 0 && index == 1 && middle == 2 && ring == 3 && pinky == 3)
  {
      Serial.print("p");
  }
  // else if (thumb == 0 && index == 0 && middle == 0 && ring == 1 && pinky == 1)
  // {
  //     Serial.print("q");
  // }
  // else if (thumb == 0 && index == 0 && middle == 1 && ring == 0 && pinky == 1)
  // {
  //     Serial.print("r");
  // }
  else if (thumb == 2 && index == 3 && middle == 3 && ring == 3 && pinky == 3)
  {
      Serial.print("s");
  }
  // else if (thumb ==  && index == 1 && middle == 0 && ring == 0 && pinky == 1)
  // {
  //     Serial.print("t");
  // }
  // else if (thumb == 0 && index == 1 && middle == 0 && ring == 1 && pinky == 0)
  // {
  //     Serial.print("u");
  // }
  else if (thumb == 3 && index == 0 && middle == 3 && ring == 3 && pinky == 3)
  {
      Serial.print("v");
  }
  else if (thumb == 1 && index == 0 && middle == 3 && ring == 3 && pinky == 3)
  {
      Serial.print("w");
  }
  else if (thumb == 3 && index == 2 && middle == 3 && ring == 3 && pinky == 3)
  {
      Serial.print("x");
  }
  else if (thumb == 0 && index == 3 && middle == 3 && ring == 3 && pinky == 0)
  {
      Serial.print("y");
  }
  // else if (thumb == 0 && index == 1 && middle == 0 && ring == 0 && pinky == 0)
  // {
  //     Serial.print("z");
  // }

  else if (thumb == 3 && index == 0 && middle == 0 && ring == 0 && pinky == 0)
  {
    if (thumb == 3 && index == 3 && middle == 3 && ring == 3 && pinky == 3)
    {
      if(thumb == 3 && index == 0 && middle == 0 && ring == 0 && pinky == 0)
      {
        Serial.print("SOS");
      }
    }
  }








  delay(3000);
}
