#include <property/property.hpp>

#include <iostream>

class Test SERIALIZETHIS(Test) {
  SCALAR(age, int, "age of test");
  SCALAR(name, std::string, "name of test");
  public:
  
  CONSTRUCTORS(Test)
};

class Test2 SERIALIZETHIS(Test2) {
  SCALAR(age, int, "age of test");
//  SCALAR(name, std::string, "name of test");
  SCALAR(test1, Test, "name of test");
//  SCALAR(test2, Test, "name of test");
//  SCALAR(test3, Test, "name of test");
//  SCALAR(test4, Test, "name of test");
//  SCALAR(test5, Test, "name of test");
//  SCALAR(test6, Test, "name of test");
//  SCALAR(name3, std::string, "name of test");
  public:
  
  CONSTRUCTORS(Test2)
};
class Test3 SERIALIZETHIS(Test3) {
  SCALAR(age, int, "age of test");
//  SCALAR(name, std::string, "name of test");
  SCALAR(test1, Test2, "name of test");
//  SCALAR(test2, Test, "name of test");
//  SCALAR(test3, Test, "name of test");
//  SCALAR(test4, Test, "name of test");
//  SCALAR(test5, Test, "name of test");
//  SCALAR(test6, Test, "name of test");
  SCALAR(name3, std::string, "name of test");
  public:
  
  CONSTRUCTORS(Test3)
};
int main() {
  int version = property::property_version();
  int major = version >> 16;
  int minor = version & 0xFF;
  
  std::cout << "version: " << version << "\n";
  std::cout << "major: " <<  major << "\n";
  std::cout << "minor: " <<  minor << "\n";

  Test3 test("test", "simple test serialization");
  test.age.set(42);
//  test.name.set("vadya");
  test.serialize([](const std::string &serdata){
    // save it to file
    std::cout << "output:\n" << serdata << "\n";
  });
  
//  std::string serddata_from_file;
//  test.deserialize(serddata_from_file);
  // test ready to use;
}

//#include <vector>
//#include <map>
//#include <iostream>
//#include <string_view>
//#include <fstream>
//#include <cmath>
//#include <functional>
//#include <type_traits>


//
//template<typename O>
//struct holder<ObjectType::sequence, std::vector<O>> {
//  using type = Serializable<std::vector<O>>;
//  type holder_object;
//  holder(const char* name_, const char* desc_, const char* type_name_, std::vector<SerializeNode*>& childs) : holder_object{name_, desc_, "sequence"} { 
//      childs.push_back(&holder_object);
//      holder_object.value = {};
//      holder_object.serialize = [&] () {
//        std::cout << holder_object.name << " " << holder_object.type_name << "\n";
//      };
//  }
//};
//
//template<typename K, typename O>
//struct holder<ObjectType::map, Serializable<std::map<K, O>>> {
//  using type = Serializable<std::map<K,O>>;
//  type holder_object;
//  holder(const char* name_, const char* desc_, std::vector<SerializeNode*> &childs) : holder_object{name_, desc_, "map"} { 
//    //childs.push_back(&holder_object.node);
//    }
//};
//
//
//template<typename O>
//using Serialize = holder<ObjectType::serialize, Serializable<O>>;
//template<typename O>
//using Scalar = std::conditional_t< is_base_of_holder<O>, O, holder<ObjectType::scalar, O>>;
//template<typename O>
//using Sequence = holder<ObjectType::sequence, std::vector<O>>;
//template<typename K, typename O>
//using Map = holder<ObjectType::map, Serializable<std::map<K, O>>>;
//
//#define serializable_s(param_name, param_type, param_name_text, param_desc) \
//  private: \
//    Scalar<param_type>  param_name{ # param_name, param_desc, #param_type, this->childs}; 
//
//#define serializable_v(param_name, param_type, param_name_text, param_desc) \
//  private: \
//    Sequence<param_type>  param_name{ # param_name, param_desc, #param_type, this->childs}; 
//
//#define serializable_m(param_name, param_type1, param_type2, param_name_text, param_desc) \
//  private: \
//    Map<param_type1, param_type2>  param_name{ # param_name, param_desc, this->childs}; 
//
//#define SCALAR(param_name, param_type, param_desc) serializable_s(param_name, param_type, param_name, param_desc)
//#define SEQUENCE(param_name, param_type, param_desc) serializable_v(param_name, param_type, param_name, param_desc)
//#define MAP(param_name, param_type1, param_type2, param_desc) serializable_m(param_name, param_type1, param_type2, param_name, param_desc)
//
//#define SERIALIZETHIS(type_name) \
//  final : public Serialize<type_name> 
//#define CONSTRUCTORS(class_name) \
//  public: \
//  class_name(const std::string_view &name_, const std::string_view &desc_) : holder{name_.data(), desc_.data(), #class_name} {} \
//  class_name(const std::string_view &name_, const std::string_view &desc_, const std::string_view& type_name_, std::vector<SerializeNode*> &childs_) : holder{name_.data(), desc_.data(), type_name_.data()} { \
//    childs_.push_back(&holder_object); \
//    std::copy(std::begin(childs), std::end(childs),  std::back_inserter(childs_)); \
//  }
//
//class Test SERIALIZETHIS(Test) {
//  SEQUENCE(param7, int, "int sequence value");
//  SEQUENCE(param8, int, "int sequence value");
//  SEQUENCE(param9, int, "int sequence value");
//  SEQUENCE(param, int, "int sequence value");
////  MAP     (param3, int, int, "int map value");
//  public:
//  CONSTRUCTORS(Test)
//};
//class Test2 SERIALIZETHIS(Test2){
////  serializethis(Test2, "The test2 class that you can ser/des")
//  SCALAR  (param1,  float, "float value");
//  SCALAR  (param2,  float, "float value");
//  SCALAR  (param3,  float, "float value");
//  SCALAR  (param4,  float, "float value");
//  SCALAR  (param5,  float, "float value");
//  SCALAR  (param6,  Test, "Test value");
//  CONSTRUCTORS(Test2)
//};
//
//int main() {
//  DEBUG("yaml start serialize\n");
//  Test2 t{"t", "The test2 class"};
//
//  t.serialize();
//
//  return 0;
//}
