#include <Geode/Geode.hpp>
using namespace geode::prelude;
#include <Geode/modify/CCKeyboardDispatcher.hpp>
#include "eatfile.hpp"

class $modify(CCKeyboardDispatcher) {
	bool dispatchKeyboardMSG(cocos2d::enumKeyCodes key, bool down, bool repeat) {
		if (down) {
			if (static_cast<int>(key) >= 0) {
				MainFileUitl::intperFile(keyToString(key));
			}
		}
		return CCKeyboardDispatcher::dispatchKeyboardMSG(key, down, repeat);
	}
};