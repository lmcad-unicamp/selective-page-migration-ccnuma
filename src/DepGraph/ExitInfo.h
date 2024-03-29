/*
 * ExitInfo.h
 *
 *  Created on: Dec 16, 2013
 *      Author: raphael
 */

#ifndef EXITINFO_H_
#define EXITINFO_H_

#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/PassAnalysisSupport.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/InstrTypes.h"
#include <set>


namespace llvm {

	/*
	 * The class ExitInfo collects the instructions that make the program
	 * to stop (in normal circunstances; does not apply to exceptions raised
	 * by the OS).
	 *
	 * Those instructions are :
	 * 		- calls to exit or abort
	 * 		- return instruction in the main function
	 */
	class ExitInfo: public ModulePass {
	public:
		static char ID;

		std::set<Instruction*> exitPoints;

		ExitInfo(): ModulePass(ID) {};
		virtual ~ExitInfo() {};

		virtual void getAnalysisUsage(AnalysisUsage &AU) const{
			AU.setPreservesAll();
		}

		virtual bool runOnModule(Module &M);
	};

}
#endif /* EXITINFO_H_ */
