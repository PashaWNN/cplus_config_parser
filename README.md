# C++ Config Parser(CCP)

## What's this?
Okay, I'm recently started to learn C++ language and first problem I encountered when I was writing my little pet-project is to effectively store and read settings of my software, so I decided to make very simple and lightweight library for saving and reading data from configuration files. That's it.

## Ok, how can I use it in my project?
Oh, it's very simple: you include *pwnn_config_parser.h* in your project, load config with **pwnn_config_parser::Instance()->LoadConfig(filename)** and then you can access it's data from any point of your program with **...->GetInt()**, **...->GetString()** etc. because it uses *singleton* pattern. You can see example of using this library in file **main.cpp** — this file isn't a part of library, just example.

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
