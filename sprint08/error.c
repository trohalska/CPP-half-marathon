Checking gitlab.ucode.world:/unit-factory-kyiv/cpp-sprint08/trohalska.git
----------------------------------------
Running tests for t00 for User
Running tests for t00 for Test
----------------------------------------
Comparing outputs
Test case 0 Ok
You get 25 points
----------------------------------------
----------------------------------------
Comparing outputs
Test case 1 Ok
You get 25 points
----------------------------------------
----------------------------------------
Comparing outputs
Test case 2 Failed

user output vs test output
1c1
< 212
---
> 228

You lost 50 points
----------------------------------------
Total 50 points for t00 [ FAIL ]
----------------------------------------
----------------------------------------
// Running tests for t01 for User
// {
//     Running tests for t01 for Test
//     ----------------------------------------
//     Comparing outputs
//     Test case 0 Ok
//     You get 100 points
// }
// ----------------------------------------
// Total 100 points for t01 [ SUCCESS ]
// ----------------------------------------
----------------------------------------
Running tests for t02 for User
Running tests for t02 for Test
---------------------------------------- // ???
Comparing outputs
Test case 0 Failed

user output vs test output
1,4c1,4
< int is r-value reference
< int is l-value reference
< char is r-value reference
< char is l-value reference
---
> i is r-value reference
> i is l-value reference
> c is r-value reference
> c is l-value reference

You lost 100 points
----------------------------------------
Total 0 points for t02 [ FAIL ]
----------------------------------------
----------------------------------------
// Running tests for t03 for User
// Running tests for t03 for Test
// ----------------------------------------  // fixed
// Comparing outputs
// Test case 0 Failed

// user output vs test output
// 10c10
// < I Love you !
// ---
// > I love you !
// 21c21
// < I Love eight !
// ---
// > I love eight !

// You lost 100 points
// ----------------------------------------
// Total 0 points for t03 [ FAIL ]
----------------------------------------
----------------------------------------  // need to realize functions in cpp
Running tests for t04 for User
Undefined symbols for architecture x86_64:
  "SomeClass::SomeClass(int, char, float)", referenced from:
      serializer_any(char**, int&, char&, float&, Serializer&) in main.cpp.o
  "SomeClass::output() const", referenced from:
      deserializer(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, Serializer&) in main.cpp.o
      serializer_any(char**, int&, char&, float&, Serializer&) in main.cpp.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
make[2]: *** [../serializer] Error 1
make[1]: *** [app/CMakeFiles/serializer.dir/all] Error 2
make: *** [all] Error 2
