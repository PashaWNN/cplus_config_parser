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
    cout << "Hello, " << Name << "!\n";
    int count = config->GetInt("Count");
    vector<int> test = config->GetIntArray("intArr");
    for (int i = 0; i < count; i++) {
        cout << "intArr[" << i << "] = " << test[i] << endl;
    }
    config->SetString("Name", "Pasha");                 //Writing various types of data to registry
    config->SetInt("Integer", 1337);
    config->SetInt("Count", 5);
    config->SetFloat("Float", 0.5);
    config->SetBool("positive", true);
    config->SetBool("negative", false);
    vector<int> ia(5, 1);
    vector<string> sa(3, "abc");
    config->SetIntArray("intArr", ia);
    config->SetStringArray("strArray", sa);
    config->SaveConfig("test.conf");                    //Saving registry to file
    return 0;
}

