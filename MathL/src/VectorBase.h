#pragma once

namespace MathL {

	template<int D, typename T>
	class VectorBase
	{
	protected:
		T m_Data[D]{};
		int m_Dimension = D;
	public:
		VectorBase() {}
		virtual ~VectorBase() {}
	};

}