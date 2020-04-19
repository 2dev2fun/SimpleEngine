// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Command.h"
#include "System/Input.h"

#include <algorithm>
#include <memory>

namespace engine {

InputSystem::InputSystem(Game* game) : mGame(game) {}

InputSystem::~InputSystem() {}

void InputSystem::update() {
	for (auto& command : mCommands) { command->execute(); }
}

void InputSystem::attachCommand(std::shared_ptr<Command> command) {
	mCommands.emplace_back(std::move(command));
}

void InputSystem::detachCommand(std::shared_ptr<Command> command) {
	auto it = std::find(mCommands.begin(), mCommands.end(), command);
	if (it != mCommands.end()) { mCommands.erase(it); } else { ASSERT(0); }
}

} // namespace engine
