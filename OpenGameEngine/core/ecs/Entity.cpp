#include "Entity.h"
namespace openge {
	// Construtor padr�o
	template<typename T>
	Entity<T>::Entity() : m_id(0) {}

	// Construtor com par�metros
	template<typename T>
	Entity<T>::Entity(std::uint64_t entityId) : m_id(entityId) {}

	// Destrutor
	template<typename T>
	Entity<T>::~Entity() {}
	/*
	* static_assert � uma diretiva de pr�-processador que permite realizar verifica��o est�tica de uma express�o em tempo de compila��o.
	* � usada para impor uma condi��o em tempo de compila��o e gerar um erro de compila��o se a condi��o n�o for satisfeita.
	*/
	template<typename T>
	template<typename ComponentType, typename ...Args>
	void Entity<T>::addComponent(Args && ...args)
	{
		static_assert(std::is_same<ComponentType, Component<T>>::value, "ComponentType must be Component<T>");
		/*
		std::forward<Args>(args)... � uma constru��o usada para encaminhar os argumentos passados para a fun��o make_shared para o construtor do ComponentType. Ela � usada para preservar a categoria de valor (lvalue ou rvalue) dos argumentos passados para o make_shared.

		Args � um pacote de argumentos que pode conter zero ou mais argumentos. � uma forma gen�rica de especificar os argumentos do construtor.

		std::forward � uma fun��o de utilidade que permite encaminhar argumentos exatamente como foram passados para uma fun��o.
		*/
		std::shared_ptr<ComponentType> component = std::make_shared<ComponentType>(std::forward<Args>(args)...);
		/*
		A fun��o typeid � uma opera��o do C++ que retorna um objeto do tipo std::type_info, que cont�m informa��es sobre o tipo em tempo de execu��o de um objeto ou uma express�o.

		O typeid � usado para obter informa��es sobre tipos em tempo de execu��o. Ele pode ser �til em situa��es em que � necess�rio realizar verifica��es ou tomar decis�es com base no tipo de objeto em tempo de execu��o.
		*/
		m_components[std::type_index(typeid(ComponentType))] = component;
	}

	template<typename T>
	template<typename ComponentType>
	std::shared_ptr<ComponentType> Entity<T>::getComponent()
	{
		static_assert(std::is_same<ComponentType, Component<T>>::value, "ComponentType must be Component<T>");
		auto it = m_components.find(std::type_index(typeid(ComponentType)));
		if (it != m_components.end()) {
			/**
			* std::dynamic_pointer_cast � uma fun��o da biblioteca padr�o do C++ que permite realizar convers�es seguras de ponteiros inteligentes (std::shared_ptr ou std::weak_ptr) para outros tipos relacionados.
			*
			* A chave e o valor do par usando it->first e it->second, respectivamente.
			*/
			return std::dynamic_pointer_cast<ComponentType>(it->second);
		}
		return nullptr;
	}

	template<typename T>
	template<typename ComponentType>
	bool Entity<T>::HasComponent()
	{
		static_assert(std::is_same<ComponentType, Component<T>>::value, "ComponentType must be Component<T>");
		return m_components.find(std::type_index(typeid(ComponentType))) != !m_components.end();
	}

	template<typename T>
	template<typename ComponentType>
	void Entity<T>::removeComponent()
	{
		static_assert(std::is_same<ComponentType, Component<T>>::value, "ComponentType must be Component<T>");
		m_components.erase(std::type_index(typeid(ComponentType)));
	}
}
