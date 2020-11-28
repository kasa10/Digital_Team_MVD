#include <iostream>
#include "handlerengine.h"
#include <vector>
#include <fstream>
#include <sstream>

#include <regex>
#include "nlohmann/json.hpp"

// Обработка команды
// TextHandlerInterface thrd male single 'Текст на обработку'

std::string parseStringWithoutQuotes(std::string str)
{
    const char* token = "\"";
    size_t pos1 = 0, pos2 = 0;

    while ( (pos1 = str.find(token, pos1)) != std::string::npos &&
            (pos2 = str.find(token, pos1 + 1)) != std::string::npos )
        str.erase( pos1, pos2 - pos1 + 1 );

    return str;
}

std::string getDbPathFromConfigFile(const std::string& path)
{
    auto ss = std::ostringstream{};
    std::ifstream file(path);
    ss << file.rdbuf();
    auto input = ss.str();
    input.erase(std::remove(input.begin(), input.end(), '\r'),
                input.end());
    input.erase(std::remove(input.begin(), input.end(), '\n'),
                input.end());
    return input;
}



int main(int argc, char** argv)
{
    if(argc==8)
    {
        std::string program_mode = std::string(argv[1]);

        // выбран режим замены
        if(program_mode=="replace")
        {
            std::string face_mode = std::string(argv[2]);
            std::string sex_mode = std::string(argv[3]);
            std::string counting_mode = std::string(argv[4]);
            std::string subject = std::string(argv[5]);
            std::string path = std::string(argv[6]);
            std::string input_text = std::string(argv[7]);
            std::string outputText = std::string(argv[7]);

            HandlerEngine* engine = new HandlerEngine(getDbPathFromConfigFile(path));

            std::vector<std::string> input_words;
            Sex sex;
            Counting counting;

            if(face_mode=="thrd") {
                if(sex_mode=="male") {
                    sex=Sex::Male;
                    if(counting_mode=="single") {
                        counting = Counting::Single;
                    } else if(counting_mode=="plural") {
                        counting = Counting::Plural;
                    }
                }
                else if(sex_mode=="female") {
                    sex = Sex::Female;
                    if(counting_mode=="single") {
                        counting = Counting::Single;
                    } else if(counting_mode=="plural") {
                        counting = Counting::Plural;
                    }
                }
            }

            //Получение объекта
            auto input = engine->getTextObject(input_text);

            //Наполнение словесного кэша
            for(auto p: input.paragraphs)
            {
                for(auto s: p.sentences)
                { for(auto w: s.words)
                    { input_words.push_back(w); } }
            }

            //основной ход алгоритма
            if(input_words.size()>0)
            {
                for(unsigned long long i=0; i<input_words.size(); i++)
                {
                    if( input_words[i]!="я "
                            && input_words[i]!=" я "
                            && input_words[i]!="Я "
                            && input_words[i]!=" я"
                            && input_words[i]!=" Я "
                            && input_words[i]!="я"
                            && input_words[i]!="Я")
                    {
                        auto keyword = engine->getThirdFaceRuleByFirstFace(input_words[i], sex, counting);
                        if(keyword!="")
                        {
                            outputText = std::regex_replace(outputText, std::regex(input_words[i]), keyword);
                        }
                    }
                    else
                    {
                        outputText = std::regex_replace(outputText, std::regex("Я "), subject+" ");
                        outputText = std::regex_replace(outputText, std::regex(" я "), subject+" ");
                        outputText = std::regex_replace(outputText, std::regex(" Я "), subject+" ");
                        outputText = std::regex_replace(outputText, std::regex("Я, "), subject+", ");
                    }
                }
            }

            // Пост-обработка предложения на специфические словосочетания
            // цикл автозамены в предложениях специфических слов и выражений
            for(auto c: engine->getThirdFaceSpecificCorrect(sex, counting))
            {
                outputText = std::regex_replace(outputText, std::regex(c.source), c.target);
            }

            //Вывод результата
            std::cout << outputText << std::endl;
        }



        //если другой какой-то режим
        else {
            std::cout << "Режим не распознан. Действие не выполнено" << std::endl;
        }

    }
    else if (argc==4) {

        std::string program_mode = std::string(argv[1]);
        // выбран режим обучения

        if (program_mode=="study")
        {
            std::cout << "Выбран режим самообучения" << std::endl;
            std::string filename = std::string(argv[2]);
            std::string config = std::string(argv[3]);
            std::ifstream file(filename);
            std::string str;

            HandlerEngine* engine = new HandlerEngine(getDbPathFromConfigFile(config));
            engine->removeTrainRulesFromMachine();

            int i = 1;
            while(getline(file,str))
            {
                str.erase(std::remove(str.begin(), str.end(), '\r'),
                            str.end());
                str.erase(std::remove(str.begin(), str.end(), '\n'),
                            str.end());

                std::cout << i << "\t" << str << std::endl;
                auto j = nlohmann::json::parse(str);
                engine->addTrainRuleToMachine(str);
                i++;
            }
        }
    }
    else
    {
        std::cout << "Указаны не все параметры программы" << std::endl;
    }

    return 0;
}
