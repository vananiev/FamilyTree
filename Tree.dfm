object frmTree: TfrmTree
  Left = 267
  Top = 170
  Width = 790
  Height = 533
  HorzScrollBar.Style = ssHotTrack
  VertScrollBar.Style = ssHotTrack
  Caption = #1044#1077#1088#1077#1074#1086' '#1078#1080#1079#1085#1080
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = Menu
  OldCreateOrder = False
  Position = poScreenCenter
  OnActivate = FormActivate
  OnClick = FormClick
  OnDeactivate = FormDeactivate
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object B: TLabel
    Left = 380
    Top = 68
    Width = 81
    Height = 13
    AutoSize = False
    BiDiMode = bdRightToLeft
    Caption = '333333'
    Color = clSilver
    ParentBiDiMode = False
    ParentColor = False
    Visible = False
    OnClick = BClick
  end
  object Nastr: TGroupBox
    Left = 4
    Top = 4
    Width = 341
    Height = 169
    Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080' '#1074#1077#1088#1096#1080#1085
    TabOrder = 0
    Visible = False
    object Label1: TLabel
      Left = 12
      Top = 28
      Width = 42
      Height = 13
      Caption = #1064#1080#1088#1080#1085#1072':'
    end
    object Label2: TLabel
      Left = 12
      Top = 52
      Width = 41
      Height = 13
      Caption = #1042#1099#1089#1086#1090#1072':'
    end
    object Label3: TLabel
      Left = 12
      Top = 100
      Width = 78
      Height = 13
      Caption = #1052'/'#1076' '#1089#1090#1086#1083#1073#1094#1072#1084#1080
    end
    object Label4: TLabel
      Left = 12
      Top = 76
      Width = 75
      Height = 13
      Caption = #1052'/'#1076' '#1089#1090#1088#1086#1082#1072#1084#1080':'
    end
    object sWidth: TScrollBar
      Left = 68
      Top = 32
      Width = 261
      Height = 9
      Max = 300
      Min = 1
      PageSize = 0
      Position = 1
      TabOrder = 0
    end
    object sHeight: TScrollBar
      Left = 68
      Top = 56
      Width = 261
      Height = 9
      Max = 50
      Min = 1
      PageSize = 0
      Position = 1
      TabOrder = 1
    end
    object s_k2: TScrollBar
      Left = 104
      Top = 80
      Width = 225
      Height = 9
      Max = 500
      Min = 10
      PageSize = 0
      Position = 10
      TabOrder = 2
    end
    object s_k: TScrollBar
      Left = 104
      Top = 104
      Width = 225
      Height = 9
      Min = 10
      PageSize = 0
      Position = 10
      TabOrder = 3
    end
    object btnFont: TButton
      Left = 16
      Top = 128
      Width = 73
      Height = 21
      Caption = #1064#1088#1080#1092#1090
      TabOrder = 4
      OnClick = btnFontClick
    end
    object btnColor: TButton
      Left = 100
      Top = 128
      Width = 81
      Height = 21
      Caption = #1062#1074#1077#1090' '#1092#1086#1085#1072
      TabOrder = 5
      OnClick = btnColorClick
    end
  end
  object Menu: TMainMenu
    Left = 408
    Top = 16
    object N1: TMenuItem
      Caption = #1042#1080#1076
      object Roditeli: TMenuItem
        Caption = #1054#1090#1086#1073#1088#1072#1078#1072#1090#1100' '#1088#1086#1076#1080#1090#1077#1083#1077#1081' '#1089#1091#1087#1088#1091#1075#1086#1074
        Checked = True
        OnClick = RoditeliClick
      end
      object Vertex: TMenuItem
        Caption = #1042#1077#1088#1096#1080#1085#1099
      end
      object Param: TMenuItem
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
        OnClick = ParamClick
      end
    end
  end
  object FontDialog: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Left = 216
    Top = 132
  end
  object ColorDialog: TColorDialog
    Ctl3D = True
    Left = 260
    Top = 132
  end
end
