/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> co_utils.o -> r_co_util_pack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

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
  byte *pbVar9;
  undefined4 uVar10;
  undefined1 uVar11;
  ushort *puVar12;
  undefined4 *puVar13;
  undefined1 uVar14;
  ushort *puVar15;
  int iVar16;
  byte *apbStack_44 [4];
  
  puVar15 = (ushort *)((int)param_2 + param_4);
  bVar2 = param_1 != (undefined1 *)0x0;
  bVar3 = param_2 != (ushort *)0x0;
  apbStack_44[0] = param_5;
  if (param_5 == (byte *)0x0) {
    r_assert_err(0,0x10000,0xab);
  }
  if (*param_5 == 0x3c) {
    apbStack_44[0] = param_5 + 1;
    bVar4 = true;
  }
  else {
    bVar4 = true;
    if (*param_5 == 0x3e) {
      apbStack_44[0] = param_5 + 1;
      bVar4 = false;
    }
  }
  __n = 1;
  bVar6 = false;
  iVar16 = 0;
  __dest = param_1;
  do {
    while( true ) {
      if (*apbStack_44[0] == 0) {
        if (iVar16 == 0) {
          *param_3 = (short)__dest - (short)param_1;
        }
        return iVar16;
      }
      if (iVar16 != 0) {
        return iVar16;
      }
      if ((byte)(*apbStack_44[0] - 0x30) < 10) {
        __n = r_co_util_read_array_size(apbStack_44);
      }
      pbVar9 = apbStack_44[0] + 1;
      bVar1 = *apbStack_44[0];
      apbStack_44[0] = pbVar9;
      if (bVar1 < 0x4f) break;
      if (bVar1 == 0x6e) goto _L27;
_L51:
      iVar16 = 3;
    }
    if (bVar1 < 0x42) goto _L51;
    switch(bVar1) {
    default:
      goto _L51;
    case 0x44:
      puVar13 = (undefined4 *)((int)param_2 + 3U & 0xfffffffc);
      puVar12 = (ushort *)(puVar13 + 1);
      if (bVar3 && bVar2) {
        if (puVar12 <= puVar15) {
          uVar10 = *puVar13;
          uVar5 = (undefined1)((uint)uVar10 >> 0x10);
          uVar11 = (undefined1)((uint)uVar10 >> 8);
          if (bVar4) {
            *__dest = (char)uVar10;
            __dest[1] = uVar11;
            __dest[2] = uVar5;
          }
          else {
            *__dest = uVar5;
            __dest[1] = uVar11;
            __dest[2] = (char)uVar10;
          }
          goto _L38;
        }
        goto _L58;
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
        if (puVar15 < puVar12) {
_L58:
          iVar16 = 1;
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
          if (puVar15 < puVar12 + 1) {
            iVar16 = 1;
            break;
          }
          uVar5 = (undefined1)(*puVar12 >> 8);
          uVar11 = (undefined1)*puVar12;
          if (bVar4) {
            *__dest = uVar11;
            __dest[1] = uVar5;
          }
          else {
            *__dest = uVar5;
            __dest[1] = uVar11;
          }
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
        if (puVar15 < puVar12) goto _L58;
        uVar10 = *puVar13;
        uVar14 = (undefined1)((uint)uVar10 >> 0x18);
        uVar11 = (undefined1)((uint)uVar10 >> 0x10);
        uVar5 = (undefined1)((uint)uVar10 >> 8);
        if (bVar4) {
          *__dest = (char)uVar10;
          __dest[1] = uVar5;
          __dest[2] = uVar11;
          __dest[3] = uVar14;
        }
        else {
          *__dest = uVar14;
          __dest[1] = uVar11;
          __dest[2] = uVar5;
          __dest[3] = (char)uVar10;
        }
      }
      __dest = __dest + 4;
      param_2 = puVar12;
    }
  } while( true );
}

