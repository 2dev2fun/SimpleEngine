// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Utility/GLTF2/Animation.h"

namespace engine {
namespace gltf2 {

void Animation::load(rj::Value& animation) {
	auto samplersIt = animation.FindMember("samplers");
	ASSERT(samplersIt != animation.MemberEnd());

	auto& samplers = samplersIt->value;
	ASSERT(samplers.IsArray());

	mSamplers.resize(samplers.Size());

	for (rj::SizeType j = 0; j < samplers.Size(); ++j) {

		auto inputIt = samplers[j].FindMember("input");
		ASSERT(inputIt != samplers[j].MemberEnd());

		auto& input = inputIt->value;
		ASSERT(input.IsUint());

		mSamplers[j].input = input.GetUint();


		auto outputIt = samplers[j].FindMember("output");
		ASSERT(outputIt != samplers[j].MemberEnd());

		auto& output = outputIt->value;
		ASSERT(output.IsUint());

		mSamplers[j].output = output.GetUint();


		auto interpolationIt = samplers[j].FindMember("interpolation");
		ASSERT(interpolationIt != samplers[j].MemberEnd());

		auto& interpolation = interpolationIt->value;
		ASSERT(interpolation.IsString());

		const std::string& interpolationString = interpolation.GetString();

		if (interpolationString == "LINEAR") {
			mSamplers[j].interpolation = Sampler::Interpolation::LINEAR;
			continue;
		}

		ASSERT(0);
	}


	auto channelsIt = animation.FindMember("channels");
	ASSERT(channelsIt != animation.MemberEnd());

	auto& channels = channelsIt->value;
	ASSERT(channels.IsArray());

	mChannels.resize(channels.Size());

	for (rj::SizeType j = 0; j < channels.Size(); ++j) {

		auto samplerIt = channels[j].FindMember("sampler");
		ASSERT(samplerIt != channels[j].MemberEnd());

		auto& sampler = samplerIt->value;
		ASSERT(sampler.IsUint());

		mChannels[j].sampler = sampler.GetUint();


		auto targetIt = channels[j].FindMember("target");
		ASSERT(targetIt != channels[j].MemberEnd());

		auto& target = targetIt->value;
		ASSERT(target.IsObject());


		auto nodeIt = target.FindMember("node");
		ASSERT(nodeIt != target.MemberEnd());

		auto& node = nodeIt->value;
		ASSERT(node.IsUint());

		mChannels[j].target.node = node.GetUint();


		auto pathIt = target.FindMember("path");
		ASSERT(pathIt != target.MemberEnd());

		auto& path = pathIt->value;
		ASSERT(path.IsString());

		const std::string& pathString = path.GetString();

		if (pathString == "rotation") {
			mChannels[j].target.path = Channel::Target::Path::rotation;
			continue;
		}

		ASSERT(0);
	}
}

} // namespace gltf2
} // namespace engine
