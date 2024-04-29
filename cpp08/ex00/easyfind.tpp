template<typename T>
typename T::const_iterator easyfind(T& container, int target) {
	return std::find(container.begin(), container.end(), target);
}
