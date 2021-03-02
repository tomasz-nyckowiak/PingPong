//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

  int x = 4;
  int y = 4;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_ballTimer(TObject *Sender)
{
    b->Left += x;
    b->Top += y;

    //odbij od gornej sciany
    if (b->Top <= tlo->Top) y = -y;

    //odbij od dolnej sciany
    if (b->Top + b->Height >= tlo->Height) y = -y;

    //skucha i odbicie: Gracz1
    if (b->Left + b->Width <= p1->Left - 15)
    {
       Timer_ball->Enabled = false;
       b->Visible = false;
    }
    else if ((b->Top > p1->Top - b->Height) &&
             (b->Top < p1->Top + p1->Height + b->Height) &&
             (b->Left <= p1->Left + p1->Width))
    {
       if (x > 0) x = -x;
    }

    //skucha i odbicie: Gracz2
    if (b->Left + b->Width >= p2->Left + 15)
    {
       Timer_ball->Enabled = false;
       b->Visible = false;
    }
    else if (b->Top > p2->Top - b->Height/2 &&
             b->Top < p2->Top + p2->Height &&
             b->Left + b->Width >= p2->Left)
    {
       if (x > 0) x = -x;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::up2Timer(TObject *Sender)
{
    if (p2->Top > 10) p2->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::down2Timer(TObject *Sender)
{
    if (p2->Top + p2->Height + 10 <= tlo->Height) p2->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_UP) up2->Enabled = true;
    if (Key == VK_DOWN) down2->Enabled = true;
    if (Key == 'A') up1->Enabled = true;
    if (Key == 'Z') down1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_UP) up2->Enabled = false;
    if (Key == VK_DOWN) down2->Enabled = false;
    if (Key == 'A') up1->Enabled = false;
    if (Key == 'Z') down1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::up1Timer(TObject *Sender)
{
    if (p1->Top > 10) p1->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::down1Timer(TObject *Sender)
{
    if (p1->Top + p1->Height + 10 <= tlo->Height) p1->Top += 10;
}
//---------------------------------------------------------------------------
