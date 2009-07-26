object Form4: TForm4
  Left = 293
  Top = 426
  Width = 728
  Height = 246
  Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1088#1086#1076#1089#1090#1074#1077#1085#1085#1080#1082#1072
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
  object Label8: TLabel
    Left = 48
    Top = 88
    Width = 85
    Height = 13
    Caption = #1050#1077#1084' '#1087#1088#1080#1093#1086#1076#1080#1090#1089#1103':'
  end
  object lblRel: TLabel
    Left = 312
    Top = 88
    Width = 3
    Height = 13
  end
  object Label7: TLabel
    Left = 288
    Top = 88
    Width = 18
    Height = 13
    Caption = #1076#1083#1103
  end
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 127
    Height = 13
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1088#1086#1076#1089#1090#1074#1077#1085#1085#1080#1082#1072':'
  end
  object lblMer: TLabel
    Left = 48
    Top = 120
    Width = 58
    Height = 13
    Caption = #1054#1090' '#1073#1088#1072#1082#1072' '#1089':'
    Visible = False
  end
  object lblNotMer: TLabel
    Left = 232
    Top = 120
    Width = 173
    Height = 13
    Caption = #1085#1077' '#1074' '#1073#1088#1072#1082#1077' ('#1080#1083#1080' '#1085#1077' '#1091#1082#1072#1079#1072#1085' '#1089#1091#1087#1088#1091#1075'):'
    Visible = False
  end
  object lblWho: TLabel
    Left = 40
    Top = 120
    Width = 3
    Height = 13
  end
  object edLink: TComboBox
    Left = 152
    Top = 88
    Width = 113
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = #1089#1091#1087#1088#1091#1075'('#1072')'
    OnChange = edLinkChange
    Items.Strings = (
      #1089#1091#1087#1088#1091#1075'('#1072')'
      #1089#1099#1085'('#1076#1086#1095#1100')'
      #1086#1090#1077#1094'('#1084#1072#1090#1100')')
  end
  object btnAdd: TButton
    Left = 544
    Top = 168
    Width = 65
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
  object btnCancel: TButton
    Left = 624
    Top = 168
    Width = 73
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 2
  end
  object lstPpl: TComboBox
    Left = 48
    Top = 40
    Width = 281
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 3
  end
  object lstS: TComboBox
    Left = 48
    Top = 144
    Width = 281
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 4
    Visible = False
  end
end
