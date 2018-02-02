# C++ Config Parser

## What's this?
Okay, I'm recently started to learn C++ language and first problem I encountered when I was writing my little pet-project is to effectively store and read settings of my software, so I decided to make very simple and lightweight library for saving and reading data from configuration files. That's it.

## Ok, how can I use it in my project?
Oh, it's very simple: you include *pwnn_config_parser.h* in your project, load config with **pwnn_config_parser::Instance()->LoadConfig(filename)** and then you can access it's data from any point of your program with **...->GetInt()**, **...->GetString()** etc. because it uses *singleton* pattern. You can see example of using this library in file **main.cpp** — this file isn't a part of library, just example.
