/* The copyright in this software is being made available under the BSD
 * License, included below. This software may be subject to other third party
 * and contributor rights, including patent rights, and no such rights are
 * granted under this license.
 *
 * Copyright (c) 2010-2022, ITU/ISO/IEC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *  * Neither the name of the ITU/ISO/IEC nor the names of its contributors may
 *    be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/** \file     decmain.cpp
    \brief    Decoder application main
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "TAppDecTop.h"
#include "../../Lib/TLibCommon/TComPrediction.cpp"
#include "../../Lib/TLibDecoder/TDecCu.cpp"

//int modosIntra64x64[35] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//int modosIntra32x32[35] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//int modosIntra16x16[35] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//int modosIntra8x8[35] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//int modosIntra4x4[35] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//string formatosInter = {"64x64", "64x32", "32x64", "64xA", "Ax64", "32x32", "32x16", "16x32", "32xA", "Ax32", "16x16", "16x8", "8x16", "16xA", "Ax16", "8x8", "8x4", "4x8"}; 
//string formatosIntra = {"64x64", "32x32", "16x16", "8x8", "4x4"};

//int maxHorMV4x8 = -9999;
//int maxHorMV8x4 = -9999;
//int maxHorMV8x8 = -9999;
//int maxHorMVAx16 = -9999;
//int maxHorMV16xA = -9999;
//int maxHorMV8x16 = -9999;
//int maxHorMV16x8 = -9999;
//int maxHorMV16x16 = -9999;
//int maxHorMVAx32 = -9999;
//int maxHorMV32xA = -9999;
//int maxHorMV16x32 = -9999;
//int maxHorMV32x16 = -9999;
//int maxHorMV32x32 = -9999;
//int maxHorMVAx64 = -9999;
//int maxHorMV64xA = -9999;
//int maxHorMV32x64 = -9999;
//int maxHorMV64x32 = -9999;
//int maxHorMV64x64 = -9999;
//
//int minHorMV4x8 = 9999;
//int minHorMV8x4 = 9999;
//int minHorMV8x8 = 9999;
//int minHorMVAx16 = 9999;
//int minHorMV16xA = 9999;
//int minHorMV8x16 = 9999;
//int minHorMV16x8 = 9999;
//int minHorMV16x16 = 9999;
//int minHorMVAx32 = 9999;
//int minHorMV32xA = 9999;
//int minHorMV16x32 = 9999;
//int minHorMV32x16 = 9999;
//int minHorMV32x32 = 9999;
//int minHorMVAx64 = 9999;
//int minHorMV64xA = 9999;
//int minHorMV32x64 = 9999;
//int minHorMV64x32 = 9999;
//int minHorMV64x64 = 9999;
//
//int maxVerMV4x8 = -9999;
//int maxVerMV8x4 = -9999;
//int maxVerMV8x8 = -9999;
//int maxVerMVAx16 = -9999;
//int maxVerMV16xA = -9999;
//int maxVerMV8x16 = -9999;
//int maxVerMV16x8 = -9999;
//int maxVerMV16x16 = -9999;
//int maxVerMVAx32 = -9999;
//int maxVerMV32xA = -9999;
//int maxVerMV16x32 = -9999;
//int maxVerMV32x16 = -9999;
//int maxVerMV32x32 = -9999;
//int maxVerMVAx64 = -9999;
//int maxVerMV64xA = -9999;
//int maxVerMV32x64 = -9999;
//int maxVerMV64x32 = -9999;
//int maxVerMV64x64 = -9999;
//
//int minVerMV4x8 = 9999;
//int minVerMV8x4 = 9999;
//int minVerMV8x8 = 9999;
//int minVerMVAx16 = 9999;
//int minVerMV16xA = 9999;
//int minVerMV8x16 = 9999;
//int minVerMV16x8 = 9999;
//int minVerMV16x16 = 9999;
//int minVerMVAx32 = 9999;
//int minVerMV32xA = 9999;
//int minVerMV16x32 = 9999;
//int minVerMV32x16 = 9999;
//int minVerMV32x32 = 9999;
//int minVerMVAx64 = 9999;
//int minVerMV64xA = 9999;
//int minVerMV32x64 = 9999;
//int minVerMV64x32 = 9999;
//int minVerMV64x64 = 9999;

int i = 0;
int j = 0;



//! \ingroup TAppDecoder
//! \{

// ====================================================================================================================
// Main function
// ====================================================================================================================

int main(int argc, char* argv[])
{
  Int returnCode = EXIT_SUCCESS;
  TAppDecTop  cTAppDecTop;

  // print information
  fprintf( stdout, "\n" );
  fprintf( stdout, "HM software: Decoder Version [%s] (including RExt)", NV_VERSION );
  fprintf( stdout, NVM_ONOS );
  fprintf( stdout, NVM_COMPILEDBY );
  fprintf( stdout, NVM_BITS );
  fprintf( stdout, "\n" );

  // create application decoder class
  cTAppDecTop.create();

  // parse configuration
  if(!cTAppDecTop.parseCfg( argc, argv ))
  {
    cTAppDecTop.destroy();
    returnCode = EXIT_FAILURE;
    return returnCode;
  }

  // starting time
  Double dResult;
  clock_t lBefore = clock();

  // call decoding function
  cTAppDecTop.decode();

  if (cTAppDecTop.getNumberOfChecksumErrorsDetected() != 0)
  {
    printf("\n\n***ERROR*** A decoding mismatch occured: signalled md5sum does not match\n");
    returnCode = EXIT_FAILURE;
  }

  // ending time
  dResult = (Double)(clock()-lBefore) / CLOCKS_PER_SEC;
  printf("\n Total Time: %12.3f sec.\n", dResult);

  // destroy application decoder class
  cTAppDecTop.destroy();
  cout << "PREDIÇÃO INTER\n\n";
  cout << "\nCU 64x64" << "\n" << "Maior vetor horizontal: " << maxHorMV64x64 << "\n" << "Maior vetor vertical: " << maxVerMV64x64 << "\n" << "Menor vetor horizontal: " << minHorMV64x64 << "\n" << "Menor vetor vertical: " << minVerMV64x64 << "\n";
  cout << "\nCU 64x32" << "\n" << "Maior vetor horizontal: " << maxHorMV64x32 << "\n" << "Maior vetor vertical: " << maxVerMV64x32 << "\n" << "Menor vetor horizontal: " << minHorMV64x32 << "\n" << "Menor vetor vertical: " << minVerMV64x32 << "\n";  
  cout << "\nCU 32x64" << "\n" << "Maior vetor horizontal: " << maxHorMV32x64 << "\n" << "Maior vetor vertical: " << maxVerMV32x64 << "\n" << "Menor vetor horizontal: " << minHorMV32x64 << "\n" << "Menor vetor vertical: " << minVerMV32x64 << "\n"; 
  cout << "\nCU 64xA" << "\n" << "Maior vetor horizontal: " << maxHorMV64xA << "\n" << "Maior vetor vertical: " << maxVerMV64xA << "\n" << "Menor vetor horizontal: " << minHorMV64xA << "\n" << "Menor vetor vertical: " << minVerMV64xA << "\n"; 
  cout << "\nCU Ax64" << "\n" << "Maior vetor horizontal: " << maxHorMVAx64 << "\n" << "Maior vetor vertical: " << maxVerMVAx64 << "\n" << "Menor vetor horizontal: " << minHorMVAx64 << "\n" << "Menor vetor vertical: " << minVerMVAx64 << "\n"; 
  cout << "\nCU 32x32" << "\n" << "Maior vetor horizontal: " << maxHorMV32x32 << "\n" << "Maior vetor vertical: " << maxVerMV32x32 << "\n" << "Menor vetor horizontal: " << minHorMV32x32 << "\n" << "Menor vetor vertical: " << minVerMV32x32 << "\n"; 
  cout << "\nCU 32x16" << "\n" << "Maior vetor horizontal: " << maxHorMV32x16 << "\n" << "Maior vetor vertical: " << maxVerMV32x16 << "\n" << "Menor vetor horizontal: " << minHorMV32x16 << "\n" << "Menor vetor vertical: " << minVerMV32x16 << "\n"; 
  cout << "\nCU 16x32" << "\n" << "Maior vetor horizontal: " << maxHorMV16x32 << "\n" << "Maior vetor vertical: " << maxVerMV16x32 << "\n" << "Menor vetor horizontal: " << minHorMV16x32 << "\n" << "Menor vetor vertical: " << minVerMV16x32 << "\n"; 
  cout << "\nCU 32xA" << "\n" << "Maior vetor horizontal: " << maxHorMV32xA << "\n" << "Maior vetor vertical: " << maxVerMV32xA << "\n" << "Menor vetor horizontal: " << minHorMV32xA << "\n" << "Menor vetor vertical: " << minVerMV32xA << "\n"; 
  cout << "\nCU Ax32" << "\n" << "Maior vetor horizontal: " << maxHorMVAx32 << "\n" << "Maior vetor vertical: " << maxVerMVAx32 << "\n" << "Menor vetor horizontal: " << minHorMVAx32 << "\n" << "Menor vetor vertical: " << minVerMVAx32 << "\n"; 
  cout << "\nCU 16x16" << "\n" << "Maior vetor horizontal: " << maxHorMV16x16 << "\n" << "Maior vetor vertical: " << maxVerMV16x16 << "\n" << "Menor vetor horizontal: " << minHorMV16x16 << "\n" << "Menor vetor vertical: " << minVerMV16x16 << "\n"; 
  cout << "\nCU 16x8" << "\n" << "Maior vetor horizontal: " << maxHorMV16x8 << "\n" << "Maior vetor vertical: " << maxVerMV16x8 << "\n" << "Menor vetor horizontal: " << minHorMV16x8 << "\n" << "Menor vetor vertical: " << minVerMV16x8 << "\n"; 
  cout << "\nCU 8x16" << "\n" << "Maior vetor horizontal: " << maxHorMV8x16 << "\n" << "Maior vetor vertical: " << maxVerMV8x16 << "\n" << "Menor vetor horizontal: " << minHorMV8x16 << "\n" << "Menor vetor vertical: " << minVerMV8x16 << "\n"; 
  cout << "\nCU 16xA" << "\n" << "Maior vetor horizontal: " << maxHorMV16xA << "\n" << "Maior vetor vertical: " << maxVerMV16xA << "\n" << "Menor vetor horizontal: " << minHorMV16xA << "\n" << "Menor vetor vertical: " << minVerMV16xA << "\n"; 
  cout << "\nCU Ax16" << "\n" << "Maior vetor horizontal: " << maxHorMVAx16 << "\n" << "Maior vetor vertical: " << maxVerMVAx16 << "\n" << "Menor vetor horizontal: " << minHorMVAx16 << "\n" << "Menor vetor vertical: " << minVerMVAx16 << "\n"; 
  cout << "\nCU 8x8" << "\n" << "Maior vetor horizontal: " << maxHorMV8x8 << "\n" << "Maior vetor vertical: " << maxVerMV8x8 << "\n" << "Menor vetor horizontal: " << minHorMV8x8 << "\n" << "Menor vetor vertical: " << minVerMV8x8 << "\n";
  cout << "\nCU 8x4" << "\n" << "Maior vetor horizontal: " << maxHorMV8x4 << "\n" << "Maior vetor vertical: " << maxVerMV8x4 << "\n" << "Menor vetor horizontal: " << minHorMV8x4 << "\n" << "Menor vetor vertical: " << minVerMV8x4 << "\n"; 
  cout << "\nCU 4x8" << "\n" << "Maior vetor horizontal: " << maxHorMV4x8 << "\n" << "Maior vetor vertical: " << maxVerMV4x8 << "\n" << "Menor vetor horizontal: " << minHorMV4x8 << "\n" << "Menor vetor vertical: " << minVerMV4x8 << "\n";  
  
  cout << "\n\nPREDIÇÃO INTRA\n\n";
  cout << "CU 64x64\n";
  for(j = 0; j < 36; j++){
  	cout << "Modo " << j << ": "<< modosIntra64x64[j] << "\n";	
  }
  cout << "\nCU 32x32\n";
  for(j = 0; j < 36; j++){
  	cout << "Modo " << j << ": "<< modosIntra32x32[j] << "\n";	
  }
  cout << "\nCU 16x16\n";
  for(j = 0; j < 36; j++){
  	cout << "Modo " << j << ": "<< modosIntra16x16[j] << "\n";	
  }
  cout << "\nCU 8x8\n";
  for(j = 0; j < 36; j++){
  	cout << "Modo " << j << ": "<< modosIntra8x8[j] << "\n";	
  }
  cout << "\nCU 4x4\n";
  for(j = 0; j < 36; j++){
  	cout << "Modo " << j << ": "<< modosIntra4x4[j] << "\n";	
  }
  
  
  
  return returnCode;
}

//! \}
