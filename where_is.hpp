/**
 * @file where_is.hpp
 * @author SAMAKAKI
 * @brief 
 * @version 0.1
 * @date 2023-07-01
 * 
 */

#pragma once

#ifndef __WHERE_IS_
#define __WHERE_IS_

#include <iostream>
#include <dirent.h>
#include <functional>
#include "colorizing_text.hpp"

#define MAIN_PATH "/"


/**
 * @brief whereis namespace
 */
namespace whereis{
    /**
     * @brief return file path
     * 
     * @param name_file name your file which you would like find(with file extension for example main.hpp)
     * @param path place where you would like find file(/your/path/)
     * @param path_view function which return path 
     */
    void find_file(const std::string &name_file, const std::string &path, std::function<void(const std::string &)> path_view){
        if(DIR* dir = opendir(path.c_str())){
            while(dirent* f = readdir(dir)){
                if(!f->d_name || f->d_name[0] == '.') continue;
                if(f->d_type == DT_DIR){
                    find_file(name_file, path + f->d_name + "/", path_view);
                }
                if(f->d_type == DT_REG){
                    if(f->d_name == name_file){
                        path_view(path + f->d_name);
                    }
                }
            }

            closedir(dir);
        }
    }

    /**
     * @brief return folder path
     * 
     * @param name_folder name your folder which you would like find
     * @param path place where you would like find folder(/your/path/)
     * @param path_view function which return path
     */
    void find_folder(const std::string &name_folder, const std::string &path, std::function<void(const std::string &)> path_view){
        if(DIR* dir = opendir(path.c_str())){
            while(dirent* f = readdir(dir)){
                if(!f->d_name || f->d_name[0] == '.') continue;
                if(f->d_type == DT_DIR){
                    if(f->d_name == name_folder)
                        path_view(path + f->d_name);

                    find_folder(name_folder, path + f->d_name + "/", path_view);
                }
            }

            closedir(dir);
        }
    }
}


#endif