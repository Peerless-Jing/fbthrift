/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "module_reflection.h"
#include <thrift/lib/cpp/Reflection.h>

 namespace module_reflection_ {

// Reflection initializer for enum module.Company
static void reflectionInitializer_16163282776448022760(::apache::thrift::reflection::Schema& schema) {
  const uint64_t id = 16163282776448022760U;
  if (schema.dataTypes.count(id)) return;
  ::apache::thrift::reflection::DataType& dt = schema.dataTypes[id];
  dt.name = "enum module.Company";
  schema.names[dt.name] = id;
  dt.__isset.enumValues = true;
  static const std::pair<const char*, int32_t> enumValues[] = {
    {"FACEBOOK", 0},
    {"INSTAGRAM", 3},
    {"OCULUS", 2},
    {"WHATSAPP", 1},
  };
  dt.enumValues.insert(boost::container::ordered_unique_range_t(), enumValues, enumValues + 4);
}

void  reflectionInitializer_16163282776448022760(::apache::thrift::reflection::Schema&);  // enum module.Company
// Reflection initializer for struct module.Internship
void reflectionInitializer_9022508676980868684(::apache::thrift::reflection::Schema& schema) {
  const uint64_t id = 9022508676980868684U;
  if (schema.dataTypes.count(id)) return;
  ::apache::thrift::reflection::DataType& dt = schema.dataTypes[id];
  dt.name = "struct module.Internship";
  schema.names[dt.name] = id;
  dt.__isset.fields = true;
  {
    ::apache::thrift::reflection::StructField& f = dt.fields[1];
    f.isRequired = true;
    f.type = 5U;
    f.name = "weeks";
    f.order = 0;
  }
  {
    ::apache::thrift::reflection::StructField& f = dt.fields[2];
    f.isRequired = true;
    f.type = 1U;
    f.name = "title";
    f.order = 1;
  }
  {
    ::apache::thrift::reflection::StructField& f = dt.fields[3];
    f.isRequired = true;
    f.type = 16163282776448022760U;
    f.name = "employer";
    f.order = 2;
  }
  reflectionInitializer_16163282776448022760(schema);  // enum module.Company
}

}
