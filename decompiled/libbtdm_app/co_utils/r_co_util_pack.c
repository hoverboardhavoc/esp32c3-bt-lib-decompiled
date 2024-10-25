/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  ushort *puVar5;
  undefined1 uVar6;
  byte *pbVar7;
  undefined4 uVar8;
  uint __n;
  uint uVar9;
  bool bVar10;
  undefined1 *puVar11;
  undefined1 uVar12;
  ushort *puVar13;
  undefined4 *puVar14;
  undefined1 uVar15;
  int iVar16;
  byte *apbStack_44 [4];
  
  puVar5 = (ushort *)((int)param_2 + param_4);
  bVar2 = param_1 != (undefined1 *)0x0;
  bVar3 = param_2 != (ushort *)0x0;
  apbStack_44[0] = param_5;
  if (param_5 == (byte *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"co_utils.c",0xab,*(code **)(_r_plf_funcs_p + 8));
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
  bVar10 = false;
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
        __n = (**(code **)(_r_modules_funcs_p + 0x14))
                        (apbStack_44,*(code **)(_r_modules_funcs_p + 0x14));
      }
      pbVar7 = apbStack_44[0] + 1;
      bVar1 = *apbStack_44[0];
      apbStack_44[0] = pbVar7;
      if (bVar1 != 0x48) break;
_L49:
      puVar13 = (ushort *)0x0;
      for (uVar9 = 0; uVar9 < __n; uVar9 = uVar9 + 1 & 0xff) {
        puVar13 = (ushort *)((int)param_2 + 1U & 0xfffffffe);
        if (bVar3 && bVar2) {
          if (puVar5 < puVar13 + 1) {
            iVar16 = 1;
            break;
          }
          uVar6 = (undefined1)(*puVar13 >> 8);
          uVar12 = (undefined1)*puVar13;
          if (bVar4) {
            *__dest = uVar12;
            __dest[1] = uVar6;
          }
          else {
            *__dest = uVar6;
            __dest[1] = uVar12;
          }
        }
        __dest = __dest + 2;
        param_2 = puVar13 + 1;
      }
      __n = 1;
      if (bVar1 == 0x4e) {
        __n = (uint)*puVar13;
      }
    }
    if (0x48 < bVar1) {
      if (bVar1 == 0x4e) goto _L49;
      if (bVar1 == 0x6e) {
_L23:
        puVar13 = (ushort *)((int)param_2 + __n);
        if (bVar3 && bVar2) {
          if (puVar5 < puVar13) {
_L56:
            iVar16 = 1;
            goto _L41;
          }
          if ((!bVar10) || (uVar9 = __n, puVar11 = __dest, bVar4)) {
            memmove(__dest,param_2,__n);
          }
          else {
            while (uVar9 != 0) {
              uVar9 = uVar9 - 1 & 0xffff;
              *puVar11 = *(undefined1 *)((int)param_2 + uVar9);
              puVar11 = puVar11 + 1;
            }
          }
        }
        __dest = __dest + __n;
        if (bVar1 == 0x6e) {
          __n = (uint)*(byte *)((int)puVar13 + -1);
        }
        else {
          __n = 1;
        }
        bVar10 = false;
        param_2 = puVar13;
        goto _L41;
      }
      if (bVar1 == 0x4c) {
        puVar14 = (undefined4 *)((int)param_2 + 3U & 0xfffffffc);
        puVar13 = (ushort *)(puVar14 + 1);
        if (bVar3 && bVar2) {
          if (puVar5 < puVar13) goto _L56;
          uVar8 = *puVar14;
          uVar15 = (undefined1)((uint)uVar8 >> 0x18);
          uVar12 = (undefined1)((uint)uVar8 >> 0x10);
          uVar6 = (undefined1)((uint)uVar8 >> 8);
          if (bVar4) {
            *__dest = (char)uVar8;
            __dest[1] = uVar6;
            __dest[2] = uVar12;
            __dest[3] = uVar15;
          }
          else {
            *__dest = uVar15;
            __dest[1] = uVar12;
            __dest[2] = uVar6;
            __dest[3] = (char)uVar8;
          }
        }
        __dest = __dest + 4;
        param_2 = puVar13;
      }
      else {
_L71:
        iVar16 = 3;
      }
      goto _L41;
    }
    if (bVar1 != 0x44) {
      if (bVar1 == 0x47) {
        bVar10 = true;
      }
      else if (bVar1 != 0x42) goto _L71;
      goto _L23;
    }
    puVar14 = (undefined4 *)((int)param_2 + 3U & 0xfffffffc);
    puVar13 = (ushort *)(puVar14 + 1);
    if (bVar3 && bVar2) {
      if (puVar5 < puVar13) goto _L56;
      uVar8 = *puVar14;
      uVar6 = (undefined1)((uint)uVar8 >> 0x10);
      uVar12 = (undefined1)((uint)uVar8 >> 8);
      if (bVar4) {
        *__dest = (char)uVar8;
        __dest[1] = uVar12;
        __dest[2] = uVar6;
      }
      else {
        *__dest = uVar6;
        __dest[1] = uVar12;
        __dest[2] = (char)uVar8;
      }
    }
    __dest = __dest + 3;
    param_2 = puVar13;
  } while( true );
}

