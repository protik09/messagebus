@echo off

:: Old command below
::
:: pdflatex Assn3_3.3.tex

:: List all tex files in the directory without fancy headers and write to variable
dir *.tex /s /b /o:gn > tempfile
:: Stupid batch hack to assign value to variable from command output
set /p tex_file= < tempfile
del tempfile
:: Convert Latex to PDF
pdflatex "%tex_file%"

:: Wait for user input
PAUSE

@echo on