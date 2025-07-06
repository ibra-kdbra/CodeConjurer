#pragma once
#include "nets/defines.h"
#include "zlib.h"

/*
 * Converts zlib error the NETS result.
 * result - zlib result value.
 */
inline static NetsResult zlibErrorToNetsResult(int result)
{
	switch (result)
	{
	default:
		return UNKNOWN_ERROR_NETS_RESULT;
	case Z_NEED_DICT:
	case Z_DATA_ERROR:
	case Z_STREAM_ERROR:
		return BAD_DATA_NETS_RESULT;
	case Z_MEM_ERROR:
	case Z_BUF_ERROR:
		return OUT_OF_MEMORY_NETS_RESULT;
	}
}