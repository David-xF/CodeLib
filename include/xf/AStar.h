#pragma once

struct sNode {
    bool bObstacle = false;
    bool bVisited = false;
    float fGlobalGoal;
    float fLocalGoal;
    int x;
    int y;
    xf::Vector<sNode*> vecNeighbours;
    sNode* parent;
};

class AStar {
public:
    AStar() {
        
    }

    void setup() {
        nMapHeight = 32;
        nMapWidth  = 32;
        nodes = new sNode[nMapWidth * nMapHeight];

        
        for (int x = 0; x < nMapWidth; x++) {
            for (int y = 0; y < nMapHeight; y++) {
                nodes[y * nMapWidth + x].x = x;
                nodes[y * nMapWidth + x].y = y;
                nodes[y * nMapWidth + x].bObstacle = false;
                nodes[y * nMapWidth + x].bVisited = false;
                nodes[y * nMapWidth + x].parent = nullptr;
            }
        }

        for (int x = 0; x < nMapWidth; x++) {
            for (int y = 0; y < nMapHeight; y++) {
                if (y > 0)              nodes[y * nMapWidth + x].vecNeighbours.push_back(&nodes[(y - 1) * nMapWidth + (x + 0)]);
                if (y < nMapHeight - 1) nodes[y * nMapWidth + x].vecNeighbours.push_back(&nodes[(y + 1) * nMapWidth + (x + 0)]);
                if (x > 0)              nodes[y * nMapWidth + x].vecNeighbours.push_back(&nodes[(y + 0) * nMapWidth + (x - 1)]);
                if (x < nMapWidth - 1)  nodes[y * nMapWidth + x].vecNeighbours.push_back(&nodes[(y + 0) * nMapWidth + (x + 1)]);
            }
        } 

        nodeStart = &nodes[xf::utils::Random::next(0, nMapHeight - 1) * nMapWidth + xf::utils::Random::next(0, nMapWidth - 16)];
        nodeEnd   = &nodes[xf::utils::Random::next(0, nMapHeight - 1) * nMapWidth + xf::utils::Random::next(0, nMapWidth - 16)];
    }

    void solveAStar() {
        for (int x = 0; x < nMapWidth; x++) {
            for (int y = 0; y < nMapHeight; y++) {
                nodes[y * nMapWidth + x].bVisited = false;
                nodes[y * nMapWidth + x].fGlobalGoal = INFINITY;
                nodes[y * nMapWidth + x].fLocalGoal = INFINITY;
                nodes[y * nMapWidth + x].parent = nullptr;
            }
        }

        auto distance = [](sNode* a, sNode* b) {
            return sqrtf(powf(a->x - b->x, 2) + powf(a->y - b->y, 2));
        };

        auto heuristic = [distance](sNode* a, sNode* b) {
            return distance(a, b);
        };

        sNode* current;
        nodeStart->fLocalGoal = 0.0f;
        nodeStart->fGlobalGoal = heuristic(nodeStart, nodeEnd);

        xf::Vector<sNode*> notTested;
        notTested.push_back(nodeStart);

        while (!notTested.isEmpty() && current != nodeEnd) {
            sNode** data = notTested.getData();
            sNode** sortedData = sort<sNode*>(data, notTested.getSize(), [](sNode*& lhs, sNode*& rhs) {
                return lhs->fGlobalGoal < rhs->fGlobalGoal;
            });

            notTested.setData(sortedData, notTested.getSize());

            while (!notTested.isEmpty() && notTested.front()->bVisited) {
                notTested.pop_front();
            }

            if (notTested.isEmpty()) break;

            current = notTested.front();
            current->bVisited = true;
            
            for (auto nodeNeighbour : current->vecNeighbours) {
                if (!nodeNeighbour->bVisited && nodeNeighbour->bObstacle == 0) 
                    notTested.push_back(nodeNeighbour);

                float fPossiblyLowerGoal = current->fLocalGoal + distance(current, nodeNeighbour);
                if (fPossiblyLowerGoal < nodeNeighbour->fLocalGoal) {
                    nodeNeighbour->parent = current;
                    nodeNeighbour->fLocalGoal = fPossiblyLowerGoal;

                    nodeNeighbour->fGlobalGoal = nodeNeighbour->fLocalGoal + heuristic(nodeNeighbour, nodeEnd);
                }
            }
        }
    }

    void onUserUpdate() {
        mc::LocalPlayer* lPlayer = mc::Minecraft::getInstance()->thePlayer;
        int selectedX = toInt(lPlayer->x);
        int selectedY = toInt(lPlayer->z);

        if (selectedX >= 0 && selectedX < nMapWidth) {
            if (selectedY >= 0 && selectedY < nMapHeight) {
                nodes[selectedY * nMapWidth + selectedX].bObstacle = !nodes[selectedY * nMapWidth + selectedX].bObstacle;
                solveAStar();
            }
        }

        auto getColor = [](AStar* n, sNode* node) {
            int toRet = 2;
            if (node->bObstacle)                                          toRet = 173;
            if (node->bVisited)                                           toRet = 4;
            if (node->x == n->nodeStart->x && node->y == n->nodeStart->y) toRet = 57;
            if (node->x == n->nodeEnd->x   && node->y == n->nodeEnd->y)   toRet = 133;
            
            return toRet;
        };
        
        auto setBlock = [](mc::BlockPos const & pos, int id) {
            if (mc::MinecraftServer::getInstance()->getLevel(0)->getBlockId(pos.x, pos.y, pos.z) != id) {
                mc::MinecraftServer::getInstance()->getLevel(0)->setBlock(
                    pos, 
                    mc::Block::byItem(
                        mc::Item::byId(id)
                    )->defaultBlockState(), 
                    3, false);
            }
        };

        int nY = 3;
        for (int x = 0; x < nMapWidth; x++) {
            for (int y = 0; y < nMapHeight; y++) {
                setBlock({x, nY, y}, getColor(this, &nodes[y * nMapWidth + x]));
            }
        }

        if (nodeEnd != nullptr) {
            sNode* p = nodeEnd;
            while (p->parent != nullptr) {
                if (!(p->x == nodeEnd->x && p->y == nodeEnd->y)) {
                    setBlock({p->x, nY, p->y}, 208);
                }

                p = p->parent;
            }
        }
    }

    sNode* nodes = nullptr;
    int nMapWidth = 16;
    int nMapHeight = 16;

    sNode* nodeStart = nullptr;
    sNode* nodeEnd = nullptr;
};