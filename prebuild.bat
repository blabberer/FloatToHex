@echo off
pushd ..
set DBGSDK_INC_PATH=F:\windbg_xp\sdk\inc
set DBGSDK_LIB_PATH=F:\windbg_xp\sdk\lib
set DBGLIB_LIB_PATH=F:\windbg_xp\sdk\lib
@call C:\WinDDK\7600.16385.1\bin\setenv.bat C:\WinDDK\7600.16385.1\ fre x86 WXP
popd
build -cZMg
