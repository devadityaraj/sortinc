@echo off
setlocal

REM --- Configuration ---
set "INSTALL_DIR=C:\Include"
set "HEADER_FILE=sort.h"

REM --- Check if file exists ---
if not exist "%HEADER_FILE%" (
    echo Error: The file '%HEADER_FILE%' was not found in the current directory.
    echo Please run this script from the same directory as '%HEADER_FILE%'.
    exit /b 1
)

REM --- Create installation directory if it doesn't exist ---
if not exist "%INSTALL_DIR%" (
    echo Creating installation directory: %INSTALL_DIR%
    mkdir "%INSTALL_DIR%"
    if errorlevel 1 (
        echo Error: Could not create directory %INSTALL_DIR%. Check your permissions.
        exit /b 1
    )
)

REM --- Copy file ---
echo Copying '%HEADER_FILE%' to '%INSTALL_DIR%'...
copy "%HEADER_FILE%" "%INSTALL_DIR%\" >nul
if errorlevel 1 (
    echo Error: Failed to copy the file. Check your permissions.
    exit /b 1
)

echo Installation successful!
echo.
echo To use the library, simply include it in your C code:
echo #include ^<sort.h^>
echo.
echo Then compile your program as usual:
echo cl your_program.c /I "%INSTALL_DIR%" /Fe:your_program.exe

endlocal
pause
