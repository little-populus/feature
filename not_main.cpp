#include <format>
#include <iostream>

struct base
{
    int x;
    virtual ~base() = default;
};

extern "C" int not_main()
{
    base b{};
    auto c = b;
    c.x = 1;
    std::cout << std::format("{}\n", c.x);
    return 0;
}
