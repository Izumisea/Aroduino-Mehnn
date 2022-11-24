//Every Woman in The World
//code by Izumisea


#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

void setup() {
  lcd.init();
  lcd.clear();         
  lcd.backlight();    

   // Print a message on both lines of the LCD.
  lcd.setCursor(2,0);  //start
  lcd.clear();
  lcd.setCursor(2,1);  
  lcd.clear();
  delay(5000);
   lcd.setCursor(2,0);  //1
  lcd.print("I was dancing in");
  lcd.setCursor(2,1); 
  lcd.print("the dark with");
  delay(2000);
  lcd.setCursor(2,0);  
  lcd.clear();
  lcd.setCursor(2,1);  
  lcd.clear();
  delay(500);
   lcd.setCursor(2,0);   //2
  lcd.print("strangers  no");
  lcd.setCursor(2,1);   
  lcd.print("love around me");
  delay(2000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);
   lcd.setCursor(2,0);   //3
  lcd.print("When suddenly");
  lcd.setCursor(2,1);  
  lcd.print("u found me, oh");
  delay(5000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);
   lcd.setCursor(2,0);   //4
  lcd.print("Girl, ur every");
  lcd.setCursor(2,1);  
  lcd.print("woman in the");
  delay(4500);
  lcd.setCursor(2,0);   
  lcd.clear(); 
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);
   lcd.setCursor(2,0);   //5
  lcd.print("world to me");
  lcd.setCursor(2,1);  
  lcd.print(" ");
  delay(3000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);
   lcd.setCursor(2,0);   //6
  lcd.print("ur my fantasy");
  lcd.setCursor(2,1);  
  lcd.print("ur my reality ");
  delay(5000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);
   lcd.setCursor(2,0);   //7
  lcd.print("Girl, ur every");
  lcd.setCursor(2,1);  
  lcd.print("woman in the");
  delay(4500);
  lcd.setCursor(2,0);   
  lcd.clear(); 
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);
   lcd.setCursor(2,0);   //8
  lcd.print("world to me");
  lcd.setCursor(2,1);  
  lcd.print(" ");
  delay(3000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);
   lcd.setCursor(2,0);   //9
  lcd.print("ur everything");
  lcd.setCursor(2,1);  
  lcd.print("I need ");
  delay(2000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);
   lcd.setCursor(2,0);   //10
  lcd.print("ur everything");
  lcd.setCursor(2,1);  
  lcd.print("to me, Oh girl");
  delay(4000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);
}

void loop() {

}
