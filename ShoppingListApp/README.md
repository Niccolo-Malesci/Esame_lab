Posizionarsi sulla cartella principale del progetto
da prompt dei comandi poi:

rmdir /s /q build
mkdir build
cd build
cmake ..
cmake --build . --config Debug
Debug\runTests.exe
