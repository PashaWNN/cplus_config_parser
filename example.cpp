/*
 * This is an example of using pwnn_config_parser.
 */
#define config pwnn_config_parser::Instance()
#include <cstdlib>
#include <iostream>
#include "pwnn_config_parser.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    config->LoadConfig("test.conf");                    //Loading a config from "test.conf"
    std::string Name = config->GetString("Name");       //Getting variables from loaded registry
    int count = config->GetInt("Count");
    for (int i = 0; i < count; i++) {                                         
        cout << "Hello, " << Name << "!\n";
        /*cout << "Enter key: ";                                                //You can uncomment it to write custom string to test.conf
        std::string key;
        std::string val;
        cin >> key;
        cout << "Enter value: ";
        cin >> val;
        config->SetString(key, val); */
    }
    config->SetString("Name", "Pasha");                 //Writing various types of data to registry
    config->SetInt("Integer", 1337);
    config->SetInt("Count", 1);
    config->SetFloat("Float", 0.5);
    config->SetBool("positive", true);
    config->SetBool("negative", false);
    config->SaveConfig("test.conf");                    //Saving registry to file
    return 0;
}

