/**
 * Copyright 2015 Denis Blank <denis.blank@outlook.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "aethina_core.hpp"

#include "aethina_config.hpp"

#include <boost/type_index.hpp>

#include <typeinfo>

namespace aethina
{
    AETHINA_CORE_API bool RegisterBundle(Bundle const* bundle)
    {
        auto name = typeid(*bundle).name();
        return true;
    }

    AETHINA_CORE_API bool UnregisterBundle(Bundle const* bundle)
    {
        return true;
    }

    AETHINA_CORE_API bool AddBundleListener(BundleListener* bundle)
    {
        return true;
    }

    AETHINA_CORE_API bool RemoveBundleListener(BundleListener* bundle)
    {
        return true;
    }
}
