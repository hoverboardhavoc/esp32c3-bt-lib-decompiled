/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  ushort *puVar5;
  undefined1 uVar6;
  uint __n;
  uint uVar7;
  bool bVar8;
  undefined1 *puVar9;
  byte *pbVar10;
  undefined4 uVar11;
  ushort *puVar12;
  undefined4 *puVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  int iVar16;
  byte *apbStack_44 [4];
  
  puVar5 = (ushort *)((int)param_2 + param_4);
  bVar2 = param_1 != (undefined1 *)0x0;
  bVar3 = param_2 != (ushort *)0x0;
  apbStack_44[0] = param_5;
  if (param_5 == (byte *)0x0) {
    r_assert_err(0,"co_utils.c",0xab);
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
  bVar8 = false;
  iVar16 = 0;
  __dest = param_1;
_L41:
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
      pbVar10 = apbStack_44[0] + 1;
      bVar1 = *apbStack_44[0];
      apbStack_44[0] = pbVar10;
      if (bVar1 != 0x48) break;
_L49:
      puVar12 = (ushort *)0x0;
      for (uVar7 = 0; uVar7 < __n; uVar7 = uVar7 + 1 & 0xff) {
        puVar12 = (ushort *)((int)param_2 + 1U & 0xfffffffe);
        if (bVar3 && bVar2) {
          if (puVar5 < puVar12 + 1) {
            iVar16 = 1;
            break;
          }
          uVar15 = (undefined1)(*puVar12 >> 8);
          uVar6 = (undefined1)*puVar12;
          if (bVar4) {
            *__dest = uVar6;
            __dest[1] = uVar15;
          }
          else {
            *__dest = uVar15;
            __dest[1] = uVar6;
          }
        }
        __dest = __dest + 2;
        param_2 = puVar12 + 1;
      }
      __n = 1;
      if (bVar1 == 0x4e) {
        __n = (uint)*puVar12;
      }
    }
    if (0x48 < bVar1) {
      if (bVar1 == 0x4e) goto _L49;
      if (bVar1 == 0x6e) {
_L23:
        puVar12 = (ushort *)((int)param_2 + __n);
        if (bVar3 && bVar2) {
          if (puVar5 < puVar12) {
_L56:
            iVar16 = 1;
            goto _L41;
          }
          if ((!bVar8) || (uVar7 = __n, puVar9 = __dest, bVar4)) {
            memmove(__dest,param_2,__n);
          }
          else {
            while (uVar7 != 0) {
              uVar7 = uVar7 - 1 & 0xffff;
              *puVar9 = *(undefined1 *)((int)param_2 + uVar7);
              puVar9 = puVar9 + 1;
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
        bVar8 = false;
        param_2 = puVar12;
        goto _L41;
      }
      if (bVar1 == 0x4c) {
        puVar13 = (undefined4 *)((int)param_2 + 3U & 0xfffffffc);
        puVar12 = (ushort *)(puVar13 + 1);
        if (bVar3 && bVar2) {
          if (puVar5 < puVar12) goto _L56;
          uVar11 = *puVar13;
          uVar14 = (undefined1)((uint)uVar11 >> 0x18);
          uVar6 = (undefined1)((uint)uVar11 >> 8);
          uVar15 = (undefined1)((uint)uVar11 >> 0x10);
          if (bVar4) {
            *__dest = (char)uVar11;
            __dest[1] = uVar6;
            __dest[2] = uVar15;
            __dest[3] = uVar14;
          }
          else {
            *__dest = uVar14;
            __dest[1] = uVar15;
            __dest[2] = uVar6;
            __dest[3] = (char)uVar11;
          }
        }
        __dest = __dest + 4;
        param_2 = puVar12;
      }
      else {
_L71:
        iVar16 = 3;
      }
      goto _L41;
    }
    if (bVar1 != 0x44) {
      if (bVar1 == 0x47) {
        bVar8 = true;
      }
      else if (bVar1 != 0x42) goto _L71;
      goto _L23;
    }
    puVar13 = (undefined4 *)((int)param_2 + 3U & 0xfffffffc);
    puVar12 = (ushort *)(puVar13 + 1);
    if (bVar3 && bVar2) {
      if (puVar5 < puVar12) goto _L56;
      uVar11 = *puVar13;
      uVar6 = (undefined1)((uint)uVar11 >> 0x10);
      uVar15 = (undefined1)((uint)uVar11 >> 8);
      if (bVar4) {
        *__dest = (char)uVar11;
        __dest[1] = uVar15;
        __dest[2] = uVar6;
      }
      else {
        *__dest = uVar6;
        __dest[1] = uVar15;
        __dest[2] = (char)uVar11;
      }
    }
    __dest = __dest + 3;
    param_2 = puVar12;
  } while( true );
}

