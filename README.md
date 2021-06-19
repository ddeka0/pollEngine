#### pollEngine [A genral poll engine all kinds of file destriptor using epoll]
##### [ project under dev and plan to merge this with io_uring support also]

##### Build Command
    1. cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ .
    Or
    1. cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 .

    2. make
    3. ./build/bin/pollEngine


##### Valgrind Check
    1. valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./build/bin/pollEngine


##### Clang-Tidy Check
    1. sudo apt install clang-tidy-9
    2. clang-tidy -p ./ testApp/src/myapp.cpp  --checks="-*,cppcoreguidelines-*,hicpps-*" --header-filter='.*'
        Add -fix to fix

##### Clang-format formatting
    1. find . -regex '.*\.\(cpp\|hpp\|cc\|cxx\)' -exec clang-format -style=file -i {} \;


#### Doxygen Documentation
    1. doxygen Doxyfile


#### Source Trail View
    1. Install Source Trail
    2. Run Cmake to generate compile_commands.json file
    3. Use this file to create a Source Trail Project