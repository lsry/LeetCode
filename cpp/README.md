## C++ Solutions   

#### 1. 變量大括號初始化   
當使用 auto 來配合大括號初始化時，變量會被類型推導為 `std::initializer_list<T>`。    
```C++ 
auto a = {1};  // a 的類型為 std::initializer_list<int>
```