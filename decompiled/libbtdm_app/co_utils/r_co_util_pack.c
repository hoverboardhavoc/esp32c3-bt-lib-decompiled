/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> co_utils.o -> r_co_util_pack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_co_util_pack(undefined1 *param_1,ushort *param_2,short *param_3,int param_4,byte *param_5)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined1 *__dest;
  undefined1 uVar5;
  bool bVar6;
  undefined1 *puVar7;
  uint __n;
  uint uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined4 uVar11;
  ushort *puVar12;
  undefined4 *puVar13;
  ushort *puVar14;
  int iVar15;
  byte *pbVar16;
  byte *apbStack_44 [4];
  
  puVar14 = (ushort *)((int)param_2 + param_4);
  bVar2 = param_1 != (undefined1 *)0x0;
  bVar3 = param_2 != (ushort *)0x0;
  apbStack_44[0] = param_5;
  if (param_5 == (byte *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0xab,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*apbStack_44[0] == 0x3c) {
    apbStack_44[0] = apbStack_44[0] + 1;
    bVar4 = true;
  }
  else {
    bVar4 = true;
    if (*apbStack_44[0] == 0x3e) {
      apbStack_44[0] = apbStack_44[0] + 1;
      bVar4 = false;
    }
  }
  __n = 1;
  bVar6 = false;
  iVar15 = 0;
  __dest = param_1;
  pbVar16 = apbStack_44[0];
  do {
    while( true ) {
      if (*pbVar16 == 0) {
        if (iVar15 == 0) {
          *param_3 = (short)__dest - (short)param_1;
        }
        return iVar15;
      }
      if (iVar15 != 0) {
        return iVar15;
      }
      if ((byte)(*pbVar16 - 0x30) < 10) {
        __n = (**(code **)(_r_modules_funcs_p + 0x14))
                        (apbStack_44,*(code **)(_r_modules_funcs_p + 0x14));
      }
      pbVar16 = apbStack_44[0] + 1;
      bVar1 = *apbStack_44[0];
      apbStack_44[0] = pbVar16;
      if (bVar1 < 0x4f) break;
      if (bVar1 == 0x6e) goto _L27;
_L49:
      iVar15 = 3;
    }
    if (bVar1 < 0x42) goto _L49;
    switch(bVar1) {
    default:
      goto _L49;
    case 0x44:
      puVar13 = (undefined4 *)((int)param_2 + 3U & 0xfffffffc);
      puVar12 = (ushort *)(puVar13 + 1);
      if (bVar3 && bVar2) {
        if (puVar12 <= puVar14) {
          uVar11 = *puVar13;
          uVar5 = (undefined1)((uint)uVar11 >> 0x10);
          uVar9 = (undefined1)((uint)uVar11 >> 8);
          if (bVar4) {
            *__dest = (char)uVar11;
            __dest[1] = uVar9;
            __dest[2] = uVar5;
          }
          else {
            *__dest = uVar5;
            __dest[1] = uVar9;
            __dest[2] = (char)uVar11;
          }
          goto _L38;
        }
        goto _L57;
      }
_L38:
      __dest = __dest + 3;
      param_2 = puVar12;
      break;
    case 0x47:
      bVar6 = true;
    case 0x42:
_L27:
      puVar12 = (ushort *)((int)param_2 + __n);
      if (bVar3 && bVar2) {
        if (puVar14 < puVar12) {
_L57:
          iVar15 = 1;
          break;
        }
        if ((!bVar6) || (puVar7 = __dest, uVar8 = __n, bVar4)) {
          memmove(__dest,param_2,__n);
        }
        else {
          while (uVar8 != 0) {
            uVar8 = uVar8 - 1 & 0xffff;
            *puVar7 = *(undefined1 *)((int)param_2 + uVar8);
            puVar7 = puVar7 + 1;
          }
        }
      }
      __dest = __dest + __n;
      if (bVar1 == 0x6e) {
        __n = (uint)*(byte *)((int)puVar12 + -1);
      }
      else {
        __n = 1;
      }
      bVar6 = false;
      param_2 = puVar12;
      break;
    case 0x48:
    case 0x4e:
      puVar12 = (ushort *)0x0;
      for (uVar8 = 0; uVar8 < __n; uVar8 = uVar8 + 1 & 0xff) {
        puVar12 = (ushort *)((int)param_2 + 1U & 0xfffffffe);
        if (bVar3 && bVar2) {
          if (puVar14 < puVar12 + 1) {
            iVar15 = 1;
            break;
          }
          uVar5 = (undefined1)(*puVar12 >> 8);
          uVar9 = (undefined1)*puVar12;
          if (bVar4) {
            *__dest = uVar9;
            uVar9 = uVar5;
          }
          else {
            *__dest = uVar5;
          }
          __dest[1] = uVar9;
        }
        __dest = __dest + 2;
        param_2 = puVar12 + 1;
      }
      __n = 1;
      if (bVar1 == 0x4e) {
        __n = (uint)*puVar12;
      }
      break;
    case 0x4c:
      puVar13 = (undefined4 *)((int)param_2 + 3U & 0xfffffffc);
      puVar12 = (ushort *)(puVar13 + 1);
      if (bVar3 && bVar2) {
        if (puVar14 < puVar12) goto _L57;
        uVar11 = *puVar13;
        uVar5 = (undefined1)((uint)uVar11 >> 0x18);
        uVar9 = (undefined1)((uint)uVar11 >> 8);
        uVar10 = (undefined1)((uint)uVar11 >> 0x10);
        if (bVar4) {
          *__dest = (char)uVar11;
          __dest[1] = uVar9;
          __dest[2] = uVar10;
          __dest[3] = uVar5;
        }
        else {
          *__dest = uVar5;
          __dest[1] = uVar10;
          __dest[2] = uVar9;
          __dest[3] = (char)uVar11;
        }
      }
      __dest = __dest + 4;
      param_2 = puVar12;
    }
  } while( true );
}

