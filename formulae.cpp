//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("formulae.res");
USEFORM("Unit1.cpp", Form1);

//runtime pkgs: Vcl50;Vclx50;bcbsmp50;Vcldb50;vclado50;ibsmp50;VCLBDE50;vcldbx50;Qrpt50;TeeUI50;TeeDB50;Tee50;Dss50;TeeQR50;VCLIB50;Vclmid50;vclie50;Inetdb50;Inet50;NMFast50;webmid50;bcbie50;dclocx50;bcb2kaxserver50;
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
  {
     Application->Initialize();
     Application->Title = "Formula Calculator";
     Application->CreateForm(__classid(TForm1), &Form1);
     Application->Run();
  }
  catch (Exception &exception)
  {
     Application->ShowException(&exception);
  }
  return 0;
}
//---------------------------------------------------------------------------
