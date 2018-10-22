__int64 __fastcall RtlpFreeHeap(_HEAP *heap, __int64 flags, _HEAP_ENTRY *header, signed __int64 mem)
{
  _HEAP_ENTRY *v4; // r14
  _HEAP *v5; // rbx
  char v6; // r12
  int v8; // edi
  signed __int64 v9; // r8
  _DWORD *v10; // rcx
  _BYTE *v11; // rcx
  unsigned __int8 *v12; // rsi
  _HEAP_ENTRY *v13; // r15
  _HEAP_LOCK *v14; // rcx
  struct _TEB *v15; // rax
  signed __int8 v16; // cf
  void *v17; // rax
  unsigned int v18; // edx
  _HEAP_LIST_LOOKUP *v19; // rcx
  int v20; // edx
  char *v21; // r8
  char v22; // al
  $BC2C84EDD1A61D8001D9900647BA32E5 *v23; // rsi
  unsigned __int16 size; // ax
  unsigned __int16 *v25; // rdx
  unsigned int v26; // ecx
  __int64 v27; // rdx
  unsigned __int64 size1; // r8
  unsigned __int64 v29; // rcx
  _HEAP_ENTRY *prev; // r12
  int v31; // edx
  __int64 *v32; // r11
  __int64 **v33; // rax
  __int64 *v34; // rax
  _HEAP_LIST_LOOKUP *v35; // rdi
  unsigned __int64 v36; // r13
  unsigned __int64 v37; // rcx
  unsigned int v38; // ecx
  unsigned int v39; // esi
  __int64 v40; // rax
  _LIST_ENTRY **v41; // r8
  __int64 *v42; // r10
  unsigned int v43; // eax
  _LIST_ENTRY *v44; // r14
  _LIST_ENTRY *v45; // rdx
  int v46; // edx
  int v47; // er12
  __int64 *v48; // rax
  __int64 **v49; // rcx
  char v50; // al
  unsigned __int64 v51; // rdi
  _LIST_ENTRY *v52; // rdx
  __int64 v53; // rdx
  __int64 v54; // rcx
  _HEAP_ENTRY *next_; // r14
  int v56; // edx
  __int64 **v98; // r11
  __int64 v99; // r12
  __int64 *v100; // rax
  __int64 *v101; // rax
  _HEAP_LIST_LOOKUP *v102; // rdi
  unsigned __int64 v103; // r13
  unsigned __int64 v104; // rcx
  unsigned int v105; // ecx
  unsigned int v106; // esi
  __int64 v107; // rax
  __int64 **v108; // r10
  _LIST_ENTRY **v109; // r8
  __int64 **v110; // rax
  unsigned int v111; // edx
  __int64 *v112; // r14
  __int64 *v113; // rax
  int v114; // edx
  int v115; // er12
  __int64 *v116; // rax
  char v117; // al
  unsigned __int64 v118; // rdi
  _LIST_ENTRY *v119; // rdx
  __int64 v120; // rdx
  __int64 v121; // rcx
  unsigned int v122; // edi
  unsigned __int64 v123; // rdx
  _LIST_ENTRY *v124; // rax
  _HEAP_LIST_LOOKUP *v125; // r12
  unsigned __int64 v126; // rcx
  int v127; // er14
  __int64 v128; // r14
  _LIST_ENTRY *v129; // rsi
  _LIST_ENTRY *v130; // r13
  _LIST_ENTRY *v131; // rax
  int v132; // edx
  int v133; // edi
  int v134; // eax
  signed __int64 v135; // r8
  int v136; // edx
  int v137; // edi
  int v138; // eax
  _LIST_ENTRY *v139; // rdi
  __int64 v140; // rdi
  unsigned int *v141; // r8
  unsigned int v142; // edx
  int v143; // ecx
  __int64 v144; // rdi
  int v145; // ecx
  int v146; // eax
  _HEAP_ENTRY *v147; // r14
  _HEAP_ENTRY **v148; // rax
  _HEAP_LIST_LOOKUP *v149; // rdi
  __int64 *v150; // r12
  unsigned __int64 v151; // rcx
  unsigned int v152; // ecx
  unsigned int v153; // esi
  __int64 v154; // rax
  signed __int64 v155; // rdx
  _LIST_ENTRY *v156; // r13
  int v157; // ecx
  int v158; // er14
  unsigned __int64 v159; // rsi
  signed __int64 v160; // r8
  unsigned __int64 v161; // rdx
  _LIST_ENTRY *v162; // rdi
  _LIST_ENTRY *v163; // r8
  int v164; // ecx
  int v165; // eax
  _HEAP_ENTRY *v166; // rsi
  _HEAP_ENTRY **v167; // rax
  _HEAP_LIST_LOOKUP *v168; // rdx
  unsigned __int64 v169; // rdi
  int v170; // edx
  unsigned __int16 v171; // cx
  __int16 v172; // dx
  signed __int64 v173; // rdi
  signed __int64 v174; // r15
  __int64 v175; // rcx
  __int64 v176; // rax
  __int64 *v177; // rcx
  __int64 v178; // rdx
  __int64 v179; // r8
  __int64 v180; // rdx
  __int64 v181; // rdi
  _BYTE *v182; // rcx
  __int64 v183; // rcx
  _BYTE *v184; // rcx
  __int64 v185; // ST30_8
  unsigned __int8 *v186; // rdi
  _BYTE *v187; // rcx
  __int64 v188; // ST30_8
  unsigned int v189; // edx
  unsigned __int64 v190; // rcx
  _HEAP_LOCK *v191; // rdi
  bool v192; // zf
  signed __int32 v193; // ebx
  __int64 v194; // r8
  int v195; // edx
  signed __int32 v196; // eax
  __int64 *v197; // [rsp+20h] [rbp-1D8h]
  __int64 v198; // [rsp+28h] [rbp-1D0h]
  char v199; // [rsp+48h] [rbp-1B0h]
  char v200; // [rsp+49h] [rbp-1AFh]
  __int16 v201; // [rsp+4Ch] [rbp-1ACh]
  _HEAP_ENTRY *v202; // [rsp+50h] [rbp-1A8h]
  signed __int64 v203; // [rsp+50h] [rbp-1A8h]
  unsigned __int64 v204; // [rsp+50h] [rbp-1A8h]
  signed __int64 v205; // [rsp+50h] [rbp-1A8h]
  unsigned __int64 size2; // [rsp+58h] [rbp-1A0h]
  _HEAP_ENTRY *v207; // [rsp+60h] [rbp-198h]
  __int64 v208; // [rsp+68h] [rbp-190h]
  char v209; // [rsp+70h] [rbp-188h]
  __int16 v210; // [rsp+72h] [rbp-186h]
  __int16 v211; // [rsp+74h] [rbp-184h]
  __int64 *v212; // [rsp+78h] [rbp-180h]
  __int64 **v213; // [rsp+80h] [rbp-178h]
  unsigned int v214; // [rsp+88h] [rbp-170h]
  unsigned int v215; // [rsp+8Ch] [rbp-16Ch]
  unsigned int v216; // [rsp+90h] [rbp-168h]
  unsigned int v218; // [rsp+98h] [rbp-160h]
  unsigned __int64 v219; // [rsp+A0h] [rbp-158h]
  __int64 v220; // [rsp+A8h] [rbp-150h]
  unsigned __int64 v221; // [rsp+B0h] [rbp-148h]
  __int64 v222; // [rsp+B8h] [rbp-140h]
  unsigned int v223; // [rsp+C0h] [rbp-138h]
  unsigned int v224; // [rsp+C4h] [rbp-134h]
  __int64 v225; // [rsp+C8h] [rbp-130h]
  unsigned __int64 v226; // [rsp+D0h] [rbp-128h]
  _HEAP_ENTRY *v227; // [rsp+D8h] [rbp-120h]
  __int64 v230; // [rsp+F0h] [rbp-108h]
  unsigned __int64 v231; // [rsp+F8h] [rbp-100h]
  unsigned int *v232; // [rsp+100h] [rbp-F8h]
  __int64 v233; // [rsp+108h] [rbp-F0h]
  _HEAP_ENTRY *v234; // [rsp+110h] [rbp-E8h]
  __int64 v235; // [rsp+118h] [rbp-E0h]
  __int64 v236; // [rsp+120h] [rbp-D8h]
  struct _TEB *v237; // [rsp+128h] [rbp-D0h]
  unsigned __int64 v238; // [rsp+130h] [rbp-C8h]
  int v239; // [rsp+140h] [rbp-B8h]
  unsigned int v240; // [rsp+150h] [rbp-A8h]
  int v242; // [rsp+170h] [rbp-88h]
  int v243; // [rsp+180h] [rbp-78h]
  int v244; // [rsp+190h] [rbp-68h]
  unsigned int v245; // [rsp+1A0h] [rbp-58h]
  int v246; // [rsp+1B0h] [rbp-48h]
  unsigned int v247; // [rsp+1C0h] [rbp-38h]
  _HEAP_ENTRY *v248; // [rsp+210h] [rbp+18h]

  v248 = header;
  v4 = header;
  v5 = heap;
  v6 = 1;
  v200 = 1;
  v199 = 0;
  v215 = 1;
  v219 = 0i64;
  v201 = 0;
  if ( heap == (_HEAP *)header )                // mitigation, can not free _HEAP
  {
    RtlpLogHeapFailure(9i64, (__int64)heap);
    return 0i64;
  }
  v8 = heap->ForceFlags | flags;
  if ( v8 & 0x7D010F60 )
  {
    v6 = 0;
    v200 = 0;
    v9 = 4i64;
    if ( v8 & 0x61000000 && !_bittest(&v8, 0x1Cu) )
      return RtlDebugFreeHeap(heap);
  }
  else
  {
    v9 = 3i64;
  }
  v10 = NtCurrentPeb()->SharedData;
  if ( v10 && *v10 )
  {
    v11 = (char *)NtCurrentPeb()->SharedData + 0x226;
    v12 = (unsigned __int8 *)0x7FFE0380;
  }
  else
  {
    v12 = (unsigned __int8 *)0x7FFE0380;
    v11 = (_BYTE *)0x7FFE0380;
  }
  if ( *v11 && NtCurrentPeb()->TracingFlags & 1 )
  {
    v13 = v248;
    if ( !((v248->UnpackedEntry.Flags ^ (unsigned __int8)(v5->Encoding.UnpackedEntry.Flags & (v5->EncodeFlagMask >> 17))) & 8) )
      RtlpLogHeapFreeEvent(v5, mem, v9);
  }
  else
  {
    v13 = v248;
  }
  if ( v8 & 1 )                                 // HEAP_NO_SERIALIZE
  {
    if ( v5->EncodeFlagMask )
    {
      v20 = v13->UnpackedEntry.SubSegmentCode ^ v5->Encoding.UnpackedEntry.SubSegmentCode;
      v13->UnpackedEntry.SubSegmentCode = v20;
      if ( HIBYTE(v20) != ((unsigned __int8)v20 ^ (unsigned __int8)(BYTE1(v20) ^ BYTE2(v20))) )
        RtlpAnalyzeHeapFailure((unsigned __int64)v5, (unsigned __int64)v13);
    }
  }
  else
  {
    v14 = v5->LockVariable;
    v15 = NtCurrentTeb();
    v16 = _interlockedbittestandreset(&v14->Lock.CriticalSection.LockCount, 0);
    v17 = v15->ClientId.UniqueThread;
    if ( v16 )
    {
      v14->Lock.CriticalSection.OwningThread = v17;
      v14->Lock.CriticalSection.RecursionCount = 1;
      ++v5->Counters.LockAcquires;
    }
    else if ( v14->Lock.CriticalSection.OwningThread == v17 )
    {
      ++v14->Lock.CriticalSection.RecursionCount;
      ++v5->Counters.LockAcquires;
    }
    else
    {
      if ( byte_18015C3A8 )
      {
        NtCurrentTeb()->LastStatusValue = 0xC0000194;
        v237 = NtCurrentTeb();
        v237->LastErrorValue = RtlNtStatusToDosError(0xC0000194i64, flags);
        v215 = 0;
LABEL_356:
        v122 = 256;
        goto LABEL_357;
      }
      RtlEnterCriticalSection(v5->LockVariable);
      RtlpUpdateHeapRates(v5, 1i64);
    }
    v199 = 1;
    v13 = v248;
    if ( v5->EncodeFlagMask )
    {
      v18 = v248->UnpackedEntry.SubSegmentCode ^ v5->Encoding.UnpackedEntry.SubSegmentCode;
      v248->UnpackedEntry.SubSegmentCode = v18;
      if ( HIBYTE(v18) != ((unsigned __int8)v18 ^ (unsigned __int8)(BYTE1(v18) ^ BYTE2(v18))) )
        RtlpAnalyzeHeapFailure((unsigned __int64)v5, (unsigned __int64)v248);
    }
    v19 = (_HEAP_LIST_LOOKUP *)v5->BlocksIndex;
    do
    {
      if ( v248->UnpackedEntry.Size < (unsigned __int64)v19->ArraySize )
        break;
      v19 = v19->ExtendedLookup;
    }
    while ( v19 );
  }
  v21 = &v13->UnpackedEntry.Flags;
  v22 = v13->UnpackedEntry.Flags;
  if ( v22 & 8 )                                // HEAP_ENTRY_VIRTUAL_ALLOC
    *v21 = v22 & 0xF7;
  if ( v13->UnpackedEntry.UnusedBytes == 4 )
  {
    v174 = (signed __int64)&v13[-3];
    v208 = v174;
    v175 = *(_QWORD *)(v174 + 32);
    v222 = v175;
    v219 = v174 & 0xFFFFFFFFFFFF0000ui64;
    v5->Counters.TotalSizeInVirtualBlocks -= v175;
    v176 = *(_QWORD *)v174;
    v177 = *(__int64 **)(v174 + 8);
    v178 = *v177;
    if ( *v177 != *(_QWORD *)(*(_QWORD *)v174 + 8i64) || v178 != v174 )
    {
      LODWORD(v197) = v178;
      RtlpLogHeapFailure(13i64, 0i64);
    }
    else
    {
      *v177 = v176;
      *(_QWORD *)(v176 + 8) = v177;
    }
    if ( !v6 )
    {
      v224 = NtCurrentPeb()->NtGlobalFlag;
      v177 = (__int64 *)v224;
      if ( _bittest((const signed int *)&v177, 0xBu) )
      {
        v179 = *(_QWORD *)(v174 + 32) >> 4;
        LODWORD(v197) = 3;
        v174 = v208;
        v180 = *(unsigned __int16 *)(v208 + 18);
        RtlpUpdateTagEntry((_DWORD)v5);
      }
      else
      {
        v174 = v208;
      }
    }
    if ( v199 )
    {
      RtlLeaveCriticalSection(v5->LockVariable);
      v199 = 0;
    }
    v181 = *(_QWORD *)(v174 + 40);
    v236 = *(_QWORD *)(v174 + 40);
    if ( (unsigned int)RtlGetCurrentServiceSessionId(v177) )
    {
      v182 = (char *)NtCurrentPeb()->SharedData + 558;
      LODWORD(v174) = v208;
      v181 = v236;
    }
    else
    {
      v182 = (_BYTE *)0x7FFE0388;
    }
    if ( *v182 )
      RtlpHeapLogRangeRelease(v5, v219, v181);
    size2 = 0i64;
    RtlpSecMemFreeVirtualMemory(v182, &v219, &size2, 0x8000i64, (_DWORD)v197);
    if ( (unsigned int)RtlGetCurrentServiceSessionId(v183) )
    {
      v184 = (char *)NtCurrentPeb()->SharedData + 550;
      LODWORD(v174) = v208;
    }
    else
    {
      v184 = (_BYTE *)0x7FFE0380;
    }
    if ( *v184 )
    {
      if ( NtCurrentPeb()->TracingFlags & 1 )
      {
        if ( (unsigned int)RtlGetCurrentServiceSessionId(v184) )
          v12 = (unsigned __int8 *)NtCurrentPeb()->SharedData + 550;
        v185 = *v12;
        LODWORD(v174) = v208;
        RtlpLogHeapContractEvent((char)v5, v208, v222, 16 * v5->TotalFreeSize);
      }
      else
      {
        LODWORD(v174) = v208;
      }
    }
    v186 = (unsigned __int8 *)0x7FFE038A;
    if ( (unsigned int)RtlGetCurrentServiceSessionId(v184) )
    {
      v187 = (char *)NtCurrentPeb()->SharedData + 560;
      LODWORD(v174) = v208;
    }
    else
    {
      v187 = (_BYTE *)0x7FFE038A;
    }
    if ( *v187 )
    {
      if ( (unsigned int)RtlGetCurrentServiceSessionId(v187) )
      {
        v186 = (unsigned __int8 *)NtCurrentPeb()->SharedData + 560;
        LODWORD(v174) = v208;
      }
      v188 = *v186;
      RtlpLogHeapContractEvent((char)v5, v174, v222, 16 * v5->TotalFreeSize);
    }
    goto LABEL_356;
  }
  v23 = ($BC2C84EDD1A61D8001D9900647BA32E5 *)&v13->Code1;
  size = v13->UnpackedEntry.Size;
  if ( size < v5->FrontEndHeapMaximumIndex )    // LFH counter decrement
  {
    if ( !((unsigned __int8)(1 << (size & 7)) & v5->FrontEndHeapStatusBitmap[(unsigned __int64)size >> 3]) )
    {
      v25 = &v5->FrontEndHeapUsageData[LOWORD(v23->CompactHeader)];
      if ( *v25 > 1u )
        --*v25;
    }
    v13 = v248;
  }
  if ( !v6 )
  {
    v223 = NtCurrentPeb()->NtGlobalFlag;
    v26 = v223;
    v13 = v248;
    if ( _bittest((const signed int *)&v26, 0xBu) )
    {
      LODWORD(v197) = 2;
      if ( *v21 & 2 )
        v27 = *((unsigned __int16 *)&v248[v4->UnpackedEntry.Size] - 7);
      else
        v209 = v248->UnpackedEntry.SmallTagIndex;
      v201 = RtlpUpdateTagEntry((_DWORD)v5);
    }
  }
  size1 = LOWORD(v23->CompactHeader);
  size2 = LOWORD(v23->CompactHeader);
  if ( SLOBYTE(v5->Flags) >= 0 )                // HEAP_DISABLE_COALESCE_ON_FREE
  {
    v227 = v13;
    v29 = 0x10 * (v13->UnpackedEntry.PreviousSize ^ (unsigned __int64)v5->Encoding.UnpackedEntry.PreviousSize);
    prev = &v13[v29 / 0xFFFFFFFFFFFFFFF0ui64];
    v202 = &v13[v29 / 0xFFFFFFFFFFFFFFF0ui64];
    if ( &v13[v29 / 0xFFFFFFFFFFFFFFF0ui64] == v13
      || (prev->UnpackedEntry.Flags ^ (unsigned __int8)(v5->Encoding.UnpackedEntry.Flags & (v5->EncodeFlagMask >> 20))) & 1 )// determine prev is the first block or busy block
    {
      goto skip_prev_unlink;                    // otherwise, ignore prev unlink
    }
    if ( v5->EncodeFlagMask )
    {
      v31 = prev->UnpackedEntry.SubSegmentCode ^ v5->Encoding.UnpackedEntry.SubSegmentCode;
      prev->UnpackedEntry.SubSegmentCode = v31;
      if ( HIBYTE(v31) != ((unsigned __int8)v31 ^ (unsigned __int8)(BYTE1(v31) ^ BYTE2(v31))) )// decode and check prev _HEAP_ENTRY
        RtlpAnalyzeHeapFailure((unsigned __int64)v5, (unsigned __int64)prev);
    }
    v32 = (__int64 *)&prev[1];
    v212 = (__int64 *)prev[1].UnpackedEntry.PreviousBlockPrivateData;
    v33 = (__int64 **)prev[1].UnpackedEntry.CompactHeader;
    v213 = v33;
    v34 = *v33;
    mem = v212[1];
    if ( v34 != (__int64 *)mem || v34 != v32 )  // check prev, blink->flink == flink->blink == x
    {
      v198 = 0i64;
      v197 = v34;
      RtlpLogHeapFailure(13i64, (__int64)v5);
LABEL_99:
      size1 = size2;
skip_prev_unlink:
      next_ = &v13[size1];
      v203 = (signed __int64)&v13[size1];
      if ( !v5->EncodeFlagMask )
        goto LABEL_104;
      v240 = next_->UnpackedEntry.SubSegmentCode ^ v5->Encoding.UnpackedEntry.SubSegmentCode;
      if ( HIBYTE(v240) != ((unsigned __int8)v240 ^ (unsigned __int8)(BYTE1(v240) ^ BYTE2(v240))) )// check next _HEAP_ENTRY
      {
        v198 = 0i64;
        v197 = 0i64;
        RtlpLogHeapFailure(3i64, (__int64)v5);
      }
      while ( 1 )
      {
        while ( 1 )
        {
          size1 = size2;
LABEL_104:
          if ( (next_->UnpackedEntry.Flags ^ (unsigned __int8)(v5->Encoding.UnpackedEntry.Flags & (v5->EncodeFlagMask >> 20))) & 1 )// determine busy block
          {
LABEL_190:
            v248 = v13;
            v6 = v200;
            goto LABEL_191;
          }
          if ( v5->EncodeFlagMask )
          {
            v56 = next_->UnpackedEntry.SubSegmentCode ^ v5->Encoding.UnpackedEntry.SubSegmentCode;
            next_->UnpackedEntry.SubSegmentCode = v56;
            if ( HIBYTE(v56) != ((unsigned __int8)v56 ^ (unsigned __int8)(BYTE1(v56) ^ BYTE2(v56))) )// check and decode next _HEAP_ENTRY
              RtlpAnalyzeHeapFailure((unsigned __int64)v5, (unsigned __int64)next_);
          }
          v98 = (__int64 **)&next_[1];
          v99 = (__int64)next_[1].UnpackedEntry.PreviousBlockPrivateData;
          v207 = (_HEAP_ENTRY *)v99;
          v100 = (__int64 *)next_[1].UnpackedEntry.CompactHeader;
          v212 = v100;
          v101 = (__int64 *)*v100;
          mem = *(_QWORD *)(v99 + 8);
          if ( v101 == (__int64 *)mem && v101 == (__int64 *)v98 )
            break;                              // check next, blink->flink == flink->blink == x
          v198 = 0i64;
          v197 = v101;
          RtlpLogHeapFailure(13i64, (__int64)v5);
        }
        v5->TotalFreeSize -= next_->UnpackedEntry.Size;
        v102 = (_HEAP_LIST_LOOKUP *)v5->BlocksIndex;
        if ( v102 )
        {
          v103 = next_->UnpackedEntry.Size;
          while ( 1 )
          {
            v104 = v102->ArraySize;
            if ( v103 < v104 )
            {
              v230 = next_->UnpackedEntry.Size;
              v105 = v103;
              goto LABEL_155;
            }
            if ( !v102->ExtendedLookup )
              break;
            v102 = v102->ExtendedLookup;
          }
          v105 = v104 - 1;
          v230 = v105;
LABEL_155:
          v238 = v103;
          v106 = v105 - v102->BaseIndex;
          if ( v102->ExtraItem )
            v107 = 2 * v106;
          else
            v107 = v106;
          v108 = (__int64 **)(8 * v107);
          v213 = (__int64 **)(8 * v107);
          v109 = v102->ListHints;
          v110 = (__int64 **)v109[v107];
          --v102->ItemCount;
          v111 = v102->ArraySize;
          mem = v111 - 1;
          if ( v105 == (_DWORD)mem )
            --v102->OutOfRangeItems;
          if ( v110 == v98 )
          {
            v218 = v111;
            if ( !v102->ExtendedLookup )
              v111 = mem;
            v218 = v111;
            v112 = *v98;
            v113 = (__int64 *)v102->ListHead;
            if ( v105 >= v111 )
            {
              if ( v112 != v113 )
              {
                *(__int64 **)((char *)v108 + (_QWORD)v109) = v112;
                next_ = (_HEAP_ENTRY *)v203;
                goto LABEL_171;
              }
              *(__int64 **)((char *)v108 + (_QWORD)v109) = 0i64;
              goto LABEL_175;
            }
            if ( v112 == v113 )
              goto LABEL_383;
            v114 = *((_DWORD *)v112 - 2);
            v242 = *((_DWORD *)v112 - 2);
            if ( v5->EncodeFlagMask )
            {
              v115 = v114 ^ v5->Encoding.UnpackedEntry.SubSegmentCode;
              v242 = v115;
              LOWORD(v114) = v115;
              if ( HIBYTE(v115) != ((unsigned __int8)v115 ^ (unsigned __int8)(BYTE1(v115) ^ BYTE2(v115))) )
              {
                v198 = 0i64;
                v197 = 0i64;
                RtlpLogHeapFailure(3i64, (__int64)v5);
                LOWORD(v114) = v115;
                v108 = v213;
              }
              v99 = (__int64)v207;
            }
            if ( (_DWORD)v103 != (unsigned __int16)v114 )
            {
LABEL_383:
              *(__int64 **)((char *)v108 + (unsigned __int64)v102->ListHints) = 0i64;
LABEL_175:
              v102->ListsInUseUlong[v106 >> 5] &= ~(1 << (v106 & 0x1F));// update ListsInUseUlong bitmap
              next_ = (_HEAP_ENTRY *)v203;
              goto LABEL_171;
            }
            *(__int64 **)((char *)v108 + (unsigned __int64)v102->ListHints) = v112;
            next_ = (_HEAP_ENTRY *)v203;
          }
        }
LABEL_171:
        v116 = v212;
        *v212 = v99;                            // unlink write
        *(_QWORD *)(v99 + 8) = v116;
        if ( !(next_->UnpackedEntry.Flags & 8) || (unsigned __int8)RtlpCommitBlock(v5, next_) )
        {
          v117 = next_->UnpackedEntry.Flags;
          if ( v117 & 4 )
          {
            v118 = 16i64 * next_->UnpackedEntry.Size - 32;
            v231 = 16i64 * next_->UnpackedEntry.Size - 32;
            if ( v117 & 2 && v118 > 4 )
            {
              v118 -= 4i64;
              v231 = v118;
            }
            if ( RtlCompareMemoryUlong(&next_[2], v118, 0xFEEEFEEEi64) != v118 )
            {
              if ( NtCurrentPeb()->Ldr )
              {
                v119 = NtCurrentPeb()->Ldr->InLoadOrderModuleList.Flink;
                DbgPrint("HEAP[%wZ]: ");
              }
              else
              {
                DbgPrint("HEAP: ");
              }
              DbgPrint("HEAP: Free Heap block %p modified at %p after it was freed\n");
              RtlpBreakPointHeap(v121, v120);
            }
          }
          v13->UnpackedEntry.Flags = 0;
          v13->UnpackedEntry.UnusedBytes = 0;
          size2 += next_->UnpackedEntry.Size;   // update new size
          v13->UnpackedEntry.Size = size2;
          v13[size2].UnpackedEntry.PreviousSize = size2 ^ v5->Encoding.UnpackedEntry.PreviousSize;
          size1 = size2;
          goto LABEL_190;
        }
        RtlpDeCommitFreeBlock((__int64)v5, (__int64)next_, next_->UnpackedEntry.Size, 1);
      }
    }
    v5->TotalFreeSize -= prev->UnpackedEntry.Size;
    v35 = (_HEAP_LIST_LOOKUP *)v5->BlocksIndex;
    if ( v35 )
    {
      v36 = prev->UnpackedEntry.Size;
      while ( 1 )
      {
        v37 = v35->ArraySize;
        if ( v36 < v37 )
        {
          v225 = prev->UnpackedEntry.Size;
          v38 = v36;
          goto LABEL_63;
        }
        if ( !v35->ExtendedLookup )
          break;
        v35 = v35->ExtendedLookup;
      }
      v38 = v37 - 1;
      v225 = v38;
LABEL_63:
      v207 = (_HEAP_ENTRY *)v36;
      v39 = v38 - v35->BaseIndex;
      if ( v35->ExtraItem )
        v40 = 2 * v39;
      else
        v40 = v39;
      mem = 8 * v40;
      v207 = (_HEAP_ENTRY *)(8 * v40);
      v41 = v35->ListHints;
      v42 = (__int64 *)v41[v40];
      --v35->ItemCount;
      v43 = v35->ArraySize;
      if ( v38 == v43 - 1 )
        --v35->OutOfRangeItems;
      if ( v42 == v32 )
      {
        v216 = v43;
        if ( !v35->ExtendedLookup )
          --v43;
        v216 = v43;
        v44 = (_LIST_ENTRY *)*v32;
        v45 = v35->ListHead;
        if ( v38 >= v43 )
        {
          if ( v44 != v45 )
          {
            *(_LIST_ENTRY **)((char *)v41 + mem) = v44;
            goto LABEL_79;
          }
          *(_LIST_ENTRY **)((char *)v41 + mem) = 0i64;
        }
        else
        {
          if ( v44 != v45 )
          {
            v46 = (int)v44[-1].Blink;
            v239 = (int)v44[-1].Blink;
            if ( v5->EncodeFlagMask )
            {
              v47 = v46 ^ v5->Encoding.UnpackedEntry.SubSegmentCode;
              v239 = v47;
              LOWORD(v46) = v47;
              if ( HIBYTE(v47) != ((unsigned __int8)v47 ^ (unsigned __int8)(BYTE1(v47) ^ BYTE2(v47))) )
              {
                v198 = 0i64;
                v197 = 0i64;
                RtlpLogHeapFailure(3i64, (__int64)v5);
                LOWORD(v46) = v47;
                mem = (signed __int64)v207;
              }
              prev = v202;
            }
            if ( (_DWORD)v36 == (unsigned __int16)v46 )
            {
              *(_LIST_ENTRY **)((char *)v35->ListHints + mem) = v44;
              goto LABEL_79;
            }
          }
          *(_LIST_ENTRY **)((char *)v35->ListHints + mem) = 0i64;
        }
        v35->ListsInUseUlong[v39 >> 5] &= ~(1 << (v39 & 0x1F));
        goto LABEL_79;
      }
    }
LABEL_79:
    v48 = v212;
    v49 = v213;
    *v213 = v212;
    v48[1] = (__int64)v49;
    if ( !(prev->UnpackedEntry.Flags & 8) || (unsigned __int8)RtlpCommitBlock(v5, prev) )
    {
      v50 = prev->UnpackedEntry.Flags;
      if ( v50 & 4 )
      {
        v51 = 0x10i64 * prev->UnpackedEntry.Size - 32;
        v226 = 0x10i64 * prev->UnpackedEntry.Size - 32;
        if ( v50 & 2 && v51 > 4 )
        {
          v51 -= 4i64;
          v226 = v51;
        }
        if ( RtlCompareMemoryUlong(&prev[2], v51, 0xFEEEFEEEi64) != v51 )
        {
          if ( NtCurrentPeb()->Ldr )
          {
            v52 = NtCurrentPeb()->Ldr->InLoadOrderModuleList.Flink;
            DbgPrint("HEAP[%wZ]: ");
          }
          else
          {
            DbgPrint("HEAP: ");
          }
          DbgPrint("HEAP: Free Heap block %p modified at %p after it was freed\n");
          RtlpBreakPointHeap(v54, v53);
        }
      }
      prev->UnpackedEntry.Flags = 0;
      prev->UnpackedEntry.UnusedBytes = 0;
      v13 = prev;
      v227 = prev;
      size2 += prev->UnpackedEntry.Size;
      prev->UnpackedEntry.Size = size2;
      prev[size2].UnpackedEntry.PreviousSize = size2 ^ v5->Encoding.UnpackedEntry.PreviousSize;
    }
    else
    {
      RtlpDeCommitFreeBlock((__int64)v5, (__int64)prev, prev->UnpackedEntry.Size, 1);
    }
    goto LABEL_99;
  }
LABEL_191:                                      // after prev and next unlink
  if ( size1 < v5->DeCommitFreeBlockThreshold || size1 + v5->TotalFreeSize < v5->DeCommitTotalFreeThreshold )
  {
    if ( size1 + v5->TotalFreeSize > v5->DeCommitTotalFreeThreshold )
    {
      v122 = 0x100;
      if ( size1 >= 0x100 && v5->Encoding.UnpackedEntry.PreviousSize == v13->UnpackedEntry.PreviousSize )
      {
        RtlpDeCommitFreeBlock((__int64)v5, (__int64)v13, size1, 0);
        goto LABEL_357;
      }
    }
    if ( size1 > 0xFF00 )                       // HEAP_MAX_BLOCK_SIZE
    {
      RtlpInsertFreeBlock(v5, v13);
      if ( !v201 )
        goto LABEL_384;
LABEL_316:
      if ( v5->EncodeFlagMask )
      {
        v170 = v13->UnpackedEntry.SubSegmentCode ^ v5->Encoding.UnpackedEntry.SubSegmentCode;
        v13->UnpackedEntry.SubSegmentCode = v170;
        if ( HIBYTE(v170) != ((unsigned __int8)v170 ^ (unsigned __int8)(BYTE1(v170) ^ BYTE2(v170))) )
          RtlpAnalyzeHeapFailure((unsigned __int64)v5, (unsigned __int64)v13);
      }
      v13->UnpackedEntry.Flags |= 2u;
      v171 = v13->UnpackedEntry.Size;
      v172 = v171 >> 8;
      v173 = (signed __int64)&v13[v13->UnpackedEntry.Size];
      if ( v5->EncodeFlagMask )
      {
        v13->UnpackedEntry.SmallTagIndex = v171 ^ v172 ^ v13->UnpackedEntry.Flags;
        v13->UnpackedEntry.SubSegmentCode ^= v5->Encoding.UnpackedEntry.SubSegmentCode;
      }
      *(_WORD *)(v173 - 4) = v201;
      *(_WORD *)(v173 - 2) = 0;
      if ( v5->Flags & 0x8000000 )
      {
        *(_WORD *)(v173 - 2) = RtlLogStackBackTraceEx(1i64);
        v122 = 256;
      }
      else
      {
LABEL_384:
        v122 = 256;
      }
      goto LABEL_357;
    }
    if ( v6 )                                   // insertion point search
    {
      v123 = (unsigned __int16)size1;
      v204 = (unsigned __int16)size1;
      v13->UnpackedEntry.Flags = 0;
      v13->UnpackedEntry.UnusedBytes = 0;
      v124 = &v5->FreeLists;
      v125 = (_HEAP_LIST_LOOKUP *)v5->BlocksIndex;
      if ( v125 )
      {
        while ( 1 )
        {
          v126 = v125->ArraySize;
          if ( (unsigned __int16)size1 < v126 )
          {
            v127 = (unsigned __int16)size1;
            v220 = (unsigned __int16)size1;
            goto LABEL_207;
          }
          if ( !v125->ExtendedLookup )
            break;
          v125 = v125->ExtendedLookup;
        }
        v127 = v126 - 1;
        v220 = (unsigned int)(v126 - 1);
LABEL_207:
        while ( 1 )
        {
          v128 = v127 - v125->BaseIndex;
          v129 = 0i64;
          v130 = v125->ListHead;
          v131 = v130->Blink;
          if ( v130 == v131 )
          {
            v129 = v125->ListHead;
          }
          else
          {
            v132 = (int)v131[-1].Blink;
            v243 = (int)v131[-1].Blink;
            if ( v5->EncodeFlagMask )
            {
              v133 = v132 ^ v5->Encoding.UnpackedEntry.SubSegmentCode;
              v243 = v133;
              LOWORD(v132) = v133;
              if ( HIBYTE(v133) != ((unsigned __int8)v133 ^ (unsigned __int8)(BYTE1(v133) ^ BYTE2(v133))) )
              {
                v198 = 0i64;
                v197 = 0i64;
                RtlpLogHeapFailure(3i64, (__int64)v5);
                LOWORD(v132) = v133;
              }
            }
            v134 = (unsigned __int16)v132;
            v123 = v204;
            if ( (signed int)v204 - v134 <= 0 )
            {
              v135 = (signed __int64)&v130->Flink[0xFFFFFFFF];
              v136 = *(_DWORD *)(v135 + 8);
              v244 = *(_DWORD *)(v135 + 8);
              if ( v5->EncodeFlagMask )
              {
                v137 = v136 ^ v5->Encoding.UnpackedEntry.SubSegmentCode;
                v244 = v137;
                LOWORD(v136) = v137;
                if ( HIBYTE(v137) != ((unsigned __int8)v137 ^ (unsigned __int8)(BYTE1(v137) ^ BYTE2(v137))) )
                {
                  v198 = 0i64;
                  v197 = 0i64;
                  RtlpLogHeapFailure(3i64, (__int64)v5);
                  LOWORD(v136) = v137;
                }
              }
              v138 = (unsigned __int16)v136;
              v123 = v204;
              if ( (signed int)v204 - v138 > 0 )
              {
                if ( v125->ExtendedLookup || (_DWORD)v220 != v125->ArraySize - 1 )
                {
                  v140 = (unsigned int)v128 >> 5;
                  v214 = (unsigned int)v128 >> 5;
                  mem = ((v125->ArraySize - v125->BaseIndex) >> 5) - 1;
                  v141 = &v125->ListsInUseUlong[v140];
                  v232 = v141;
                  v142 = *v141 & ~((1 << (v128 & 0x1F)) - 1);
                  while ( !v142 )
                  {
                    if ( (unsigned int)v140 > (unsigned int)mem )
                    {
                      v13 = v248;
                      goto LABEL_247;
                    }
                    ++v141;
                    v232 = v141;
                    v142 = *v141;
                    LODWORD(v140) = v140 + 1;
                    v214 = v140;
                  }
                  if ( (_WORD)v142 )
                  {
                    if ( (_BYTE)v142 )
                      v143 = (unsigned __int8)RtlpBitsClearLow[(unsigned __int8)v142];
                    else
                      v143 = (unsigned __int8)RtlpBitsClearLow[BYTE1(v142)] + 8;
                  }
                  else if ( v142 & 0xFF0000 )
                  {
                    v143 = (unsigned __int8)RtlpBitsClearLow[BYTE2(v142)] + 16;
                  }
                  else
                  {
                    v143 = (unsigned __int8)RtlpBitsClearLow[(unsigned __int64)v142 >> 24] + 24;
                  }
                  v144 = (unsigned int)(v143 + 0x20 * v140);
                  v214 = v144;
                  if ( v125->ExtraItem )
                    v144 = (unsigned int)(2 * v144);
                  v129 = v125->ListHints[v144];
LABEL_243:
                  v123 = v204;
                }
                else
                {
                  if ( v125->ExtraItem )
                    v128 = (unsigned int)(2 * v128);
                  v139 = v125->ListHints[v128];
                  while ( v130 != v139 )
                  {
                    LOBYTE(mem) = 1;
                    if ( (signed int)RtlpHeapListCompare(v5, v139, v123, mem, v197, v198) <= 0 )
                    {
                      v129 = v139;
                      goto LABEL_243;
                    }
                    v139 = v139->Flink;
                    v123 = v204;
                  }
                }
              }
              else
              {
                v129 = v130->Flink;
              }
            }
            else
            {
              v129 = v130;
            }
            v13 = v248;
          }
          if ( v129 )
            break;
LABEL_247:
          v125 = v125->ExtendedLookup;
          v127 = v125->BaseIndex;
          v220 = v125->BaseIndex;
          v123 = v204;
        }
        v124 = &v5->FreeLists;
      }
      else
      {
        v129 = v124->Flink;
      }
      while ( v124 != v129 )                    // link-in
      {
        if ( v5->EncodeFlagMask )
        {
          v145 = (int)v129[-1].Blink;
          v245 = v145;
          if ( v145 & v5->EncodeFlagMask )
          {
            v146 = v145 ^ v5->Encoding.UnpackedEntry.SubSegmentCode;
            v245 = v145 ^ v5->Encoding.UnpackedEntry.SubSegmentCode;
          }
          else
          {
            LOWORD(v146) = v145;
          }
          v13 = v248;
        }
        else
        {
          LOWORD(v146) = v129[-1].Blink;
        }
        v210 = v146;
        if ( v123 <= (unsigned __int16)v146 )
          break;
        v129 = v129->Flink;
        v124 = &v5->FreeLists;
      }
      v147 = v13 + 1;
      v207 = v13 + 1;
      v148 = (_HEAP_ENTRY **)v129->Blink;
      if ( *v148 == (_HEAP_ENTRY *)v129 )
      {
        v147->UnpackedEntry.PreviousBlockPrivateData = v129; // link node into double linked-list
        v13[1].UnpackedEntry.CompactHeader = (unsigned __int64)v148;
        *v148 = v147;
        v129->Blink = (_LIST_ENTRY *)v147;
      }
      else
      {
        RtlpLogHeapFailure(13i64, 0i64);
      }
      v5->TotalFreeSize += v13->UnpackedEntry.Size;
      v149 = (_HEAP_LIST_LOOKUP *)v5->BlocksIndex;
      if ( v149 )
      {
        v150 = (__int64 *)v13->UnpackedEntry.Size;
        while ( 1 )
        {
          v151 = v149->ArraySize;
          if ( (unsigned __int64)v150 < v151 )
          {
            v233 = v13->UnpackedEntry.Size;
            v152 = (unsigned int)v150;
            goto LABEL_268;
          }
          if ( !v149->ExtendedLookup )
            break;
          v149 = v149->ExtendedLookup;
        }
        v152 = v151 - 1;
        v233 = v152;
LABEL_268:
        v212 = v150;
        v153 = v152 - v149->BaseIndex;
        if ( v149->ExtraItem )
          v154 = 2 * v153;
        else
          v154 = v153;
        ++v149->ItemCount;
        v155 = 8 * v154;
        v205 = 8 * v154;
        v156 = v149->ListHints[v154];
        if ( v152 == v149->ArraySize - 1 )
          ++v149->OutOfRangeItems;
        if ( !v156 )
          goto LABEL_385;
        v157 = (int)v156[0xFFFFFFFFi64].Blink;
        v246 = (int)v156[0xFFFFFFFFi64].Blink;
        if ( v5->EncodeFlagMask )
        {
          v158 = v157 ^ v5->Encoding.UnpackedEntry.SubSegmentCode;
          v246 = v158;
          LOWORD(v157) = v158;
          if ( HIBYTE(v158) != ((unsigned __int8)v158 ^ (unsigned __int8)(BYTE1(v158) ^ BYTE2(v158))) )
          {
            RtlpLogHeapFailure(3i64, (__int64)v5);
            LOWORD(v157) = v158;
          }
          v147 = v207;
          v155 = v205;
        }
        v13 = v248;
        if ( (signed int)v150 - (unsigned __int16)v157 <= 0 )
LABEL_385:
          *(_LIST_ENTRY **)((char *)v149->ListHints + v155) = (_LIST_ENTRY *)v147;
        if ( !v156 )
          v149->ListsInUseUlong[v153 >> 5] |= 1 << (v153 & 0x1F); // update bitmap
      }
LABEL_282:
      if ( v5->EncodeFlagMask )                 // recover header
      {
        v13->UnpackedEntry.SmallTagIndex = LOBYTE(v13->Code1) ^ BYTE1(v13->AgregateCode) ^ v13->UnpackedEntry.Flags;
        v13->UnpackedEntry.SubSegmentCode ^= v5->Encoding.UnpackedEntry.SubSegmentCode;
      }
      goto LABEL_316;
    }
    v159 = (unsigned __int16)size1;
    v13->UnpackedEntry.Flags &= 0xF0u;
    v13->UnpackedEntry.UnusedBytes = 0;
    if ( !(v5->Flags & 0x40) )                  // HEAP_FREE_CHECKING_ENABLED
    {
LABEL_293:
      v162 = &v5->FreeLists;
      if ( v5->BlocksIndex )
        v163 = (_LIST_ENTRY *)RtlpFindEntry(v5, v159);
      else
        v163 = v162->Flink;
      while ( v162 != v163 )
      {
        if ( v5->EncodeFlagMask )
        {
          v164 = (int)v163[-1].Blink;
          v247 = v164;
          if ( v164 & v5->EncodeFlagMask )
          {
            v165 = v164 ^ v5->Encoding.UnpackedEntry.SubSegmentCode;
            v247 = v164 ^ v5->Encoding.UnpackedEntry.SubSegmentCode;
          }
          else
          {
            LOWORD(v165) = v164;
          }
          v13 = v248;
        }
        else
        {
          LOWORD(v165) = v163[-1].Blink;
        }
        v211 = v165;
        if ( v159 <= (unsigned __int16)v165 )
          break;
        v163 = v163->Flink;
      }
      v166 = v13 + 1;
      v167 = (_HEAP_ENTRY **)v163->Blink;
      if ( *v167 == (_HEAP_ENTRY *)v163 )
      {
        v166->UnpackedEntry.PreviousBlockPrivateData = v163;
        v13[1].UnpackedEntry.CompactHeader = (unsigned __int64)v167;
        *v167 = v166;
        v163->Blink = (_LIST_ENTRY *)v166;
      }
      else
      {
        RtlpLogHeapFailure(13i64, 0i64);
      }
      v5->TotalFreeSize += v13->UnpackedEntry.Size;
      v168 = (_HEAP_LIST_LOOKUP *)v5->BlocksIndex;
      if ( v168 )
      {
        while ( 1 )
        {
          v169 = v168->ArraySize;
          if ( v13->UnpackedEntry.Size < v169 )
          {
            v235 = v13->UnpackedEntry.Size;
            goto LABEL_313;
          }
          if ( !v168->ExtendedLookup )
            break;
          v168 = v168->ExtendedLookup;
        }
        v235 = (unsigned int)(v169 - 1);
LABEL_313:
        LOBYTE(v163) = 1;
        RtlpHeapAddListEntry((_DWORD)v5, (_DWORD)v168, (__int64)v163);
      }
      goto LABEL_282;
    }
    v160 = (signed __int64)&v13[2];
    v234 = v13 + 2;
    v161 = (16 * (unsigned __int64)(unsigned int)v159 - 32) >> 2;
    v221 = v161;
    if ( v161 )
    {
      if ( !(v160 & 4) )
        goto LABEL_290;
      *(_DWORD *)v160 = 0xFEEEFEEE;
      v221 = --v161;
      if ( v161 )
      {
        v160 = (signed __int64)&v13[2].Reserved + 4;
        v234 = (_HEAP_ENTRY *)((char *)v13 + 36);
LABEL_290:
        memset64((void *)v160, 0xFEEEFEEEFEEEFEEEui64, v161 >> 1);
        if ( v161 & 1 )
          *(_DWORD *)(v160 + 4 * v161 - 4) = 0xFEEEFEEE;
        goto LABEL_292;
      }
    }
LABEL_292:
    v13->UnpackedEntry.Flags |= 4u;
    goto LABEL_293;
  }
  RtlpDeCommitFreeBlock((__int64)v5, (__int64)v13, size1, 0);
  v122 = 256;
LABEL_357:
  if ( v199 )
  {
    if ( !(v5->ForceFlags & 0x1000000) )
    {
      ++v5->Counters.PollIntervalCounter;
      v189 = v5->Counters.HeapPollInterval;
      if ( v5->Counters.PollIntervalCounter > v189 )
      {
        v5->Counters.PollIntervalCounter = 0;
        v190 = v5->Counters.TotalMemoryCommitted - 16 * v5->TotalFreeSize;
        if ( v190 > v5->Counters.HighWatermarkSize )
          v5->Counters.HighWatermarkSize = v190;
        v5->Counters.LastPolledSize = v190;
      }
      if ( ++v5->Counters.AllocAndFreeOps >= 0x1000 )
      {
        if ( v5->FrontEndHeapType != 2 || v5->Counters.AllocationIndicesActive <= 0x10 )
          v122 = 16;
        if ( v5->Counters.DecommitsSinceLastCheck > v122 && v189 < 0x10000 )
          v5->Counters.HeapPollInterval = 2 * v189;
        v5->Counters.DecommitsSinceLastCheck = 0;
        v5->Counters.AllocAndFreeOps = 0;
      }
    }
    v191 = v5->LockVariable;
    v192 = v191->Lock.CriticalSection.RecursionCount-- == 1;
    if ( v192 )
    {
      v191->Lock.CriticalSection.OwningThread = 0i64;
      v193 = _InterlockedCompareExchange(&v191->Lock.CriticalSection.LockCount, -1, -2);
      if ( v193 != -2 )
      {
        if ( v191->Lock.CriticalSection.LockCount & 1 )
          RtlpNotOwnerCriticalSection(v191);
        v194 = (__int64)v191->Lock.CriticalSection.LockSemaphore;
        if ( !v194 )
          v194 = RtlpCreateDeferredCriticalSectionEvent(v191);
        do
        {
          v195 = v193 & 2 | 1;
          v196 = _InterlockedCompareExchange(&v191->Lock.CriticalSection.LockCount, v193 + v195, v193);
          v192 = v193 == v196;
          v193 = v196;
        }
        while ( !v192 );
        if ( v195 & 2 )
          RtlpUnWaitCriticalSectionEx(v191, v194);
      }
    }
  }
  return v215;
}
