#ifndef EJDBCONTROLLER_H
#define EJDBCONTROLLER_H
#include "ejdb/ejdb.h"
#include "list"
#include <string>



class EJDBController
{
public:
    explicit EJDBController(std::string databasePath);
    ~EJDBController();

    //Усиановка коллекции
    void setCurrentTableName(std::string tableName);

    //Вставка документа
    void insertDocument(std::string document);

    //Загрузка
    std::list<std::string> loadDocument(std::string request);
    std::list<std::string> loadDocument(std::string request, std::string hints);
    uint32_t countDocument(std::string request);

    //Удаление и обновление
    bool deleteDocument(std::string deleteOID);
    bool deleteDocuments(std::list<std::string> deleteOIDs);
    uint32_t updateDocuments(std::string baseRequest);

    //Индексирование
    bool setStringIndexingSchema(std::string indexField, bool rebuild);
    bool setArrayIndexingSchema(std::string indexField, bool rebuild);
    bool setIntIndexingSchema(std::string indexField, bool rebuild);

private:
    EJCOLL* coll;
    EJDB* ejdb_db;
};

#endif // EJDBCONTROLLER_H
