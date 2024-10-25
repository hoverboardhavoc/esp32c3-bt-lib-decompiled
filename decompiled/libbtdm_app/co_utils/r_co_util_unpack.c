/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  byte *pbVar5;
  ushort *puVar6;
  uint *puVar7;
  ushort uVar8;
  uint uVar9;
  uint __n;
  uint uVar10;
  bool bVar11;
  uint *puVar12;
  uint *__dest;
  int iVar13;
  uint *puVar14;
  uint *puVar15;
  byte *apbStack_44 [4];
  
  puVar15 = (uint *)((int)param_2 + param_4);
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
  bVar11 = false;
  iVar13 = 0;
  __dest = param_1;
_L78:
  while( true ) {
    if ((*apbStack_44[0] == 0) || (iVar13 != 0)) {
      if (puVar15 < param_2) {
        iVar13 = 1;
      }
      *param_3 = (short)__dest - (short)param_1;
      return iVar13;
    }
    if ((byte)(*apbStack_44[0] - 0x30) < 10) {
      __n = (**(code **)(_r_modules_funcs_p + 0x14))
                      (apbStack_44,*(code **)(_r_modules_funcs_p + 0x14));
    }
    pbVar5 = apbStack_44[0] + 1;
    bVar1 = *apbStack_44[0];
    apbStack_44[0] = pbVar5;
    if (bVar1 != 0x48) break;
_L108:
    puVar6 = (ushort *)0x0;
    for (uVar10 = 0; uVar10 < __n; uVar10 = uVar10 + 1 & 0xff) {
      puVar6 = (ushort *)((uint)((int)__dest + 1) & 0xfffffffe);
      if (!bVar3 && !bVar2) {
        if (puVar15 < (uint *)((int)param_2 + 2)) {
          iVar13 = 1;
          break;
        }
        if (puVar14 < puVar6 + 1) {
          iVar13 = 2;
          break;
        }
        uVar8 = (ushort)*param_2;
        if (!bVar4) {
          uVar8 = uVar8 << 8 | uVar8 >> 8;
        }
        *puVar6 = uVar8;
      }
      __dest = (uint *)(puVar6 + 1);
      param_2 = (uint *)((int)param_2 + 2);
    }
    __n = 1;
    if (bVar1 == 0x4e) {
      __n = (uint)*puVar6;
    }
  }
  if (0x48 < bVar1) {
    if (bVar1 != 0x4e) {
      if (bVar1 != 0x6e) {
        if (bVar1 != 0x4c) goto _L140;
        puVar7 = (uint *)((uint)((int)__dest + 3) & 0xfffffffc);
        puVar12 = param_2 + 1;
        if (!bVar3 && !bVar2) {
          if (puVar12 <= puVar15) {
            if (puVar7 + 1 <= puVar14) {
              uVar10 = *param_2;
              if (!bVar4) {
                uVar9 = uVar10 << 0x18 | uVar10 >> 0x18 | (uVar10 & 0xff00) << 8;
                uVar10 = uVar10 >> 8 & 0xff00;
                goto _L142;
              }
              goto _L139;
            }
            goto _L119;
          }
          goto _L118;
        }
        goto _L99;
      }
      goto _L83;
    }
    goto _L108;
  }
  if (bVar1 == 0x44) {
    puVar7 = (uint *)((uint)((int)__dest + 3) & 0xfffffffc);
    puVar12 = (uint *)((int)param_2 + 3);
    if (bVar3 || bVar2) {
_L99:
      param_2 = puVar12;
      __dest = puVar7 + 1;
    }
    else if (puVar15 < puVar12) {
_L118:
      iVar13 = 1;
    }
    else {
      if (puVar7 + 1 <= puVar14) {
        uVar10 = (uint)(uint3)*param_2;
        if (!bVar4) {
          uVar9 = uVar10 & 0xff00 | (uint)(uint3)((uint3)*param_2 >> 0x10);
          uVar10 = (uVar10 & 0xff) << 0x10;
_L142:
          uVar10 = uVar10 | uVar9;
        }
_L139:
        *puVar7 = uVar10;
        goto _L99;
      }
_L119:
      iVar13 = 2;
    }
    goto _L78;
  }
  if (bVar1 == 0x47) {
    bVar11 = true;
  }
  else if (bVar1 != 0x42) {
_L140:
    iVar13 = 3;
    goto _L78;
  }
_L83:
  puVar12 = (uint *)((int)param_2 + __n);
  if (!bVar3 && !bVar2) {
    if (puVar15 < puVar12) goto _L118;
    if (puVar14 < (uint *)((int)__dest + __n)) goto _L119;
    if ((!bVar11) || (uVar10 = __n, puVar7 = __dest, bVar4)) {
      memmove(__dest,param_2,__n);
    }
    else {
      while (uVar10 != 0) {
        uVar10 = uVar10 - 1 & 0xffff;
        *(undefined1 *)puVar7 = *(undefined1 *)((int)param_2 + uVar10);
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
  bVar11 = false;
  param_2 = puVar12;
  goto _L78;
}

