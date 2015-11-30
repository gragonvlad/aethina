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

#include <typeinfo>
#include <unordered_map>
#include <unordered_set>

#include "aethina_config.hpp"

namespace aethina
{
    /**
     * Map which stores all bundles
     */
    std::unordered_multimap<std::size_t /*bundle hash_code*/, Bundle* /*bundle*/> bundles;

    /**
     * Map which stores the subscriber of a specific bundle.
     */
    std::unordered_multimap<std::size_t /*bundle hash_code*/, BundleSubscriber* /*subscriber*/> subscriber;

    /**
     * Set which stores the default bundle listeners.
     */
    std::unordered_set<BundleListener* /*listener*/> listener;

    BundleGuard::BundleGuard(BundleGuard&& guard)
    {
        counter_ = guard.counter_;
        guard.counter_ = nullptr;
    }

    BundleGuard::BundleGuard(BundleGuard const& guard)
    {
        ++(*guard.counter_);
        counter_ = guard.counter_;
    }

    BundleGuard::~BundleGuard()
    {
        if (--counter_)
        {
            // ToDo
            delete counter_;
        }
    }

    BundleGuard& BundleGuard::operator=(BundleGuard const& guard)
    {
        if (&guard != this)
        {
            ++(*guard.counter_);
            counter_ = guard.counter_;
        }
        return *this;
    }

    BundleGuard& BundleGuard::operator=(BundleGuard&& guard)
    {
        if (&guard != this)
        {
            counter_ = guard.counter_;
            guard.counter_ = nullptr;
        }
        return *this;
    }

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

    AETHINA_CORE_API bool AddBundleListener(BundleSubscriber* bundle)
    {
        return true;
    }

    AETHINA_CORE_API bool RemoveBundleListener(BundleSubscriber* bundle)
    {
        return true;
    }
}
