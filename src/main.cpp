#include <iostream>
#include <string>

class InputHandler{
private:
    //this is made to stop the user from entering 10000 element string and causing stack overflow
    static int constexpr MAX_RAW_INPUT_LENGTH = 5;
    static int constexpr MAX_MENU_ITEMS = 5; 
    static int getInput(){
        std::string input = "", effectiveInput = "";

        getline(std::cin, input);

        if(input.empty())
            return INVALID_INPUT;

        if(input.size() > MAX_RAW_INPUT_LENGTH)
            return INVALID_INPUT;

        for(char ch : input){
            if(ch == ' ') continue; //ignore spaces
            if(!std::isdigit(ch))
                return INVALID_INPUT;    
            effectiveInput += ch;
        }

        //if max input changed in the future, this will prevent out of range input
        try{
            int choice = std::stoi(effectiveInput);
            return (choice >= 1 && choice <= MAX_MENU_ITEMS) ? choice : INVALID_INPUT;
        }catch(...){
            return INVALID_INPUT;
        }

    }

public:
    static constexpr int INVALID_INPUT = -1;
    static int getUserOperation(){
        std::cout<<"**********************************************************"<<std::endl<<std::endl;
        std::cout<<"        Welcome to smart Home Automation Assistant"<<std::endl<<std::endl;
        std::cout<<"**********************************************************"<<std::endl<<std::endl;

        std::cout<<"1) create device"<<std::endl;
        std::cout<<"2) list device info"<<std::endl;
        std::cout<<"3) list devices' info"<<std::endl;
        std::cout<<"4) remove device"<<std::endl;
        std::cout<<"5) exit"<<std::endl<<std::endl;
        
        std::cout<<"Choose operation: ";
        return getInput();
    }

};

int main(){
    int input = InputHandler::getUserOperation();
    if(input == InputHandler::INVALID_INPUT)
        std::cout<<"input a valid choice within range"<<std::endl;
}