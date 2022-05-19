// Copyright 2021 TIER IV, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef NETWORK_TRT_HPP_
#define NETWORK_TRT_HPP_

#include <tvm_wrapper.hpp>

namespace centerpoint
{
class VoxelEncoderTRT : public TVMWrapper
{
public:
  using TVMWrapper::TVMWrapper;

protected:
  bool setProfile(
    nvinfer1::IBuilder & builder, nvinfer1::INetworkDefinition & network,
    nvinfer1::IBuilderConfig & config) override;
};

class HeadTRT : public TVMWrapper
{
public:
  using TVMWrapper::TVMWrapper;

  HeadTRT(const std::size_t num_class, const bool verbose);

protected:
  bool setProfile(
    nvinfer1::IBuilder & builder, nvinfer1::INetworkDefinition & network,
    nvinfer1::IBuilderConfig & config) override;

  std::size_t num_class_{0};
};

}  // namespace centerpoint

#endif  // NETWORK_TRT_HPP_
