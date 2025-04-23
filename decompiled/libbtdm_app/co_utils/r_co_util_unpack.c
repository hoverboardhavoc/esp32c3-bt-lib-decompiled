/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> co_utils.o -> r_co_util_unpack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_co_util_unpack(uint *param_1,uint *param_2,ushort *param_3,int param_4,byte *param_5)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  uint *__dest;
  ushort *puVar7;
  uint *puVar8;
  uint uVar9;
  uint __n;
  uint uVar10;
  ushort uVar11;
  uint *puVar12;
  bool bVar13;
  byte *pbVar14;
  uint *puVar15;
  uint *puVar16;
  byte *apbStack_44 [4];
  
  puVar16 = (uint *)((int)param_2 + param_4);
  puVar15 = (uint *)((int)param_1 + (uint)*param_3);
  bVar2 = param_2 == (uint *)0x0;
  bVar3 = param_1 == (uint *)0x0;
  if (*param_5 == 0x3c) {
    apbStack_44[0] = param_5 + 1;
    bVar4 = true;
  }
  else {
    bVar4 = true;
    apbStack_44[0] = param_5;
    if (*param_5 == 0x3e) {
      apbStack_44[0] = param_5 + 1;
      bVar4 = false;
    }
  }
  __n = 1;
  bVar13 = false;
  iVar6 = 0;
  __dest = param_1;
  pbVar14 = apbStack_44[0];
_L79:
  do {
    while( true ) {
      if ((*pbVar14 == 0) || (iVar6 != 0)) {
        if (puVar16 < param_2) {
          iVar6 = 1;
        }
        *param_3 = (short)__dest - (short)param_1;
        return iVar6;
      }
      if ((byte)(*pbVar14 - 0x30) < 10) {
        __n = (**(code **)(_r_modules_funcs_p + 0x14))
                        (apbStack_44,*(code **)(_r_modules_funcs_p + 0x14));
      }
      pbVar14 = apbStack_44[0] + 1;
      bVar1 = *apbStack_44[0];
      apbStack_44[0] = pbVar14;
      if (bVar1 < 0x4f) break;
      if (bVar1 == 0x6e) goto _L88;
_L109:
      iVar6 = 3;
    }
    if (bVar1 < 0x42) goto _L109;
    switch(bVar1) {
    default:
      goto _L109;
    case 0x44:
      puVar8 = (uint *)((uint)((int)__dest + 3) & 0xfffffffc);
      puVar12 = (uint *)((int)param_2 + 3);
      if (!bVar3 && !bVar2) {
        if (puVar12 <= puVar16) {
          if (puVar15 < puVar8 + 1) goto _L121;
          uVar10 = (uint)(uint3)*param_2;
          if (!bVar4) {
            uVar9 = uVar10 & 0xff00 | (uint)(uint3)((uint3)*param_2 >> 0x10);
            uVar10 = uVar10 << 0x10;
            uVar5 = 0xff0000;
_L144:
            uVar10 = uVar10 & uVar5 | uVar9;
          }
_L142:
          *puVar8 = uVar10;
          goto _L101;
        }
        goto _L120;
      }
_L101:
      param_2 = puVar12;
      __dest = puVar8 + 1;
      break;
    case 0x47:
      bVar13 = true;
    case 0x42:
_L88:
      puVar12 = (uint *)((int)param_2 + __n);
      if (!bVar3 && !bVar2) {
        if (puVar16 < puVar12) {
_L120:
          iVar6 = 1;
          break;
        }
        if (puVar15 < (uint *)((int)__dest + __n)) {
_L121:
          iVar6 = 2;
          break;
        }
        if ((!bVar13) || (puVar8 = __dest, uVar10 = __n, bVar4)) {
          memmove(__dest,param_2,__n);
        }
        else {
          while (uVar10 != 0) {
            uVar10 = uVar10 - 1 & 0xffff;
            *(undefined1 *)puVar8 = *(undefined1 *)((int)param_2 + uVar10);
            puVar8 = (uint *)((int)puVar8 + 1);
          }
        }
      }
      __dest = (uint *)((int)__dest + __n);
      if (bVar1 == 0x6e) {
        __n = (uint)*(byte *)((int)puVar12 + -1);
      }
      else {
        __n = 1;
      }
      bVar13 = false;
      param_2 = puVar12;
      break;
    case 0x48:
    case 0x4e:
      goto _L110;
    case 0x4c:
      puVar8 = (uint *)((uint)((int)__dest + 3) & 0xfffffffc);
      puVar12 = param_2 + 1;
      if (bVar3 || bVar2) goto _L101;
      if (puVar16 < puVar12) goto _L120;
      if (puVar8 + 1 <= puVar15) {
        uVar10 = *param_2;
        if (!bVar4) {
          uVar9 = uVar10 << 0x18 | uVar10 >> 0x18 | (uVar10 & 0xff00) << 8;
          uVar10 = uVar10 >> 8;
          uVar5 = 0xff00;
          goto _L144;
        }
        goto _L142;
      }
      goto _L121;
    }
  } while( true );
_L110:
  puVar7 = (ushort *)0x0;
  for (uVar10 = 0; uVar10 < __n; uVar10 = uVar10 + 1 & 0xff) {
    puVar7 = (ushort *)((uint)((int)__dest + 1) & 0xfffffffe);
    if (!bVar3 && !bVar2) {
      if (puVar16 < (uint *)((int)param_2 + 2)) {
        iVar6 = 1;
        break;
      }
      if (puVar15 < puVar7 + 1) {
        iVar6 = 2;
        break;
      }
      uVar11 = (ushort)*param_2;
      if (!bVar4) {
        uVar11 = uVar11 << 8 | uVar11 >> 8;
      }
      *puVar7 = uVar11;
    }
    __dest = (uint *)(puVar7 + 1);
    param_2 = (uint *)((int)param_2 + 2);
  }
  __n = 1;
  if (bVar1 == 0x4e) {
    __n = (uint)*puVar7;
  }
  goto _L79;
}

