object Form3: TForm3
  Left = 268
  Top = 169
  Width = 771
  Height = 533
  Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 75
    Height = 13
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1060#1048#1054':'
  end
  object Label5: TLabel
    Left = 16
    Top = 40
    Width = 64
    Height = 13
    Caption = #1043#1086#1076#1099' '#1078#1080#1079#1085#1080':'
  end
  object Label6: TLabel
    Left = 16
    Top = 72
    Width = 98
    Height = 13
    Caption = #1052#1077#1089#1090#1086' '#1078#1080#1090#1077#1083#1100#1089#1090#1074#1072':'
  end
  object Label2: TLabel
    Left = 16
    Top = 136
    Width = 31
    Height = 13
    Caption = #1060#1086#1090#1086':'
  end
  object Label3: TLabel
    Left = 16
    Top = 112
    Width = 32
    Height = 13
    Caption = #1060#1072#1081#1083':'
  end
  object Label4: TLabel
    Left = 192
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
  object Qwes: TLabel
    Left = 520
    Top = 144
    Width = 168
    Height = 13
    Caption = #1042#1099' '#1091#1074#1077#1088#1077#1085#1099', '#1095#1090#1086' '#1093#1086#1090#1080#1090#1077' '#1091#1076#1072#1083#1080#1090#1100'?'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Label9: TLabel
    Left = 296
    Top = 112
    Width = 35
    Height = 13
    Caption = #1055#1072#1087#1082#1072':'
  end
  object imFoto: TImage
    Left = 616
    Top = 8
    Width = 137
    Height = 121
    Stretch = True
  end
  object edSerName: TEdit
    Left = 120
    Top = 8
    Width = 169
    Height = 21
    TabOrder = 0
    Text = #1040#1085#1072#1085#1100#1077#1074
  end
  object edName: TEdit
    Left = 288
    Top = 8
    Width = 169
    Height = 21
    TabOrder = 1
    Text = #1042#1080#1090#1072#1083#1080#1081
  end
  object edOtchestvo: TEdit
    Left = 456
    Top = 8
    Width = 161
    Height = 21
    TabOrder = 2
    Text = #1042#1077#1085#1080#1072#1084#1080#1085#1086#1074#1080#1095
  end
  object edBorn: TEdit
    Left = 120
    Top = 40
    Width = 65
    Height = 21
    TabOrder = 3
  end
  object edDead: TEdit
    Left = 208
    Top = 40
    Width = 65
    Height = 21
    TabOrder = 4
  end
  object edFoto: TEdit
    Left = 120
    Top = 136
    Width = 153
    Height = 21
    TabOrder = 5
    OnDblClick = edFotoDblClick
  end
  object btnAdd: TButton
    Left = 312
    Top = 168
    Width = 65
    Height = 25
    Caption = #1048#1079#1084#1077#1085#1080#1090#1100
    Default = True
    ModalResult = 1
    TabOrder = 6
    OnClick = btnAddClick
  end
  object edFile: TEdit
    Left = 120
    Top = 112
    Width = 153
    Height = 21
    TabOrder = 7
    OnDblClick = edFileDblClick
  end
  object btnCancel: TButton
    Left = 384
    Top = 168
    Width = 73
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 8
  end
  object edResidence: TMemo
    Left = 120
    Top = 72
    Width = 153
    Height = 33
    Lines.Strings = (
      'edResidence')
    ScrollBars = ssVertical
    TabOrder = 9
  end
  object btnAddRel: TButton
    Left = 10
    Top = 168
    Width = 143
    Height = 25
    Caption = #1053#1086#1074#1099#1081' '#1088#1086#1076#1089#1090#1074#1077#1085#1085#1080#1082
    ModalResult = 6
    TabOrder = 10
  end
  object btnRel: TButton
    Left = 160
    Top = 168
    Width = 145
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100'  '#1088#1086#1076#1089#1090#1074#1077#1085#1085#1080#1082#1072
    ModalResult = 8
    TabOrder = 11
  end
  object btnDel: TButton
    Left = 552
    Top = 168
    Width = 73
    Height = 25
    Caption = #1044#1072
    ModalResult = 3
    TabOrder = 12
    Visible = False
  end
  object btnNo: TButton
    Left = 632
    Top = 168
    Width = 73
    Height = 25
    Caption = #1053#1077#1090
    TabOrder = 13
    OnClick = btnNoClick
  end
  object btnQwes: TButton
    Left = 632
    Top = 168
    Width = 75
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 14
    OnClick = btnQwesClick
  end
  object edDir: TEdit
    Left = 368
    Top = 112
    Width = 153
    Height = 21
    TabOrder = 15
    OnDblClick = edDirDblClick
  end
  object data: TMemo
    Left = 0
    Top = 208
    Width = 753
    Height = 289
    Lines.Strings = (
      'data')
    TabOrder = 16
  end
  object btnDir: TButton
    Left = 520
    Top = 112
    Width = 65
    Height = 21
    Caption = #1055#1088#1086#1089#1084#1086#1090#1088
    TabOrder = 17
    OnClick = btnDirClick
  end
  object OpenDialog: TOpenDialog
    Filter = #1042#1089#1077'|*.*'
    Left = 300
    Top = 32
  end
end
