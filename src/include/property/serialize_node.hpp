#ifndef PROPERTY_SERIALIZE_NODE_HPP
#define PROPERTY_SERIALIZE_NODE_HPP

#include <string_view>
#include <functional>
#include <queue>

//#include <vector>
//#include <map>
//#include <iostream>
//#include <string_view>
//#include <fstream>
//#include <cmath>
//#include <functional>
//#include <type_traits>

namespace property {
/*
*
*    ObjectType:
*      case serialize: // ...
*      case scalar: // ...
*      case sequence: // ...
*      case map: // ...
* */
    enum class ObjectType {
        serialize,
        scalar,
        sequence,
        map
    };

    struct SerializeNode {
        using SerializeQueue = std::queue<std::string>;
        using VoidFunction = std::function < void( SerializeQueue &) >;
        struct Impl;
        std::unique_ptr<Impl> impl;
      
        std::string_view name;
        std::string_view type_name;
        std::string_view desc;
        ObjectType object_type;
      
        VoidFunction serialize;
        VoidFunction deserialize;

        SerializeNode(const char *name, const char *desc, const char *type_name, const ObjectType object_type);
        ~SerializeNode();
        
      
        std::string commit(const SerializeQueue &out);
    };
}

#endif // PROPERTY_SERIALIZE_NODE_HPP