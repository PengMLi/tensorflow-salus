/*
 * <one line to give the library's name and an idea of what it does.>
 * Copyright (C) 2017  Aetf <aetf@unlimitedcodeworks.xyz>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef RPCALLOCATOR_H
#define RPCALLOCATOR_H

#include "tensorflow/core/framework/allocator.h"
#include "tensorflow/core/platform/types.h"
#include "third_party/eigen3/unsupported/Eigen/CXX11/Tensor"

#include <memory>

namespace tensorflow {

class RpcClient;

/**
 * @todo write docs
 */
class RPCAllocator : public Allocator
{
public:
    RPCAllocator(RpcClient &rpc);

    ~RPCAllocator() override;

    string Name() override;
    void *AllocateRaw(size_t alignment, size_t num_bytes) override;
    void DeallocateRaw(void *ptr) override;

private:

    RpcClient &m_rpc;

    TF_DISALLOW_COPY_AND_ASSIGN(RPCAllocator);
};

class OneTimeAllocator : public Allocator
{
public:
    static std::unique_ptr<OneTimeAllocator> create(uint64_t);

    ~OneTimeAllocator() override;

    string Name() override;
    void *AllocateRaw(size_t alignment, size_t num_bytes) override;
    void DeallocateRaw(void *ptr) override;

private:
    OneTimeAllocator(uint64_t addr_handle);

    uint64_t m_addr_handle;

    TF_DISALLOW_COPY_AND_ASSIGN(OneTimeAllocator);
};

}

#endif // RPCALLOCATOR_H
