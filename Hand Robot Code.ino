#include <Servo.h>

#include <cvzone.h>
SerialData serialData(1,2);

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

Servo Pitch;
Servo Roll;
Servo Little;
Servo Ring;
Servo Middle;
Servo Index;
Servo Thumb;

int RollAngle=90, RollAngleMin=0, RollAngleMax=180,
    PitchAngle=170, PitchAngleMin=170, PitchAngleMax=0,
    LittleAngle=30, LittleAngleMin=30, LittleAngleMax=150,
    RingAngle=30, RingAngleMin=30, RingAngleMax=170,
    MiddleAngle=15, MiddleAngleMin=15, MiddleAngleMax=175,
    IndexAngle=180, IndexAngleMin=180, IndexAngleMax=0,
    ThumbAngle=170, ThumbAngleMin=170, ThumbAngleMax=10,
    counter, valsRec[1],
    Delay=4;

#define PitchRelatedAngle 3
char Reading;

void setup() 
{serialData.begin();

 Little.attach(6); 
 Ring.attach(9);
 Middle.attach(11);
 Index.attach(12);
 Thumb.attach(13);
 Roll.attach(3);
 Pitch.attach(5);
   
 Little.write(LittleAngle);
 Ring.write(RingAngle);
 Middle.write(MiddleAngle);
 Index.write(IndexAngle);
 Thumb.write(ThumbAngle);
 Roll.write(RollAngle);
 Pitch.write(PitchAngle);
 delay(500);

lcd.init();
lcd.backlight();
lcd.print("     SMART");
lcd.setCursor(2,2);
lcd.print("TECHNOLOGY");

 }

void DefaultAngles()
{Roll.write(90);
 Pitch.write(PitchAngleMin);
 Little.write(LittleAngleMin);
 Ring.write(RingAngleMin);
 Middle.write(MiddleAngleMin);
 Index.write(IndexAngleMin);
 Thumb.write(ThumbAngleMin);
 delay(500);
 }


void RollLeft()
{for (counter=0; counter<=10; counter+=1)
    {if(RollAngle!=RollAngleMax)
      {RollAngle+=1;
       RollAngle=constrain(RollAngle,RollAngleMin,RollAngleMax);
       Roll.write(RollAngle);
       delay(Delay);
       }
     }
 }

void RollRight()
{for (counter=0; counter<=10; counter+=1)
    {if(RollAngle!=RollAngleMin)
      {RollAngle-=1;
       RollAngle=constrain(RollAngle,RollAngleMin,RollAngleMax);
       Roll.write(RollAngle);
       delay(Delay);
       }
     }
 }


void PitchUp()
{for (counter=0; counter<=10; counter+=1)
   {PitchAngle+=1;
    PitchAngle=constrain(PitchAngle,PitchAngleMax,PitchAngleMin);
    Pitch.write(PitchAngle);
    delay(Delay);
    }
 if (PitchAngle != PitchAngleMin)
   {LittleAngle-=(PitchRelatedAngle-1);
    LittleAngle=constrain(LittleAngle,LittleAngleMin,LittleAngleMax);
    Little.write(LittleAngle);

    RingAngle-=PitchRelatedAngle;
    RingAngle=constrain(RingAngle,RingAngleMin,RingAngleMax);
    Ring.write(RingAngle);

    MiddleAngle-=(PitchRelatedAngle+3);
    MiddleAngle=constrain(MiddleAngle,MiddleAngleMin,MiddleAngleMax);
    Middle.write(MiddleAngle);

    IndexAngle+=PitchRelatedAngle;
    IndexAngle=constrain(IndexAngle,IndexAngleMax,IndexAngleMin);
    Index.write(IndexAngle);

    ThumbAngle+=PitchRelatedAngle;
    ThumbAngle=constrain(ThumbAngle,ThumbAngleMax,ThumbAngleMin);
    Thumb.write(ThumbAngle);
   }
 }

void PitchDown()
{for (counter=0; counter<=10; counter+=1)
   {PitchAngle-=1;
    PitchAngle=constrain(PitchAngle,PitchAngleMax,PitchAngleMin);
    Pitch.write(PitchAngle);
    delay(Delay);
    }
 if (PitchAngle != PitchAngleMax)
   {LittleAngle+=(PitchRelatedAngle-1);
    LittleAngle=constrain(LittleAngle,LittleAngleMin,LittleAngleMax);
    Little.write(LittleAngle);

    RingAngle+=PitchRelatedAngle;
    RingAngle=constrain(RingAngle,RingAngleMin,RingAngleMax);
    Ring.write(RingAngle);

    MiddleAngle+=(PitchRelatedAngle+3);
    MiddleAngle=constrain(MiddleAngle,MiddleAngleMin,MiddleAngleMax);
    Middle.write(MiddleAngle);

    IndexAngle-=PitchRelatedAngle;
    IndexAngle=constrain(IndexAngle,IndexAngleMax,IndexAngleMin);
    Index.write(IndexAngle);

    ThumbAngle-=PitchRelatedAngle;
    ThumbAngle=constrain(ThumbAngle,ThumbAngleMax,ThumbAngleMin);
    Thumb.write(ThumbAngle);
   }  
 }


void LittleUp()
{for (counter=0; counter<=10; counter+=1)
   {LittleAngle-=1;
    LittleAngle=constrain(LittleAngle,LittleAngleMin,LittleAngleMax);
    Little.write(LittleAngle);
    delay(Delay);
    }
 }
 
void LittleDown()
{for (counter=0; counter<=10; counter+=1)
   {LittleAngle+=1;
    LittleAngle=constrain(LittleAngle,LittleAngleMin,LittleAngleMax);
    Little.write(LittleAngle);
    delay(Delay);
    }
 }


void RingUp()
{for (counter=0; counter<=10; counter+=1)
   {RingAngle-=1;
    RingAngle=constrain(RingAngle,RingAngleMin,RingAngleMax);
    Ring.write(RingAngle);
    delay(Delay);
    }
 }

void RingDown()
{for (counter=0; counter<=10; counter+=1)
   {RingAngle+=1;
    RingAngle=constrain(RingAngle,RingAngleMin,RingAngleMax);
    Ring.write(RingAngle);
    delay(Delay);
    }
 }


void MiddleUp()
{for (counter=0; counter<=10; counter+=1)
   {MiddleAngle-=1;
    MiddleAngle=constrain(MiddleAngle,MiddleAngleMin,MiddleAngleMax);
    Middle.write(MiddleAngle);
    delay(Delay);
    }
 }

 void MiddleDown()
{for (counter=0; counter<=10; counter+=1)
   {MiddleAngle+=1;
    MiddleAngle=constrain(MiddleAngle,MiddleAngleMin,MiddleAngleMax);
    Middle.write(MiddleAngle);
    delay(Delay);
    }
 }


void IndexUp()
{for (counter=0; counter<=10; counter+=1)
   {IndexAngle+=1;
    IndexAngle=constrain(IndexAngle,IndexAngleMax,IndexAngleMin);
    Index.write(IndexAngle);
    delay(Delay);
    }
 }

void IndexDown()
{for (counter=0; counter<=10; counter+=1)
   {IndexAngle-=1;
    IndexAngle=constrain(IndexAngle,IndexAngleMax,IndexAngleMin);
    Index.write(IndexAngle);
    delay(Delay);
    }
 }


void ThumbUp()
{for (counter=0; counter<=10; counter+=1)
   {ThumbAngle+=1;
    ThumbAngle=constrain(ThumbAngle,ThumbAngleMax,ThumbAngleMin);
    Thumb.write(ThumbAngle);
    delay(Delay);
    }
 }

 void ThumbDown()
{for (counter=0; counter<=10; counter+=1)
   {ThumbAngle-=1;
    ThumbAngle=constrain(ThumbAngle,ThumbAngleMax,ThumbAngleMin);
    Thumb.write(ThumbAngle);
    delay(Delay);
    }
 }




void RollLeftMax()
{for (counter=0; counter<=100; counter+=1)
    {if(RollAngle!=RollAngleMax)
      {RollAngle+=1;
       RollAngle=constrain(RollAngle,RollAngleMin,RollAngleMax);
       Roll.write(RollAngle);
       delay(Delay);
       }
     }
 }

void RollRightMax()
{for (counter=0; counter<=100; counter+=1)
    {if(RollAngle!=RollAngleMin)
      {RollAngle-=1;
       RollAngle=constrain(RollAngle,RollAngleMin,RollAngleMax);
       Roll.write(RollAngle);
       delay(Delay);
       }
     }
 }


void PitchUpMax()
{for (counter=0; counter<=15; counter+=1)
 {if (PitchAngle != PitchAngleMin)
  {PitchUp();
   }
  }
 }

void PitchDownMax()
{for (counter=0; counter<=15; counter+=1)
 {if (PitchAngle != PitchAngleMax)
  {PitchDown();
   }
  }
 }

void LittleUpMax()
{for (counter=0; counter<=15; counter+=1)
 {if (LittleAngle != LittleAngleMin)
  {LittleUp();
   }
  }
 }

void LittleDownMax()
{for (counter=0; counter<=15; counter+=1)
 {if (LittleAngle != LittleAngleMax)
  {LittleDown();
   }
  }
 }

void RingUpMax()
{for (counter=0; counter<=15; counter+=1)
 {if (RingAngle != RingAngleMin)
  {RingUp();
   }
  }
 }

void RingDownMax()
{for (counter=0; counter<=15; counter+=1)
 {if (RingAngle != RingAngleMax)
  {RingDown();
   }
  }
 }

void MiddleUpMax()
{for (counter=0; counter<=25; counter+=1)
 {if (MiddleAngle != MiddleAngleMin)
  {MiddleUp();
   }
  }
 }

void MiddleDownMax()
{for (counter=0; counter<=25; counter+=1)
 {if (MiddleAngle != MiddleAngleMax)
  {MiddleDown();
   }
  }
 }

void IndexUpMax()
{for (counter=0; counter<=15; counter+=1)
 {if (IndexAngle != IndexAngleMin)
  {IndexUp();
   }
  }
 }

void IndexDownMax()
{for (counter=0; counter<=15; counter+=1)
 {if (IndexAngle != IndexAngleMax)
  {IndexDown();
   }
  }
 }

void ThumbUpMax()
{for (counter=0; counter<=30; counter+=1)
 {if (ThumbAngle != ThumbAngleMin)
  {ThumbUp();
   }
  }
 }

void ThumbDownMax()
{for (counter=0; counter<=30; counter+=1)
 {if (ThumbAngle != ThumbAngleMax)
  {ThumbDown();
   }
  }
 }





void Zero()
{Delay=Delay/1.5;
 LittleDownMax();
 RingDownMax();
 MiddleDownMax();
 IndexDownMax();
 ThumbDownMax();
 Delay=Delay*1.5;
 delay(500);
 }
 
void One()
{Delay=Delay/3;
 LittleDownMax();
 RingDownMax();
 MiddleDownMax();
 IndexUpMax();
 ThumbDownMax();
 Delay=Delay*3;
 delay(500);
 }

void Two()
{Delay=Delay/3;
 LittleDownMax();
 RingDownMax();
 MiddleUpMax();
 IndexUpMax();
 ThumbDownMax();
 Delay=Delay*3;
 delay(500);
 }

void Three()
{Delay=Delay/3;
 LittleDownMax();
 RingUpMax();
 MiddleUpMax();
 IndexUpMax();
 ThumbDownMax();
 Delay=Delay*3;
 delay(500);
 }

void Four()
{Delay=Delay/3;
 LittleUpMax();
 RingUpMax();
 MiddleUpMax();
 IndexUpMax();
 ThumbDownMax();
 Delay=Delay*3;
 delay(500);
 }

void Five()
{Delay=Delay/3;
 LittleUpMax();
 RingUpMax();
 MiddleUpMax();
 IndexUpMax();
 ThumbUpMax();
 Delay=Delay*3;
 delay(500);
 }

void OK()
{Delay=Delay/3;
 ThumbUpMax();
 LittleDownMax();
 RingDownMax();
 MiddleDownMax();
 IndexDownMax();
 ThumbUpMax();
 Delay=Delay*3;
 delay(500);
 }




void at()
{
 Little.attach(6); 
 Ring.attach(9);
 Middle.attach(11);
 Index.attach(12);
 Thumb.attach(13);
 Roll.attach(3);
 Pitch.attach(5);
 } 

void dt()
{
 Little.detach(); 
 Ring.detach();
 Middle.detach();
 Index.detach();
 Thumb.detach();
 Roll.detach();
 Pitch.detach(); 
 }







 
void loop() 
{

serialData.Get(valsRec);
if(valsRec[0]==1)  {Thumb.attach(13); ThumbUpMax();   lcd.clear(); lcd.print("Thumb Finger");lcd.setCursor(2,0);lcd.print("Up");}
if(valsRec[0]==2)  { Thumb.attach(13); ThumbDownMax();   lcd.clear(); lcd.print("Thumb Finger");lcd.setCursor(2,0);lcd.print("Down");}
if(valsRec[0]==3)   {Index.attach(12); IndexUpMax();   lcd.clear(); lcd.print("Index Finger");lcd.setCursor(2,0);lcd.print("Up");}
if(valsRec[0]==4) {Index.attach(12); IndexDownMax();   lcd.clear(); lcd.print("Index Finger");lcd.setCursor(2,0);lcd.print("Down");}
if(valsRec[0]==5)  {Middle.attach(11); MiddleUpMax();   lcd.clear(); lcd.print("Middle Finger");lcd.setCursor(2,0);lcd.print("Up");}
if(valsRec[0]==6)  {Middle.attach(11); MiddleDownMax();   lcd.clear(); lcd.print("Middle Finger");lcd.setCursor(2,0);lcd.print("Down");}
if(valsRec[0]==7)  {Ring.attach(9); RingUpMax();   lcd.clear(); lcd.print("Ring Finger");lcd.setCursor(2,0);lcd.print("Up");}
if(valsRec[0]==8)  {Ring.attach(9); RingDownMax();   lcd.clear(); lcd.print("Ring Finger");lcd.setCursor(2,0);lcd.print("Down");}
if(valsRec[0]==9)  {Little.attach(6); LittleUpMax();   lcd.clear(); lcd.print("Little Finger");lcd.setCursor(2,0);lcd.print("Up");}
if(valsRec[0]==10)  {Little.attach(6); LittleDownMax();   lcd.clear(); lcd.print("Little Finger");lcd.setCursor(2,0);lcd.print("Down");}
//
//else
//  {delay(Delay*100); 
//    dt();
//   }












  
//
//if(Serial.available()>0)
//{//at();
// Reading=Serial.read();
// switch(Reading)
//       {case 'w': Roll.attach(3); RollRight();   lcd.clear(); lcd.print("Rolling Right"); break;
//        case 'q': Roll.attach(3); RollLeft();   lcd.clear(); lcd.print("Rolling Left");  break;
//        case 'a': at(); PitchUp(); lcd.print("Pitch");   lcd.clear(); lcd.setCursor(2,0);lcd.print("Up"); break;
//        case 's': at(); PitchDown(); lcd.print("Pitch");   lcd.clear(); lcd.setCursor(2,0);lcd.print("Down"); break;
//        case 'z': Little.attach(6); LittleUp();   lcd.clear(); lcd.print("Little Finger");lcd.setCursor(2,0);lcd.print("Up"); break;
//        case 'x': Little.attach(6); LittleDown();   lcd.clear(); lcd.print("Little Finger");lcd.setCursor(2,0);lcd.print("Down"); break;
//        case 'c': Ring.attach(9); RingUp();   lcd.clear(); lcd.print("Ring Finger");lcd.setCursor(2,0);lcd.print("Up"); break;
//        case 'v': Ring.attach(9); RingDown();   lcd.clear(); lcd.print("Ring Finger");lcd.setCursor(2,0);lcd.print("Down"); break;
//        case 'b': Middle.attach(11); MiddleUp();   lcd.clear(); lcd.print("Middle Finger");lcd.setCursor(2,0);lcd.print("Up"); break;
//        case 'n': Middle.attach(11); MiddleDown();   lcd.clear(); lcd.print("Middle Finger");lcd.setCursor(2,0);lcd.print("Down"); break;
//        case 'h': Index.attach(12); IndexUp();   lcd.clear(); lcd.print("Index Finger");lcd.setCursor(2,0);lcd.print("Up"); break;
//        case 'j': Index.attach(12); IndexDown();   lcd.clear(); lcd.print("Index Finger");lcd.setCursor(2,0);lcd.print("Down"); break;
//        case 'k': Thumb.attach(13); ThumbUp();   lcd.clear(); lcd.print("Thumb Finger");lcd.setCursor(2,0);lcd.print("Up"); break;
//        case 'l': Thumb.attach(13); ThumbDown();   lcd.clear(); lcd.print("Thumb Finger");lcd.setCursor(2,0);lcd.print("Down"); break;
//        case 'd': at(); DefaultAngles();   lcd.clear(); lcd.print("Default Position"); break;
//        case 'e': Roll.attach(3); RollLeftMax();   lcd.clear(); lcd.print("Rolling Left");lcd.setCursor(2,0);lcd.print("Max"); break;
//        case 'r': Roll.attach(3); RollRightMax();   lcd.clear(); lcd.print("Rolling Right");lcd.setCursor(2,0);lcd.print("Max"); break;
//        case 't': at(); PitchUpMax();   lcd.clear(); lcd.print("Pitch");lcd.setCursor(2,0);lcd.print("Up   Max"); break;
//        case 'y': at(); PitchDownMax();   lcd.clear(); lcd.print("Pitch");lcd.setCursor(2,0);lcd.print("Down   Max"); break;
//        case 'u': Little.attach(6); LittleUpMax();   lcd.clear(); lcd.print("Little");lcd.setCursor(2,0);lcd.print("Up   Max"); break;
//        case 'i': Little.attach(6); LittleDownMax();   lcd.clear(); lcd.print("Little");lcd.setCursor(2,0);lcd.print("Down   Max"); break;
//        case 'o': Ring.attach(9); RingUpMax();   lcd.clear(); lcd.print("Ring");lcd.setCursor(2,0);lcd.print("Up   Max"); break;
//        case 'p': Ring.attach(9); RingDownMax();   lcd.clear(); lcd.print("Ring");lcd.setCursor(2,0);lcd.print("Down   Max"); break;
//        case '[': Middle.attach(11); MiddleUpMax();   lcd.clear(); lcd.print("Middle");lcd.setCursor(2,0);lcd.print("Up   Max"); break;
//        case ']': Middle.attach(11); MiddleDownMax();   lcd.clear(); lcd.print("Middle");lcd.setCursor(2,0);lcd.print("Down   Max"); break;
//        case '/': Index.attach(12); IndexUpMax();   lcd.clear(); lcd.print("Index");lcd.setCursor(2,0);lcd.print("Up   Max"); break;
//        case '*': Index.attach(12); IndexDownMax();   lcd.clear(); lcd.print("Index");lcd.setCursor(2,0);lcd.print("Down   Max"); break;
//        case '-': Thumb.attach(13); ThumbUpMax();   lcd.clear(); lcd.print("Thumb");lcd.setCursor(2,0);lcd.print("Up   Max"); break;
//        case '=': Thumb.attach(13); ThumbDownMax();   lcd.clear(); lcd.print("Thumb");lcd.setCursor(2,0);lcd.print("Down   Max"); break;
//        case '0': at(); Zero();  lcd.clear(); lcd.print("Zero"); break;
//        case '1': at(); One();  lcd.clear(); lcd.print("One"); break;
//        case '2': at(); Two();  lcd.clear(); lcd.print("Two"); break;
//        case '3': at(); Three();  lcd.clear(); lcd.print("Three"); break;
//        case '4': at(); Four();  lcd.clear();  lcd.print("Four"); break;
//        case '5': at(); Five();  lcd.clear(); lcd.print("Five  "); break;
//        case '6': at(); OK(); lcd.clear(); lcd.print("Ok");break;
//        
//         }
// } 

}
