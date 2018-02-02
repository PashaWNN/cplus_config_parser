
#ifndef PWNN_CONFIG_PARSER_H
#define PWNN_CONFIG_PARSER_H
#include <unordered_map>
using namespace std;

typedef unordered_map<string, int> IntDict;
typedef unordered_map<string, string> StringDict;
typedef unordered_map<string, bool> BoolDict;
typedef unordered_map<string, float> FloatDict;

class pwnn_config_parser
{
private: 
    StringDict Strings;
    FloatDict Floats;
    IntDict Integers;
    BoolDict Booleans;
    void Push(string str);
    pwnn_config_parser() = default;
    ~pwnn_config_parser() = default;
public:
    static pwnn_config_parser* Instance() { static pwnn_config_parser s; return &s; }
    pwnn_config_parser(const pwnn_config_parser&) = delete;
    void operator=(const pwnn_config_parser&) = delete;
    void LoadConfig(string fn);
    void SaveConfig(string fn);
    string GetString(string key);
    int GetInt(string key);
    bool GetBool(string key);
    float GetFloat(string key);
    void SetString(string key, string value);
    void SetInt(string key, int value);
    void SetBool(string key, bool value);
    void SetFloat(string key, float value);
}; 

#endif /* PWNN_CONFIG_PARSER_H */

