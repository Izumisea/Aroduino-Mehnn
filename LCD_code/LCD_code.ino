//code made by Izumisea
//     SDA - A4
//     SCl - A5

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

void setup() {
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on

  lcd.setCursor(2,0);   //26
  lcd.print("Ohh, What ");
  lcd.setCursor(2,1);  
  lcd.print("a thing to do");
  delay(3000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(2500);

   lcd.setCursor(2,0);   //27
  lcd.print("And It Was");
  lcd.setCursor(2,1);  
  lcd.print("All Yellow");
  delay(3000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(4500);
  
    lcd.setCursor(2,0);   //29
  lcd.print("Your Skin,");
  lcd.setCursor(2,1);  
  lcd.print("Oh Yeah,");
  delay(3000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);

   lcd.setCursor(2,0);   //30
  lcd.print("Your Skin");
  lcd.setCursor(2,1);  
  lcd.print("And Bones");
  delay(2500);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);

   lcd.setCursor(2,0);   //31
  lcd.print("Turn Into");
  lcd.setCursor(2,1);  
  lcd.print("");
  delay(2000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);

   lcd.setCursor(2,0);   //32
  lcd.print(" Something ");
  lcd.setCursor(2,1);  
  lcd.print(" Beautiful ");
  delay(2000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);

   lcd.setCursor(2,0);   //34
  lcd.print("And You Know,");
  lcd.setCursor(2,1);  
  lcd.print("For You");
  delay(3000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);

   lcd.setCursor(2,0);   //35
  lcd.print("I'd Bleed");
  lcd.setCursor(2,1);  
  lcd.print("Myself Dry");
  delay(3000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(2000);

   lcd.setCursor(2,0);   //36
  lcd.print("For You");
  lcd.setCursor(2,1);  
  lcd.print("");
  delay(1000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);

   lcd.setCursor(2,0);   //37
  lcd.print("I'd Bleed");
  lcd.setCursor(2,1);  
  lcd.print("Myself Dry");
  delay(3000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500); 

   lcd.setCursor(2,0);  //38
  lcd.clear();
  lcd.setCursor(2,1);  
  lcd.clear();
  delay(20500);
  //22 Second

  
   lcd.setCursor(2,0);   //39
  lcd.print("It's True");
  lcd.setCursor(2,1);  
  lcd.print("");
  delay(3500);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500); 

  lcd.setCursor(2,0);   //40
  lcd.print("Look How They");
  lcd.setCursor(2,1);   
  lcd.print("Shine For You");
  delay(4000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(1000);

   lcd.setCursor(2,0);   //41
  lcd.print("Look How They");
  lcd.setCursor(2,1);   
  lcd.print("Shine For You");
  delay(4000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(1000);

   lcd.setCursor(2,0);   //42
  lcd.print("Look How They");
  lcd.setCursor(2,1);   
  lcd.print("Shine For...");
  delay(4000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(1500);

   lcd.setCursor(2,0);   //43
  lcd.print("Look How They");
  lcd.setCursor(2,1);   
  lcd.print("Shine For You");
  delay(4000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(1400);

   lcd.setCursor(2,0);   //44
  lcd.print("Look How They");
  lcd.setCursor(2,1);   
  lcd.print("Shine For You");
  delay(4000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(1500);

   lcd.setCursor(2,0);   //45
  lcd.print("Look How They");
  lcd.setCursor(2,1);   
  lcd.print("Shine");
  delay(4000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(1000);

    lcd.setCursor(2,0);  //46
  lcd.print("Look At");
  lcd.setCursor(2,1); 
  lcd.print("The Stars");
  delay(2000);
  lcd.setCursor(2,0);  
  lcd.clear();
  lcd.setCursor(2,1);  
  lcd.clear();
  delay(500);
  
   lcd.setCursor(2,0);   //47
  lcd.print("Look How They");
  lcd.setCursor(2,1);   
  lcd.print("Shine For You");
  delay(4000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(1500);
  
   lcd.setCursor(2,0);   //48
  lcd.print("And All The");
  lcd.setCursor(2,1);  
  lcd.print("Things That");
  delay(2500);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);

   lcd.setCursor(2,0);   //49
  lcd.print("You Do..");
  lcd.setCursor(2,1);  
  lcd.print("");
  delay(3000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);
}

void loop() {
}
