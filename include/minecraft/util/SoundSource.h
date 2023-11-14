#pragma once

namespace mc {
    class SoundSource {
    public:
        enum ESoundSource : int {
            unk_0x0,
		    unk_0x1,
		    noteblock,
		    lightningBolt,
		    unk_0x4,
		    monster,
		    entity,
		    player
        };
    };
}