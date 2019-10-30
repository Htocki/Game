#include <algorithm>
#include <cassert>

#include <SceneNode.hpp>



// Присоединение дочернего узла
void SceneNode::attachChild(std::unique_ptr<SceneNode> child) {
	child->parent_ = this;
	children_.push_back(std::move(child);
}


// Отсоединение дочернего узла
std::unique_ptr<SceneNode> SceneNode::detachChild(const SceneNode& node) {
	// Ищем указанный узел в контейнере
	auto found = std::find_if(children_.begin(), children_.end(),
			[&] (std::unique_ptr<SceneNode>& p) -> bool 
			{ return p.get() == &node;);

	assert(found != children_.end());

	// Перемещаем найденный узел из контейнера в переменную result
	// Устанавливаем родительский указатель узла на nullptr
	// Удаляем пустой элемент из контейнера
	// Возвращаем указатель, содержащий отсоединенный узел
	std::unique_ptr<SceneNode> result = std::move(*found);
	result->parent_ = nullptr;
	children_.erase(found);
	return result;
}


// Выражение с оператором *= объединяет абсолютное преобразование родителя с относительным
// преобразованием текущего узла.
// Результатом является абсолютное преобразование текущего узла, в котором хранится
// место в мире,где находится наш узел сцены.
void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();

	// Отрисовка производного объекта
	drawCurrent(target, states);

	// Отрисовка всех дочерних узлов
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


