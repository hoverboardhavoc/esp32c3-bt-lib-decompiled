/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  ushort uVar5;
  uint __n;
  uint uVar6;
  byte *pbVar7;
  uint *puVar8;
  ushort *puVar9;
  bool bVar10;
  uint *puVar11;
  uint *__dest;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  byte *apbStack_44 [4];
  
  puVar14 = (uint *)((int)param_2 + param_4);
  puVar13 = (uint *)((uint)*param_3 + (int)param_1);
  bVar2 = param_2 != (uint *)0x0;
  bVar3 = param_1 != (uint *)0x0;
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
  iVar12 = 0;
  __dest = param_1;
  do {
    while( true ) {
      if ((*apbStack_44[0] == 0) || (iVar12 != 0)) {
        if (puVar14 < param_2) {
          iVar12 = 1;
        }
        *param_3 = (short)__dest - (short)param_1;
        return iVar12;
      }
      if ((byte)(*apbStack_44[0] - 0x30) < 10) {
        __n = r_co_util_read_array_size(apbStack_44);
      }
      pbVar7 = apbStack_44[0] + 1;
      bVar1 = *apbStack_44[0];
      apbStack_44[0] = pbVar7;
      if (bVar1 != 0x48) break;
_L108:
      puVar9 = (ushort *)0x0;
      for (uVar6 = 0; uVar6 < __n; uVar6 = uVar6 + 1 & 0xff) {
        puVar9 = (ushort *)((uint)((int)__dest + 1) & 0xfffffffe);
        if (bVar3 && bVar2) {
          if (puVar14 < (uint *)((int)param_2 + 2)) {
            iVar12 = 1;
            break;
          }
          if (puVar13 < puVar9 + 1) {
            iVar12 = 2;
            break;
          }
          uVar5 = (ushort)*param_2;
          if (!bVar4) {
            uVar5 = uVar5 << 8 | uVar5 >> 8;
          }
          *puVar9 = uVar5;
        }
        __dest = (uint *)(puVar9 + 1);
        param_2 = (uint *)((int)param_2 + 2);
      }
      __n = 1;
      if (bVar1 == 0x4e) {
        __n = (uint)*puVar9;
      }
    }
    if (bVar1 < 0x49) {
      if (bVar1 != 0x44) {
        if (bVar1 == 0x47) {
          bVar10 = true;
        }
        else if (bVar1 != 0x42) goto _L140;
        goto _L83;
      }
      puVar8 = (uint *)((uint)((int)__dest + 3) & 0xfffffffc);
      if (bVar3 && bVar2) {
        if (puVar14 < (uint *)((int)param_2 + 3)) {
_L118:
          iVar12 = 1;
        }
        else {
          if (puVar8 + 1 <= puVar13) {
            uVar6 = (uint)(uint3)*param_2;
            if (!bVar4) {
              uVar6 = (uVar6 & 0xff) << 0x10 |
                      uVar6 & 0xff00 | (uint)(uint3)((uint3)*param_2 >> 0x10);
            }
            *puVar8 = uVar6;
            goto _L97;
          }
_L119:
          iVar12 = 2;
        }
      }
      else {
_L97:
        __dest = puVar8 + 1;
        param_2 = (uint *)((int)param_2 + 3);
      }
    }
    else {
      if (bVar1 == 0x4e) goto _L108;
      if (bVar1 == 0x6e) {
_L83:
        puVar8 = (uint *)((int)param_2 + __n);
        if (bVar3 && bVar2) {
          if (puVar14 < puVar8) goto _L118;
          if (puVar13 < (uint *)((int)__dest + __n)) goto _L119;
          if ((!bVar10) || (uVar6 = __n, puVar11 = __dest, bVar4)) {
            memmove(__dest,param_2,__n);
          }
          else {
            while (uVar6 != 0) {
              uVar6 = uVar6 - 1 & 0xffff;
              *(undefined1 *)puVar11 = *(undefined1 *)((int)param_2 + uVar6);
              puVar11 = (uint *)((int)puVar11 + 1);
            }
          }
        }
        __dest = (uint *)((int)__dest + __n);
        if (bVar1 == 0x6e) {
          __n = (uint)*(byte *)((int)puVar8 + -1);
        }
        else {
          __n = 1;
        }
        bVar10 = false;
        param_2 = puVar8;
      }
      else if (bVar1 == 0x4c) {
        puVar8 = (uint *)((uint)((int)__dest + 3) & 0xfffffffc);
        if (bVar3 && bVar2) {
          if (puVar14 < param_2 + 1) goto _L118;
          if (puVar13 < puVar8 + 1) goto _L119;
          uVar6 = *param_2;
          if (!bVar4) {
            uVar6 = uVar6 >> 8 & 0xff00 | uVar6 << 0x18 | uVar6 >> 0x18 | (uVar6 & 0xff00) << 8;
          }
          *puVar8 = uVar6;
        }
        __dest = puVar8 + 1;
        param_2 = param_2 + 1;
      }
      else {
_L140:
        iVar12 = 3;
      }
    }
  } while( true );
}

