#include <iostream>
// RAPIDJSON lib
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include "rapidjson/reader.h"
#include "rapidjson/filereadstream.h"
using namespace rapidjson;
using namespace std;
class JSON {
public:
    // gets JSON String
    std::string getDocument(std::string file){
        ifstream ifs(file);
        rapidjson::IStreamWrapper isw(ifs);
        rapidjson::Document doc;
        doc.ParseStream(isw);
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<StringBuffer> writer(buffer);
        doc.Accept(writer);
        return buffer.GetString();
    }
    // gets JSON object and puts it in a string
    std::string getStringValue(std::string file, char v[100]){
        ifstream ifs(file);
        rapidjson::IStreamWrapper isw(ifs);
        rapidjson::Document doc;
        doc.ParseStream(isw);
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<StringBuffer> writer(buffer);
        doc.Accept(writer);
        assert(doc.HasMember(v));
        assert(doc[v].IsString());
        return doc[v].GetString();
    }
    // gets JSON object and puts it in an int
    int getIntValue(std::string file, char v[100]){
        ifstream ifs(file);
        rapidjson::IStreamWrapper isw(ifs);
        rapidjson::Document doc;
        doc.ParseStream(isw);
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<StringBuffer> writer(buffer);
        doc.Accept(writer);
        assert(doc.HasMember(v));
        assert(doc[v].IsInt());
        return doc[v].GetInt();
    }
    // gets JSON by an int
    std::string get(std::string file, char pointer1[100], int pointer2){
        return query(file,pointer1)[pointer2].GetString();
    }

private:
    // returns array from JSON
    rapidjson::GenericValue<rapidjson::UTF8<> >::Array query(std::string file, char v[100]){
        ifstream ifs(file);
        rapidjson::IStreamWrapper isw(ifs);
        rapidjson::Document doc;
        doc.ParseStream(isw);
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<StringBuffer> writer(buffer);
        doc.Accept(writer);
        assert(doc.HasMember(v));
        assert(doc[v].IsArray());
        return doc[v].GetArray();
    }
};