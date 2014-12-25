// Copyright (c) 2013- PPSSPP Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0 or later versions.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official git repository and contact information can be found at
// https://github.com/hrydgard/ppsspp and http://www.ppsspp.org/.

#include "Common/CPUDetect.h"
#include "Core/MIPS/JitCommon/JitState.h"

namespace MIPSComp {
	JitOptions::JitOptions() {
		enableBlocklink = true;
#ifdef ARM
		downcountInRegister = true;
#else
		downcountInRegister = false;
#endif

#if defined(_M_IX86) || defined(_M_X64)
		enableVFPUSIMD = true;
#endif

		useBackJump = false;
		useForwardJump = false;
		cachePointers = true;
		immBranches = false;
		continueBranches = false;
		continueJumps = false;
		continueMaxInstructions = 300;

		useNEONVFPU = false;  // true
		if (!cpu_info.bNEON)
			useNEONVFPU = false;
	}
}

