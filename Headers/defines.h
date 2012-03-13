// defines.h

#define JOIN( X, Y ) JOIN2(X,Y)
#define JOIN2( X, Y ) X##Y


#ifdef __ATLCOLL_H__
	typedef CAtlMap<CString, bool, CStringRefElementTraits<CString>> CAtlStringMap;
#endif


#undef BEGIN_MSG_MAP
#define BEGIN_MSG_MAP BEGIN_MSG_MAP_EX


#ifdef _DEBUG
	#define DEBUG_ONLY(f)      (f)
	#define WND_CLASS_SUFIX L"-APPCLASS_MIDI_DEBUG"
#else
	#define DEBUG_ONLY(f)      ((void)0)
	#define WND_CLASS_SUFIX L"-APPCLASS_MIDI_RELEASE"
#endif


#define DWORD_FILL(byte_size)										\
	static_assert((byte_size)%sizeof(DWORD) == 0,					\
					"Byte size is not a DWORD multiple");			\
	struct {														\
		DWORD JOIN(FILL_GAP, JOIN(__LINE__,JOIN(_, byte_size)))		\
		[(byte_size)/sizeof(DWORD)];								\
	};
