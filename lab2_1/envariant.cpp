#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <locale>
#include <cstdlib>

char ruvowels[10] {'а','е','ё','ю','я','у','э','о','и','ы'};
char ruconsonants[22] {'б','й','к','н','г','ш','щ','з','х','ъ','ф','в','п','р','л','д','ж','ч','с','м','т', 'ь'};
char vowels[6] {'a','e','i','u','y','o'};
char consonants[20] {'b','c','d','f','g','h','k','l','j','m','n','p','q','r','s','t','v','w','x','z'};
char numbers[10] {'0','1','2','3','4','5','6','7','8','9'};
char signs[31] {'`','~','!','#','$','%','^','&','*','(',')','-','_','=','+','[',']','{','}','|','\\','/','?',',','.','\'','"','№',';',':',' '};

void printWindowsApi(std::string string, std::vector<std::vector<char>> vec){
    std::vector colors{FOREGROUND_RED,FOREGROUND_BLUE,FOREGROUND_GREEN,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    for(auto s : string){
        bool printed = false;
        if(s == ' '){
            SetConsoleTextAttribute(console, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            std::cout<<s;
            printed = true;
        }else{
            for(int i = 0; i < vec.size(); ++i){
                for(int j = 0; j < vec[i].size(); ++j){
                    if(s <= 'Z' && s >= 'A'){
                        if(s+32 == vec[i][j]){
                            SetConsoleTextAttribute(console, colors[i]);
                            std::cout<<s;
                            printed = true;
                        }
                    }else{
                        if(s == vec[i][j]){
                            SetConsoleTextAttribute(console, colors[i]);
                            std::cout<<s;
                            printed = true;
                        }
                    }
                }
            }
        }
        if(!printed){
            SetConsoleTextAttribute(console, colors[4]);
            std::cout<<s;
        }

    }
    SetConsoleTextAttribute(console, colors[4]);
    std::cout<<"\n";
}


void printANSI(std::string string, std::vector<std::vector<char>> vec){
    bool inVec = false;
    for (char s : string){
        inVec = false;
        for(int i = 0; i < vec.size(); ++i){
            for(int j = 0; j < vec[i].size(); ++j){
                if(s >= 'A' && s <= 'Z'){
                    if(s+32 == vec[i][j]){
                        inVec = true;
                        switch (i){
                        case 0:
                            std::cout<<"\033[31m"<<s<<"\033[0m";
                            break;
                        case 1:
                            std::cout<<"\033[34m"<<s<<"\033[0m";
                            break;
                        case 2:
                            std::cout<<"\033[32m"<<s<<"\033[0m";
                            break;
                        case 3:
                            std::cout<<"\033[33m"<<s<<"\033[0m";
                            break;
                        default:
                            break;
                        }
                    }
                }else{
                    if(s == vec[i][j]){
                        inVec = true;
                        if(s == ' '){
                            std::cout<<"\033[33;43m"<<s<<"\033[0m";
                            continue;
                        }
                        switch (i){
                        case 0:
                            std::cout<<"\033[31m"<<s<<"\033[0m";
                            break;
                        case 1:
                            std::cout<<"\033[34m"<<s<<"\033[0m";
                            break;
                        case 2:
                            std::cout<<"\033[32m"<<s<<"\033[0m";
                            break;
                        case 3:
                            std::cout<<"\033[33m"<<s<<"\033[0m";
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
        }
        if(!inVec){
            std::cout<<s;
        }
    }
}

int find(char c){
    for(char sym : vowels){
        if(c == sym){
            return 0;
        }
    }
    for(char sym : consonants){
        if(c == sym){
            return 1;
        }
    }
    for(char sym : numbers){
        if(c == sym){
            return 2;
        }
    }
    for(char sym : signs){
        if(c == sym){
            return 3;
        }
    }
    return -1;
}
int main(){
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    system("chcp 65001");
    system("cls");
    //std::setlocale(LC_CTYPE, "RU-ru.UTF-8");
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::vector<char>> arr;
    arr.reserve(4);
    std::vector<char> vowel;
    vowel.reserve(6);
    std::vector<char>consonant;
    consonant.reserve(20);
    std::vector<char> number;
    number.reserve(10);
    std::vector<char> sign;
    sign.reserve(20);

    for(char s : input){
        int flag;
        if(s <= 'Я' && s >= 'А'){
            s+=32;
            flag = find(s);
        }else{
            flag = find(s);
        }
        switch(flag){
            bool add;
            case 0: 
                add = true;
                for(char c : vowel){
                    if(c == s){
                        add = false;
                        break;
                    }
                }
                if(add){
                    vowel.push_back(s);
                }
                break;
            case 1:
                add = true;
                for(char c : consonant){
                    if(c == s){
                        add = false;
                        break;
                    }
                }
                if(add){
                    consonant.push_back(s);
                }
                break;
            case 2:
                add = true;
                for(char c : number){
                    if(c == s){
                        add = false;
                        break;
                    }
                }
                if(add){
                    number.push_back(s);
                }
                break;
            case 3:
                add = true;
                for(char c : sign){
                    if(c == s){
                        add = false;
                        break;
                    }
                }
                if(add){
                    sign.push_back(s);
                }
                break;            
            case -1:
                break;
        }
    }
    arr.push_back(vowel);
    arr.push_back(consonant);
    arr.push_back(number);
    arr.push_back(sign);
    for(int i =0; i <arr.size();++i){
        for(int j = 0; j <arr[i].size();++j){
            std::cout<<arr[i][j];
        }
        std::cout<<std::endl;
    }
    //input += "+АБВ123";
    input += "+ABC123";
    printWindowsApi(input, arr);
    printANSI(input, arr);
}