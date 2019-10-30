#include <memory>



class SceneNode
	: public sf::Transformable
	, public sf::Drawable
	, private sf::NonCopyable
{
public:
	SceneNode();
	void 				attachChild(std::unique_ptr<SceneNode>);
	std::unique_ptr<SceneNode>	detachChild(const SceneNode& node);
	void				update(sf::Time dt);

private:
	virtual void 	draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void 	drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void 	updateCurrent(sf::Time dt);
	void		updateChildren(sf::Time dt);

	std::vector<std::unique_ptr<SceneNode> children_;
	SceneNode* parent_;
};	
