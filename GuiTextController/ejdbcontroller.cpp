#include "ejdbcontroller.h"
#include "iostream"


EJDBController::EJDBController(std::string databasePath)
{
    this->ejdb_db=ejdbnew();
    if (ejdbopen(this->ejdb_db, databasePath.c_str(), JBOREADER | JBOWRITER | JBOCREAT))
    {
        std::cout << "Database opened successfully" << std::endl;
    }else{
        std::cout << "Database open error" << std::endl;
    }
}

EJDBController::~EJDBController()
{
    //Close database
    ejdbclose(this->ejdb_db);
    ejdbdel(this->ejdb_db);
}

void EJDBController::setCurrentTableName(std::string tableName)
{
    //Get or create collection
    this->coll = ejdbcreatecoll(this->ejdb_db, tableName.c_str(), nullptr);

}

void EJDBController::insertDocument(std::string document)
{
    bson_oid_t oid;
    auto c = json2bson(document.c_str());

    //Save BSON
    ejdbsavebson(coll, c, &oid);
    bson_destroy(c);

    //На всякий случай
    ejdbtrancommit(coll);
}

std::list<std::string> EJDBController::loadDocument(std::string request)
{
    std::list<std::string> result;
    result.clear();
    if(request!="")
    {
        auto bq1 = json2bson(request.c_str());
        EJQ *q1 = ejdbcreatequery(this->ejdb_db, bq1, nullptr, 0, nullptr);
        uint32_t count;
        TCLIST *res = ejdbqryexecute(coll, q1, &count, 0, nullptr);

        //Now print the result set records
        for (int i = 0; i < TCLISTNUM(res); ++i)
        {
            void *bsdata = TCLISTVALPTR(res, i);
            char* buffer; int size;
            bson2json(static_cast<char*>(bsdata), &buffer, &size);
            std::string s (buffer, size);
            result.push_back(s);
        }
        ejdbquerydel(q1);
        bson_destroy(bq1);
    }
    return result;
}

std::list<std::string> EJDBController::loadDocument(std::string request, std::string hints)
{
    std::list<std::string> result;
    result.clear();
    if(request!="")
    {
        auto bq1 = json2bson(request.c_str());
        auto hint1 = json2bson(hints.c_str());
        EJQ *q1 = ejdbcreatequery(this->ejdb_db, bq1, nullptr, 0, hint1);
        uint32_t count;
        TCLIST *res = ejdbqryexecute(coll, q1, &count, 0, nullptr);

        //Now print the result set records
        for (int i = 0; i < TCLISTNUM(res); ++i)
        {
            void *bsdata = TCLISTVALPTR(res, i);
            //bson_print_raw(bsdata, 0);

            char* buffer; int size;
            bson2json(static_cast<char*>(bsdata), &buffer, &size);
            std::string s (buffer, size);
            result.push_back(s);
        }
        ejdbquerydel(q1);
        bson_destroy(bq1);
    }
    return result;
}

uint32_t EJDBController::countDocument(std::string request)
{
    uint32_t result = 0;
    if(request!="")
    {
        auto bq1 = json2bson(request.c_str());
        EJQ *q1 = ejdbcreatequery(this->ejdb_db, bq1, nullptr, 0, nullptr);
        ejdbqryexecute(coll, q1, &result, 0, nullptr);
    }
    return result;
}

bool EJDBController::deleteDocument(std::string deleteOID)
{
    if(deleteOID!="")
    {
        bson_oid_t oid;
        bson_oid_from_string(&oid, deleteOID.c_str());
        return ejdbrmbson(coll, &oid);
    }else
    {
        std::cout << "Идентификатор отсутствует" << std::endl;
        return false;
    }
}

bool EJDBController::deleteDocuments(std::list<std::string> deleteOIDs)
{
    for (auto d_oid: deleteOIDs)
    {
        if(d_oid!="")
        {
            bson_oid_t oid;
            bson_oid_from_string(&oid, d_oid.c_str());
            ejdbrmbson(coll, &oid);
        }else
        {
            std::cout << "Идентификатор отсутствует" << std::endl;
        }
    }
    return true;
}

uint32_t EJDBController::updateDocuments(std::string baseRequest)
{
    uint32_t result = 0;
    if(baseRequest!="")
    {
        auto bq1 = json2bson(baseRequest.c_str());
        result = ejdbupdate(coll, bq1, nullptr, 0, nullptr, nullptr);
        bson_destroy(bq1);
    }
    return result;
}

bool EJDBController::setStringIndexingSchema(std::string indexField, bool rebuild)
{
    if (rebuild==true)
        return ejdbsetindex(coll, indexField.c_str(), JBIDXSTR | JBIDXREBLD );
    else
        return ejdbsetindex(coll, indexField.c_str(), JBIDXSTR);
}

bool EJDBController::setArrayIndexingSchema(std::string indexField, bool rebuild)
{
    if (rebuild==true)
        return ejdbsetindex(coll, indexField.c_str(), JBIDXARR | JBIDXREBLD );
    else
        return ejdbsetindex(coll, indexField.c_str(), JBIDXARR);
}

bool EJDBController::setIntIndexingSchema(std::string indexField, bool rebuild)
{
    if (rebuild==true)
        return ejdbsetindex(coll, indexField.c_str(), JBIDXNUM | JBIDXREBLD );
    else
        return ejdbsetindex(coll, indexField.c_str(), JBIDXNUM);
}


