#ifndef HANDLERENGINE_H
#define HANDLERENGINE_H

#include <string>
#include <vector>
#include <list>
#include "ejdbcontroller.h"

//Базовая структура любого текста
struct Sentence { std::vector<std::string> words; };
struct Paragraph { std::vector<Sentence> sentences; };
struct Text { std::vector<Paragraph> paragraphs; };
struct Specific { std::string source; std::string target; };

enum Counting { Single, Plural }; // единственное и множественное число
enum Sex { Male, Female }; //Женский и мужской род

class HandlerEngine
{
public:
    HandlerEngine(std::string dbLocation);
    Text getTextObject(std::string inputText);

    //Сеттеры
    bool addThirdFaceRuleToMachine(std::string first_face,
                                               std::string third_face,
                                               Sex sex, Counting counting);
    bool editRuleById(const std::string& id, const std::string& first_face, const std::string& third_face,
                      Sex sex, Counting counting);

    bool deleteRule(const std::string& id);


    //Геттеры
    std::list<std::string> getRuleByFirstFace(std::string first_face, Sex sex, Counting counting);
    std::string getThirdFaceRuleByFirstFace(std::string first_face, Sex sex, Counting counting);
    std::list<std::string> getAllRules(Sex sex, Counting counting);

    //Сеть коррекции специфики
    bool addThirdFaceCorrectSentence(std::string inputString, std::string outputString, Sex sex, Counting counting);
    std::list<Specific> getThirdFaceSpecificCorrect(Sex sex, Counting counting);
    std::list<std::string> getAllSpecificRules(Sex sex, Counting counting);
    bool deleteSpecificRule(const std::string& id);
private:
    EJDBController* controller;
};

#endif // HANDLERENGINE_H
