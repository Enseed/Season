# Season

Season is a C++ json serializer and deserializer based on the Reflect API:
 - Reflect parses target .h files and generate introspection structures
 - Season uses the instrospection structures to generate json strings

Once set up correctly in Visual Studio, adding fields in the .h file is automatically picked up by Season and require no extra work.

Season currently support writing the following types to json format:
 - Basic types (char, int, float, double, boolean, etc.)
 - std::string and const char *
 - complex types processed with Reflect
 - std::vector of other supported types
 - std::map of other supported types
 - boost::optional of other supported types
 - std::unique_ptr of other supported types
 - std::shared_ptr of other supported types

Adding support for additional container can be done with about 5 lines of code by specializing a template for the container type.

Serialization to JSON is done using third party libraries. Currently boost::property_tree::json_parser and RapidJSON are supported. Season contains the logic to visit C++ objects and is designed to accomodate other third party json serializer.

The code for json serialization (visiting object fields, getting their name and type) is generated at compile time.  No RTTI or dynamic cast is required.

Current results with

```c++
struct MySubStructure
{
	std::string mySubStructure;
	std::shared_ptr<int> sharedIntPtr;
};

struct MyStructure
{
	int intValue;
	std::string stringValue;
	std::vector<int> vectorOfInt;
	std::map<std::string, int> mapOfInt;
	boost::optional<int> optionalInt;
	MySubStructure subStruct;
};
```

Initialized in the following way:

```c++
	MyStructure s;
	s.intValue = 123;
	s.stringValue = "abc";
	s.vectorOfInt.push_back(1);
	s.vectorOfInt.push_back(2);
	s.vectorOfInt.push_back(3);
	s.mapOfInt["foo"] = 123;
	s.optionalInt.emplace(999);
	s.subStruct.sharedIntPtr.reset(new int(777));
```

Give the following results:

```
437628 iterations / second using RapidSeason
{
    "d": {
        "intValue": 123,
        "stringValue": "abc",
        "vectorOfInt": [
            1,
            2,
            3
        ],
        "mapOfInt": {
            "foo": 123
        },
        "optionalInt": 999,
        "subStruct": {
            "mySubStructure": "",
            "sharedIntPtr": 777
        }
    }
}
 1.200023s wall, 1.014007s user + 0.187201s system = 1.201208s CPU (100.1%)
16817 iterations / second using BoostSeason
{
    "d": {
        "intValue": "123",
        "stringValue": "abc",
        "vectorOfInt": [
            "1",
            "2",
            "3"
        ],
        "mapOfInt": {
            "foo": "123"
        },
        "optionalInt": "999",
        "subStruct": {
            "mySubStructure": "",
            "sharedIntPtr": "777"
        }
    }
}

 1.029572s wall, 1.014007s user + 0.015600s system = 1.029607s CPU (100.0%)
 ```
 
 
 For comparison, a similar structure serialized using gson (Google) in Java yields:
 
 ```
 69939 iterations / second using gson
{
  "d": {
    "intValue": 123,
    "stringValue": "abc",
    "vectorOfInt": [
      1,
      2,
      3
    ],
    "mapOfInt": {
      "foo": 123
    },
    "optionalInt": 999,
    "subStruct": {
      "sharedIntPtr": 777
    }
  }
}
```
