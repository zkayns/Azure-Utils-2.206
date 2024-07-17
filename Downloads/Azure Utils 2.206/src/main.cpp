#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/utils/web.hpp>
#include <Geode/modify/MenuGameLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/BasedButtonSprite.hpp>
#include <Geode/ui/GeodeUI.hpp>
using namespace geode::prelude;
class AzureUtilsLayer : public CCLayer {

public:
    void onButton(CCObject* sender) {
		geode::openSettingsPopup(Mod::get());
    }
};
class $modify(MenuLayer) {
	// Socials Confirmation
	void onTwitch(cocos2d::CCObject* sender) {
		if (Mod::get()->getSettingValue<bool>("socialsconfirmation")) {
			geode::createQuickPopup(
    			"Twitch",
    			"Are you sure you want to open RobTop\'s <cp>Twitch</c>?",
    			"Cancel", "Yes",
    			[](auto, bool btn2) {
        			if (btn2) {
            			geode::utils::web::openLinkInBrowser("https://www.twitch.tv/robtopgames");
        			}
    			}
			);
		} 
		if (!Mod::get()->getSettingValue<bool>("socialsconfirmation")) {
            geode::utils::web::openLinkInBrowser("https://www.twitch.tv/robtopgames");
		}
	}
	void onYouTube(cocos2d::CCObject* sender) {
		if (Mod::get()->getSettingValue<bool>("socialsconfirmation")) {
			geode::createQuickPopup(
    			"YouTube",
    			"Are you sure you want to open RobTop\'s <cr>YouTube</c>?",
    			"Cancel", "Yes",
    			[](auto, bool btn2) {
        			if (btn2) {
            			geode::utils::web::openLinkInBrowser("https://www.youtube.com/@robtopgames");
        			}
    			}
			);
		} 
		if (!Mod::get()->getSettingValue<bool>("socialsconfirmation")) {
            geode::utils::web::openLinkInBrowser("https://www.youtube.com/@robtopgames");
		}
	}
	void onTwitter(cocos2d::CCObject* sender) {
		if (Mod::get()->getSettingValue<bool>("socialsconfirmation")) {
			geode::createQuickPopup(
    			"Twitter",
    			"Are you sure you want to open RobTop\'s <cj>Twitter</c>?",
    			"Cancel", "Yes",
    			[](auto, bool btn2) {
        			if (btn2) {
            			geode::utils::web::openLinkInBrowser("https://x.com/robtopgames");
        			}
    			}
			);
		} 
		if (!Mod::get()->getSettingValue<bool>("socialsconfirmation")) {
            geode::utils::web::openLinkInBrowser("https://x.com/robtopgames");
		}
	}
	void onFacebook(cocos2d::CCObject* sender) {
		if (Mod::get()->getSettingValue<bool>("socialsconfirmation")) {
			geode::createQuickPopup(
    			"Facebook",
    			"Are you sure you want to open RobTop\'s <cb>Facebook</c>?",
    			"Cancel", "Yes",
    			[](auto, bool btn2) {
        			if (btn2) {
            			geode::utils::web::openLinkInBrowser("https://www.facebook.com/people/RobTop-Games/100081802506994/");
        			}
    			}
			);
		} 
		if (!Mod::get()->getSettingValue<bool>("socialsconfirmation")) {
            geode::utils::web::openLinkInBrowser("https://www.facebook.com/people/RobTop-Games/100081802506994/");
		}
	}
	void onDiscord(cocos2d::CCObject* sender) {
		if (Mod::get()->getSettingValue<bool>("socialsconfirmation")) {
			geode::createQuickPopup(
    			"Discord",
    			"Are you sure you want to open the Geometry Dash <cl>Discord</c>?",
    			"Cancel", "Yes",
    			[](auto, bool btn2) {
        			if (btn2) {
            			geode::utils::web::openLinkInBrowser("https://discord.com/invite/geometrydash");
        			}
    			}
			);
		} 
		if (!Mod::get()->getSettingValue<bool>("socialsconfirmation")) {
            geode::utils::web::openLinkInBrowser("https://discord.com/invite/geometrydash");
		}
	}
};
class $modify(MenuGameLayer) {
	// Disable Menu Kills
	void destroyPlayer() {
		if (!Mod::get()->getSettingValue<bool>("disablemenukill")) {
			MenuGameLayer::destroyPlayer();
		}
	}
};
class $modify(PlayLayer) {
	void updateAttempts() {
		if (!Mod::get()->getSettingValue<bool>("freezeattempts")) {
			PlayLayer::updateAttempts();
		}
	}
    void destroyPlayer(PlayerObject* player, GameObject* object) override {
        if (!Mod::get()->getSettingValue<bool>("noclip")) {
            PlayLayer::destroyPlayer(player, object);
        }
    };
};
class $modify(PauseLayer) {
	void customSetup() {
		PauseLayer::customSetup();
		auto menu = this->getChildByID("bottom-button-menu");
		auto spr = CircleButtonSprite::createWithSpriteFrameName("diffIcon_02_btn_001.png");
    	auto btn = CCMenuItemSpriteExtra::create(
        	spr, this, menu_selector(AzureUtilsLayer::onButton)
    	);
    	menu->addChild(btn);
		menu->updateLayout();

	}
};