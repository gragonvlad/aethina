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

#include <type_traits>
#include <atomic>

#include "aethina_config.hpp"

#ifdef core_EXPORTS
#  define AETHINA_CORE_API AETHINA_API_EXPORT
#else
#  define AETHINA_CORE_API AETHINA_API_IMPORT
#endif

namespace aethina
{
    class Bundle;

    /**
     *
     */
    class AETHINA_CORE_API BundleGuard
    {
        friend class Bundle;

        BundleGuard(std::atomic<std::size_t>* counter)
            : counter_(counter) { }

    public:
        BundleGuard(BundleGuard&& guard);
        BundleGuard(BundleGuard const& guard);

        ~BundleGuard();

        BundleGuard& operator= (BundleGuard&& guard);
        BundleGuard& operator= (BundleGuard const& guard);

    private:
        std::atomic<std::size_t>* counter_;
    };

    /**
     *
     */
    class AETHINA_CORE_API Bundle
    {
    protected:
        Bundle() { }

    public:
        Bundle(Bundle const&) = delete;
        Bundle(Bundle&&) = delete;
        virtual ~Bundle() { }
        Bundle& operator= (Bundle const&) = delete;
        Bundle& operator= (Bundle&&) = delete;

        /**
         *
         */
        template<typename T>
        inline bool IsInterface() const
        {
            return ToInterface<T>() != nullptr;
        }

        /**
         *
         */
        template<typename T>
        inline bool ToInterface()
        {
            return dynamic_cast<T*>(this);
        }

        /**
         *
         */
        template<typename T>
        inline bool ToInterface() const
        {
            return dynamic_cast<typename std::add_const<T*>::type>(this);
        }
    };

    /**
     *
     */
    class AETHINA_CORE_API BundleListener
    {
    protected:
        BundleListener() { }

    public:
        BundleListener(BundleListener const&) = delete;
        BundleListener(BundleListener&&) = delete;
        virtual ~BundleListener() { }
        BundleListener& operator= (BundleListener const&) = delete;
        BundleListener& operator= (BundleListener&&) = delete;

        /**
         *
         */
        virtual void Visit(Bundle* bundle) = 0;
    };

    /**
     *
     */
    class AETHINA_CORE_API BundleSubscriber : public BundleListener
    {
    protected:
        BundleSubscriber() { }

    public:
        virtual ~BundleSubscriber() { }

        /**
         *
         */
        virtual std::size_t GetSubscribedBundlesHashCode() const = 0;
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

    /**
     *
     */
    AETHINA_CORE_API bool AddBundleListener(BundleSubscriber* bundle);

    /**
     *
     */
    AETHINA_CORE_API bool RemoveBundleListener(BundleSubscriber* bundle);

    /**
     *
     */
    enum class BundleReferenceWaitType
    {
        LOCK,
        THROW
    };

    namespace detail
    {
        template<typename /*T*/, BundleReferenceWaitType /*W*/>
        class BundleReferenceBase;

        template<typename T>
        class BundleReferenceBase<T, BundleReferenceWaitType::LOCK>
            : public BundleSubscriber
        {
        public:
            BundleReferenceBase() : reference_(nullptr) { }
            virtual ~BundleReferenceBase() { }

        protected:
            inline T* Wait()
            {
                return nullptr;
            }

            T* reference_;
        };

        template<typename T>
        class BundleReferenceBase<T, BundleReferenceWaitType::THROW>
            : public BundleSubscriber
        {
        public:
            BundleReferenceBase() : reference_(nullptr) { }
            virtual ~BundleReferenceBase() { }

        protected:
            inline T* Wait()
            {
                return nullptr;
            }

            T* reference_;
        };
    }

    /**
     *
     */
    template<typename T, BundleReferenceWaitType W = BundleReferenceWaitType::LOCK>
    class BundleReference : public detail::BundleReferenceBase<T, W>
    {
    public:
        BundleReference()
        {
            AddBundleListener(this);
        }

        virtual ~BundleReference()
        {
            RemoveBundleListener(this);
        }

        inline T* operator-> ()
        {
            if (!reference_)
                return reference_;
            else
                return Wait();
        }

        virtual void Visit(Bundle* bundle)
        {
        }

        std::size_t GetSubscribedBundlesHashCode() const
        {
            return typeid(T).hash_code();
        }
    };
}

#endif // AETHINA_CORE_HPP_INCLUDED
