#include "handlerengine.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include "ejdbcontroller.h"
#include "nlohmann/json.hpp"

std::string known_hosts = "known_hosts";
std::string correction_hosts = "correction_hosts";

std::vector<std::string> split(const std::string &s, char delim) {
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim)) {
        elems.push_back(std::move(item)); // if C++11 (based on comment from @mchiasson)
    }
    return elems;
}

HandlerEngine::HandlerEngine(std::string dbLocation)
{
    this->controller=new EJDBController(dbLocation);
    this->controller->setCurrentTableName(known_hosts);
}

Text HandlerEngine::getTextObject(std::string inputText) //Получение текстового объекта
{
    this->controller->setCurrentTableName(known_hosts);
    Text resultTxt;

    //сначала разделяем текст на абзацы
    for (auto paragraps_strings: split(inputText, '\n'))
    {
        //затем - разделяем абзацы на предложения
        Paragraph par;
        for(auto sentence_strings: split(paragraps_strings, '.'))
        {
            //затем получаем слова в предложении
            Sentence sent;
            for(auto word: split(sentence_strings, ' '))
            {
                //и проходимся обработчиком по словам, проверяя их и заменяя спецсимволы в них
                if(word.size()>0 && word!=" ")
                {
                    word.erase(std::remove(word.begin(), word.end(), '#'), word.end());
                    word.erase(std::remove(word.begin(), word.end(), ' '), word.end());
                    word.erase(std::remove(word.begin(), word.end(), ','), word.end());
                    word.erase(std::remove(word.begin(), word.end(), '.'), word.end());
                    word.erase(std::remove(word.begin(), word.end(), '?'), word.end());
                    word.erase(std::remove(word.begin(), word.end(), '/'), word.end());
                    word.erase(std::remove(word.begin(), word.end(), '"'), word.end());
                    std::transform(word.begin(), word.end(),
                                   word.begin(),  [](unsigned char c){ return std::tolower(c); });
                    sent.words.push_back(word);
                }
            }
            par.sentences.push_back(sent);
        }
        resultTxt.paragraphs.push_back(par);
    }
    return resultTxt;
}

bool HandlerEngine::addThirdFaceRuleToMachine(std::string first_face, std::string third_face, Sex sex, Counting counting)
{
    this->controller->setCurrentTableName(known_hosts);
    //Формирование объекта для добавления в базу
    nlohmann::json j;
    j["first_face"]=nlohmann::json::object();
    j["third_face"]=nlohmann::json::object();

    switch (sex)
    {
    case Sex::Male:
        j["first_face"]["male"]=nlohmann::json::object();
        j["third_face"]["male"]=nlohmann::json::object();
        {
            switch (counting)
            {
            case Counting::Single:
                j["first_face"]["male"]["single"]=first_face;
                j["third_face"]["male"]["single"]=third_face;
                break;
            case Counting::Plural:
                j["first_face"]["male"]["plural"]=first_face;
                j["third_face"]["male"]["plural"]=third_face;
                break;
            }
        }
        break;
    case Sex::Female:
        j["first_face"]["female"]=nlohmann::json::object();
        j["third_face"]["female"]=nlohmann::json::object();
        {
            switch (counting)
            {
            case Counting::Single:
                j["first_face"]["female"]["single"]=first_face;
                j["third_face"]["female"]["single"]=third_face;
                break;
            case Counting::Plural:
                j["first_face"]["female"]["plural"]=first_face;
                j["third_face"]["female"]["plural"]=third_face;
                break;
            }
        }
        break;
    }

    //Теперь формирование поискового запроса
    nlohmann::json search;
    switch (sex)
    {
    case Sex::Male:
        {
            switch (counting)
            {
            case Counting::Single:
                search["first_face.male.single"]=first_face;
                break;
            case Counting::Plural:
                search["first_face.male.plural"]=first_face;
                break;
            }
        }
        break;
    case Sex::Female:
        {
            switch (counting)
            {
            case Counting::Single:
                search["first_face.female.single"]=first_face;
                break;
            case Counting::Plural:
                search["first_face.female.plural"]=first_face;
                break;
            }
        }
        break;
    }


    //сначала проверим, есть ли в базе уже такое слово?
    auto response = this->controller->countDocument(search.dump());
    if(response>0)
    {
        nlohmann::json update_request=search;
        update_request["$set"] = j;
        if(this->controller->updateDocuments(update_request.dump())>0) return true; else return false;
    }

    //если такое слово еще не добавлено
    else
    {
        this->controller->insertDocument(j.dump());
        return true;
    }
}

bool HandlerEngine::addTrainRuleToMachine(std::string rule)
{
    this->controller->setCurrentTableName(known_hosts);
    nlohmann::json j = nlohmann::json::parse(rule);
    j["auto"] = true;
    this->controller->insertDocument(j.dump());
    return true;
}

bool HandlerEngine::removeTrainRulesFromMachine()
{
    this->controller->setCurrentTableName(known_hosts);
    nlohmann::json search;
    search["auto"] = true;
    std::list<std::string> oids;

    for(auto d: this->controller->loadDocument(search.dump()))
    {
        nlohmann::json k = nlohmann::json::parse(d);
        oids.push_back(k["_id"].get<std::string>());
    }

    return this->controller->deleteDocuments(oids);
}

std::list<std::string> HandlerEngine::getRuleByFirstFace(std::string first_face, Sex sex, Counting counting)
{
    this->controller->setCurrentTableName(known_hosts);
    nlohmann::json request;
    //Теперь формирование поискового запроса
    switch (sex)
    {
    case Sex::Male:
        {
            switch (counting)
            {
            case Counting::Single:
                request["first_face.male.single"]=first_face;
                break;
            case Counting::Plural:
                request["first_face.male.plural"]=first_face;
                break;
            }
        }
        break;
    case Sex::Female:
        {
            switch (counting)
            {
            case Counting::Single:
                request["first_face.female.single"]=first_face;
                break;
            case Counting::Plural:
                request["first_face.female.plural"]=first_face;
                break;
            }
        }
        break;
    }
    return this->controller->loadDocument(request.dump());
}

std::string HandlerEngine::getThirdFaceRuleByFirstFace(std::string first_face, Sex sex, Counting counting) //Получить третье лицо из первого
{
    this->controller->setCurrentTableName(known_hosts);
    nlohmann::json request;
    //Теперь формирование поискового запроса
    std::string sex_param = "";
    std::string counting_param = "";

    switch (sex)
    {
    case Sex::Male:
        {
            sex_param="male";
            switch (counting)
            {
            case Counting::Single:
                request["first_face.male.single"]=first_face;
                counting_param="single";
                break;
            case Counting::Plural:
                request["first_face.male.plural"]=first_face;
                counting_param="plural";
                break;
            }
        }
        break;
    case Sex::Female:
        {
            sex_param="female";
            switch (counting)
            {
            case Counting::Single:
                request["first_face.female.single"]=first_face;
                counting_param="single";
                break;
            case Counting::Plural:
                request["first_face.female.plural"]=first_face;
                counting_param="plural";
                break;
            }
        }
        break;
    }


    auto r = this->controller->loadDocument(request.dump());
    if(r.size()>0)
    {
        nlohmann::json j = nlohmann::json::parse(r.front());

        //если есть поле третьего лица
        if(j.find("third_face")!=j.end())
        {
            //если есть поле с выбранным полом
            if(j["third_face"].find(sex_param)!=j["third_face"].end())
            {
                if(j["third_face"][sex_param].find(counting_param)!=j["third_face"][sex_param].end())
                {
                    return j["third_face"][sex_param][counting_param].get<std::string>();
                } else return "";
            } else return "";
        }
        else {
            return "";
        }
    }
    else {
        return "";
    }
}

bool HandlerEngine::addThirdFaceCorrectSentence(std::string inputString, std::string outputString, Sex sex, Counting counting)
{
    this->controller->setCurrentTableName(correction_hosts);
    //Формирование объекта для добавления в базу
    nlohmann::json j;

    switch (sex)
    {
    case Sex::Male:
        j["male"]=nlohmann::json::object();
        j["male"]=nlohmann::json::object();
        {
            switch (counting)
            {
            case Counting::Single:
                j["male"]["single"]["source"]=inputString;
                j["male"]["single"]["target"]=outputString;
                break;
            case Counting::Plural:
                j["male"]["plural"]["source"]=inputString;
                j["male"]["plural"]["target"]=outputString;
                break;
            }
        }
        break;
    case Sex::Female:
        j["female"]=nlohmann::json::object();
        j["female"]=nlohmann::json::object();
        {
            switch (counting)
            {
            case Counting::Single:
                j["female"]["single"]["source"]=inputString;
                j["female"]["single"]["target"]=outputString;
                break;
            case Counting::Plural:
                j["female"]["plural"]["source"]=inputString;
                j["female"]["plural"]["target"]=outputString;
                break;
            }
        }
        break;
    }

    //Теперь формирование поискового запроса
    nlohmann::json search;
    switch (sex)
    {
    case Sex::Male:
        {
            switch (counting)
            {
            case Counting::Single:
                search["male.single.source"]=inputString;
                break;
            case Counting::Plural:
                search["male.plural.source"]=inputString;
                break;
            }
        }
        break;
    case Sex::Female:
        {
            switch (counting)
            {
            case Counting::Single:
                search["female.single.source"]=inputString;
                break;
            case Counting::Plural:
                search["female.plural.source"]=inputString;
                break;
            }
        }
        break;
    }


    //сначала проверим, есть ли в базе уже такое слово?
    auto response = this->controller->countDocument(search.dump());
    if(response>0)
    {
        nlohmann::json update_request=search;
        update_request["$set"] = j;
        if(this->controller->updateDocuments(update_request.dump())>0) return true; else return false;
    }

    //если такое слово еще не добавлено
    else
    {
        this->controller->insertDocument(j.dump());
        return true;
    }
}

std::list<Specific> HandlerEngine::getThirdFaceSpecificCorrect(Sex sex, Counting counting)
{
    this->controller->setCurrentTableName(correction_hosts);
    std::list<Specific> result;
    std::string m_sex;
    std::string m_counting;

    //Теперь формирование поискового запроса
    nlohmann::json search;
    switch (sex)
    {
    case Sex::Male:
        {
            m_sex="male";
            switch (counting)
            {
            case Counting::Single:
                m_counting="single";
                search["male.single.source"]["$exists"]=true;
                break;
            case Counting::Plural:
                m_counting="plural";
                search["male.plural.source"]["$exists"]=true;
                break;
            }
        }
        break;
    case Sex::Female:
        {
            m_sex="female";
            switch (counting)
            {
            case Counting::Single:
                m_counting="single";
                search["female.single.source"]["$exists"]=true;
                break;
            case Counting::Plural:
                m_counting="plural";
                search["female.plural.source"]["$exists"]=true;
                break;
            }
        }
        break;
    }
    auto response = controller->loadDocument(search.dump());
    for(auto c: response)
    {
        auto x = nlohmann::json::parse(c);
        Specific sp;
        sp.source = x[m_sex][m_counting]["source"].get<std::string>();
        sp.target = x[m_sex][m_counting]["target"].get<std::string>();
        result.push_back(sp);
    }
    response.clear();
    return result;
}
