@echo off
pushd ..
@call C:\WinDDK\7600.16385.1\bin\setenv.bat C:\WinDDK\7600.16385.1\ fre x86 WXP
popd
build -cZMg
copy .\objfre_wxp_x86\i386\f2h.dll f:\windbg\winext\. /y
