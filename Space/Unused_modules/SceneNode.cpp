#include <algorithm>
#include <cassert>

#include <SceneNode.hpp>



void SceneNode::attachChild(std::unique_ptr<SceneNode> child) {
	child->parent_ = this;
	children_.push_back(std::move(child);
}

std::unique_ptr<SceneNode> SceneNode::detachChild(const SceneNode& node) {
	auto found = std::find_if(children_.begin(), children_.end(),
			[&] (std::unique_ptr<SceneNode>& p) -> bool 
			{ return p.get() == &node;);

	assert(found != children_.end());

	std::unique_ptr<SceneNode> result = std::move(*found);
	result->parent_ = nullptr;
	children_.erase(found);
	return result;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();

	drawCurrent(target, states);

	for (const std::unique_ptr<SceneNode>& child : children_)
		child->draw(target, states);
}

void SceneNode::update(sf::Time dt) {
	updateCurrent(dt);
	updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time) {}

void SceneNode::updateChildren(sf::Time dt) {
	for (std::unique_ptr<SceneNode>& child : children_)
		child->update(dt);
}


