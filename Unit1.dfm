object Form1: TForm1
  Left = 192
  Top = 105
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Formula Calculator'
  ClientHeight = 488
  ClientWidth = 610
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Chart1: TChart
    Left = 8
    Top = 8
    Width = 593
    Height = 337
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    MarginBottom = 2
    MarginLeft = 2
    MarginRight = 2
    MarginTop = 3
    Title.Visible = False
    View3D = False
    TabOrder = 0
    object Series1: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clRed
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object Panel1: TPanel
    Left = 8
    Top = 352
    Width = 593
    Height = 129
    TabOrder = 1
    object Label1: TLabel
      Left = 272
      Top = 68
      Width = 3
      Height = 16
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 292
      Top = 68
      Width = 3
      Height = 16
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ListBox1: TListBox
      Left = 8
      Top = 8
      Width = 257
      Height = 113
      Hint = 'Formulaes list'
      Columns = 2
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ItemHeight = 16
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnClick = ListBox1Click
    end
    object Edit1: TEdit
      Left = 272
      Top = 36
      Width = 313
      Height = 25
      Hint = 'Enter variable and its formulae here'
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
    end
    object Edit2: TEdit
      Left = 272
      Top = 64
      Width = 313
      Height = 25
      Hint = 'Result wiil be shown here after calculation'
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ReadOnly = True
      ShowHint = True
      TabOrder = 2
    end
    object Add: TButton
      Left = 272
      Top = 96
      Width = 73
      Height = 25
      Hint = 'Add formulae'
      Caption = 'Add'
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
      OnClick = AddClick
    end
    object Remove: TButton
      Left = 352
      Top = 96
      Width = 73
      Height = 25
      Hint = 'Remove formulae'
      Caption = 'Remove'
      ParentShowHint = False
      ShowHint = True
      TabOrder = 4
      OnClick = RemoveClick
    end
    object Solve: TButton
      Left = 432
      Top = 96
      Width = 73
      Height = 25
      Hint = 'Solve formulae system'
      Caption = 'Solve'
      ParentShowHint = False
      ShowHint = True
      TabOrder = 5
      OnClick = SolveClick
    end
    object Draw: TButton
      Left = 512
      Top = 8
      Width = 73
      Height = 25
      Hint = 'Draw entered variable values from its dependencies'
      Caption = 'Draw'
      ParentShowHint = False
      ShowHint = True
      TabOrder = 6
      OnClick = DrawClick
    end
    object Edit3: TEdit
      Left = 272
      Top = 8
      Width = 233
      Height = 25
      Hint = 'Enter variable and its dependencies here, example: y(x)'
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 7
    end
    object Differentiate: TButton
      Left = 512
      Top = 96
      Width = 73
      Height = 25
      Hint = 'Differentiate'
      Caption = 'Differentiate'
      ParentShowHint = False
      ShowHint = True
      TabOrder = 8
      OnClick = DifferentiateClick
    end
  end
end
