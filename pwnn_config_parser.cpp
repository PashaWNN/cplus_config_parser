
#include "pwnn_config_parser.h"
#include <regex>   // Moa-ha-ha-ha-ha
#include <iostream>
#include <fstream>


void pwnn_config_parser::LoadConfig(string fn) {
    ifstream file(fn);
    string str;
    while (getline(file, str)) {
        Push(str); //Parse line
    }
}

void pwnn_config_parser::Push(string str) {
    std::regex var("^(bool|string|int|float) ([A-Za-z]+):(.+)");
    std::regex arr("^array (bool|string|int|float) ([A-Za-z]+):(.+;)");
    std::smatch m;
    if (std::regex_match(str, m, var)) {
        string valType = m[1];
        string Name = m[2];
        string Value = m[3];
        SetVar(Name, valType, Value);
    } else if (std::regex_match(str, m, arr)) {
        string valType = m[1]; //TODO: multiline arrays reading
        string Name = m[2];
        string Value = m[3];
        SetArray(Name, valType, Value);
    }
}

void pwnn_config_parser::SaveConfig(string fn) {
    ofstream file;
    file.open(fn);
    for (auto &i: Strings) {
        file << "string " << i.first << ":" << i.second << endl;
    }
    for (auto &i: Floats) {
        file << "float " << i.first << ":" << i.second << endl;
    }
    for (auto &i: Integers) {
        file << "int " << i.first << ":" << i.second << endl;
    }
    for (auto &i: Booleans) {
        file << "bool " << i.first << ":" << i.second << endl;
    }
    for (auto &i: StringArrays) {
        file << "array string " << i.first << ":" << array_to_string(i.second) << endl;
    }
    for (auto &i: IntegerArrays) {
        file << "array int " << i.first << ":" << array_to_string(i.second) << endl;
    }
    for (auto &i: FloatArrays) {
        file << "array float " << i.first << ":" << array_to_string(i.second) << endl;
    }
    for (auto &i: BooleanArrays) {
        file << "array bool " << i.first << ":" << array_to_string(i.second) << endl;
    }
    file.close();
}

void pwnn_config_parser::SetArray(string key, string valType, string values) {
    vector<string> vals;
    string buffer;
    for (char value : values) {
        if (value != ';') {
            buffer += value;
        } else {
            vals.push_back(buffer);
            buffer = "";
        }
    }
    switch (string_to_type(valType)) {
        case TYPE_STRING:
            SetStringArray(key, vals);
        case TYPE_INT: {
            vector<int> arr;
            for (const auto &val : vals) {
                try {
                    arr.push_back(stoi(val));
                }
                catch (const std::invalid_argument &ia) {}
            }
            SetIntArray(key, arr);
        }
        case TYPE_FLOAT: {
            vector<float> arr;
            for (const auto &val : vals) {
                try {
                    arr.push_back(stof(val));
                }
                catch (const std::invalid_argument &ia) {}
            }
            SetFloatArray(key, arr);
        }
        case TYPE_BOOL: {
            vector<bool> arr;
            for (const auto &val : vals) {
                if (val == "1") {
                    arr.push_back(true);
                } else if (val == "0") {
                    arr.push_back(false);
                }
            }
            SetBoolArray(key, arr);
        }
    }
}

void pwnn_config_parser::SetVar(string key, string valType, string value) {
    switch (string_to_type(valType)) {
        case TYPE_BOOL: {
            if (value == "1") {
                SetBool(key, true);
            } else if (value == "0") {
                SetBool(key, false);
            }
        }
        case TYPE_STRING:
            SetString(key, value);
        case TYPE_INT: {
            try {
                SetInt(key, std::stoi(value));
            }
            catch (const std::invalid_argument &ia) {}
        }
        case TYPE_FLOAT: {
            try {
                SetFloat(key, std::stof(value));
            }
            catch (const std::invalid_argument &ia) {}
        }
    }
}

int pwnn_config_parser::string_to_type(string type) {
    if (type == "string") {
        return TYPE_STRING;
    } else if (type == "float") {
        return TYPE_FLOAT;
    } else if (type == "bool") {
        return TYPE_BOOL;
    } else if (type == "int") {
        return TYPE_INT;
    } else return TYPE_UNKNOWN;
}

string pwnn_config_parser::array_to_string(vector<string> arr) {
    string str;
    for (unsigned i = 0; i < arr.size(); i++) {
        str += arr[i] + ";";
    }
    return str;
}

template<class T>
string pwnn_config_parser::array_to_string(const vector<T> &arr) {
    string str;
    for (unsigned i; i < arr.size(); i++) {
        str += to_string(arr[i]) + ";";
    }
    return str;
}