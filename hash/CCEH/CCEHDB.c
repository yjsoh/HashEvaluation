// https://github.com/basicthinker/YCSB-C/blob/master/db/hashtable_db.h

#include "./hash/CCEH/CCEHDB.h"
#include "hash/CCEH/CCEH.h"

#include <string>
#include <vector>
#include "YCSB-C/lib/string_hashtable.h"

using std::string;
using std::vector;
using vmp::StringHashtable;

namespace ycsbc {

CCEH &cceh;

int CCEHDB::Read(const string &table, const string &key, const vector<string> *fields, vector<KVPair> &result) {
    return cceh.find(*cceh, 0, fields, 0);
    // confused about this method, difference between fields and result
}

int CCEDB::Scan(const string &table, const string &key, int len) {
    return cceh.scan(*cceh, key, len);
}

int CCEDB::Update(const string &table, const string &key, vector<KVPair> &values) {
  return cceh.update(*cceh, 0, values, 0);
}

int CCEDB::Insert(const string &table, const string &key, vector<KVPair> &values) {
    return cceh.update(*cceh, key, values, 0, 0, 0);
}

int CCEDB::Delete(const string &table, const string &key) {
    return cceh.remove(*cceh, key);
}

} // ycsbc
