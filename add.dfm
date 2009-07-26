object Form2: TForm2
  Left = 291
  Top = 425
  Width = 729
  Height = 235
  Caption = #1053#1086#1074#1099#1081' '#1088#1086#1076#1089#1090#1074#1077#1085#1085#1080#1082
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
    Top = 72
    Width = 64
    Height = 13
    Caption = #1043#1086#1076#1099' '#1078#1080#1079#1085#1080':'
  end
  object Label6: TLabel
    Left = 16
    Top = 104
    Width = 98
    Height = 13
    Caption = #1052#1077#1089#1090#1086' '#1078#1080#1090#1077#1083#1100#1089#1090#1074#1072':'
  end
  object Label2: TLabel
    Left = 16
    Top = 168
    Width = 31
    Height = 13
    Caption = #1060#1086#1090#1086':'
  end
  object Label3: TLabel
    Left = 16
    Top = 144
    Width = 32
    Height = 13
    Caption = #1060#1072#1081#1083':'
  end
  object Label8: TLabel
    Left = 16
    Top = 40
    Width = 85
    Height = 13
    Caption = #1050#1077#1084' '#1087#1088#1080#1093#1086#1076#1080#1090#1089#1103':'
  end
  object lblRel: TLabel
    Left = 280
    Top = 40
    Width = 3
    Height = 13
    FocusControl = edSerName
  end
  object Label7: TLabel
    Left = 256
    Top = 40
    Width = 18
    Height = 13
    Caption = #1076#1083#1103
  end
  object Label4: TLabel
    Left = 192
    Top = 64
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
  object lblMer: TLabel
    Left = 344
    Top = 64
    Width = 58
    Height = 13
    Caption = #1054#1090' '#1073#1088#1072#1082#1072' '#1089':'
    Visible = False
  end
  object Label9: TLabel
    Left = 304
    Top = 144
    Width = 35
    Height = 13
    Caption = #1055#1072#1087#1082#1072':'
  end
  object edSerName: TEdit
    Left = 120
    Top = 8
    Width = 169
    Height = 21
    TabOrder = 0
  end
  object edName: TEdit
    Left = 288
    Top = 8
    Width = 169
    Height = 21
    TabOrder = 1
  end
  object edOtchestvo: TEdit
    Left = 456
    Top = 8
    Width = 161
    Height = 21
    TabOrder = 2
  end
  object edBorn: TEdit
    Left = 120
    Top = 72
    Width = 65
    Height = 21
    TabOrder = 3
  end
  object edDead: TEdit
    Left = 208
    Top = 72
    Width = 65
    Height = 21
    TabOrder = 4
  end
  object edFoto: TEdit
    Left = 120
    Top = 168
    Width = 153
    Height = 21
    TabOrder = 5
    OnDblClick = edFotoDblClick
  end
  object btnAdd: TButton
    Left = 552
    Top = 168
    Width = 65
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    Default = True
    ModalResult = 1
    TabOrder = 6
    OnClick = btnAddClick
  end
  object edFile: TEdit
    Left = 120
    Top = 144
    Width = 153
    Height = 21
    TabOrder = 7
    OnDblClick = edFileDblClick
  end
  object btnCancel: TButton
    Left = 632
    Top = 168
    Width = 73
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 8
  end
  object edResidence: TMemo
    Left = 120
    Top = 104
    Width = 153
    Height = 33
    Lines.Strings = (
      'edResidence')
    ScrollBars = ssVertical
    TabOrder = 9
  end
  object edLink: TComboBox
    Left = 120
    Top = 40
    Width = 113
    Height = 21
    ItemHeight = 13
    TabOrder = 10
    Text = #1089#1091#1087#1088#1091#1075'('#1072')'
    OnChange = edLinkChange
    Items.Strings = (
      #1089#1091#1087#1088#1091#1075'('#1072')'
      #1089#1099#1085'('#1076#1086#1095#1100')'
      #1086#1090#1077#1094'('#1084#1072#1090#1100')')
  end
  object lstS: TComboBox
    Left = 352
    Top = 88
    Width = 281
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 11
    Visible = False
  end
  object edDir: TEdit
    Left = 376
    Top = 144
    Width = 153
    Height = 21
    TabOrder = 12
    OnDblClick = edDirDblClick
  end
  object OpenDialog: TOpenDialog
    Filter = #1042#1089#1077'|*.*'
    Left = 664
    Top = 16
  end
end
