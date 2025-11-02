/**
 * ICFG.h
 * @author kisslune 
 */
#ifndef ANSWERS_ICFG_H
#define ANSWERS_ICFG_H

// 关键：只包含LLVM的头文件（让编译器找到UnifyFunctionExitNodesLegacyPass的定义）
// 无需手动typedef，因为LLVM头文件里已经有这个类了
#include <llvm/Transforms/Utils/UnifyFunctionExitNodes.h>

// 再包含SVF的头文件（此时SVF能找到llvm::UnifyFunctionExitNodesLegacyPass）
#include "Graphs/SVFG.h"
#include "SVF-LLVM/SVFIRBuilder.h"

class CFGAnalysis
{
public:
    explicit CFGAnalysis(SVF::ICFG *icfg);
    void analyze(SVF::ICFG *icfg);
    void dumpPaths();
protected:
    void recordPath(const std::vector<unsigned> &path);
    std::stack<unsigned> callStack;
    std::set<unsigned> sources;
    std::set<unsigned> sinks;
    std::set<std::vector<unsigned>> reachablePaths;
};

#endif //ANSWERS_ICFG_H