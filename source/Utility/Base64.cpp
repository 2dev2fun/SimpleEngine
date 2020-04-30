// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Base64.h"

namespace engine {
namespace base64 {

const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

bool is_base64(UInt8 c) { return (isalnum(c) || (c == '+') || (c == '/')); }

std::string encode(UInt8 const* buf, UInt32 bufLen) {
	std::string ret;
	Int32 i = 0;
	Int32 j = 0;
	UInt8 char_array_3[3];
	UInt8 char_array_4[4];

	while (bufLen--) {
		char_array_3[i++] = *(buf++);
		if (i == 3) {
			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
			char_array_4[3] = char_array_3[2] & 0x3f;

			for(i = 0; (i <4) ; i++) { ret += base64_chars[char_array_4[i]]; }

			i = 0;
		}
	}

	if (i) {
		for(j = i; j < 3; j++) { char_array_3[j] = '\0'; }

		char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
		char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
		char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
		char_array_4[3] = char_array_3[2] & 0x3f;

		for (j = 0; (j < i + 1); j++) { ret += base64_chars[char_array_4[j]]; }

		while((i++ < 3)) { ret += '='; }
	}

	return ret;
}

void decode(std::string const& text, std::vector<UInt8>& data) {
	Int32 in_len = text.size();
	Int32 i = 0;
	Int32 j = 0;
	Int32 in_ = 0;
	UInt8 char_array_4[4], char_array_3[3];

	UInt32 index = 0;

	while (in_len-- && (text[in_] != '=') && is_base64(text[in_])) {
		char_array_4[i++] = text[in_]; in_++;
		if (i ==4) {
			for (i = 0; i <4; ++i) {
				char_array_4[i] = base64_chars.find(char_array_4[i]);
			}

			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

			for (i = 0; (i < 3); i++) {
				ASSERT(index + 1 <= text.size());
				data[index++] = char_array_3[i];
			}

			i = 0;
		}
	}

	if (i) {
		for (j = i; j < 4; ++j) {
			char_array_4[j] = 0;
		}

		for (j = 0; j < 4; ++j) {
			char_array_4[j] = base64_chars.find(char_array_4[j]);
		}

		char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
		char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
		char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

		for (j = 0; (j < i - 1); j++) {
			ASSERT(index + 1 <= text.size());
			data[index++] = char_array_3[j];
		}
	}
}

} // namespace base64
} // namespace engine
