
#include "aethina_core.hpp"
#include "aethina_common.hpp"

#include <vector>

class MyBundle : public aethina::Bundle
{
public:
    MyBundle() { }
    virtual ~MyBundle() { }
};

class MyOtherBundle : public aethina::Bundle
{
public:
    MyOtherBundle() { }
    virtual ~MyOtherBundle() { }
};

using namespace aethina;

#include <typeinfo>

int main(int, char**)
{
    auto tf2 = aethina::make_unique<MyBundle>();
    aethina::RegisterBundle(tf2.get());

    auto test = typeid(*tf2.get()).hash_code() == typeid(MyOtherBundle).hash_code();

    aethina::AddBundleListener(static_cast<aethina::BundleSubscriber*>(nullptr));
    aethina::AddBundleListener(static_cast<aethina::BundleListener*>(nullptr));

    BundleReference<MyOtherBundle> ref;

    return 0;
}
