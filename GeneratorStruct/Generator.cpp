#include <iostream>
#include <string>
#include <format>
#include <optional>
#include <coroutine>
#include <generator>


using std::string;
using std::cout;
using std::endl;
using std::coroutine_handle;


template<typename T>
struct Generator {
	struct promise_type;
	using handle_type = coroutine_handle<promise_type>;



};
