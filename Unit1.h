//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <FormulaeSystem.h>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
  TChart *Chart1;
  TLineSeries *Series1;
  TPanel *Panel1;
  TListBox *ListBox1;
  TEdit *Edit1;
  TEdit *Edit2;
  TButton *Add;
  TButton *Remove;
  TButton *Solve;
  TButton *Draw;
  TEdit *Edit3;
  TLabel *Label1;
  TLabel *Label2;
  TButton *Differentiate;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall AddClick(TObject *Sender);
  void __fastcall SolveClick(TObject *Sender);
  void __fastcall RemoveClick(TObject *Sender);
  void __fastcall ListBox1Click(TObject *Sender);
  void __fastcall DrawClick(TObject *Sender);
  void __fastcall DifferentiateClick(TObject *Sender);
private:	// User declarations
  TFormulaeSystem *form;
public:		// User declarations
  __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 