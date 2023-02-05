#ifndef CCEH_DB
#define CCEH_DB

#include "YCSB-C/core/db.h"

#include <string>
#include <vector>
#include "YCSB-C/lib/string_hashtable.h"

// https://github.com/basicthinker/YCSB-C/blob/master/db/hashtable_db.h
namespace ycsbc {

class CCEHDB : public DB {
 public:
  typedef vmp::StringHashtable<const char *> FieldHashtable;
  typedef vmp::StringHashtable<FieldHashtable *> KeyHashtable;

  int Read(const std::string &table, const std::string &key,
           const std::vector<std::string> *fields,
           std::vector<KVPair> &result);
  int Scan(const std::string &table, const std::string &key,
           int len, const std::vector<std::string> *fields,
           std::vector<std::vector<KVPair>> &result);
  int Update(const std::string &table, const std::string &key,
             std::vector<KVPair> &values);
  int Insert(const std::string &table, const std::string &key,
             std::vector<KVPair> &values);
  int Delete(const std::string &table, const std::string &key);

 protected:
  CCEHDB(KeyHashtable *table) : key_table_(table) { }

  virtual FieldHashtable *NewFieldHashtable() = 0;
  virtual void DeleteFieldHashtable(FieldHashtable *table) = 0;

  virtual const char *CopyString(const std::string &str) = 0;
  virtual void DeleteString(const char *str) = 0;

  KeyHashtable *key_table_;
};

} // ycsbc

#endif // YCSB_C_HASHTABLE_DB_H_