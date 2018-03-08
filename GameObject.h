class GameObject{
	protected:
		std::string text = "";

		const std::string& getText_p() const { return text; }
		void setText_p(std::string t){ text = std::move(t); }
		void promptText(IGUIEnvironment* guienv){}

	public:
};
