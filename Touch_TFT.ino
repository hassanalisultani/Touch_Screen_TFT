#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library
#include <TouchScreen.h> //touch library

//if the IC model is known or the modules is unreadable,you can use this constructed function
LCDWIKI_KBV my_lcd(ILI9486,A3,A2,A1,A0,A4); //model,cs,cd,wr,rd,reset
//if the IC model is not known and the modules is readable,you can use this constructed function
//LCDWIKI_KBV my_lcd(320,480,A3,A2,A1,A0,A4);//width,height,cs,cd,wr,rd,reset

#define PREVBOXSIZE my_lcd.Get_Display_Width()/6
#define NEXTBOXSIZE my_lcd.Get_Display_Width()/4

#define MINPRESSURE 10
#define MAXPRESSURE 1000

#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin

//param calibration from kbv
#define TS_MINX 906
#define TS_MAXX 116

#define TS_MINY 92 
#define TS_MAXY 952

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

int16_t old_color, current_color,flag_colour;
int16_t old_pen,current_pen,flag_pen;
boolean show_flag = true;

int page = 0;
int id;
void first_page(void)
{
  
  id = 53;
  Serial.write(id);
  my_lcd.Fill_Screen(0x0);
  my_lcd.Fill_Screen(120, 120, 120);
  my_lcd.Set_Draw_color(70, 70, 70);
  my_lcd.Set_Text_Mode(1);
  my_lcd.Set_Text_Size(3);
  my_lcd.Print_String("Hello Everyone!", 110, 30);
  my_lcd.Set_Text_Size(2);
  my_lcd.Fill_Round_Rectangle(120, 80, 350, 130, 5);
  my_lcd.Fill_Round_Rectangle(120, 150, 350, 200, 5);
  my_lcd.Fill_Round_Rectangle(120, 220, 350, 270, 5);
  my_lcd.Print_String("GO TO PAGE 1", 160, 100);
  my_lcd.Print_String("GO TO PAGE 2", 160, 170);
  my_lcd.Print_String("GO TO PAGE 3", 160, 240);
  my_lcd.Print_String("Hassan here!", RIGHT, my_lcd.Get_Display_Height()/2-1+140);
  page = 1;
}


int a,b,i,j,k;
int btn[24]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16,-17,-18,-19,-20,-21,-22,-23,-24};
int state[24];
String names[] = {"Button1", "Button2", "Button3", "Button4", "Button5", "Button6", "Button7", "Button8", "Button9", "Button10", "Button11", "Button12", "Button13", "Button14", "Button15", "Button16", "Button17", "Button18", "Button19", "Button20", "Button21", "Button22", "Button23", "Button24"};

void second_page(void)
{
  id = 51;
  Serial.write(id);
  my_lcd.Fill_Screen(0x0);
  my_lcd.Fill_Screen(120, 120, 120);
  my_lcd.Set_Draw_color(70, 70, 70);
  
  my_lcd.Set_Text_Mode(1);
  my_lcd.Set_Text_Size(1);
  k=0;
  for (j=20; j<250; j=j+75)
  {
    for (i=20; i<400; i=i+75)
    {
      my_lcd.Fill_Round_Rectangle(i, j, i+60, j+60, 5);
      my_lcd.Print_String(names[k], i+10, j+20);
      k=k+1;
    }
  }
  show_menu();
  page = 2;
}

void logic_btn (void)
{
  if (a==360)
  {
    if (b==0)
    {
      j = 20;
      i = 20;
      k=0;
    }
    else if (b==50)
    {
      j = 20;
      i = 95;
      k=1;
    }
    else if (b==100)
    {
      j = 20;
      i = 170;
      k=2;
    }
    else if (b==150)
    {
      j = 20;
      i = 245;
      k=3;
    }
    else if (b==200)
    {
      j = 20;
      i = 320;
      k=4;
    }
    else if (b==250)
    {
      j = 20;
      i = 395;
      k=5;
    }
  }
  if (a==240)
  {
    if (b==0)
    {
      j = 95;
      i = 20;
      k=6;
    }
    else if (b==50)
    {
      j = 95;
      i = 95;
      k=7;
    }
    else if (b==100)
    {
      j = 95;
      i = 170;
      k=8;
    }
    else if (b==150)
    {
      j = 95;
      i = 245;
      k=9;
    }
    else if (b==200)
    {
      j = 95;
      i = 320;
      k=10;
    }
    else if (b==250)
    {
      j = 95;
      i = 395;
      k=11;
    }
  }
  if (a==120)
  {
    if (b==0)
    {
      j = 170;
      i = 20;
      k=12;
    }
    else if (b==50)
    {
      j = 170;
      i = 95;
      k=13;
    }
    else if (b==100)
    {
      j = 170;
      i = 170;
      k=14;
    }
    else if (b==150)
    {
      j = 170;
      i = 245;
      k=15;
    }
    else if (b==200)
    {
      j = 170;
      i = 320;
      k=16;
    }
    else if (b==250)
    {
      j = 170;
      i = 395;
      k=17;
    }
  }
  if (a==0)
  {
    if (b==0)
    {
      j = 245;
      i = 20;
      k=18;
    }
    else if (b==50)
    {
      j = 245;
      i = 95;
      k=19;
    }
    else if (b==100)
    {
      j = 245;
      i = 170;
      k=20;
    }
    else if (b==150)
    {
      j = 245;
      i = 245;
      k=21;
    }
    else if (b==200)
    {
      j = 245;
      i = 320;
      k=22;
    }
    else if (b==250)
    {
      j = 245;
      i = 395;
      k=23;
    }
  }
  switch (state[k])
  {
    case 0:
    my_lcd.Set_Draw_color(0, 170, 255);
    my_lcd.Fill_Round_Rectangle(i, j, i+60, j+60, 5);
    my_lcd.Print_String(names[k], i+10, j+20);
    btn[k]=k+1;
    state[k]=1;
    Serial.write(btn[k]);
    break;
    
    case 1:
    my_lcd.Set_Draw_color(70, 70, 70);
    my_lcd.Fill_Round_Rectangle(i, j, i+60, j+60, 5);
    my_lcd.Print_String(names[k], i+10, j+20);
    btn[k]=-(k+1);
    state[k]=0;
    Serial.write(btn[k]);
    break;
  }
  show_menu(); 
}


String val;

void third_page(void)
{
  id = 52;
  Serial.write(id);
  val = "0";
  my_lcd.Fill_Screen(0x0);
  my_lcd.Fill_Screen(120, 120, 120);
  my_lcd.Set_Draw_color(70, 70, 70);
  my_lcd.Fill_Round_Rectangle(130, 200, 350, 270, 5);
  my_lcd.Set_Draw_color(0, 170, 255);
  my_lcd.Fill_Round_Rectangle(130, 200, 180, 270, 5);
  my_lcd.Fill_Round_Rectangle(300, 200, 350, 270, 5);
  my_lcd.Set_Text_Mode(1);
  my_lcd.Set_Text_Size(2);
  my_lcd.Print_String(val, 230, 230);
  my_lcd.Print_String("<", 150, 230);
  my_lcd.Print_String(">", 320, 230);
  my_lcd.Set_Draw_color(70, 70, 70);
  my_lcd.Fill_Round_Rectangle(60, 50, 160, 150, 5);
  my_lcd.Print_String("FIRST", 80, 80);
  my_lcd.Print_String("BUTTON", 75, 100);
  my_lcd.Fill_Round_Rectangle(190, 50, 290, 150, 5);
  my_lcd.Print_String("SECOND", 205, 80);
  my_lcd.Print_String("BUTTON", 205, 100);
  my_lcd.Fill_Round_Rectangle(320, 50, 420, 150, 5);
  my_lcd.Print_String("THIRD", 340, 80);
  my_lcd.Print_String("BUTTON", 335, 100);
  show_menu();
  page = 3;
}

int color1 = 0;
int color2 = 0;
int color3 = 0;

void first_button(void)
{
  switch (color1)
  {
    case 0:
    my_lcd.Set_Draw_color(0, 170, 255);
    my_lcd.Fill_Round_Rectangle(60, 50, 160, 150, 5);
    my_lcd.Print_String("FIRST", 80, 80);
    my_lcd.Print_String("BUTTON", 75, 100);
    color1 = 1;
    Serial.write(2);
    break;
    
    case 1:
    my_lcd.Set_Draw_color(70, 70, 70);
    my_lcd.Fill_Round_Rectangle(60, 50, 160, 150, 5);
    my_lcd.Print_String("FIRST", 80, 80);
    my_lcd.Print_String("BUTTON", 75, 100);
    color1 = 0;
    Serial.write(1);
    break;
  }
}
void second_button(void)
{
  switch (color2)
  {
    case 0:
    my_lcd.Set_Draw_color(0, 170, 255);
    my_lcd.Fill_Round_Rectangle(190, 50, 290, 150, 5);
    my_lcd.Print_String("SECOND", 205, 80);
    my_lcd.Print_String("BUTTON", 205, 100);
    color2 = 1;
    Serial.write(4);
    break;

    case 1:
    my_lcd.Set_Draw_color(70, 70, 70);
    my_lcd.Fill_Round_Rectangle(190, 50, 290, 150, 5);
    my_lcd.Print_String("SECOND", 205, 80);
    my_lcd.Print_String("BUTTON", 205, 100);
    color2 = 0;
    Serial.write(3);
    break;
  }
}
void third_button(void)
{
  switch (color3)
  {
    case 0:
    my_lcd.Set_Text_colour(255, 255, 255);
    my_lcd.Set_Draw_color(0, 170, 255);
    my_lcd.Fill_Round_Rectangle(320, 50, 420, 150, 5);
    my_lcd.Print_String("THIRD", 340, 80);
    my_lcd.Print_String("BUTTON", 335, 100);
    color3 = 1;
    Serial.write(6);
    break;
    
    case 1:
    my_lcd.Set_Text_colour(255, 255, 255);
    my_lcd.Set_Draw_color(70, 70, 70);
    my_lcd.Fill_Round_Rectangle(320, 50, 420, 150, 5);
    my_lcd.Print_String("THIRD", 340, 80);
    my_lcd.Print_String("BUTTON", 335, 100);
    color3 = 0;
    Serial.write(5);
    break;
  }
}

void inc (void)
{
  int newval = val.toInt();
  if (newval < 255)
  {
    newval = newval+15;
    Serial.write(newval);
    val = String(newval);
    my_lcd.Set_Draw_color(70, 70, 70);
    my_lcd.Fill_Round_Rectangle(180, 200, 300, 270, 5);
    my_lcd.Set_Text_Mode(1);
    my_lcd.Set_Text_Size(2);
    my_lcd.Print_String(val, 230, 230);
  }
}
void dec (void)
{
  int newval = val.toInt();
  if (newval > 0)
  {
    newval = newval-15;
    Serial.write(newval);
    val = String(newval);
    my_lcd.Set_Draw_color(70, 70, 70);
    my_lcd.Fill_Round_Rectangle(180, 200, 300, 270, 5);
    my_lcd.Set_Text_Mode(1);
    my_lcd.Set_Text_Size(2);
    my_lcd.Print_String(val, 230, 230);
  }
}

void forth_page(void)
{
  my_lcd.Fill_Screen(0x0);
  my_lcd.Fill_Screen(120, 120, 120);
  my_lcd.Set_Draw_color(70, 70, 70);
  my_lcd.Fill_Round_Rectangle(my_lcd.Get_Display_Width()/2-1-220+1, my_lcd.Get_Display_Height()/2-1-100+1, my_lcd.Get_Display_Width()/2-1+220-1, my_lcd.Get_Display_Height()/2-1+100-1,5);
  my_lcd.Set_Text_Mode(1);
  my_lcd.Set_Text_Size(2);
  my_lcd.Print_String("Hello Everone!", CENTER, my_lcd.Get_Display_Height()/2-1-140);
  my_lcd.Set_Text_Size(3);
  my_lcd.Print_String("This is My GUI", CENTER, my_lcd.Get_Display_Height()/2-1-30);
  my_lcd.Set_Text_Size(2);
  my_lcd.Print_String("Hassan here!", RIGHT, my_lcd.Get_Display_Height()/2-1+140);
  show_menu();
  page = 4;
}

void show_menu(void)
{
  my_lcd.Set_Draw_color(255, 255, 255);
  my_lcd.Fill_Round_Rectangle(5, 290, 30, 320, 5);
}


void setup() 
{
  Serial.begin(9600);
  Serial.println(my_lcd.Read_ID(), HEX);
  my_lcd.Init_LCD();
  my_lcd.Fill_Screen(0x0);  
  my_lcd.Set_Rotation(1);
  my_lcd.Set_Text_colour(255, 255, 255);
  first_page();
  for(int c=0; c<24; c++)
  {
    state[c]=0;
  }
}

void loop() 
{
  comme:
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) 
  {
    p.x = map(p.x, TS_MINX, TS_MAXX, my_lcd.Get_Display_Width(), 0);
    p.y = map(p.y, TS_MINY, TS_MAXY, my_lcd.Get_Display_Height(),0);
      
      
    if(p.x > 2 && p.x < 25 && page!=1)
    {
      if(p.y > 2 && p.y < 15) //for home button
      {
        p.x=0;
        p.y=0;
        first_page();
        delay(200);
      }
    }
      
    if(p.x > 300 && p.x < 350 && page==1)
    {
      if(p.y > 80 && p.y < 230)
      {
        p.x=0;
        p.y=0;
        second_page();
        delay(200);
      }
    }
    if(p.x > 180 && p.x < 230 && page==1)
    {
      if(p.y > 80 && p.y < 230)
      {
        p.x=0;
        p.y=0;
        third_page();
        delay(200);
      }
    }
    if(p.x > 80 && p.x < 130 && page==1)
    {
      if(p.y > 80 && p.y < 230)
      {
        p.x=0;
        p.y=0;
        forth_page();
        delay(200);
      }
    }

    for (a=0; a<480; a=a+120)
    {
      for (b=0; b<300; b=b+50)
      {
        if(p.x > a+10 && p.x < a+100 && p.y > b+10 && p.y < b+50 && page==2)
        {
          p.x=0;
          p.y=0;
          logic_btn();
          delay(300);
        }
      }
    }
    
    if(p.x > 70 && p.x < 170 && page==3)
    {
      if(p.y > 200 && p.y < 230)
      {
        p.x=0;
        p.y=0;
        inc();
        delay(100);
      }
    }
    if(p.x > 70 && p.x < 170 && page==3)
    {
      if(p.y > 85 && p.y < 115)
      {
        p.x=0;
        p.y=0;
        dec();
        delay(100);
      }
    }
    if(p.x > 255 && p.x < 405 && page==3)
    {
      if(p.y > 40 && p.y < 105)
      {
        p.x=0;
        p.y=0;
        first_button();
        delay(300);
      }
    }
    if(p.x > 255 && p.x < 405 && page==3)
    {
      if(p.y > 125 && p.y < 190)
      {
        p.x=0;
        p.y=0;
        second_button();
        delay(300);
      }
    }
    if(p.x > 255 && p.x < 405 && page==3)
    {
      if(p.y > 215 && p.y < 280)
      {
        p.x=0;
        p.y=0;
        third_button();
        delay(300);
      }
    }
  }
}
