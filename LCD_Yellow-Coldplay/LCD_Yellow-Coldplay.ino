//Yellow-Coldplay
//code by Izumisea


#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

void setup() {
  lcd.init();
  lcd.clear();         
  lcd.backlight();    

   
  lcd.setCursor(2,0);  //start
  lcd.clear();
  lcd.setCursor(2,1);  
  lcd.clear();
  delay(34000);
  
  lcd.setCursor(2,0);  //1
  lcd.print("Look At");
  lcd.setCursor(2,1); 
  lcd.print("The Stars");
  delay(2000);
  lcd.setCursor(2,0);  
  lcd.clear();
  lcd.setCursor(2,1);  
  lcd.clear();
  delay(500);
  
   lcd.setCursor(2,0);   //2
  lcd.print("Look How They");
  lcd.setCursor(2,1);   
  lcd.print("Shine For You");
  delay(4000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(2500);
  
   lcd.setCursor(2,0);   //3
  lcd.print("And Everything");
  lcd.setCursor(2,1);  
  lcd.print("You Do");
  delay(5000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);
  
   lcd.setCursor(2,0);   //4
  lcd.print("Yeah They Were");
  lcd.setCursor(2,1);  
  lcd.print("All Yellow");
  delay(2000);
  lcd.setCursor(2,0);   
  lcd.clear(); 
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);
  
   lcd.setCursor(2,0);   //5
  lcd.print("I Came Along");
  lcd.setCursor(2,1);  
  lcd.print(" ");
  delay(2500);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);
  
   lcd.setCursor(2,0);   //6
  lcd.print("I Wrote A Song");
  lcd.setCursor(2,1);  
  lcd.print("For You");
  delay(5000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);
  
   lcd.setCursor(2,0);   //7
  lcd.print("And All The");
  lcd.setCursor(2,1);  
  lcd.print("Things You Do");
  delay(4500);
  lcd.setCursor(2,0);   
  lcd.clear(); 
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);
  
   lcd.setCursor(2,0);   //8
  lcd.print("And It Was");
  lcd.setCursor(2,1);  
  lcd.print("Called Yellow");
  delay(3000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(2500);
  
   lcd.setCursor(2,0);   //9
  lcd.print("So Then I Took");
  lcd.setCursor(2,1);  
  lcd.print("My Turn");
  delay(3500);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(2000);
  
   lcd.setCursor(2,0);   //10
  lcd.print("Oh,What Thing");
  lcd.setCursor(2,1);  
  lcd.print("To Have Done");
  delay(3000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(3000);

   lcd.setCursor(2,0);   //11
  lcd.print("It Was All");
  lcd.setCursor(2,1);  
  lcd.print("YELLOW");
  delay(2500);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(5000);

   lcd.setCursor(2,0);   //12
  lcd.print("Your Skin,");
  lcd.setCursor(2,1);  
  lcd.print("Oh Yeah,");
  delay(3000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);

   lcd.setCursor(2,0);   //13
  lcd.print("Your Skin");
  lcd.setCursor(2,1);  
  lcd.print("And Bones");
  delay(2500);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);

   lcd.setCursor(2,0);   //14
  lcd.print("Turn Into");
  lcd.setCursor(2,1);  
  lcd.print("");
  delay(2000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);

   lcd.setCursor(2,0);   //15
  lcd.print(" Something ");
  lcd.setCursor(2,1);  
  lcd.print(" Beautiful ");
  delay(2000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);

   lcd.setCursor(2,0);   //16
  lcd.print("and you know,");
  lcd.setCursor(2,1);  
  lcd.print("you know");
  delay(2500);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);

   lcd.setCursor(2,0);   //17
  lcd.print("I Love You So");
  lcd.setCursor(2,1);  
  lcd.print("");
  delay(3500);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);

   lcd.setCursor(2,0);   //18
  lcd.print("You Know");
  lcd.setCursor(2,1);  
  lcd.print("I Love You So");
  delay(3000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);

   lcd.setCursor(2,0);  //19
  lcd.clear();
  lcd.setCursor(2,1);  
  lcd.clear();
  delay(22000);
  //22second
  
   lcd.setCursor(2,0);   //20
  lcd.print("I Swam Across");
  lcd.setCursor(2,1);  
  lcd.print("");
  delay(3000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(1000);

   lcd.setCursor(2,0);   //21
  lcd.print("I Jumped");
  lcd.setCursor(2,1);  
  lcd.print("Across For You");
  delay(3000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(2000);

   lcd.setCursor(2,0);   //22
  lcd.print("Ohh, What ");
  lcd.setCursor(2,1);  
  lcd.print("A Thing To Do");
  delay(3000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(3000);

   lcd.setCursor(2,0);   //23
  lcd.print("Cause You Were");
  lcd.setCursor(2,1);  
  lcd.print(" All Yellow");
  delay(2500);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(1000);

   lcd.setCursor(2,0);   //24
  lcd.print("I Drew A Line");
  lcd.setCursor(2,1);  
  lcd.print("");
  delay(1500);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(500);

  lcd.setCursor(2,0);   //25
  lcd.print("I Drew A Line");
  lcd.setCursor(2,1);  
  lcd.print("For You");
  delay(3000);
  lcd.setCursor(2,0);   
  lcd.clear();
  lcd.setCursor(2,1);   
  lcd.clear();
  delay(2500);

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
  delay(4500); ////////--------
  
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
  delay(2000);
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
