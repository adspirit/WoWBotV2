   M S B A M L   `   `   `  ����   AgonyLauncher)    #AgonyLauncher.Windows.PluginsWindow   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     @d2http://schemas.microsoft.com/expression/blend/2008     Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     -     � Title$  Plugins��$	��450��$	��750�� � WindowStartupLocation$ CenterScreen=�$	��650��$	��300�����	#FF333333 � 	Resources  �� MergedDictionaries �� Source��  �� $# ../Styles/ExpressionDark.xaml?�%    .��]� .+��  � RowDefinitions �� $��40 ��� $��* ��� $��40 �.+�� $��0��.+��� -    ��Name$ ButtonNewPlugin��$��5q�$��
New Plugin��� $��1��.+�&   System.Windows.Controls.DataGrid  -     Name$ PluginsGrid��$ �� IsSynchronizedWithCurrentItem$
 TrueY�	   GridLinesVisibility$	 Vertical=�
   CanUserAddRows
 .     HeadersVisibility$ Column=�   CanUserReorderColumns .    CanUserResizeColumns .     CanUserSortColumns .     AutoGenerateColumns .     CanUserResizeRows .  $
��Left=�$��Disabled=�$
��Auto=�����    Columns 4  .System.Windows.Controls.DataGridTemplateColumn  ,  &System.Windows.Controls.DataGridColumn   Header$ Enabled��   MinWidth$ 55Q�   CellTemplate �� .R���  ��Name$ PluginEnabledCheckBox��-   $��Center=�$��Center=�
 � Tag ��  d� 	IsChecked �� *
IsActive+0  *System.Windows.Controls.DataGridTextColumn  $
 Name��   Width5  /System.Windows.Controls.DataGridLengthConverter$
 100*    
IsReadOnly . 1  +System.Windows.Controls.DataGridBoundColumn   Binding �� *AssemblyName+  $ Author��$
 100*  .  �� *Author+  $
 Type��$	 100  .  �� *Type+  $ Location��$
 100*  .  �� *
Location+  $ Version��$	 100  .  �� *	Version+  $ Status��$	 100  .  �� *Status+   RowStyle ��  �� 
TargetType)  #System.Windows.Controls.DataGridRow"   �� BasedOn# [B .�-   ��  �� Property �@�ContextMenu �� Value ��   ��Name$  RowContextMenu��.@�m� ! m�Name$! 
EnableMenu��$��Enable�� �� ���� " m�# [Bm�.�-   ��  � y�$ 	Collapsed=�" �� Triggers" �� # �� Binding# �� *
IsActive+$ �� Value	$ False.a���  � y�$ Visible=�m� $! DisableMenu��$��Disable�� �� ���� " m�# [Bm�.�-   ��  � y�$ 	Collapsed=�" �� # �� *
IsActive+$ True.a���  � y�$ Visible=�m� $! OpenLocationMenu��$��Open Location�� �� ���� " m�# [Bm�.�-   � $��2��.+�� $	��5 0q�% � ColumnDefinitions% �� $	��100 ��� $	��100 ��� $��* ��� $	��100 ��� $	��100 ��� $	��100 ��� $	��100 �.+��� -	   $ ButtonEnableAll��$��5q�$��0��$��Enable���� -
   $ ButtonDisableAll��$��5q�$��1��$��Disable���� -   $ ButtonSettings��$��5q�$��3��$��Settings���� -   $ ButtonUpdate��$��5q�$��4��$��Update���� -   $ ButtonRecomile��$��5q�$��5��$��	Recompile���� -   $ ButtonUninstall��$��5q�$��6��$��	Uninstall��