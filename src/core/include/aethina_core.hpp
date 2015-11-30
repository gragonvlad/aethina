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

#ifndef AETHINA_CORE_HPP_INCLUDED
#define AETHINA_CORE_HPP_INCLUDED

#include "aethina_config.hpp"

#ifdef core_EXPORTS
#  define AETHINA_CORE_API AETHINA_API_EXPORT
#else
#  define AETHINA_CORE_API AETHINA_API_IMPORT
#endif

namespace aethina
{
    /**
     *
     */
    class Bundle
    {
    protected:
        Bundle() { }

    public:
        virtual ~Bundle() { }
    };

    /**
     *
     */
    class BundleListener
    {
    protected:
        BundleListener() { }

    public:
        virtual ~BundleListener() { }

        /**
        *
        */
        virtual void Visit(Bundle* bundle) = 0;
    };

    /**
     *
     */
    AETHINA_CORE_API bool RegisterBundle(Bundle const* bundle);

    /**
     *
     */
    AETHINA_CORE_API bool UnregisterBundle(Bundle const* bundle);

    /**
     *
     */
    AETHINA_CORE_API bool AddBundleListener(BundleListener* bundle);

    /**
     *
     */
    AETHINA_CORE_API bool RemoveBundleListener(BundleListener* bundle);
}

#endif // AETHINA_CORE_HPP_INCLUDED
