#include "Player.h"

Player::Player() {}

Player::~Player() {}

void Player::load(int x, int y, int width, int height, std::string textureID) {
	Player::textureID = textureID;
}
void Player::draw() {
}
void Player::update() {
}
void Player::clean() {
}

std::string Player::getTextureId() {
	return textureID;
}
