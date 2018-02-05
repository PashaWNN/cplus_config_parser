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
Now it supports four data types: that's **int**, **string**, **bool** and **float**.
Parameter syntax is:
`type key:value`
Where **type** is "int", "string", "bool" or "float", **key** is accessing key, satisfying regex "[A-Za-z]+" and **value** is parameter value. *Note that **bool** parameters can have only "true" and "false" lowercase values.*
If value is not valid(e.g. text in int parameter or digits in bool), it's just ignored and doesn't adding to runtime registry.
## More about methods

### pwnn_config_parser::Instance()->LoadConfig(std::string filename)
This method loads config from file to runtime registry.
### pwnn_config_parser::Instance()->SaveConfig(std::string filename)
And this saves it back to file. **Note that file is being rewrited, so don't call SaveConfig before old parameters is loaded from file, if you don't want to lose it.**
### pwnn_config_parser::Instance()->GetString(std::string key)
Get string value from runtime registry by it's key. Note that if this parameter isn't loaded or even specified, null will be returned.
### Other Get* methods are similar.
### pwnn_config_parser::Instance()->SetString(std::string key, std::string value)
Used to set parameter into runtime registry. Don't forget to save changes by SaveConfig().
### And other Set* methods are similar.
