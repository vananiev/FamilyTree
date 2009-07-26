object Form1: TForm1
  Left = 266
  Top = 118
  Width = 773
  Height = 535
  Caption = #1056#1086#1076#1086#1089#1083#1086#1074#1085#1086#1077' '#1076#1077#1088#1077#1074#1086
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = Menu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnActivate = FormActivate
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 75
    Height = 13
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1060#1048#1054':'
  end
  object TLabel
    Left = 440
    Top = 184
    Width = 136
    Height = 13
    Caption = #1041#1083#1080#1078#1072#1081#1096#1080#1077' '#1088#1086#1076#1089#1090#1074#1077#1085#1085#1080#1082#1080':'
  end
  object Label2: TLabel
    Left = 40
    Top = 184
    Width = 74
    Height = 13
    Caption = #1048#1079#1074#1077#1089#1090#1085#1086', '#1095#1090#1086':'
  end
  object Label3: TLabel
    Left = 24
    Top = 120
    Width = 49
    Height = 13
    Caption = #1053#1072#1081#1076#1077#1085#1099':'
  end
  object Label4: TLabel
    Left = 184
    Top = 32
    Width = 8
    Height = 29
    Caption = '-'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 8
    Top = 40
    Width = 64
    Height = 13
    Caption = #1043#1086#1076#1099' '#1078#1080#1079#1085#1080':'
  end
  object Label6: TLabel
    Left = 8
    Top = 72
    Width = 98
    Height = 13
    Caption = #1052#1077#1089#1090#1086' '#1078#1080#1090#1077#1083#1100#1089#1090#1074#1072':'
  end
  object imFoto: TImage
    Left = 592
    Top = 40
    Width = 137
    Height = 121
    Stretch = True
  end
  object edSerName: TEdit
    Left = 112
    Top = 8
    Width = 169
    Height = 21
    TabOrder = 0
  end
  object data: TMemo
    Left = 16
    Top = 208
    Width = 417
    Height = 249
    Lines.Strings = (
      'data')
    TabOrder = 1
  end
  object Relative: TListBox
    Left = 432
    Top = 208
    Width = 313
    Height = 249
    ItemHeight = 13
    TabOrder = 2
    OnDblClick = RelativeDblClick
    OnMouseDown = RelativeMouseDown
  end
  object btnFind: TButton
    Left = 400
    Top = 104
    Width = 137
    Height = 17
    Caption = #1048#1089#1082#1072#1090#1100
    Default = True
    TabOrder = 3
    OnClick = btnFindClick
  end
  object lstPpl: TComboBox
    Left = 88
    Top = 120
    Width = 281
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 4
    OnChange = lstPplChange
  end
  object edName: TEdit
    Left = 280
    Top = 8
    Width = 169
    Height = 21
    TabOrder = 5
  end
  object edOtchestvo: TEdit
    Left = 448
    Top = 8
    Width = 161
    Height = 21
    TabOrder = 6
  end
  object edBorn: TEdit
    Left = 112
    Top = 40
    Width = 65
    Height = 21
    TabOrder = 7
  end
  object edDead: TEdit
    Left = 200
    Top = 40
    Width = 65
    Height = 21
    TabOrder = 8
  end
  object edResidence: TEdit
    Left = 112
    Top = 72
    Width = 153
    Height = 21
    TabOrder = 9
  end
  object btnModify: TButton
    Left = 400
    Top = 120
    Width = 137
    Height = 17
    Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 10
    OnClick = btnModifyClick
  end
  object btnAddRel2: TButton
    Left = 400
    Top = 136
    Width = 137
    Height = 17
    Caption = #1053#1086#1074#1099#1081' '#1088#1086#1076#1089#1090#1074#1077#1085#1085#1080#1082
    TabOrder = 11
    OnClick = btnAddRel2Click
  end
  object btnAddRelEx: TButton
    Left = 400
    Top = 152
    Width = 137
    Height = 17
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1088#1086#1076#1089#1090#1074#1077#1085#1085#1080#1082#1072
    TabOrder = 12
    OnClick = btnAddRelExClick
  end
  object btnDelRel: TButton
    Left = 432
    Top = 432
    Width = 313
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1088#1086#1076#1089#1090#1074#1077#1085#1085#1091#1102' '#1089#1074#1103#1079#1100
    TabOrder = 13
    Visible = False
    OnClick = btnDelRelClick
  end
  object btnDir: TButton
    Left = 592
    Top = 160
    Width = 137
    Height = 17
    Caption = #1055#1088#1086#1089#1084#1086#1090#1088' '#1087#1072#1087#1082#1080
    TabOrder = 14
    Visible = False
    OnClick = btnDirClick
  end
  object Menu1: TMainMenu
    AutoLineReduction = maManual
    OwnerDraw = True
    Left = 560
    Top = 40
    object N2: TMenuItem
      Caption = #1060#1072#1081#1083
      object N5: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100
        OnClick = N5Click
      end
      object N6: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        OnClick = N6Click
      end
      object N10: TMenuItem
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100
        OnClick = N10Click
      end
      object CreateTree: TMenuItem
        Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100' '#1076#1077#1088#1077#1074#1086
        OnClick = CreateTreeClick
      end
    end
    object N1: TMenuItem
      Caption = #1054#1073#1098#1077#1082#1090
      object N3: TMenuItem
        Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1053#1086#1074#1099#1081' '#1088#1086#1076#1089#1090#1074#1077#1085#1085#1080#1082
        OnClick = N4Click
      end
      object N7: TMenuItem
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1088#1086#1076#1089#1090#1074#1077#1085#1085#1080#1082#1072
        OnClick = N7Click
      end
      object N8: TMenuItem
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100
        OnClick = N8Click
      end
      object N9: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100
        OnClick = N9Click
      end
    end
  end
  object OpenDialog: TOpenDialog
    Filter = #1060#1072#1081#1083#1099' '#1076#1099#1085#1085#1099#1093'|*.rel|'#1042#1089#1077'|*.*'
    Left = 632
  end
  object SaveDialog: TSaveDialog
    Filter = #1060#1072#1081#1083#1099' '#1076#1099#1085#1085#1099#1093'|*.rel|'#1042#1089#1077'|*.*'
    Left = 688
  end
end
