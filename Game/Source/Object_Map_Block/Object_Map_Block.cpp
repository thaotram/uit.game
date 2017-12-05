#include "Object_Map_Block.h"

Object_Map_Block::Object_Map_Block(string pName) {
	pName = "Resources/" + pName + ".json";
	this->clear();
	try {
		ifstream i(pName);
		json j;
		i >> j;

		json block = j["block"];

		//! square
		json squares = block["square"];
		for (auto& s : squares) {
			this->insert_or_assign(
				BlockType::square,
				RECT{ s[0],s[1],s[2],s[3] }
			);
		}
	}
	catch (exception e) {
		this->clear();
	}
}