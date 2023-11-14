#pragma once

namespace mc_boost {
	template<typename T>
	class shared_ptr {
	public:
		shared_ptr(T* p) {
			ptr = p;
	    	cnt = 0;
	  	}
	
		shared_ptr() {
	    	ptr = 0;
	    	cnt = 0;
	  	}
		
		T* operator->() const { return ptr; }
		T& operator[](int i) const { return ptr[i]; }
	
		T* get() const { return ptr; }
	private:
	  	T* ptr;
	  	uint32_t cnt;
	};
}