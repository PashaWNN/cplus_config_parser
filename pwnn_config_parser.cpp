
#include "pwnn_config_parser.h"
#include <regex>   // Moa-ha-ha-ha-ha
#include <iostream>
#include <fstream>

    void pwnn_config_parser::LoadConfig(string fn) {
        ifstream file(fn);
        string str;
        while(getline(file, str)) {
            Push(str); //Parse line
        }
    }
    
    void pwnn_config_parser::Push(string str) {
        std::regex re("^(bool|string|int|float) ([A-Za-z]+):(.+)");
        std::smatch m;
        if (std::regex_match(str, m, re)) {
            string valType = m[1];
            string Name = m[2];
            string Value = m[3];
            if (valType == "bool") {
                if (Value == "true") {
                    SetBool(Name, true);
                } else
                    if (Value == "false") {
                        SetBool(Name, false);
                    }
            } else
                if (valType == "string") {
                    SetString(Name, Value);
                } else
                    if (valType == "int") {
                        try {
                        SetInt(Name, std::stoi(Value));
                        }
                        catch (const std::invalid_argument& ia) {}
                    } else
                        if (valType == "float") {
                            try {
                            SetFloat(Name, std::stof(Value));
                            }
                            catch (const std::invalid_argument& ia) {}
                        }
        }
    }
    
    void pwnn_config_parser::SaveConfig(string fn) {
        ofstream file;
        file.open(fn);
        for(auto& i: Strings) {
            file << "string " << i.first << ":" << i.second << endl;
        }
        for(auto& i: Floats) {
            file << "float " << i.first << ":" << i.second << endl;
        }
        for(auto& i: Integers) {
            file << "int " << i.first << ":" << i.second << endl;
        }
        for(auto& i: Booleans) {
            std::string boolean;
            if (i.second) {
                boolean = "true";
            } else {
                boolean = "false";
            }
            file << "bool " << i.first << ":" << boolean << endl;
        }
        file.close();
    }
    
    string pwnn_config_parser::GetString(string key) {
        return Strings[key];
    }
    
    int pwnn_config_parser::GetInt(string key) {
        return Integers[key];
    }
    
    bool pwnn_config_parser::GetBool(string key) {
        return Booleans[key];
    }
    
    float pwnn_config_parser::GetFloat(string key) {
        return Floats[key];
    }
    
    void pwnn_config_parser::SetString(string key, string value) {
        Strings[key] = value;
    }
    
    void pwnn_config_parser::SetInt(string key, int value) {
        Integers[key] = value;
    }
    
    void pwnn_config_parser::SetBool(string key, bool value) {
        Booleans[key] = value;
    }
    
    void pwnn_config_parser::SetFloat(string key, float value) {
        Floats[key] = value;
    }
