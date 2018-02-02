/*
 * This is an example of using pwnn_config_parser.
 */

#include <cstdlib>
#include <iostream>
#include "pwnn_config_parser.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    pwnn_config_parser::Instance()->LoadConfig("test.conf");                    //Loading a config from "test.conf"
    std::string Name = pwnn_config_parser::Instance()->GetString("Name");       //Getting variables from loaded registry
    int count = pwnn_config_parser::Instance()->GetInt("Count");
    for (int i = 0; i < count; i++) {                                         
        cout << "Hello, " << Name << "!\n";
        /*cout << "Enter key: ";                                                //You can uncomment it to write custom string to test.conf
        std::string key;
        std::string val;
        cin >> key;
        cout << "Enter value: ";
        cin >> val;
        pwnn_config_parser::Instance()->SetString(key, val); */
    }
    pwnn_config_parser::Instance()->SetString("Name", "Pasha");                 //Writing various types of data to registry
    pwnn_config_parser::Instance()->SetInt("Integer", 1337);
    pwnn_config_parser::Instance()->SetInt("Count", 1);
    pwnn_config_parser::Instance()->SetFloat("Float", 0.5);
    pwnn_config_parser::Instance()->SetBool("positive", true);
    pwnn_config_parser::Instance()->SetBool("negative", false);
    pwnn_config_parser::Instance()->SaveConfig("test.conf");                    //Saving registry to file
    return 0;
}

