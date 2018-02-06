
#ifndef PWNN_CONFIG_PARSER_H
#define PWNN_CONFIG_PARSER_H
#include <unordered_map>
#include <vector>
using namespace std;

const int TYPE_UNKNOWN = -1;
const int TYPE_STRING = 1;
const int TYPE_INT = 2;
const int TYPE_FLOAT = 3;
const int TYPE_BOOL = 4;

typedef unordered_map<string, int> IntDict;
typedef unordered_map<string, string> StringDict;
typedef unordered_map<string, bool> BoolDict;
typedef unordered_map<string, float> FloatDict;
typedef unordered_map<string, vector<int>> IntArrayDict;
typedef unordered_map<string, vector<string>> StringArrayDict;
typedef unordered_map<string, vector<bool>> BoolArrayDict;
typedef unordered_map<string, vector<float>> FloatArrayDict;

class pwnn_config_parser
{
private:
    StringDict Strings;
    FloatDict Floats;
    IntDict Integers;
    BoolDict Booleans;
    StringArrayDict StringArrays;
    FloatArrayDict FloatArrays;
    IntArrayDict IntegerArrays;
    BoolArrayDict BooleanArrays;


    void Push(string str);
    pwnn_config_parser() = default;
    ~pwnn_config_parser() = default;

    string array_to_string(vector<string> arr);

    template<class T>
    string array_to_string(const vector<T> &arr);

    void SetArray(string key, string valType, string values);

    void SetVar(string key, string valType, string value);

    int string_to_type(string type);
public:
    static pwnn_config_parser* Instance() { static pwnn_config_parser s; return &s; }
    pwnn_config_parser(const pwnn_config_parser&) = delete;
    void operator=(const pwnn_config_parser&) = delete;
    void LoadConfig(string fn);
    void SaveConfig(string fn);

    string GetString(string key) { return Strings[key]; }

    int GetInt(string key) { return Integers[key]; }

    bool GetBool(string key) { return Booleans[key]; }

    float GetFloat(string key) { return Floats[key]; }

    vector<string> GetStringArray(string key) { return StringArrays[key]; }

    vector<int> GetIntArray(string key) { return IntegerArrays[key]; }

    vector<bool> GetBoolArray(string key) { return BooleanArrays[key]; }

    vector<float> GetFloatArray(string key) { return FloatArrays[key]; }

    void SetString(string key, string value) { Strings[key] = value; }

    void SetInt(string key, int value) { Integers[key] = value; }

    void SetBool(string key, bool value) { Booleans[key] = value; }

    void SetFloat(string key, float value) { Floats[key] = value; }

    void SetStringArray(string key, vector<string> array) { StringArrays[key] = array; }

    void SetIntArray(string key, vector<int> array) { IntegerArrays[key] = array; }

    void SetBoolArray(string key, vector<bool> array) { BooleanArrays[key] = array; }

    void SetFloatArray(string key, vector<float> array) { FloatArrays[key] = array; }
};

#endif /* PWNN_CONFIG_PARSER_H */
