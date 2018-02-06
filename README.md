# C++ Config Parser(CCP)

## What's this?
Okay, I'm recently started to learn C++ language and first problem I encountered when I was writing my little pet-project is to effectively store and read settings of my software, so I decided to make very simple and lightweight library for saving and reading data from configuration files. That's it.

## Ok, how can I use it in my project?
First of all, add pwnn_config_parser.* files to your project. Then `#include pwnn_config_parser.h`. Also you can add macro for easier access to CCP methods as shown in example.cpp

After that you're ready to use parser. Load your configuration file with LoadConfig method
```$xslt
#define config pwnn_config_parser::Instance() //Macro for easier access to config
#include <cstdlib>
#include <iostream>
#include "pwnn_config_parser.h"

using namespace std;

int main(int argc, char** argv) {
    config->LoadConfig("test.conf");                    //Loading a config from "test.conf"
    std::string Name = config->GetString("Name");       //Getting variable from runtime registry
    cout << "Hello, " << Name << "!\n";
    cin >> Name;
    config->SetString("Name", Name);                    //Rewriting variable in registry
    config->SaveConfig("test.conf");                    //Saving registry to file
    return 0;
}
```

## File format
CCP uses very simple syntax for configuration files:
Now it supports four data types: that's **int**, **string**, **bool** and **float** and arrays for it.
Parameter syntax is:
`type key:value`
Where **type** is "int", "string", "bool" or "float", **key** is accessing key, satisfying regex "[A-Za-z]+" and **value** is parameter value. *Note that **bool** parameters can have only "1" and "0" values.*
If it's an array, there is "array" word in begin of line and values is separated by semicolon. Semicolon at the end of line is required.
If value is not valid(e.g. text in int parameter or digits in bool), it's just ignored and doesn't adding to runtime registry.
Example of valid config:
```
This is a comment line
string Name:Nick
string Surname:Ericsson
int age:29
array string Friends:Peter;Jack;Daniel;
bool haveChildren:0
float height:176.0

int invalid:10 there is some text after parameter so this parameter wouldn't be read.
```
## All methods
```
void LoadConfig(std::string filename); //This method loads config from file to runtime registry.
void SaveConfig(std::string filename); //And this saves it back to file.
//Note that file is being rewrited, so don't call SaveConfig before old parameters is loaded from file, if you don't want to lose it.
std::string GetString(std::string key);
int GetInt(std::string key);
float GetFloat(std::string key);
bool GetBool(std::string key);
//Get value from runtime registry by it's key. Note that if this parameter isn't loaded or even specified, null will be returned.
void SetString(std::string key, std::string value);
void SetInt(std::string key, int value);
void SetFloat(std::string key, float value);
void SetBool(std::string key, bool value);
//Used to set parameter into runtime registry. Don't forget to save changes by SaveConfig().
std::vector<std::string> GetStringArray(std::string key);
std::vector<float> GetFloatArray(std::string key);
std::vector<int> GetIntArray(std::string key);
std::vector<bool> GetBoolArray(std::string key);
//Used to get arrays from runtime registry
void SetStringArray(std::string key, std::vector<std::string> array);
void SetIntArray(std::string key, std::vector<int> array);
void SetFloatArray(std::string key, std::vector<float> array);
void SetBoolArray(std::string key, std::vector<bool> array);
//Used to set arrays
```

