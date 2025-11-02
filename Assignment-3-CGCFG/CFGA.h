/**
 * ICFG.h
 * @author kisslune 
 */
#ifndef ANSWERS_ICFG_H
#define ANSWERS_ICFG_H

// 新增：LLVM类型适配（必须在包含SVF头文件之前！）
#include <llvm/Transforms/Utils/UnifyFunctionExitNodes.h>  // 引入新版类型
typedef llvm::UnifyFunctionExitNodesPass llvm::UnifyFunctionExitNodesLegacyPass;  // 映射旧名到新名

// 原有SVF头文件（现在会用上面的映射）
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