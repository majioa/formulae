//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  form = new TFormulaeSystem(this,__classid(TFormulae));
//  f = form->Add();
//  f->Name = "Name";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AddClick(TObject *Sender)
{
//  f->Value = Edit1->Text;//"1,2*100%3+20";
  int i = Edit1->Text.Pos("="), j;
  TFormulae *f;
  AnsiString str;
  if(!i)
    throw EMathError ("Error in formulae");
  else
    {
    str = Edit1->Text.SubString(1, i - 1);
    i = ListBox1->Items->IndexOfName(str);
    if(i >= 0)
      {
      j = MessageDlg("The variable already exist. Do you want to replace the old formulae value variable with new one?", mtWarning, TMsgDlgButtons() << mbYes	<< mbNo, -1);
      if(j == mrYes)
        {
        ListBox1->Items->Strings[i] = Edit1->Text;
        f = form->PointerOf(ListBox1->Items->Names[i]);
        f->Value = ListBox1->Items->Values[f->Name];//Edit1->Text.SubString(i + 1,Edit1->Text.Length() - i);
        }
      }
    else
      {
      i = ListBox1->Items->Add(Edit1->Text);
      f = form->Add();
      f->Name = ListBox1->Items->Names[i];//Edit1->Text.SubString(1,i - 1);
      f->Value = ListBox1->Items->Values[f->Name];//Edit1->Text.SubString(i + 1,Edit1->Text.Length() - i);
      }
   }
//  f->Name = Name;
/*  Variant v = f->Calculate();
//  Variant v = form->Calculate(Edit1->Text);
  Edit2->Text = AnsiString(v);*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SolveClick(TObject *Sender)
{
  int i, j;
  AnsiString str;
  form->Calculate();
  Variant val = form->GetCalcValue(Label1->Caption), val1;
  if(!val.IsNull())
    {
    if(val.IsArray())
      {
//      Chart1->AddSeries();
//      Chart1->Series[0]->Clear();
      str = "{";
      for(i = 1; i < val.ArrayHighBound(1); i++)
        {
        if(i != 1)
          str += ";";
        val1 = val.GetElement(i);
        if(val1.IsArray())
          {
          str += "{" + AnsiString(val1.GetElement(1));
          for(j = 2; j < val1.ArrayHighBound(1); j++)
            {
            if(j != 1)
              str += ";";
            str += AnsiString(val1.GetElement(j));
            }
          str += "}";
          }
        else
          {
          //adds to graph
//          Chart1->AddXY(,(double)val1,"",clTeeColor);
//          Chart1->Series[0]->Add((double)val1,"",clTeeColor);
          str += AnsiString(val1);
          }
        }
      str += "}";
      Edit2->Text = str;
      }
    else
      Edit2->Text = AnsiString(val);
    }
  else
    Edit2->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RemoveClick(TObject *Sender)
{
//
  AnsiString str;
  int i, j;
  TFormulae *f;
  for(i = 0; i < ListBox1->Items->Count; i++)
    if(ListBox1->Selected[i])
      {
      str = ListBox1->Items->Names[i];
      Label1->Caption = "";
      Label2->Caption = "";
      j = form->IndexOf(str);
      form->Delete(j);
      ListBox1->Items->Delete(i);
      Edit2->Width = 265;
      break;
      }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
  int i;
  for(i = 0; i < ListBox1->Items->Count; i++)
    if(ListBox1->Selected[i])
      {
      Label1->Caption = ListBox1->Items->Names[i];
//      if(Label1->Caption.IsEmpty())
//        Label1->Caption = ListBox1->Items->Strings[i];
      Label2->Left = Label1->Left + Label1->Width;
      Label2->Caption = "=";
      Edit2->Left = Label2->Left + Label2->Width + 5;
      Edit2->Width = 308 - Label1->Width - Label2->Width;
      return;
      }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawClick(TObject *Sender)
{
//      Chart1->AddSeries();
  int i, j, k;
  double Bounds1[3], f;
  Variant x, y, val;
  AnsiString strx, stry;
  k = Edit3->Text.Pos("(");
  j = Edit3->Text.Pos(")");
  if(!k || !j)
    return;
  form->Calculate();
  stry = Edit3->Text.SubString(1, k - 1);
  strx = Edit3->Text.SubString(k + 1, j - k - 1);
  x = form->GetCalcValue(strx);
  y = form->GetCalcValue(stry);
  Chart1->Series[0]->Clear();
//  for(i = 1; i < val.ArrayHighBound(1); i++)
  if(!x.IsArray())
    return;
  if(x.GetElement(0))
    {
    k = x.ArrayHighBound(1) / 3;
    j = 1;
    for(i = 1; i <= k; i++)
      {
      Bounds1[0] = x.GetElement(i);
      Bounds1[1] = x.GetElement(i + 1);
      Bounds1[2] = x.GetElement(i + 2);
      for(f = Bounds1[0]; f <= Bounds1[1]; f += Bounds1[2])
        {
        val = y.GetElement(j++);
        Chart1->Series[0]->AddXY(f,(double)val,"",clTeeColor);
        }
      }
    }
  else
    for(i = 1; i < x.ArrayHighBound(1); i++)
      Chart1->Series[0]->AddXY((double)x.GetElement(i),(double)y.GetElement(i),"",clTeeColor);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DifferentiateClick(TObject *Sender)
{
  AnsiString str;
  int i, j;
  TFormulae *f;
  for(i = 0; i < ListBox1->Items->Count; i++)
    if(ListBox1->Selected[i])
      {
      str = ListBox1->Items->Names[i];
      f = form->Differentiate(str,"x");
      if((j = ListBox1->Items->IndexOfName(str+"'")) < 0)
        ListBox1->Items->Add(f->Name + "=" + f->StrValue);
      break;
      }
}
//---------------------------------------------------------------------------

