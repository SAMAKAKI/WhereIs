#include "where_is.hpp"

int main(int argc, char const *argv[]){
    std::string name_file, name_folder, path;

    if(argc < 2){
        printf("%sUse %s or %s to get info about this program!\n", clt::fg_bright_red("[ERROR]: ").c_str(), clt::fg_bright_green("-h").c_str(), clt::fg_bright_blue("--help").c_str());

        return 0;
    } else{
        for(int i = 0; i < argc; i++){
            if(std::string(argv[i]) == "-h" || std::string(argv[i]) == "--help"){
                printf("\n\tUseful information about program:\n\n");
                printf("\t %s  | %s\t\t\t-\tUseful information about program\n", clt::fg_bright_green("-h").c_str(), clt::fg_bright_blue("--help").c_str());
                printf("\t %s | %s\t\t\t-\tFind file (use this with file extension for example file.pdf)\n", clt::fg_bright_green("-fl").c_str(), clt::fg_bright_blue("--file").c_str());
                printf("\t %s | %s\t\t\t-\tFind folder (enter name folder)\n", clt::fg_bright_green("-fd").c_str(), clt::fg_bright_blue("--folder").c_str());
                printf("\t %s  | %s\t\t\t-\tChanging path which will be use for find file/folder (default use \"/\")\n\n", clt::fg_bright_green("-p").c_str(), clt::fg_bright_blue("--path").c_str());

                return 0;
            } else if(std::string(argv[i]) == "-fl" || std::string(argv[i]) == "--file"){
                if(!std::string(argv[i + 1]).empty()){
                    name_file = std::string(argv[i + 1]);
                } else{
                    printf("%sYou must enter name of file which you would like find!\n", clt::fg_bright_red("[ERROR]: ").c_str());

                    return 0;
                }
            } else if(std::string(argv[i]) == "-fd" || std::string(argv[i]) == "--folder"){
                if(!std::string(argv[i + 1]).empty()){
                    name_folder = std::string(argv[i + 1]);
                } else{
                    printf("%sYou must enter name of folder which you would like find!\n", clt::fg_bright_red("[ERROR]: ").c_str());

                    return 0;
                }
            } else if(std::string(argv[i]) == "-p" || std::string(argv[i]) == "--path"){
                if(!std::string(argv[i + 1]).empty()){
                    path = std::string(argv[i + 1]);
                } else{
                    path = MAIN_PATH;
                }
            }
        }

        if(name_file != ""){
            if(path != ""){
                whereis::find_file(name_file, path, [](const std::string &path_view){
                    printf("%s\n", clt::fg_bright_magenta(path_view).c_str());
                });

                return 0;
            } else{
                whereis::find_file(name_file, MAIN_PATH, [](const std::string &path_view){
                    printf("%s\n", clt::fg_bright_magenta(path_view).c_str());
                });

                return 0;
            }
        }

        if(name_folder != ""){
            if(path != ""){
                whereis::find_folder(name_folder, path, [](const std::string &path_view){
                    printf("%s\n", clt::fg_bright_magenta(path_view).c_str());
                });

                return 0;
            } else{
                whereis::find_folder(name_folder, MAIN_PATH, [](const std::string &path_view){
                    printf("%s\n", clt::fg_bright_magenta(path_view).c_str());
                });

                return 0;
            }
        }
    }

    return 0;
}
