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
 */

#ifndef TENSORFLOW_CORE_DISTRIBUTED_RUNTIME_PAGINGHELPER_H_
#define TENSORFLOW_CORE_DISTRIBUTED_RUNTIME_PAGINGHELPER_H_

namespace tensorflow {
class Tensor;
class TensorBuffer;

namespace core {
class RefCounted;
} // namespace core

namespace remote {

class PagingHelper
{
public:
    static int refCountOf(core::RefCounted &reff);

    static TensorBuffer *bufferOf(Tensor &t);
    static Tensor cloneWithNewBuffer(const Tensor &t, TensorBuffer *buf);
};

} // namespace remote
} // namespace tensorflow

#endif // TENSORFLOW_CORE_DISTRIBUTED_RUNTIME_PAGINGHELPER_H_
