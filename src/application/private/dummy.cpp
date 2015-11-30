
#include "aethina_core.hpp"
#include "aethina_common.hpp"

#include <vector>

class MyBundle : public aethina::Bundle
{
public:
    MyBundle() { }
    virtual ~MyBundle() { }
};

int main(int, char**)
{
    auto tf2 = aethina::make_unique<MyBundle>();
    aethina::RegisterBundle(tf2.get());

    return 0;
}
