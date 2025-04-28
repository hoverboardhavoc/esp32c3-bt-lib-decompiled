/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> co_utils.o -> r_co_util_unpack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_co_util_unpack(uint *param_1,uint *param_2,ushort *param_3,int param_4,byte *param_5)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  uint *__dest;
  ushort *puVar6;
  uint *puVar7;
  uint uVar8;
  uint __n;
  uint uVar9;
  bool bVar10;
  ushort uVar11;
  uint *puVar12;
  uint *puVar13;
  uint *puVar14;
  byte *apbStack_44 [4];
  
  puVar13 = (uint *)((int)param_2 + param_4);
  puVar14 = (uint *)((uint)*param_3 + (int)param_1);
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
  bVar10 = false;
  iVar5 = 0;
  __dest = param_1;
_L79:
  do {
    while( true ) {
      if ((*apbStack_44[0] == 0) || (iVar5 != 0)) {
        if (puVar13 < param_2) {
          iVar5 = 1;
        }
        *param_3 = (short)__dest - (short)param_1;
        return iVar5;
      }
      if ((byte)(*apbStack_44[0] - 0x30) < 10) {
        __n = r_co_util_read_array_size(apbStack_44);
      }
      bVar1 = *apbStack_44[0];
      apbStack_44[0] = apbStack_44[0] + 1;
      if (bVar1 < 0x4f) break;
      if (bVar1 == 0x6e) goto _L88;
_L111:
      iVar5 = 3;
    }
    if (bVar1 < 0x42) goto _L111;
    switch(bVar1) {
    default:
      goto _L111;
    case 0x44:
      puVar7 = (uint *)((uint)((int)__dest + 3) & 0xfffffffc);
      puVar12 = (uint *)((int)param_2 + 3);
      if (!bVar3 && !bVar2) {
        if (puVar12 <= puVar13) {
          if (puVar14 < puVar7 + 1) goto _L122;
          uVar9 = (uint)(uint3)*param_2;
          if (!bVar4) {
            uVar8 = uVar9 & 0xff00 | (uint)(uint3)((uint3)*param_2 >> 0x10);
            uVar9 = (uVar9 & 0xff) << 0x10;
_L144:
            uVar9 = uVar9 | uVar8;
          }
_L142:
          *puVar7 = uVar9;
          goto _L101;
        }
        goto _L121;
      }
_L101:
      param_2 = puVar12;
      __dest = puVar7 + 1;
      break;
    case 0x47:
      bVar10 = true;
    case 0x42:
_L88:
      puVar12 = (uint *)((int)param_2 + __n);
      if (!bVar3 && !bVar2) {
        if (puVar13 < puVar12) {
_L121:
          iVar5 = 1;
          break;
        }
        if (puVar14 < (uint *)((int)__dest + __n)) {
_L122:
          iVar5 = 2;
          break;
        }
        if ((!bVar10) || (uVar9 = __n, puVar7 = __dest, bVar4)) {
          memmove(__dest,param_2,__n);
        }
        else {
          while (uVar9 != 0) {
            uVar9 = uVar9 - 1 & 0xffff;
            *(undefined1 *)puVar7 = *(undefined1 *)((int)param_2 + uVar9);
            puVar7 = (uint *)((int)puVar7 + 1);
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
      bVar10 = false;
      param_2 = puVar12;
      break;
    case 0x48:
    case 0x4e:
      goto _L110;
    case 0x4c:
      puVar7 = (uint *)((uint)((int)__dest + 3) & 0xfffffffc);
      puVar12 = param_2 + 1;
      if (bVar3 || bVar2) goto _L101;
      if (puVar13 < puVar12) goto _L121;
      if (puVar7 + 1 <= puVar14) {
        uVar9 = *param_2;
        if (!bVar4) {
          uVar8 = uVar9 << 0x18 | uVar9 >> 0x18 | (uVar9 & 0xff00) << 8;
          uVar9 = uVar9 >> 8 & 0xff00;
          goto _L144;
        }
        goto _L142;
      }
      goto _L122;
    }
  } while( true );
_L110:
  puVar6 = (ushort *)0x0;
  for (uVar9 = 0; uVar9 < __n; uVar9 = uVar9 + 1 & 0xff) {
    puVar6 = (ushort *)((uint)((int)__dest + 1) & 0xfffffffe);
    if (!bVar3 && !bVar2) {
      if (puVar13 < (uint *)((int)param_2 + 2)) {
        iVar5 = 1;
        break;
      }
      if (puVar14 < puVar6 + 1) {
        iVar5 = 2;
        break;
      }
      uVar11 = (ushort)*param_2;
      if (!bVar4) {
        uVar11 = uVar11 >> 8 | uVar11 << 8;
      }
      *puVar6 = uVar11;
    }
    __dest = (uint *)(puVar6 + 1);
    param_2 = (uint *)((int)param_2 + 2);
  }
  __n = 1;
  if (bVar1 == 0x4e) {
    __n = (uint)*puVar6;
  }
  goto _L79;
}

