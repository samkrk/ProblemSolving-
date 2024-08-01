#include "DownloadingFiles/DownloadingFiles.hpp"
#include <iostream>

int main(void){
    DownloadingFiles downloader;
    std::vector<std::string> tasks;
    tasks.push_back("25 1000");    
    tasks.push_back("5 5000");
    tasks.push_back("10 5000");

    std::cout << downloader.actualTime(tasks) << std::endl;
    return 0;
}